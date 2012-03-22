// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _PANGOMM_CONTEXT_H
#define _PANGOMM_CONTEXT_H

#include <glibmm.h>

/* $Id$ */

/* context.h
 * 
 * Copyright (C) 1998-1999 The gtkmm Development Team 
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


#include <glibmm/object.h>
#include <glibmm/arrayhandle.h>
#include <glibmm/listhandle.h>
#include <pangomm/fontdescription.h>
#include <pangomm/fontmetrics.h>
#include <pangomm/fontset.h>
#include <pangomm/fontmap.h>
#include <pangomm/item.h>
#include <pangomm/attrlist.h>
#include <pangomm/types.h> //For Matrix
#include <pango/pango-context.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _PangoContext PangoContext;
typedef struct _PangoContextClass PangoContextClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Pango
{ class Context_Class; } // namespace Pango
namespace Pango
{


/** @addtogroup pangommEnums Enums and Flags */

/**
 * @ingroup pangommEnums
 */
enum Direction
{
  DIRECTION_LTR,
  DIRECTION_RTL,
  DIRECTION_TTB_LTR,
  DIRECTION_TTB_RTL,
  DIRECTION_WEAK_LTR,
  DIRECTION_WEAK_RTL,
  DIRECTION_NEUTRAL
};

} // namespace Pango


#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

template <>
class Value<Pango::Direction> : public Glib::Value_Enum<Pango::Direction>
{
public:
  static GType value_type() G_GNUC_CONST;
};

} // namespace Glib
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Pango
{


/** A Pango::Context stores global information used to control the itemization process.
 * You can retrieve a Pango::Context object with Gtk::Widget::create_pango_context() or
 * Gtk::Widget::get_pango_context(). If you don't use gtkmm call some c function of the
 * pango backend you intend to use and create a wrapper for the returned context,
 * e.g. Glib::wrap(pango_x_get_context()).
 *
 * Creating a Pango::Context object is the starting point of every rendering process.
 * You can either use it to create a high level Pango::Layout object which does all
 * the hard work for you by passing it into
 * Pango::Layout::create() or to generate glyph strings from character strings with
 * the help of itemize() and Pango::Item::shape() subsequently.
 *
 * Which fonts are used for rendering can be influenced by setting the default
 * font description, language and base direction of the context.
 *
 * If you want to calculate the space some text will need to be displayed you
 * might find the functions of Pango::FontMetrics useful. Use get_metrics() to
 * obtain the Pango::FontMetrics object for a specific Pango::FontDescription.
 * For more detailed calculations in a rendering-system-independant manner
 * and to determine whether specific characters can be represented by the
 * font that would be used for a specific Pango::FontDescription load a
 * Pango::Fontset with load_fontset() (load_font() returns the Pango::Font
 * that is the closest match for a Pango::FontDescription; however that's not
 * necessarily the font that will be used for rendering).
 */

class Context : public Glib::Object
{
   
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef Context CppObjectType;
  typedef Context_Class CppClassType;
  typedef PangoContext BaseObjectType;
  typedef PangoContextClass BaseClassType;

private:  friend class Context_Class;
  static CppClassType context_class_;

private:
  // noncopyable
  Context(const Context&);
  Context& operator=(const Context&);

protected:
  explicit Context(const Glib::ConstructParams& construct_params);
  explicit Context(PangoContext* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~Context();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  PangoContext*       gobj()       { return reinterpret_cast<PangoContext*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const PangoContext* gobj() const { return reinterpret_cast<PangoContext*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  PangoContext* gobj_copy();

private:

    //PANGO_ENABLE_BACKEND
   
protected:
  Context();
  
public:
  /** List all available font families for a context.
   * You can specify one of these as your desired font family in the Pango::FontDesciption
   * objects you use, e.g. in the default font description of the context.
   * @return An array of Pango::FontFamily objects.
   */
  Glib::ArrayHandle< Glib::RefPtr<FontFamily> > list_families() const;
  
  
  /** Gets the Pango::Fontmap used to look up fonts for this context.
   * @return The font map for the Pango::Context. This value
   * is owned by Pango and should not be unreferenced.
   * 
   * Since: 1.6.
   */
  Glib::RefPtr<FontMap> get_font_map();
  
  /** Gets the Pango::Fontmap used to look up fonts for this context.
   * @return The font map for the Pango::Context. This value
   * is owned by Pango and should not be unreferenced.
   * 
   * Since: 1.6.
   */
  Glib::RefPtr<const FontMap> get_font_map() const;  

  
  /** Loads the font in one of the fontmaps in the context
   * that is the closest match for @a desc .
   * @param desc A Pango::FontDescription describing the font to load.
   * @return The font loaded, or <tt>0</tt> if no font matched.
   */
  Glib::RefPtr<Font> load_font(const FontDescription& desc) const;
  
  /** Load a set of fonts in the context that can be used to render
   * a font matching @a desc .
   * @param desc A Pango::FontDescription describing the fonts to load.
   * @param language A Pango::Language the fonts will be used for.
   * @return The fontset, or <tt>0</tt> if no font matched.
   */
  Glib::RefPtr<Fontset> load_fontset(const FontDescription& desc, const Language& language) const;

  /** Get overall metric information for a particular font description.
   * The metrics may be substantially different for different scripts. However this
   * function overload returns the metrics of the entire font.
   * @param desc A Pango::FontDescription object.
   * @return A Pango::FontMetrics object.
   */
  FontMetrics get_metrics(const FontDescription& desc) const;
  
  /** Get overall metric information for a font particular font
   * description.  Since the metrics may be substantially different for
   * different scripts, a language tag can be provided to indicate that
   * the metrics should be retrieved that correspond to the script(s)
   * used by that language.
   * 
   * The Pango::FontDescription is interpreted in the same way as
   * by pango_itemize(), and the family name may be a comma separated
   * list of figures. If characters from multiple of these families
   * would be used to render the string, then the returned fonts would
   * be a composite of the metrics for the fonts loaded for the
   * individual families.
   * @param desc A Pango::FontDescription structure.
   * @param language Language tag used to determine which script to get the metrics
   * for.
   * @return A Pango::Metrics object.
   */
  FontMetrics get_metrics(const FontDescription& desc, const Language& language) const;
  
  /** Set the default font description for the context
   * @param desc The new pango font description.
   */
  void set_font_description(const FontDescription& desc);
  
  /** Retrieve the default font description for the context.
   * @return A pointer to the context's default font description.
   * This value must not be modified or freed.
   */
  FontDescription get_font_description() const;
  
  /** Retrieves the global language tag for the context.
   * @return The global language tag.
   */
  Language get_language() const;
  
  /** Sets the global language tag for the context.
   * @param language The new language tag.
   */
  void set_language(const Language& language);
  
  /** Sets the base direction for the context.
   * 
   * The base direction is used in applying the Unicode bidirectional
   * algorithm; if the @a direction  is Pango::DIRECTION_LTR or
   * Pango::DIRECTION_RTL, then the value will be used as the paragraph
   * direction in the Unicode bidirectional algorithm.  A value of
   * Pango::DIRECTION_WEAK_LTR or Pango::DIRECTION_WEAK_RTL is used only
   * for paragraphs that do not contain any strong characters themselves.
   * @param direction The new base direction.
   */
  void set_base_dir(Direction direction);
  
  /** Retrieves the base direction for the context. See
   * pango_context_set_base_dir().
   * @return The base direction for the context.
   */
  Direction get_base_dir() const;

  
  /** Sets the transformation matrix that will be applied when rendering
   * with this context. Note that reported metrics are in the user space
   * coordinates before the application of the matrix, not device-space
   * coordiantes after the application of the matrix. So, they don't scale
   * with the matrix, though they may change slightly for different
   * matrices, depending on how the text is fit to the pixel grid.
   * 
   * Since: 1.6
   * @param matrix A Pango::Matrix, or <tt>0</tt> to unset any existing matrix.
   * (No matrix set is the same as setting the identity matrix.).
   */
  void set_matrix(const Matrix& matrix);
  //TODO: _WRAP_METHOD(Matrix get_matrix() const, pango_context_get_matrix)

  /** Breaks a piece of text into segments with consistent directional level and shaping engine.
   * Each byte of @a text will be contained in exactly one of the items in the returned list.
   * The generated list of items will be in logical order (the start offsets of the items
   * are ascending).
   * @param text The text to itemize.
   * @param attrs The set of attributes that apply.
   * @return A list of Pango::Item objects.
   */
  ListHandle_Item itemize(const Glib::ustring& text, const AttrList& attrs) const;

  /** Breaks a piece of text into segments with consistent directional level and shaping engine.
   * Each byte of @a text will be contained in exactly one of the items in the returned list. 
   * The generated list of items will be in logical order (the start offsets of the items
   * are ascending).
   *
   * @a cached_iter should be an iterator over @a attrs currently positioned at a range before
   * or containing @a start_index. @a cached_iter will be advanced to the range covering the
   * position just after @a start_index + @a length. (i.e. if itemizing in a loop, just keep
   * passing in the same @a cached_iter).
   *
   * @param text The text to itemize.
   * @param start_index First byte in @a text to process.
   * @param length The number of bytes (not characters) to process after @a start_index. This must be >= <tt>0</tt>.
   * @param attrs The set of attributes that apply to @a text.
   * @param cached_iter Cached attribute iterator.
   * @return A list of Pango::Item structures.
   */
  ListHandle_Item itemize(const Glib::ustring& text, int start_index, int length,
                          const AttrList& attrs, AttrIter& cached_iter) const;


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} /* namespace Pango */


namespace Glib
{
  /** @relates Pango::Context
   * @param object The C instance
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   */
  Glib::RefPtr<Pango::Context> wrap(PangoContext* object, bool take_copy = false);
}


#endif /* _PANGOMM_CONTEXT_H */
