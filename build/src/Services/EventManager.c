/* EventManager.c generated by valac 0.34.9, the Vala compiler
 * generated from EventManager.vala, do not modify */

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
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>


#define CONFIGURATOR_SERVICES_TYPE_EVENT_TYPE (configurator_services_event_type_get_type ())

#define CONFIGURATOR_SERVICES_TYPE_EVENT_MANAGER (configurator_services_event_manager_get_type ())
#define CONFIGURATOR_SERVICES_EVENT_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_SERVICES_TYPE_EVENT_MANAGER, configuratorServicesEventManager))
#define CONFIGURATOR_SERVICES_EVENT_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_SERVICES_TYPE_EVENT_MANAGER, configuratorServicesEventManagerClass))
#define CONFIGURATOR_SERVICES_IS_EVENT_MANAGER(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_SERVICES_TYPE_EVENT_MANAGER))
#define CONFIGURATOR_SERVICES_IS_EVENT_MANAGER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_SERVICES_TYPE_EVENT_MANAGER))
#define CONFIGURATOR_SERVICES_EVENT_MANAGER_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_SERVICES_TYPE_EVENT_MANAGER, configuratorServicesEventManagerClass))

typedef struct _configuratorServicesEventManager configuratorServicesEventManager;
typedef struct _configuratorServicesEventManagerClass configuratorServicesEventManagerClass;
typedef struct _configuratorServicesEventManagerPrivate configuratorServicesEventManagerPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

typedef enum  {
	CONFIGURATOR_SERVICES_EVENT_TYPE_KEY_CHANGED
} configuratorServicesEventType;

struct _configuratorServicesEventManager {
	GObject parent_instance;
	configuratorServicesEventManagerPrivate * priv;
};

struct _configuratorServicesEventManagerClass {
	GObjectClass parent_class;
};


static gpointer configurator_services_event_manager_parent_class = NULL;
extern configuratorServicesEventManager* configurator_services_event_manager_instance;
configuratorServicesEventManager* configurator_services_event_manager_instance = NULL;

GType configurator_services_event_type_get_type (void) G_GNUC_CONST;
GType configurator_services_event_manager_get_type (void) G_GNUC_CONST;
enum  {
	CONFIGURATOR_SERVICES_EVENT_MANAGER_DUMMY_PROPERTY
};
configuratorServicesEventManager* configurator_services_event_manager_new (void);
configuratorServicesEventManager* configurator_services_event_manager_construct (GType object_type);
void configurator_services_event_manager_key_changed (configuratorServicesEventManager* self, GSettings* settings, const gchar* key);
configuratorServicesEventManager* configurator_services_event_manager_get_default (void);
static void g_cclosure_user_marshal_VOID__ENUM_OBJECT_STRING (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data);
static void configurator_services_event_manager_finalize (GObject* obj);


GType configurator_services_event_type_get_type (void) {
	static volatile gsize configurator_services_event_type_type_id__volatile = 0;
	if (g_once_init_enter (&configurator_services_event_type_type_id__volatile)) {
		static const GEnumValue values[] = {{CONFIGURATOR_SERVICES_EVENT_TYPE_KEY_CHANGED, "CONFIGURATOR_SERVICES_EVENT_TYPE_KEY_CHANGED", "key-changed"}, {0, NULL, NULL}};
		GType configurator_services_event_type_type_id;
		configurator_services_event_type_type_id = g_enum_register_static ("configuratorServicesEventType", values);
		g_once_init_leave (&configurator_services_event_type_type_id__volatile, configurator_services_event_type_type_id);
	}
	return configurator_services_event_type_type_id__volatile;
}


configuratorServicesEventManager* configurator_services_event_manager_construct (GType object_type) {
	configuratorServicesEventManager * self = NULL;
	self = (configuratorServicesEventManager*) g_object_new (object_type, NULL);
	return self;
}


configuratorServicesEventManager* configurator_services_event_manager_new (void) {
	return configurator_services_event_manager_construct (CONFIGURATOR_SERVICES_TYPE_EVENT_MANAGER);
}


void configurator_services_event_manager_key_changed (configuratorServicesEventManager* self, GSettings* settings, const gchar* key) {
	GSettings* _tmp0_ = NULL;
	gchar* _tmp1_ = NULL;
	gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	gboolean _tmp4_ = FALSE;
	g_return_if_fail (self != NULL);
	g_return_if_fail (settings != NULL);
	g_return_if_fail (key != NULL);
	_tmp0_ = settings;
	g_object_get (_tmp0_, "schema-id", &_tmp1_, NULL);
	_tmp2_ = _tmp1_;
	_tmp3_ = _tmp2_;
	_tmp4_ = g_strcmp0 (_tmp3_, "org.pantheon.configurator") != 0;
	_g_free0 (_tmp3_);
	if (_tmp4_) {
		GSettings* _tmp5_ = NULL;
		const gchar* _tmp6_ = NULL;
		_tmp5_ = settings;
		_tmp6_ = key;
		g_signal_emit_by_name (self, "event", CONFIGURATOR_SERVICES_EVENT_TYPE_KEY_CHANGED, _tmp5_, _tmp6_);
	}
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


configuratorServicesEventManager* configurator_services_event_manager_get_default (void) {
	configuratorServicesEventManager* result = NULL;
	configuratorServicesEventManager* _tmp0_ = NULL;
	configuratorServicesEventManager* _tmp2_ = NULL;
	configuratorServicesEventManager* _tmp3_ = NULL;
	_tmp0_ = configurator_services_event_manager_instance;
	if (_tmp0_ == NULL) {
		configuratorServicesEventManager* _tmp1_ = NULL;
		_tmp1_ = configurator_services_event_manager_new ();
		_g_object_unref0 (configurator_services_event_manager_instance);
		configurator_services_event_manager_instance = _tmp1_;
	}
	_tmp2_ = configurator_services_event_manager_instance;
	_tmp3_ = _g_object_ref0 (_tmp2_);
	result = _tmp3_;
	return result;
}


static void g_cclosure_user_marshal_VOID__ENUM_OBJECT_STRING (GClosure * closure, GValue * return_value, guint n_param_values, const GValue * param_values, gpointer invocation_hint, gpointer marshal_data) {
	typedef void (*GMarshalFunc_VOID__ENUM_OBJECT_STRING) (gpointer data1, gint arg_1, gpointer arg_2, const char* arg_3, gpointer data2);
	register GMarshalFunc_VOID__ENUM_OBJECT_STRING callback;
	register GCClosure * cc;
	register gpointer data1;
	register gpointer data2;
	cc = (GCClosure *) closure;
	g_return_if_fail (n_param_values == 4);
	if (G_CCLOSURE_SWAP_DATA (closure)) {
		data1 = closure->data;
		data2 = param_values->data[0].v_pointer;
	} else {
		data1 = param_values->data[0].v_pointer;
		data2 = closure->data;
	}
	callback = (GMarshalFunc_VOID__ENUM_OBJECT_STRING) (marshal_data ? marshal_data : cc->callback);
	callback (data1, g_value_get_enum (param_values + 1), g_value_get_object (param_values + 2), g_value_get_string (param_values + 3), data2);
}


static void configurator_services_event_manager_class_init (configuratorServicesEventManagerClass * klass) {
	configurator_services_event_manager_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->finalize = configurator_services_event_manager_finalize;
	g_signal_new ("event", CONFIGURATOR_SERVICES_TYPE_EVENT_MANAGER, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_user_marshal_VOID__ENUM_OBJECT_STRING, G_TYPE_NONE, 3, CONFIGURATOR_SERVICES_TYPE_EVENT_TYPE, g_settings_get_type (), G_TYPE_STRING);
}


static void configurator_services_event_manager_instance_init (configuratorServicesEventManager * self) {
}


static void configurator_services_event_manager_finalize (GObject* obj) {
	configuratorServicesEventManager * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, CONFIGURATOR_SERVICES_TYPE_EVENT_MANAGER, configuratorServicesEventManager);
	G_OBJECT_CLASS (configurator_services_event_manager_parent_class)->finalize (obj);
}


GType configurator_services_event_manager_get_type (void) {
	static volatile gsize configurator_services_event_manager_type_id__volatile = 0;
	if (g_once_init_enter (&configurator_services_event_manager_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (configuratorServicesEventManagerClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) configurator_services_event_manager_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (configuratorServicesEventManager), 0, (GInstanceInitFunc) configurator_services_event_manager_instance_init, NULL };
		GType configurator_services_event_manager_type_id;
		configurator_services_event_manager_type_id = g_type_register_static (G_TYPE_OBJECT, "configuratorServicesEventManager", &g_define_type_info, 0);
		g_once_init_leave (&configurator_services_event_manager_type_id__volatile, configurator_services_event_manager_type_id);
	}
	return configurator_services_event_manager_type_id__volatile;
}



