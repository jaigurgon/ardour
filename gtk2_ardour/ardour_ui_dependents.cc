/*
    Copyright (C) 2000 Paul Davis

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

*/

#ifdef WAF_BUILD
#include "gtk2ardour-config.h"
#endif

/* this file exists solely to break compilation dependencies that
   would connect changes to the mixer or editor objects.
*/

#include <cstdio>

#include "pbd/error.h"

#include "ardour/session.h"

#include "ardour_ui.h"
#include "public_editor.h"
#include "mixer_ui.h"
#include "keyboard.h"
#include "splash.h"
#include "route_params_ui.h"
#include "opts.h"
#include "i18n.h"

using namespace Gtk;
using namespace PBD;

namespace ARDOUR {
	class Session;
	class Route;
}

using namespace ARDOUR;

void
ARDOUR_UI::shutdown ()
{
	if (ui_config->dirty()) {
		ui_config->save_state();
	}
}

void
ARDOUR_UI::we_have_dependents ()
{
	install_actions ();
	ProcessorBox::register_actions ();
	keyboard->setup_keybindings ();
	editor->setup_tooltips ();
	editor->UpdateAllTransportClocks.connect (sigc::mem_fun (*this, &ARDOUR_UI::update_transport_clocks));

	editor->track_mixer_selection ();
	mixer->track_editor_selection ();
}

void
ARDOUR_UI::connect_dependents_to_session (ARDOUR::Session *s)
{
	BootMessage (_("Setup Editor"));
	editor->set_session (s);
	BootMessage (_("Setup Mixer"));
	mixer->set_session (s);

	/* its safe to do this now */

	BootMessage (_("Reload Session History"));
	s->restore_history ("");
}

static bool
_hide_splash (gpointer arg)
{
	((ARDOUR_UI*)arg)->hide_splash();
	return false;
}

void
ARDOUR_UI::goto_editor_window ()
{
	if (splash && splash->is_visible()) {
		// in 2 seconds, hide the splash screen
		Glib::signal_timeout().connect (sigc::bind (sigc::ptr_fun (_hide_splash), this), 2000);
	}

	editor->show_window ();
	editor->present ();
	flush_pending ();
}

void
ARDOUR_UI::goto_mixer_window ()
{
	if (!editor) {
		return;
	}

	Glib::RefPtr<Gdk::Window> win = editor->get_window ();
	Glib::RefPtr<Gdk::Screen> screen;
	
	if (win) {
		screen = win->get_screen();
	} else {
		screen = Gdk::Screen::get_default();
	}
	
	if (screen && screen->get_height() < 700) {
		Gtk::MessageDialog msg (_("This screen is not tall enough to display the mixer window"));
		msg.run ();
		return;
	}

	mixer->show_window ();
	mixer->present ();
	flush_pending ();
}

void
ARDOUR_UI::toggle_mixer_window ()
{
	Glib::RefPtr<Action> act = ActionManager::get_action (X_("Common"), X_("toggle-mixer"));
	if (!act) {
		return;
	}

	Glib::RefPtr<ToggleAction> tact = Glib::RefPtr<ToggleAction>::cast_dynamic (act);

	if (tact->get_active()) {
		goto_mixer_window ();
	} else {
		mixer->hide ();
	}
}

void
ARDOUR_UI::toggle_editor_mixer ()
{
	if (editor && mixer) {

		if (editor->get_screen() != mixer->get_screen()) {
			// different screens, so don't do anything
			return;
		}

		/* See if they are obscuring each other */
		
		gint ex, ey, ew, eh;
		gint mx, my, mw, mh;

		editor->get_position (ex, ey);
		editor->get_size (ew, eh);

		mixer->get_position (mx, my);
		mixer->get_size (mw, mh);

		GdkRectangle e;
		GdkRectangle m;
		GdkRectangle r;

		e.x = ex;
		e.y = ey;
		e.width = ew;
		e.height = eh;

		m.x = mx;
		m.y = my;
		m.width = mw;
		m.height = mh;
		
		if (!gdk_rectangle_intersect (&e, &m, &r)) {
			/* they do not intersect so do not toggle */
			return;
		}
	}
		
	if (mixer && mixer->fully_visible()) {
		goto_editor_window ();
	} else {
		goto_mixer_window ();
	}
}

/** The main editor window has been closed */
gint
ARDOUR_UI::exit_on_main_window_close (GdkEventAny * /*ev*/)
{
#ifdef TOP_MENUBAR
	/* just hide the window, and return - the top menu stays up */
	editor->hide ();
	return TRUE;
#else
	/* time to get out of here */
	finish();
	return TRUE;
#endif
}

