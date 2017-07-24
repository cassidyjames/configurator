/* MainWindow.c generated by valac 0.34.9, the Vala compiler
 * generated from MainWindow.vala, do not modify */

/* Copyright 2015 Marcus Wichelmann
*
* This file is part of Configurator.
*
* Configurator is free software: you can redistribute it
* and/or modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation, either version 3 of the
* License, or (at your option) any later version.
*
* Configurator is distributed in the hope that it will be
* useful, but WITHOUT ANY WARRANTY; without Configurator the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
* Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with Configurator. If not, see http://www.gnu.org/licenses/.
*/

#include <glib.h>
#include <glib-object.h>
#include <gtk/gtk.h>
#include <granite.h>
#include <gdk/gdk.h>
#include <glib/gi18n-lib.h>


#define CONFIGURATOR_TYPE_MAIN_WINDOW (configurator_main_window_get_type ())
#define CONFIGURATOR_MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_TYPE_MAIN_WINDOW, configuratorMainWindow))
#define CONFIGURATOR_MAIN_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_TYPE_MAIN_WINDOW, configuratorMainWindowClass))
#define CONFIGURATOR_IS_MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_TYPE_MAIN_WINDOW))
#define CONFIGURATOR_IS_MAIN_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_TYPE_MAIN_WINDOW))
#define CONFIGURATOR_MAIN_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_TYPE_MAIN_WINDOW, configuratorMainWindowClass))

typedef struct _configuratorMainWindow configuratorMainWindow;
typedef struct _configuratorMainWindowClass configuratorMainWindowClass;
typedef struct _configuratorMainWindowPrivate configuratorMainWindowPrivate;

#define CONFIGURATOR_TYPE_CONFIGURATOR_APP (configurator_configurator_app_get_type ())
#define CONFIGURATOR_CONFIGURATOR_APP(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_TYPE_CONFIGURATOR_APP, configuratorconfiguratorApp))
#define CONFIGURATOR_CONFIGURATOR_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_TYPE_CONFIGURATOR_APP, configuratorconfiguratorAppClass))
#define CONFIGURATOR_IS_CONFIGURATOR_APP(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_TYPE_CONFIGURATOR_APP))
#define CONFIGURATOR_IS_CONFIGURATOR_APP_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_TYPE_CONFIGURATOR_APP))
#define CONFIGURATOR_CONFIGURATOR_APP_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_TYPE_CONFIGURATOR_APP, configuratorconfiguratorAppClass))

typedef struct _configuratorconfiguratorApp configuratorconfiguratorApp;
typedef struct _configuratorconfiguratorAppClass configuratorconfiguratorAppClass;

#define CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR (configurator_widgets_title_bar_get_type ())
#define CONFIGURATOR_WIDGETS_TITLE_BAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR, configuratorWidgetsTitleBar))
#define CONFIGURATOR_WIDGETS_TITLE_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR, configuratorWidgetsTitleBarClass))
#define CONFIGURATOR_WIDGETS_IS_TITLE_BAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR))
#define CONFIGURATOR_WIDGETS_IS_TITLE_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR))
#define CONFIGURATOR_WIDGETS_TITLE_BAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR, configuratorWidgetsTitleBarClass))

typedef struct _configuratorWidgetsTitleBar configuratorWidgetsTitleBar;
typedef struct _configuratorWidgetsTitleBarClass configuratorWidgetsTitleBarClass;

#define CONFIGURATOR_WIDGETS_TYPE_BROWSER_VIEW (configurator_widgets_browser_view_get_type ())
#define CONFIGURATOR_WIDGETS_BROWSER_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_WIDGETS_TYPE_BROWSER_VIEW, configuratorWidgetsBrowserView))
#define CONFIGURATOR_WIDGETS_BROWSER_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_WIDGETS_TYPE_BROWSER_VIEW, configuratorWidgetsBrowserViewClass))
#define CONFIGURATOR_WIDGETS_IS_BROWSER_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_WIDGETS_TYPE_BROWSER_VIEW))
#define CONFIGURATOR_WIDGETS_IS_BROWSER_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_WIDGETS_TYPE_BROWSER_VIEW))
#define CONFIGURATOR_WIDGETS_BROWSER_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_WIDGETS_TYPE_BROWSER_VIEW, configuratorWidgetsBrowserViewClass))

typedef struct _configuratorWidgetsBrowserView configuratorWidgetsBrowserView;
typedef struct _configuratorWidgetsBrowserViewClass configuratorWidgetsBrowserViewClass;

#define CONFIGURATOR_WIDGETS_TYPE_EVENTS_VIEW (configurator_widgets_events_view_get_type ())
#define CONFIGURATOR_WIDGETS_EVENTS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_WIDGETS_TYPE_EVENTS_VIEW, configuratorWidgetsEventsView))
#define CONFIGURATOR_WIDGETS_EVENTS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_WIDGETS_TYPE_EVENTS_VIEW, configuratorWidgetsEventsViewClass))
#define CONFIGURATOR_WIDGETS_IS_EVENTS_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_WIDGETS_TYPE_EVENTS_VIEW))
#define CONFIGURATOR_WIDGETS_IS_EVENTS_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_WIDGETS_TYPE_EVENTS_VIEW))
#define CONFIGURATOR_WIDGETS_EVENTS_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_WIDGETS_TYPE_EVENTS_VIEW, configuratorWidgetsEventsViewClass))

typedef struct _configuratorWidgetsEventsView configuratorWidgetsEventsView;
typedef struct _configuratorWidgetsEventsViewClass configuratorWidgetsEventsViewClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define CONFIGURATOR_SERVICES_TYPE_SETTINGS (configurator_services_settings_get_type ())
#define CONFIGURATOR_SERVICES_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_SERVICES_TYPE_SETTINGS, configuratorServicesSettings))
#define CONFIGURATOR_SERVICES_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_SERVICES_TYPE_SETTINGS, configuratorServicesSettingsClass))
#define CONFIGURATOR_SERVICES_IS_SETTINGS(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_SERVICES_TYPE_SETTINGS))
#define CONFIGURATOR_SERVICES_IS_SETTINGS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_SERVICES_TYPE_SETTINGS))
#define CONFIGURATOR_SERVICES_SETTINGS_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_SERVICES_TYPE_SETTINGS, configuratorServicesSettingsClass))

typedef struct _configuratorServicesSettings configuratorServicesSettings;
typedef struct _configuratorServicesSettingsClass configuratorServicesSettingsClass;

struct _configuratorMainWindow {
	GtkWindow parent_instance;
	configuratorMainWindowPrivate * priv;
	configuratorconfiguratorApp* app;
};

struct _configuratorMainWindowClass {
	GtkWindowClass parent_class;
};

struct _configuratorMainWindowPrivate {
	GtkBox* box;
	configuratorWidgetsTitleBar* title_bar;
	GtkStack* stack;
	configuratorWidgetsBrowserView* browser_view;
	configuratorWidgetsEventsView* events_view;
};


static gpointer configurator_main_window_parent_class = NULL;

GType configurator_main_window_get_type (void) G_GNUC_CONST;
GType configurator_configurator_app_get_type (void) G_GNUC_CONST;
GType configurator_widgets_title_bar_get_type (void) G_GNUC_CONST;
GType configurator_widgets_browser_view_get_type (void) G_GNUC_CONST;
GType configurator_widgets_events_view_get_type (void) G_GNUC_CONST;
#define CONFIGURATOR_MAIN_WINDOW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), CONFIGURATOR_TYPE_MAIN_WINDOW, configuratorMainWindowPrivate))
enum  {
	CONFIGURATOR_MAIN_WINDOW_DUMMY_PROPERTY
};
configuratorMainWindow* configurator_main_window_new (configuratorconfiguratorApp* app);
configuratorMainWindow* configurator_main_window_construct (GType object_type, configuratorconfiguratorApp* app);
static void configurator_main_window_setup_ui (configuratorMainWindow* self);
GType configurator_services_settings_get_type (void) G_GNUC_CONST;
configuratorServicesSettings* configurator_services_settings_get_default (void);
gboolean configurator_services_settings_get_maximized (configuratorServicesSettings* self);
static gboolean __lambda19_ (configuratorMainWindow* self, GdkEventWindowState* e);
void configurator_services_settings_set_maximized (configuratorServicesSettings* self, gboolean value);
static gboolean ___lambda19__gtk_widget_window_state_event (GtkWidget* _sender, GdkEventWindowState* event, gpointer self);
configuratorWidgetsTitleBar* configurator_widgets_title_bar_new (configuratorMainWindow* parent);
configuratorWidgetsTitleBar* configurator_widgets_title_bar_construct (GType object_type, configuratorMainWindow* parent);
configuratorWidgetsBrowserView* configurator_widgets_browser_view_new (void);
configuratorWidgetsBrowserView* configurator_widgets_browser_view_construct (GType object_type);
configuratorWidgetsEventsView* configurator_widgets_events_view_new (void);
configuratorWidgetsEventsView* configurator_widgets_events_view_construct (GType object_type);
void configurator_widgets_title_bar_show_stack (configuratorWidgetsTitleBar* self, GtkStack* stack);
static void configurator_main_window_finalize (GObject* obj);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static gboolean __lambda19_ (configuratorMainWindow* self, GdkEventWindowState* e) {
	gboolean result = FALSE;
	configuratorServicesSettings* _tmp0_ = NULL;
	configuratorServicesSettings* _tmp1_ = NULL;
	GdkWindow* _tmp2_ = NULL;
	GdkWindowState _tmp3_ = 0;
	g_return_val_if_fail (e != NULL, FALSE);
	_tmp0_ = configurator_services_settings_get_default ();
	_tmp1_ = _tmp0_;
	_tmp2_ = gtk_widget_get_window ((GtkWidget*) self);
	_tmp3_ = gdk_window_get_state (_tmp2_);
	configurator_services_settings_set_maximized (_tmp1_, (_tmp3_ & GDK_WINDOW_STATE_MAXIMIZED) != 0);
	_g_object_unref0 (_tmp1_);
	result = FALSE;
	return result;
}


static gboolean ___lambda19__gtk_widget_window_state_event (GtkWidget* _sender, GdkEventWindowState* event, gpointer self) {
	gboolean result;
	result = __lambda19_ ((configuratorMainWindow*) self, event);
	return result;
}


configuratorMainWindow* configurator_main_window_construct (GType object_type, configuratorconfiguratorApp* app) {
	configuratorMainWindow * self = NULL;
	configuratorconfiguratorApp* _tmp0_ = NULL;
	configuratorconfiguratorApp* _tmp1_ = NULL;
	configuratorconfiguratorApp* _tmp2_ = NULL;
	configuratorServicesSettings* _tmp3_ = NULL;
	configuratorServicesSettings* _tmp4_ = NULL;
	gboolean _tmp5_ = FALSE;
	gboolean _tmp6_ = FALSE;
	gboolean _tmp7_ = FALSE;
	g_return_val_if_fail (app != NULL, NULL);
	self = (configuratorMainWindow*) g_object_new (object_type, NULL);
	_tmp0_ = app;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (self->app);
	self->app = _tmp1_;
	_tmp2_ = app;
	gtk_window_set_application ((GtkWindow*) self, (GtkApplication*) _tmp2_);
	gtk_widget_set_size_request ((GtkWidget*) self, 1000, 650);
	gtk_window_set_has_resize_grip ((GtkWindow*) self, FALSE);
	g_object_set ((GtkWindow*) self, "window-position", GTK_WIN_POS_CENTER, NULL);
	configurator_main_window_setup_ui (self);
	_tmp3_ = configurator_services_settings_get_default ();
	_tmp4_ = _tmp3_;
	_tmp5_ = configurator_services_settings_get_maximized (_tmp4_);
	_tmp6_ = _tmp5_;
	_tmp7_ = _tmp6_;
	_g_object_unref0 (_tmp4_);
	if (_tmp7_) {
		gtk_window_maximize ((GtkWindow*) self);
	} else {
		gtk_window_unmaximize ((GtkWindow*) self);
	}
	g_signal_connect_object ((GtkWidget*) self, "window-state-event", (GCallback) ___lambda19__gtk_widget_window_state_event, self, 0);
	gtk_widget_show_all ((GtkWidget*) self);
	return self;
}


configuratorMainWindow* configurator_main_window_new (configuratorconfiguratorApp* app) {
	return configurator_main_window_construct (CONFIGURATOR_TYPE_MAIN_WINDOW, app);
}


static void configurator_main_window_setup_ui (configuratorMainWindow* self) {
	GtkBox* _tmp0_ = NULL;
	configuratorWidgetsTitleBar* _tmp1_ = NULL;
	configuratorWidgetsTitleBar* _tmp2_ = NULL;
	GtkBox* _tmp3_ = NULL;
	configuratorWidgetsTitleBar* _tmp4_ = NULL;
	GtkStack* _tmp5_ = NULL;
	configuratorWidgetsBrowserView* _tmp6_ = NULL;
	GtkStack* _tmp7_ = NULL;
	configuratorWidgetsBrowserView* _tmp8_ = NULL;
	const gchar* _tmp9_ = NULL;
	configuratorWidgetsEventsView* _tmp10_ = NULL;
	GtkStack* _tmp11_ = NULL;
	configuratorWidgetsEventsView* _tmp12_ = NULL;
	const gchar* _tmp13_ = NULL;
	GtkBox* _tmp14_ = NULL;
	GtkStack* _tmp15_ = NULL;
	configuratorWidgetsTitleBar* _tmp16_ = NULL;
	GtkStack* _tmp17_ = NULL;
	GtkBox* _tmp18_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = (GtkBox*) gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
	g_object_ref_sink (_tmp0_);
	_g_object_unref0 (self->priv->box);
	self->priv->box = _tmp0_;
	_tmp1_ = configurator_widgets_title_bar_new (self);
	g_object_ref_sink (_tmp1_);
	_g_object_unref0 (self->priv->title_bar);
	self->priv->title_bar = _tmp1_;
	_tmp2_ = self->priv->title_bar;
	gtk_window_set_titlebar ((GtkWindow*) self, (GtkWidget*) _tmp2_);
	_tmp3_ = self->priv->box;
	_tmp4_ = self->priv->title_bar;
	gtk_box_pack_start (_tmp3_, (GtkWidget*) _tmp4_, FALSE, TRUE, (guint) 0);
	_tmp5_ = (GtkStack*) gtk_stack_new ();
	g_object_ref_sink (_tmp5_);
	_g_object_unref0 (self->priv->stack);
	self->priv->stack = _tmp5_;
	_tmp6_ = configurator_widgets_browser_view_new ();
	g_object_ref_sink (_tmp6_);
	_g_object_unref0 (self->priv->browser_view);
	self->priv->browser_view = _tmp6_;
	_tmp7_ = self->priv->stack;
	_tmp8_ = self->priv->browser_view;
	_tmp9_ = _ ("Schemas");
	gtk_stack_add_titled (_tmp7_, (GtkWidget*) _tmp8_, "browser", _tmp9_);
	_tmp10_ = configurator_widgets_events_view_new ();
	g_object_ref_sink (_tmp10_);
	_g_object_unref0 (self->priv->events_view);
	self->priv->events_view = _tmp10_;
	_tmp11_ = self->priv->stack;
	_tmp12_ = self->priv->events_view;
	_tmp13_ = _ ("Events");
	gtk_stack_add_titled (_tmp11_, (GtkWidget*) _tmp12_, "events", _tmp13_);
	_tmp14_ = self->priv->box;
	_tmp15_ = self->priv->stack;
	gtk_box_pack_start (_tmp14_, (GtkWidget*) _tmp15_, TRUE, TRUE, (guint) 0);
	_tmp16_ = self->priv->title_bar;
	_tmp17_ = self->priv->stack;
	configurator_widgets_title_bar_show_stack (_tmp16_, _tmp17_);
	_tmp18_ = self->priv->box;
	gtk_container_add ((GtkContainer*) self, (GtkWidget*) _tmp18_);
}


static void configurator_main_window_class_init (configuratorMainWindowClass * klass) {
	configurator_main_window_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (configuratorMainWindowPrivate));
	G_OBJECT_CLASS (klass)->finalize = configurator_main_window_finalize;
}


static void configurator_main_window_instance_init (configuratorMainWindow * self) {
	self->priv = CONFIGURATOR_MAIN_WINDOW_GET_PRIVATE (self);
}


static void configurator_main_window_finalize (GObject* obj) {
	configuratorMainWindow * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, CONFIGURATOR_TYPE_MAIN_WINDOW, configuratorMainWindow);
	_g_object_unref0 (self->app);
	_g_object_unref0 (self->priv->box);
	_g_object_unref0 (self->priv->title_bar);
	_g_object_unref0 (self->priv->stack);
	_g_object_unref0 (self->priv->browser_view);
	_g_object_unref0 (self->priv->events_view);
	G_OBJECT_CLASS (configurator_main_window_parent_class)->finalize (obj);
}


GType configurator_main_window_get_type (void) {
	static volatile gsize configurator_main_window_type_id__volatile = 0;
	if (g_once_init_enter (&configurator_main_window_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (configuratorMainWindowClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) configurator_main_window_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (configuratorMainWindow), 0, (GInstanceInitFunc) configurator_main_window_instance_init, NULL };
		GType configurator_main_window_type_id;
		configurator_main_window_type_id = g_type_register_static (gtk_window_get_type (), "configuratorMainWindow", &g_define_type_info, 0);
		g_once_init_leave (&configurator_main_window_type_id__volatile, configurator_main_window_type_id);
	}
	return configurator_main_window_type_id__volatile;
}


