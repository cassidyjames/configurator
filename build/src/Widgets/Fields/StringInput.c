/* StringInput.c generated by valac 0.34.9, the Vala compiler
 * generated from StringInput.vala, do not modify */

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
#include <gdk/gdk.h>
#include <string.h>


#define CONFIGURATOR_WIDGETS_FIELDS_TYPE_STRING_INPUT (configurator_widgets_fields_string_input_get_type ())
#define CONFIGURATOR_WIDGETS_FIELDS_STRING_INPUT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_WIDGETS_FIELDS_TYPE_STRING_INPUT, configuratorWidgetsFieldsStringInput))
#define CONFIGURATOR_WIDGETS_FIELDS_STRING_INPUT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_WIDGETS_FIELDS_TYPE_STRING_INPUT, configuratorWidgetsFieldsStringInputClass))
#define CONFIGURATOR_WIDGETS_FIELDS_IS_STRING_INPUT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_WIDGETS_FIELDS_TYPE_STRING_INPUT))
#define CONFIGURATOR_WIDGETS_FIELDS_IS_STRING_INPUT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_WIDGETS_FIELDS_TYPE_STRING_INPUT))
#define CONFIGURATOR_WIDGETS_FIELDS_STRING_INPUT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_WIDGETS_FIELDS_TYPE_STRING_INPUT, configuratorWidgetsFieldsStringInputClass))

typedef struct _configuratorWidgetsFieldsStringInput configuratorWidgetsFieldsStringInput;
typedef struct _configuratorWidgetsFieldsStringInputClass configuratorWidgetsFieldsStringInputClass;
typedef struct _configuratorWidgetsFieldsStringInputPrivate configuratorWidgetsFieldsStringInputPrivate;

struct _configuratorWidgetsFieldsStringInput {
	GtkEntry parent_instance;
	configuratorWidgetsFieldsStringInputPrivate * priv;
};

struct _configuratorWidgetsFieldsStringInputClass {
	GtkEntryClass parent_class;
};


static gpointer configurator_widgets_fields_string_input_parent_class = NULL;

GType configurator_widgets_fields_string_input_get_type (void) G_GNUC_CONST;
enum  {
	CONFIGURATOR_WIDGETS_FIELDS_STRING_INPUT_DUMMY_PROPERTY
};
configuratorWidgetsFieldsStringInput* configurator_widgets_fields_string_input_new (void);
configuratorWidgetsFieldsStringInput* configurator_widgets_fields_string_input_construct (GType object_type);
static void __lambda9_ (configuratorWidgetsFieldsStringInput* self);
static void ___lambda9__gtk_editable_changed (GtkEditable* _sender, gpointer self);


static void __lambda9_ (configuratorWidgetsFieldsStringInput* self) {
	GdkRGBA color = {0};
	const gchar* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	gboolean _tmp2_ = FALSE;
	memset (&color, 0, sizeof (GdkRGBA));
	_tmp0_ = gtk_entry_get_text ((GtkEntry*) self);
	_tmp1_ = _tmp0_;
	_tmp2_ = gdk_rgba_parse (&color, _tmp1_);
	if (_tmp2_) {
		GdkRGBA _tmp3_ = {0};
		_tmp3_ = color;
		gtk_widget_override_color ((GtkWidget*) self, GTK_STATE_FLAG_NORMAL, &_tmp3_);
	} else {
		gtk_widget_override_color ((GtkWidget*) self, GTK_STATE_FLAG_NORMAL, NULL);
	}
}


static void ___lambda9__gtk_editable_changed (GtkEditable* _sender, gpointer self) {
	__lambda9_ ((configuratorWidgetsFieldsStringInput*) self);
}


configuratorWidgetsFieldsStringInput* configurator_widgets_fields_string_input_construct (GType object_type) {
	configuratorWidgetsFieldsStringInput * self = NULL;
	self = (configuratorWidgetsFieldsStringInput*) g_object_new (object_type, NULL);
	g_signal_connect_object ((GtkEditable*) self, "changed", (GCallback) ___lambda9__gtk_editable_changed, self, 0);
	return self;
}


configuratorWidgetsFieldsStringInput* configurator_widgets_fields_string_input_new (void) {
	return configurator_widgets_fields_string_input_construct (CONFIGURATOR_WIDGETS_FIELDS_TYPE_STRING_INPUT);
}


static void configurator_widgets_fields_string_input_class_init (configuratorWidgetsFieldsStringInputClass * klass) {
	configurator_widgets_fields_string_input_parent_class = g_type_class_peek_parent (klass);
}


static void configurator_widgets_fields_string_input_instance_init (configuratorWidgetsFieldsStringInput * self) {
}


GType configurator_widgets_fields_string_input_get_type (void) {
	static volatile gsize configurator_widgets_fields_string_input_type_id__volatile = 0;
	if (g_once_init_enter (&configurator_widgets_fields_string_input_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (configuratorWidgetsFieldsStringInputClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) configurator_widgets_fields_string_input_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (configuratorWidgetsFieldsStringInput), 0, (GInstanceInitFunc) configurator_widgets_fields_string_input_instance_init, NULL };
		GType configurator_widgets_fields_string_input_type_id;
		configurator_widgets_fields_string_input_type_id = g_type_register_static (gtk_entry_get_type (), "configuratorWidgetsFieldsStringInput", &g_define_type_info, 0);
		g_once_init_leave (&configurator_widgets_fields_string_input_type_id__volatile, configurator_widgets_fields_string_input_type_id);
	}
	return configurator_widgets_fields_string_input_type_id__volatile;
}



