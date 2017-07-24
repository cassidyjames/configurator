/* UIntegerInput.c generated by valac 0.34.9, the Vala compiler
 * generated from UIntegerInput.vala, do not modify */

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
#include <float.h>
#include <math.h>


#define CONFIGURATOR_WIDGETS_FIELDS_TYPE_UINTEGER_INPUT (configurator_widgets_fields_uinteger_input_get_type ())
#define CONFIGURATOR_WIDGETS_FIELDS_UINTEGER_INPUT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_WIDGETS_FIELDS_TYPE_UINTEGER_INPUT, configuratorWidgetsFieldsUIntegerInput))
#define CONFIGURATOR_WIDGETS_FIELDS_UINTEGER_INPUT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_WIDGETS_FIELDS_TYPE_UINTEGER_INPUT, configuratorWidgetsFieldsUIntegerInputClass))
#define CONFIGURATOR_WIDGETS_FIELDS_IS_UINTEGER_INPUT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_WIDGETS_FIELDS_TYPE_UINTEGER_INPUT))
#define CONFIGURATOR_WIDGETS_FIELDS_IS_UINTEGER_INPUT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_WIDGETS_FIELDS_TYPE_UINTEGER_INPUT))
#define CONFIGURATOR_WIDGETS_FIELDS_UINTEGER_INPUT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_WIDGETS_FIELDS_TYPE_UINTEGER_INPUT, configuratorWidgetsFieldsUIntegerInputClass))

typedef struct _configuratorWidgetsFieldsUIntegerInput configuratorWidgetsFieldsUIntegerInput;
typedef struct _configuratorWidgetsFieldsUIntegerInputClass configuratorWidgetsFieldsUIntegerInputClass;
typedef struct _configuratorWidgetsFieldsUIntegerInputPrivate configuratorWidgetsFieldsUIntegerInputPrivate;

struct _configuratorWidgetsFieldsUIntegerInput {
	GtkSpinButton parent_instance;
	configuratorWidgetsFieldsUIntegerInputPrivate * priv;
};

struct _configuratorWidgetsFieldsUIntegerInputClass {
	GtkSpinButtonClass parent_class;
};


static gpointer configurator_widgets_fields_uinteger_input_parent_class = NULL;

GType configurator_widgets_fields_uinteger_input_get_type (void) G_GNUC_CONST;
enum  {
	CONFIGURATOR_WIDGETS_FIELDS_UINTEGER_INPUT_DUMMY_PROPERTY
};
configuratorWidgetsFieldsUIntegerInput* configurator_widgets_fields_uinteger_input_new (void);
configuratorWidgetsFieldsUIntegerInput* configurator_widgets_fields_uinteger_input_construct (GType object_type);


configuratorWidgetsFieldsUIntegerInput* configurator_widgets_fields_uinteger_input_construct (GType object_type) {
	configuratorWidgetsFieldsUIntegerInput * self = NULL;
	self = (configuratorWidgetsFieldsUIntegerInput*) g_object_new (object_type, NULL);
	gtk_spin_button_set_range ((GtkSpinButton*) self, (gdouble) 0, (gdouble) G_MAXUINT);
	gtk_spin_button_set_increments ((GtkSpinButton*) self, (gdouble) 1, (gdouble) 1);
	return self;
}


configuratorWidgetsFieldsUIntegerInput* configurator_widgets_fields_uinteger_input_new (void) {
	return configurator_widgets_fields_uinteger_input_construct (CONFIGURATOR_WIDGETS_FIELDS_TYPE_UINTEGER_INPUT);
}


static void configurator_widgets_fields_uinteger_input_class_init (configuratorWidgetsFieldsUIntegerInputClass * klass) {
	configurator_widgets_fields_uinteger_input_parent_class = g_type_class_peek_parent (klass);
}


static void configurator_widgets_fields_uinteger_input_instance_init (configuratorWidgetsFieldsUIntegerInput * self) {
}


GType configurator_widgets_fields_uinteger_input_get_type (void) {
	static volatile gsize configurator_widgets_fields_uinteger_input_type_id__volatile = 0;
	if (g_once_init_enter (&configurator_widgets_fields_uinteger_input_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (configuratorWidgetsFieldsUIntegerInputClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) configurator_widgets_fields_uinteger_input_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (configuratorWidgetsFieldsUIntegerInput), 0, (GInstanceInitFunc) configurator_widgets_fields_uinteger_input_instance_init, NULL };
		GType configurator_widgets_fields_uinteger_input_type_id;
		configurator_widgets_fields_uinteger_input_type_id = g_type_register_static (gtk_spin_button_get_type (), "configuratorWidgetsFieldsUIntegerInput", &g_define_type_info, 0);
		g_once_init_leave (&configurator_widgets_fields_uinteger_input_type_id__volatile, configurator_widgets_fields_uinteger_input_type_id);
	}
	return configurator_widgets_fields_uinteger_input_type_id__volatile;
}



