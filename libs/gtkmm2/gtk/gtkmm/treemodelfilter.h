// -*- c++ -*-
// Generated by gtkmmproc -- DO NOT MODIFY!
#ifndef _GTKMM_TREEMODELFILTER_H
#define _GTKMM_TREEMODELFILTER_H

#include <glibmm.h>

/* $Id$ */

/* Copyright(C) 1998-2002 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or(at your option) any later version.
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

#include <gtkmm/treeiter.h>
#include <gtkmm/treemodel.h>
// We couldn't include it in treemodel.h, but doing it here makes it easier for people.
#include <gtkmm/treepath.h>


#ifndef DOXYGEN_SHOULD_SKIP_THIS
typedef struct _GtkTreeModelFilter GtkTreeModelFilter;
typedef struct _GtkTreeModelFilterClass GtkTreeModelFilterClass;
#endif /* DOXYGEN_SHOULD_SKIP_THIS */


namespace Gtk
{ class TreeModelFilter_Class; } // namespace Gtk
namespace Gtk
{

/** 
 * @ingroup TreeView
 * 
 */

class TreeModelFilter :
  public Glib::Object,
  public TreeModel
{
  
#ifndef DOXYGEN_SHOULD_SKIP_THIS

public:
  typedef TreeModelFilter CppObjectType;
  typedef TreeModelFilter_Class CppClassType;
  typedef GtkTreeModelFilter BaseObjectType;
  typedef GtkTreeModelFilterClass BaseClassType;

private:  friend class TreeModelFilter_Class;
  static CppClassType treemodelfilter_class_;

private:
  // noncopyable
  TreeModelFilter(const TreeModelFilter&);
  TreeModelFilter& operator=(const TreeModelFilter&);

protected:
  explicit TreeModelFilter(const Glib::ConstructParams& construct_params);
  explicit TreeModelFilter(GtkTreeModelFilter* castitem);

#endif /* DOXYGEN_SHOULD_SKIP_THIS */

public:
  virtual ~TreeModelFilter();

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  static GType get_type()      G_GNUC_CONST;
  static GType get_base_type() G_GNUC_CONST;
#endif

  ///Provides access to the underlying C GObject.
  GtkTreeModelFilter*       gobj()       { return reinterpret_cast<GtkTreeModelFilter*>(gobject_); }

  ///Provides access to the underlying C GObject.
  const GtkTreeModelFilter* gobj() const { return reinterpret_cast<GtkTreeModelFilter*>(gobject_); }

  ///Provides access to the underlying C instance. The caller is responsible for unrefing it. Use when directly setting fields in structs.
  GtkTreeModelFilter* gobj_copy();

private:

  
protected:

  explicit TreeModelFilter(const Glib::RefPtr<TreeModel>& child_model);
  explicit TreeModelFilter(const Glib::RefPtr<TreeModel>& child_model, const TreeModel::Path& virtual_root);
  

public:

  /** This creates a TreeModelFilter with @a child_model as the child model.
   * You can use set_visible_func(), set_visible_column() and/or set_modify_func() to change the mapping of child
   * model to parent model.
   */
  
  static Glib::RefPtr<TreeModelFilter> create(const Glib::RefPtr<TreeModel>& child_model);


  /** This creates a TreeModelFilter with @a child_model as the child model, and @a root as the virtual root.
   * You can use set_visible_func(), set_visible_column() and/or set_modify_func() to change the mapping of child
   * model to parent model.
   */
  
  static Glib::RefPtr<TreeModelFilter> create(const Glib::RefPtr<TreeModel>& child_model, const TreeModel::Path& virtual_root);


  /** For instance,
   * bool on_visible(const TreeModel::const_iterator& iter);
   * This should return true if the given row should be visible and false otherwise.
   */                                     
  typedef sigc::slot<bool, const TreeModel::const_iterator&> SlotVisible;

  /** Sets the "visible" callback used when filtering the filter.
   * The callback function should return true if the given row should be visible and false otherwise.
   *
   * @param slot A callback slot which determines whether the row should be visible.
   */
  void set_visible_func(const SlotVisible& slot);
  

  //TODO: It would be nicer to use "const TreeModelColumnBase& column" instead of "int column",
  //but how can we get the TreeModelColumnBase from the int in the SignalProxy?
  //Maybe we could pass the ColumnsRecord to set_modify_func() and store it in the proxy? murrayc.
  /** For instance,
   *   void on_modify(const Gtk::TreeModel::iterator& iter, Glib::ValueBase& value, int column);
   *
   * where iter is an iterator to a row in the child model,
   * value is an output parameter in which you must store the value to be used in the parent model's row,
   * column is the column in the parent row whose row value you must provide in the value output paramater.
   */
  typedef sigc::slot<void, const Gtk::TreeModel::iterator& /* iter */, Glib::ValueBase& /* value */, int /* column */> SlotModify;

  /** Specify columns that will be provided by this model, and a callback that will provide data for these 
   * columns based on data in the columns of the child model.
   * The modify function will get called for each data access.
   *
   * @param columns Column types for this model (which will be exposed to the parent model/view).
   * @param slot A callback which will be called for each data access.
   */
  void set_modify_func(const TreeModelColumnRecord& columns, const SlotModify& slot);
  
 
  /** Sets @a column  of the child_model to be the column where @a filter  should
   * look for visibility information. @a columns  should be a column of type
   * G::TYPE_BOOLEAN, where <tt>true</tt> means that a row is visible, and <tt>false</tt>
   * if not.
   * 
   * Since: 2.4
   * @param column A <tt>int</tt> which is the column containing the visible information.
   */
  void set_visible_column(const TreeModelColumnBase& column);
  
  /** Sets @a column  of the child_model to be the column where @a filter  should
   * look for visibility information. @a columns  should be a column of type
   * G::TYPE_BOOLEAN, where <tt>true</tt> means that a row is visible, and <tt>false</tt>
   * if not.
   * 
   * Since: 2.4
   * @param column A <tt>int</tt> which is the column containing the visible information.
   */
  void set_visible_column(int column);

  
  /** Returns a pointer to the child model of @a filter .
   * @return A pointer to a Gtk::TreeModel.
   * 
   * Since: 2.4.
   */
  Glib::RefPtr<TreeModel> get_model();
  
  /** Returns a pointer to the child model of @a filter .
   * @return A pointer to a Gtk::TreeModel.
   * 
   * Since: 2.4.
   */
  Glib::RefPtr<const TreeModel> get_model() const;

  /** Gets an iterator that points to the sorted row that corresponds to the child row pointed at by child_iter.
   *
   * @param child_iter A valid iterator pointing to a row on the child model.
   * @result A valid iterator that points to the row in this sorted model.
   */
  iterator convert_child_iter_to_iter(const iterator& child_iter) const;

  /** Gets an iterator that points to the child row that corresponds to the sorted row pointed at by sorted_iter.
   *
   * @param filter_iter A valid iterator pointing to a row on the sorted model.
   * @result A valid iterator that points to the row in the child model.
   */
  iterator convert_iter_to_child_iter(const iterator& filter_iter) const;

  //TODO: Remove these deprecated non-const versions when we can break ABI:
  
  /** Converts @a child_path  to a path relative to @a filter . That is, @a child_path 
   * points to a path in the child model. The rerturned path will point to the
   * same row in the filtered model. If @a child_path  isn't a valid path on the
   * child model, then <tt>0</tt> is returned.
   * @param child_path A Gtk::TreePath to convert.
   * @return A newly allocated Gtk::TreePath, or <tt>0</tt>.
   * 
   * Since: 2.4.
   */
  Path convert_child_path_to_path(const Path& child_path);
  
  /** Converts @a filter_path  to a path on the child model of @a filter . That is,
   *  @a filter_path  points to a location in @a filter . The returned path will
   * point to the same location in the model not being filtered. If @a filter_path 
   * does not point to a location in the child model, <tt>0</tt> is returned.
   * @param filter_path A Gtk::TreePath to convert.
   * @return A newly allocated Gtk::TreePath, or <tt>0</tt>.
   * 
   * Since: 2.4.
   */
  Path convert_path_to_child_path(const Path& filter_path);

  
  /** Converts @a child_path  to a path relative to @a filter . That is, @a child_path 
   * points to a path in the child model. The rerturned path will point to the
   * same row in the filtered model. If @a child_path  isn't a valid path on the
   * child model, then <tt>0</tt> is returned.
   * @param child_path A Gtk::TreePath to convert.
   * @return A newly allocated Gtk::TreePath, or <tt>0</tt>.
   * 
   * Since: 2.4.
   */
  Path convert_child_path_to_path(const Path& child_path) const;
  
  /** Converts @a filter_path  to a path on the child model of @a filter . That is,
   *  @a filter_path  points to a location in @a filter . The returned path will
   * point to the same location in the model not being filtered. If @a filter_path 
   * does not point to a location in the child model, <tt>0</tt> is returned.
   * @param filter_path A Gtk::TreePath to convert.
   * @return A newly allocated Gtk::TreePath, or <tt>0</tt>.
   * 
   * Since: 2.4.
   */
  Path convert_path_to_child_path(const Path& filter_path) const;

  
  /** Emits ::row_changed for each row in the child model, which causes
   * the filter to re-evaluate whether a row is visible or not.
   * 
   * Since: 2.4
   */
  void refilter();
  
  /** This function should almost never be called. It clears the @a filter 
   * of any cached iterators that haven't been reffed with
   * ref_node(). This might be useful if the child model
   * being filtered is static (and doesn't change often) and there has been
   * a lot of unreffed access to nodes. As a side effect of this function,
   * all unreffed itters will be invalid.
   * 
   * Since: 2.4
   */
  void clear_cache();

protected:
  virtual void set_value_impl(const iterator& row, int column, const Glib::ValueBase& value);


public:

public:
  //C++ methods used to invoke GTK+ virtual functions:

protected:
  //GTK+ Virtual Functions (override these to change behaviour):

  //Default Signal Handlers::


};

} // namespace Gtk


namespace Glib
{
  /** @relates Gtk::TreeModelFilter
   * @param object The C instance
   * @param take_copy False if the result should take ownership of the C instance. True if it should take a new copy or ref.
   * @result A C++ instance that wraps this C instance.
   */
  Glib::RefPtr<Gtk::TreeModelFilter> wrap(GtkTreeModelFilter* object, bool take_copy = false);
}


#endif /* _GTKMM_TREEMODELFILTER_H */
