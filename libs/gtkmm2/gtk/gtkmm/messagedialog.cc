// Generated by gtkmmproc -- DO NOT MODIFY!

#include <gtkmm/messagedialog.h>
#include <gtkmm/private/messagedialog_p.h>

#include <gtk/gtktypebuiltins.h>
// -*- c++ -*-
/* $Id$ */

/* 
 *
 * Copyright 2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <gtk/gtkmessagedialog.h>
#include <gtk/gtklabel.h>


namespace Gtk
{

MessageDialog::MessageDialog(const Glib::ustring& message, bool use_markup,
                             MessageType type, ButtonsType buttons,
                             bool modal)
:
  Glib::ObjectBase(0), //Mark this class as gtkmmproc-generated, rather than a custom class, to allow vfunc optimisations.
  Gtk::Dialog(Glib::ConstructParams(messagedialog_class_.init(), "message_type",(GtkMessageType)type,"buttons",(GtkButtonsType)buttons, (char*) 0))
{
  set_modal(modal);
  set_message(message, use_markup);
}

MessageDialog::MessageDialog(Gtk::Window& parent, const Glib::ustring& message, bool use_markup,
                             MessageType type, ButtonsType buttons,
                             bool modal)
:
  Glib::ObjectBase(0), //Mark this class as gtkmmproc-generated, rather than a custom class, to allow vfunc optimisations.
  Gtk::Dialog(Glib::ConstructParams(messagedialog_class_.init(), "message_type",(GtkMessageType)type,"buttons",(GtkButtonsType)buttons, (char*) 0))
{
  set_modal(modal);
  set_transient_for(parent);
  set_message(message, use_markup);
}

void MessageDialog::set_message(const Glib::ustring& message, bool use_markup)
{
  // TODO: GTK+ bug: The label widget is really a <private> struct field.
  // There should really be a message property.

  if(use_markup)
    gtk_message_dialog_set_markup(gobj(), message.c_str()); 
  else
    gtk_label_set_text(GTK_LABEL(gobj()->label), message.c_str());
}

void MessageDialog::set_secondary_text(const Glib::ustring& text, bool use_markup)
{
  if(use_markup)
    gtk_message_dialog_format_secondary_markup(gobj(), text.c_str());
  else
    gtk_message_dialog_format_secondary_text(gobj(), text.c_str());
}

} // namespace Gtk


namespace
{
} // anonymous namespace

// static
GType Glib::Value<Gtk::MessageType>::value_type()
{
  return gtk_message_type_get_type();
}

// static
GType Glib::Value<Gtk::ButtonsType>::value_type()
{
  return gtk_buttons_type_get_type();
}


namespace Glib
{

Gtk::MessageDialog* wrap(GtkMessageDialog* object, bool take_copy)
{
  return dynamic_cast<Gtk::MessageDialog *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Gtk
{


/* The *_Class implementation: */

const Glib::Class& MessageDialog_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &MessageDialog_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(gtk_message_dialog_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  }

  return *this;
}

void MessageDialog_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

}


Glib::ObjectBase* MessageDialog_Class::wrap_new(GObject* o)
{
  return new MessageDialog((GtkMessageDialog*)(o)); //top-level windows can not be manage()ed.

}


/* The implementation: */

MessageDialog::MessageDialog(const Glib::ConstructParams& construct_params)
:
  Gtk::Dialog(construct_params)
{
  }

MessageDialog::MessageDialog(GtkMessageDialog* castitem)
:
  Gtk::Dialog((GtkDialog*)(castitem))
{
  }

MessageDialog::~MessageDialog()
{
  destroy_();
}

MessageDialog::CppClassType MessageDialog::messagedialog_class_; // initialize static member

GType MessageDialog::get_type()
{
  return messagedialog_class_.init().get_type();
}

GType MessageDialog::get_base_type()
{
  return gtk_message_dialog_get_type();
}


void MessageDialog::set_markup(const Glib::ustring& str)
{
  gtk_message_dialog_set_markup(gobj(), str.c_str());
}


} // namespace Gtk

