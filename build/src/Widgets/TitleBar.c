/* TitleBar.c generated by valac 0.34.9, the Vala compiler
 * generated from TitleBar.vala, do not modify */

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
#include <glib/gi18n-lib.h>


#define CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR (configurator_widgets_title_bar_get_type ())
#define CONFIGURATOR_WIDGETS_TITLE_BAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR, configuratorWidgetsTitleBar))
#define CONFIGURATOR_WIDGETS_TITLE_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR, configuratorWidgetsTitleBarClass))
#define CONFIGURATOR_WIDGETS_IS_TITLE_BAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR))
#define CONFIGURATOR_WIDGETS_IS_TITLE_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR))
#define CONFIGURATOR_WIDGETS_TITLE_BAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR, configuratorWidgetsTitleBarClass))

typedef struct _configuratorWidgetsTitleBar configuratorWidgetsTitleBar;
typedef struct _configuratorWidgetsTitleBarClass configuratorWidgetsTitleBarClass;
typedef struct _configuratorWidgetsTitleBarPrivate configuratorWidgetsTitleBarPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define CONFIGURATOR_TYPE_MAIN_WINDOW (configurator_main_window_get_type ())
#define CONFIGURATOR_MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_TYPE_MAIN_WINDOW, configuratorMainWindow))
#define CONFIGURATOR_MAIN_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_TYPE_MAIN_WINDOW, configuratorMainWindowClass))
#define CONFIGURATOR_IS_MAIN_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_TYPE_MAIN_WINDOW))
#define CONFIGURATOR_IS_MAIN_WINDOW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_TYPE_MAIN_WINDOW))
#define CONFIGURATOR_MAIN_WINDOW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_TYPE_MAIN_WINDOW, configuratorMainWindowClass))

typedef struct _configuratorMainWindow configuratorMainWindow;
typedef struct _configuratorMainWindowClass configuratorMainWindowClass;

struct _configuratorWidgetsTitleBar {
	GtkHeaderBar parent_instance;
	configuratorWidgetsTitleBarPrivate * priv;
};

struct _configuratorWidgetsTitleBarClass {
	GtkHeaderBarClass parent_class;
};

struct _configuratorWidgetsTitleBarPrivate {
	GtkStackSwitcher* stack_switcher;
};


static gpointer configurator_widgets_title_bar_parent_class = NULL;

GType configurator_widgets_title_bar_get_type (void) G_GNUC_CONST;
#define CONFIGURATOR_WIDGETS_TITLE_BAR_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR, configuratorWidgetsTitleBarPrivate))
enum  {
	CONFIGURATOR_WIDGETS_TITLE_BAR_DUMMY_PROPERTY
};
GType configurator_main_window_get_type (void) G_GNUC_CONST;
configuratorWidgetsTitleBar* configurator_widgets_title_bar_new (configuratorMainWindow* parent);
configuratorWidgetsTitleBar* configurator_widgets_title_bar_construct (GType object_type, configuratorMainWindow* parent);
void configurator_widgets_title_bar_show_stack (configuratorWidgetsTitleBar* self, GtkStack* stack);
static void configurator_widgets_title_bar_finalize (GObject* obj);


configuratorWidgetsTitleBar* configurator_widgets_title_bar_construct (GType object_type, configuratorMainWindow* parent) {
	configuratorWidgetsTitleBar * self = NULL;
	GtkStyleContext* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	GtkStackSwitcher* _tmp2_ = NULL;
	GtkStackSwitcher* _tmp3_ = NULL;
	g_return_val_if_fail (parent != NULL, NULL);
	self = (configuratorWidgetsTitleBar*) g_object_new (object_type, NULL);
	_tmp0_ = gtk_widget_get_style_context ((GtkWidget*) self);
	gtk_style_context_add_class (_tmp0_, "primary-toolbar");
	gtk_header_bar_set_show_close_button ((GtkHeaderBar*) self, TRUE);
	_tmp1_ = _ ("Configurator");
	gtk_header_bar_set_title ((GtkHeaderBar*) self, _tmp1_);
	_tmp2_ = (GtkStackSwitcher*) gtk_stack_switcher_new ();
	g_object_ref_sink (_tmp2_);
	_g_object_unref0 (self->priv->stack_switcher);
	self->priv->stack_switcher = _tmp2_;
	_tmp3_ = self->priv->stack_switcher;
	gtk_header_bar_set_custom_title ((GtkHeaderBar*) self, (GtkWidget*) _tmp3_);
	return self;
}


configuratorWidgetsTitleBar* configurator_widgets_title_bar_new (configuratorMainWindow* parent) {
	return configurator_widgets_title_bar_construct (CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR, parent);
}


void configurator_widgets_title_bar_show_stack (configuratorWidgetsTitleBar* self, GtkStack* stack) {
	GtkStackSwitcher* _tmp0_ = NULL;
	GtkStack* _tmp1_ = NULL;
	g_return_if_fail (self != NULL);
	g_return_if_fail (stack != NULL);
	_tmp0_ = self->priv->stack_switcher;
	_tmp1_ = stack;
	gtk_stack_switcher_set_stack (_tmp0_, _tmp1_);
}


static void configurator_widgets_title_bar_class_init (configuratorWidgetsTitleBarClass * klass) {
	configurator_widgets_title_bar_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (configuratorWidgetsTitleBarPrivate));
	G_OBJECT_CLASS (klass)->finalize = configurator_widgets_title_bar_finalize;
}


static void configurator_widgets_title_bar_instance_init (configuratorWidgetsTitleBar * self) {
	self->priv = CONFIGURATOR_WIDGETS_TITLE_BAR_GET_PRIVATE (self);
}


static void configurator_widgets_title_bar_finalize (GObject* obj) {
	configuratorWidgetsTitleBar * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, CONFIGURATOR_WIDGETS_TYPE_TITLE_BAR, configuratorWidgetsTitleBar);
	_g_object_unref0 (self->priv->stack_switcher);
	G_OBJECT_CLASS (configurator_widgets_title_bar_parent_class)->finalize (obj);
}


GType configurator_widgets_title_bar_get_type (void) {
	static volatile gsize configurator_widgets_title_bar_type_id__volatile = 0;
	if (g_once_init_enter (&configurator_widgets_title_bar_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (configuratorWidgetsTitleBarClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) configurator_widgets_title_bar_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (configuratorWidgetsTitleBar), 0, (GInstanceInitFunc) configurator_widgets_title_bar_instance_init, NULL };
		GType configurator_widgets_title_bar_type_id;
		configurator_widgets_title_bar_type_id = g_type_register_static (gtk_header_bar_get_type (), "configuratorWidgetsTitleBar", &g_define_type_info, 0);
		g_once_init_leave (&configurator_widgets_title_bar_type_id__volatile, configurator_widgets_title_bar_type_id);
	}
	return configurator_widgets_title_bar_type_id__volatile;
}



