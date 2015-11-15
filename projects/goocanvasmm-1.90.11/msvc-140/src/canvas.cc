// Generated by gtkmmproc -- DO NOT MODIFY!


#include <glibmm.h>

#include <goocanvasmm/canvas.h>
#include <goocanvasmm/private/canvas_p.h>


/* Copyright (C) 1998-2006 The gtkmm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <goocanvas.h>
#include <goocanvasmm/bounds.h>

namespace Goocanvas
{

Gdk::GrabStatus Canvas::pointer_grab(const Glib::RefPtr<Item>& item, Gdk::EventMask mask, guint32 time)
{
  return (Gdk::GrabStatus)goo_canvas_pointer_grab(gobj(), Glib::unwrap(item), ((GdkEventMask)(mask)), 0, time);
}

void Canvas::render(const Cairo::RefPtr<Cairo::Context>& context, double scale)
{
  goo_canvas_render(gobj(), (context)->cobj(), 0, scale);
}

void Canvas::get_bounds(Bounds& bounds) const
{
  double x1 = 0;
  double y1 = 0;
  double x2 = 0;
  double y2 = 0;
  get_bounds(x1, y1, x2, y2);
  bounds = Bounds(x1, y1, x2, y2);
}

void Canvas::set_bounds(const Bounds& bounds)
{
  set_bounds(bounds.get_x1(), bounds.get_y1(), bounds.get_x2(), bounds.get_y2());
}

} //namespace Goocanvas

namespace
{


static void Canvas_signal_item_created_callback(GooCanvas* self, GooCanvasItem* p0,GooCanvasItemModel* p1,void* data)
{
  using namespace Goocanvas;
  typedef sigc::slot< void,const Glib::RefPtr<Item>&,const Glib::RefPtr<ItemModel>& > SlotType;

  // Do not try to call a signal on a disassociated wrapper.
  if(Glib::ObjectBase::_get_current_wrapper((GObject*) self))
  {
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    try
    {
    #endif //GLIBMM_EXCEPTIONS_ENABLED
      if(sigc::slot_base *const slot = Glib::SignalProxyNormal::data_to_slot(data))
        (*static_cast<SlotType*>(slot))(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
);
    #ifdef GLIBMM_EXCEPTIONS_ENABLED
    }
    catch(...)
    {
      Glib::exception_handlers_invoke();
    }
    #endif //GLIBMM_EXCEPTIONS_ENABLED
  }
}

static const Glib::SignalProxyInfo Canvas_signal_item_created_info =
{
  "item_created",
  (GCallback) &Canvas_signal_item_created_callback,
  (GCallback) &Canvas_signal_item_created_callback
};


} // anonymous namespace


namespace Glib
{

Goocanvas::Canvas* wrap(GooCanvas* object, bool take_copy)
{
  return dynamic_cast<Goocanvas::Canvas *> (Glib::wrap_auto ((GObject*)(object), take_copy));
}

} /* namespace Glib */

namespace Goocanvas
{


/* The *_Class implementation: */

const Glib::Class& Canvas_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &Canvas_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(goo_canvas_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void Canvas_Class::class_init_function(void* g_class, void* class_data)
{
  BaseClassType *const klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);

  klass->create_item = &create_item_vfunc_callback;

  klass->item_created = &item_created_callback;
}

GooCanvasItem* Canvas_Class::create_item_vfunc_callback(GooCanvas* self, GooCanvasItemModel* model)
{
  Glib::ObjectBase *const obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    CppObjectType *const obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        return Glib::unwrap(obj->create_item_vfunc(Glib::wrap(model, true)
));
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
  );

  // Call the original underlying C function:
  if(base && base->create_item)
  {
    GooCanvasItem* retval = (*base->create_item)(self, model);
    return retval;
  }


  typedef GooCanvasItem* RType;
  return RType();
}

void Canvas_Class::item_created_callback(GooCanvas* self, GooCanvasItem* p0, GooCanvasItemModel* p1)
{
  Glib::ObjectBase *const obj_base = static_cast<Glib::ObjectBase*>(
      Glib::ObjectBase::_get_current_wrapper((GObject*)self));

  // Non-gtkmmproc-generated custom classes implicitly call the default
  // Glib::ObjectBase constructor, which sets is_derived_. But gtkmmproc-
  // generated classes can use this optimisation, which avoids the unnecessary
  // parameter conversions if there is no possibility of the virtual function
  // being overridden:
  if(obj_base && obj_base->is_derived_())
  {
    CppObjectType *const obj = dynamic_cast<CppObjectType* const>(obj_base);
    if(obj) // This can be NULL during destruction.
    {
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      try // Trap C++ exceptions which would normally be lost because this is a C callback.
      {
      #endif //GLIBMM_EXCEPTIONS_ENABLED
        // Call the virtual member method, which derived classes might override.
        obj->on_item_created(Glib::wrap(p0, true)
, Glib::wrap(p1, true)
);
        return;
      #ifdef GLIBMM_EXCEPTIONS_ENABLED
      }
      catch(...)
      {
        Glib::exception_handlers_invoke();
      }
      #endif //GLIBMM_EXCEPTIONS_ENABLED
    }
  }

  BaseClassType *const base = static_cast<BaseClassType*>(
        g_type_class_peek_parent(G_OBJECT_GET_CLASS(self)) // Get the parent class of the object class (The original underlying C class).
    );

  // Call the original underlying C function:
  if(base && base->item_created)
    (*base->item_created)(self, p0, p1);
}


Glib::ObjectBase* Canvas_Class::wrap_new(GObject* o)
{
  return Gtk::manage(new Canvas((GooCanvas*)(o)));

}


/* The implementation: */

Canvas::Canvas(const Glib::ConstructParams& construct_params)
:
  Gtk::Container(construct_params)
{
  }

Canvas::Canvas(GooCanvas* castitem)
:
  Gtk::Container((GtkContainer*)(castitem))
{
  }

Canvas::~Canvas()
{
  destroy_();
}

Canvas::CppClassType Canvas::canvas_class_; // initialize static member

GType Canvas::get_type()
{
  return canvas_class_.init().get_type();
}


GType Canvas::get_base_type()
{
  return goo_canvas_get_type();
}


Canvas::Canvas()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(0),
  Gtk::Container(Glib::ConstructParams(canvas_class_.init()))
{
  

}

Glib::RefPtr<Item> Canvas::get_root_item()
{
  Glib::RefPtr<Item> retvalue = Glib::wrap(goo_canvas_get_root_item(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Item> Canvas::get_root_item() const
{
  return const_cast<Canvas*>(this)->get_root_item();
}

void Canvas::set_root_item(const Glib::RefPtr<Item>& item)
{
  goo_canvas_set_root_item(gobj(), Glib::unwrap(item));
}

Glib::RefPtr<ItemModel> Canvas::get_root_item_model()
{
  Glib::RefPtr<ItemModel> retvalue = Glib::wrap(goo_canvas_get_root_item_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const ItemModel> Canvas::get_root_item_model() const
{
  return const_cast<Canvas*>(this)->get_root_item_model();
}

void Canvas::set_root_item_model(const Glib::RefPtr<ItemModel>& model)
{
  goo_canvas_set_root_item_model(gobj(), Glib::unwrap(model));
}

Glib::RefPtr<Item> Canvas::get_static_root_item()
{
  return Glib::wrap(goo_canvas_get_static_root_item(gobj()));
}

Glib::RefPtr<const Item> Canvas::get_static_root_item() const
{
  return const_cast<Canvas*>(this)->get_static_root_item();
}

void Canvas::set_static_root_item(const Glib::RefPtr<Item>& item)
{
  goo_canvas_set_static_root_item(gobj(), Glib::unwrap(item));
}

Glib::RefPtr<ItemModel> Canvas::get_static_root_item_model()
{
  Glib::RefPtr<ItemModel> retvalue = Glib::wrap(goo_canvas_get_static_root_item_model(gobj()));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const ItemModel> Canvas::get_static_root_item_model() const
{
  return const_cast<Canvas*>(this)->get_static_root_item_model();
}

void Canvas::set_static_root_item_model(const Glib::RefPtr<ItemModel>& model)
{
  goo_canvas_set_static_root_item_model(gobj(), Glib::unwrap(model));
}

Glib::RefPtr<Item> Canvas::get_item(const Glib::RefPtr<ItemModel>& model)
{
  Glib::RefPtr<Item> retvalue = Glib::wrap(goo_canvas_get_item(gobj(), Glib::unwrap(model)));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Item> Canvas::get_item(const Glib::RefPtr<ItemModel>& model) const
{
  return const_cast<Canvas*>(this)->get_item(model);
}

Glib::RefPtr<Item> Canvas::get_item_at(double x, double y, bool is_pointer_event)
{
  Glib::RefPtr<Item> retvalue = Glib::wrap(goo_canvas_get_item_at(gobj(), x, y, static_cast<int>(is_pointer_event)));
  if(retvalue)
    retvalue->reference(); //The function does not do a ref for us.
  return retvalue;
}

Glib::RefPtr<const Item> Canvas::get_item_at(double x, double y, bool is_pointer_event) const
{
  return const_cast<Canvas*>(this)->get_item_at(x, y, is_pointer_event);
}

std::vector< Glib::RefPtr<Item> > Canvas::get_items_at(double x, double y, bool is_pointer_event)
{
  return Glib::ListHandler<Glib::RefPtr<Item> >::list_to_vector(goo_canvas_get_items_at(gobj(), x, y, static_cast<int>(is_pointer_event)), Glib::OWNERSHIP_SHALLOW);
}

std::vector< Glib::RefPtr<const Item> > Canvas::get_items_at(double x, double y, bool is_pointer_event) const
{
  return Glib::ListHandler<Glib::RefPtr<const Item> >::list_to_vector(goo_canvas_get_items_at(const_cast<GooCanvas*>(gobj()), x, y, static_cast<int>(is_pointer_event)), Glib::OWNERSHIP_SHALLOW);
}

std::vector< Glib::RefPtr<Item> > Canvas::get_items_in_area(const Bounds& area, bool inside_area, bool allow_overlaps, bool include_containers)
{
  return Glib::ListHandler<Glib::RefPtr<Item> >::list_to_vector(goo_canvas_get_items_in_area(gobj(), (area).gobj(), static_cast<int>(inside_area), static_cast<int>(allow_overlaps), static_cast<int>(include_containers)), Glib::OWNERSHIP_SHALLOW);
}

std::vector< Glib::RefPtr<const Item> > Canvas::get_items_in_area(const Bounds& area, bool inside_area, bool allow_overlaps, bool include_containers) const
{
  return Glib::ListHandler<Glib::RefPtr<const Item> >::list_to_vector(goo_canvas_get_items_in_area(const_cast<GooCanvas*>(gobj()), (area).gobj(), static_cast<int>(inside_area), static_cast<int>(allow_overlaps), static_cast<int>(include_containers)), Glib::OWNERSHIP_SHALLOW);
}

double Canvas::get_scale() const
{
  return goo_canvas_get_scale(const_cast<GooCanvas*>(gobj()));
}

void Canvas::set_scale(double scale)
{
  goo_canvas_set_scale(gobj(), scale);
}

void Canvas::get_bounds(double& left, double& top, double& right, double& bottom) const
{
  goo_canvas_get_bounds(const_cast<GooCanvas*>(gobj()), &(left), &(top), &(right), &(bottom));
}

void Canvas::set_bounds(double left, double top, double right, double bottom)
{
  goo_canvas_set_bounds(gobj(), left, top, right, bottom);
}

void Canvas::scroll_to(double left, double top)
{
  goo_canvas_scroll_to(gobj(), left, top);
}

void Canvas::grab_focus(const Glib::RefPtr<Item>& item)
{
  goo_canvas_grab_focus(gobj(), Glib::unwrap(item));
}

void Canvas::render(const Cairo::RefPtr<Cairo::Context>& context, const Bounds& bounds, double scale)
{
  goo_canvas_render(gobj(), (context)->cobj(), (bounds).gobj(), scale);
}

void Canvas::convert_to_pixels(double& x, double& y) const
{
  goo_canvas_convert_to_pixels(const_cast<GooCanvas*>(gobj()), &(x), &(y));
}

void Canvas::convert_from_pixels(double& x, double& y) const
{
  goo_canvas_convert_from_pixels(const_cast<GooCanvas*>(gobj()), &(x), &(y));
}

void Canvas::convert_to_item_space(const Glib::RefPtr<Item>& item, double& x, double& y) const
{
  goo_canvas_convert_to_item_space(const_cast<GooCanvas*>(gobj()), Glib::unwrap(item), &(x), &(y));
}

void Canvas::convert_from_item_space(const Glib::RefPtr<Item>& item, double& x, double& y) const
{
  goo_canvas_convert_from_item_space(const_cast<GooCanvas*>(gobj()), Glib::unwrap(item), &(x), &(y));
}

void Canvas::convert_bounds_to_item_space(const Glib::RefPtr<Item>& item, Bounds& bounds) const
{
  goo_canvas_convert_bounds_to_item_space(const_cast<GooCanvas*>(gobj()), Glib::unwrap(item), (bounds).gobj());
}

Gdk::GrabStatus Canvas::pointer_grab(const Glib::RefPtr<Item>& item, Gdk::EventMask mask, const Glib::RefPtr<Gdk::Cursor>& cursor, guint32 time)
{
  return ((Gdk::GrabStatus)(goo_canvas_pointer_grab(gobj(), Glib::unwrap(item), ((GdkEventMask)(mask)), Glib::unwrap(cursor), time)));
}

void Canvas::pointer_ungrab(const Glib::RefPtr<Item>& item, guint32 time)
{
  goo_canvas_pointer_ungrab(gobj(), Glib::unwrap(item), time);
}

GdkGrabStatus Canvas::keyboard_grab(const Glib::RefPtr<Item>& item, bool owner_events, guint32 time)
{
  return goo_canvas_keyboard_grab(gobj(), Glib::unwrap(item), static_cast<int>(owner_events), time);
}

void Canvas::keyboard_ungrab(const Glib::RefPtr<Item>& item, guint32 time)
{
  goo_canvas_keyboard_ungrab(gobj(), Glib::unwrap(item), time);
}

Cairo::RefPtr<Cairo::Context> Canvas::create_cairo_context()
{
  return Cairo::RefPtr<Cairo::Context>(new Cairo::Context(goo_canvas_create_cairo_context(gobj())));
}

Glib::RefPtr<Item> Canvas::create_item(const Glib::RefPtr<ItemModel>& model)
{
  return Glib::wrap(goo_canvas_create_item(gobj(), Glib::unwrap(model)));
}

void Canvas::unregister_item(const Glib::RefPtr<ItemModel>& model)
{
  goo_canvas_unregister_item(gobj(), Glib::unwrap(model));
}

void Canvas::update()
{
  goo_canvas_update(gobj());
}

void Canvas::request_update()
{
  goo_canvas_request_update(gobj());
}

void Canvas::request_redraw(const Bounds& bounds)
{
  goo_canvas_request_redraw(gobj(), (bounds).gobj());
}

void Canvas::request_item_redraw(const Bounds& bounds, bool is_static)
{
  goo_canvas_request_item_redraw(gobj(), (bounds).gobj(), static_cast<int>(is_static));
}

double Canvas::get_default_line_width() const
{
  return goo_canvas_get_default_line_width(const_cast<GooCanvas*>(gobj()));
}

void Canvas::register_widget_item(const Glib::RefPtr<Goocanvas::Widget>& widget)
{
  goo_canvas_register_widget_item(gobj(), Glib::unwrap(widget));
}

void Canvas::unregister_widget_item(const Glib::RefPtr<Goocanvas::Widget>& widget)
{
  goo_canvas_unregister_widget_item(gobj(), Glib::unwrap(widget));
}


Glib::SignalProxy2< void,const Glib::RefPtr<Item>&,const Glib::RefPtr<ItemModel>& > Canvas::signal_item_created()
{
  return Glib::SignalProxy2< void,const Glib::RefPtr<Item>&,const Glib::RefPtr<ItemModel>& >(this, &Canvas_signal_item_created_info);
}


#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< double > Canvas::property_scale() 
{
  return Glib::PropertyProxy< double >(this, "scale");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< double > Canvas::property_scale() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "scale");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< double > Canvas::property_scale_x() 
{
  return Glib::PropertyProxy< double >(this, "scale-x");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< double > Canvas::property_scale_x() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "scale-x");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< double > Canvas::property_scale_y() 
{
  return Glib::PropertyProxy< double >(this, "scale-y");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< double > Canvas::property_scale_y() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "scale-y");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< AnchorType > Canvas::property_anchor() 
{
  return Glib::PropertyProxy< AnchorType >(this, "anchor");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< AnchorType > Canvas::property_anchor() const
{
  return Glib::PropertyProxy_ReadOnly< AnchorType >(this, "anchor");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< double > Canvas::property_x1() 
{
  return Glib::PropertyProxy< double >(this, "x1");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< double > Canvas::property_x1() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "x1");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< double > Canvas::property_y1() 
{
  return Glib::PropertyProxy< double >(this, "y1");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< double > Canvas::property_y1() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "y1");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< double > Canvas::property_x2() 
{
  return Glib::PropertyProxy< double >(this, "x2");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< double > Canvas::property_x2() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "x2");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< double > Canvas::property_y2() 
{
  return Glib::PropertyProxy< double >(this, "y2");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< double > Canvas::property_y2() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "y2");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< bool > Canvas::property_automatic_bounds() 
{
  return Glib::PropertyProxy< bool >(this, "automatic-bounds");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< bool > Canvas::property_automatic_bounds() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "automatic-bounds");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< bool > Canvas::property_bounds_from_origin() 
{
  return Glib::PropertyProxy< bool >(this, "bounds-from-origin");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< bool > Canvas::property_bounds_from_origin() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "bounds-from-origin");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< double > Canvas::property_bounds_padding() 
{
  return Glib::PropertyProxy< double >(this, "bounds-padding");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< double > Canvas::property_bounds_padding() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "bounds-padding");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< Gtk::Unit > Canvas::property_units() 
{
  return Glib::PropertyProxy< Gtk::Unit >(this, "units");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< Gtk::Unit > Canvas::property_units() const
{
  return Glib::PropertyProxy_ReadOnly< Gtk::Unit >(this, "units");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< double > Canvas::property_resolution_x() 
{
  return Glib::PropertyProxy< double >(this, "resolution-x");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< double > Canvas::property_resolution_x() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "resolution-x");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< double > Canvas::property_resolution_y() 
{
  return Glib::PropertyProxy< double >(this, "resolution-y");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< double > Canvas::property_resolution_y() const
{
  return Glib::PropertyProxy_ReadOnly< double >(this, "resolution-y");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_WriteOnly< Glib::ustring > Canvas::property_background_color() 
{
  return Glib::PropertyProxy_WriteOnly< Glib::ustring >(this, "background-color");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_WriteOnly< guint > Canvas::property_background_color_rgb() 
{
  return Glib::PropertyProxy_WriteOnly< guint >(this, "background-color-rgb");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_WriteOnly< Gdk::RGBA > Canvas::property_background_color_gdk_rgba() 
{
  return Glib::PropertyProxy_WriteOnly< Gdk::RGBA >(this, "background-color-gdk-rgba");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< bool > Canvas::property_integer_layout() 
{
  return Glib::PropertyProxy< bool >(this, "integer-layout");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< bool > Canvas::property_integer_layout() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "integer-layout");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy< bool > Canvas::property_clear_background() 
{
  return Glib::PropertyProxy< bool >(this, "clear-background");
}
#endif //GLIBMM_PROPERTIES_ENABLED

#ifdef GLIBMM_PROPERTIES_ENABLED
Glib::PropertyProxy_ReadOnly< bool > Canvas::property_clear_background() const
{
  return Glib::PropertyProxy_ReadOnly< bool >(this, "clear-background");
}
#endif //GLIBMM_PROPERTIES_ENABLED


void Goocanvas::Canvas::on_item_created(const Glib::RefPtr<Item>& item, const Glib::RefPtr<ItemModel>& model)
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->item_created)
    (*base->item_created)(gobj(),Glib::unwrap(item),Glib::unwrap(model));
}

Glib::RefPtr<Item> Goocanvas::Canvas::create_item_vfunc(const Glib::RefPtr<ItemModel>& model) 
{
  BaseClassType *const base = static_cast<BaseClassType*>(
      g_type_class_peek_parent(G_OBJECT_GET_CLASS(gobject_)) // Get the parent class of the object class (The original underlying C class).
  );

  if(base && base->create_item)
  {
    Glib::RefPtr<Item> retval(Glib::wrap((*base->create_item)(gobj(),Glib::unwrap(model))));
    return retval;
  }

  typedef Glib::RefPtr<Item> RType;
  return RType();
}


} // namespace Goocanvas


