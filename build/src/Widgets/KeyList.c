/* KeyList.c generated by valac 0.34.9, the Vala compiler
 * generated from KeyList.vala, do not modify */

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
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>


#define CONFIGURATOR_WIDGETS_TYPE_KEY_LIST (configurator_widgets_key_list_get_type ())
#define CONFIGURATOR_WIDGETS_KEY_LIST(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_WIDGETS_TYPE_KEY_LIST, configuratorWidgetsKeyList))
#define CONFIGURATOR_WIDGETS_KEY_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_WIDGETS_TYPE_KEY_LIST, configuratorWidgetsKeyListClass))
#define CONFIGURATOR_WIDGETS_IS_KEY_LIST(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_WIDGETS_TYPE_KEY_LIST))
#define CONFIGURATOR_WIDGETS_IS_KEY_LIST_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_WIDGETS_TYPE_KEY_LIST))
#define CONFIGURATOR_WIDGETS_KEY_LIST_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_WIDGETS_TYPE_KEY_LIST, configuratorWidgetsKeyListClass))

typedef struct _configuratorWidgetsKeyList configuratorWidgetsKeyList;
typedef struct _configuratorWidgetsKeyListClass configuratorWidgetsKeyListClass;
typedef struct _configuratorWidgetsKeyListPrivate configuratorWidgetsKeyListPrivate;

#define CONFIGURATOR_WIDGETS_TYPE_KEY (configurator_widgets_key_get_type ())
#define CONFIGURATOR_WIDGETS_KEY(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_WIDGETS_TYPE_KEY, configuratorWidgetsKey))
#define CONFIGURATOR_WIDGETS_KEY_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_WIDGETS_TYPE_KEY, configuratorWidgetsKeyClass))
#define CONFIGURATOR_WIDGETS_IS_KEY(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_WIDGETS_TYPE_KEY))
#define CONFIGURATOR_WIDGETS_IS_KEY_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_WIDGETS_TYPE_KEY))
#define CONFIGURATOR_WIDGETS_KEY_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_WIDGETS_TYPE_KEY, configuratorWidgetsKeyClass))

typedef struct _configuratorWidgetsKey configuratorWidgetsKey;
typedef struct _configuratorWidgetsKeyClass configuratorWidgetsKeyClass;
#define _g_settings_schema_key_unref0(var) ((var == NULL) ? NULL : (var = (g_settings_schema_key_unref (var), NULL)))
#define _g_settings_schema_unref0(var) ((var == NULL) ? NULL : (var = (g_settings_schema_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_list_free0(var) ((var == NULL) ? NULL : (var = (g_list_free (var), NULL)))

struct _configuratorWidgetsKeyList {
	GtkBox parent_instance;
	configuratorWidgetsKeyListPrivate * priv;
};

struct _configuratorWidgetsKeyListClass {
	GtkBoxClass parent_class;
};


static gpointer configurator_widgets_key_list_parent_class = NULL;

GType configurator_widgets_key_list_get_type (void) G_GNUC_CONST;
enum  {
	CONFIGURATOR_WIDGETS_KEY_LIST_DUMMY_PROPERTY
};
configuratorWidgetsKeyList* configurator_widgets_key_list_new (void);
configuratorWidgetsKeyList* configurator_widgets_key_list_construct (GType object_type);
void configurator_widgets_key_list_show_keys_for_schema (configuratorWidgetsKeyList* self, GSettings* schema);
void configurator_widgets_key_list_clear_list (configuratorWidgetsKeyList* self);
void configurator_widgets_key_list_add_item (configuratorWidgetsKeyList* self, GSettings* settings, const gchar* key, gboolean to_end, gboolean live, gboolean show_schema);
GType configurator_widgets_key_get_type (void) G_GNUC_CONST;
configuratorWidgetsKey* configurator_widgets_key_new (GSettings* settings, const gchar* name, GSettingsSchemaKey* key, gboolean live, gboolean show_schema);
configuratorWidgetsKey* configurator_widgets_key_construct (GType object_type, GSettings* settings, const gchar* name, GSettingsSchemaKey* key, gboolean live, gboolean show_schema);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);


configuratorWidgetsKeyList* configurator_widgets_key_list_construct (GType object_type) {
	configuratorWidgetsKeyList * self = NULL;
	self = (configuratorWidgetsKeyList*) g_object_new (object_type, NULL);
	gtk_orientable_set_orientation ((GtkOrientable*) self, GTK_ORIENTATION_VERTICAL);
	return self;
}


configuratorWidgetsKeyList* configurator_widgets_key_list_new (void) {
	return configurator_widgets_key_list_construct (CONFIGURATOR_WIDGETS_TYPE_KEY_LIST);
}


void configurator_widgets_key_list_show_keys_for_schema (configuratorWidgetsKeyList* self, GSettings* schema) {
	gchar** keys = NULL;
	GSettings* _tmp0_ = NULL;
	gchar** _tmp1_ = NULL;
	gchar** _tmp2_ = NULL;
	gint keys_length1 = 0;
	gint _keys_size_ = 0;
	g_return_if_fail (self != NULL);
	g_return_if_fail (schema != NULL);
	configurator_widgets_key_list_clear_list (self);
	_tmp0_ = schema;
	_tmp2_ = _tmp1_ = g_settings_list_keys (_tmp0_);
	keys = _tmp2_;
	keys_length1 = _vala_array_length (_tmp1_);
	_keys_size_ = keys_length1;
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp3_ = FALSE;
			_tmp3_ = TRUE;
			while (TRUE) {
				gint _tmp5_ = 0;
				gchar** _tmp6_ = NULL;
				gint _tmp6__length1 = 0;
				GSettings* _tmp7_ = NULL;
				gchar** _tmp8_ = NULL;
				gint _tmp8__length1 = 0;
				gint _tmp9_ = 0;
				const gchar* _tmp10_ = NULL;
				if (!_tmp3_) {
					gint _tmp4_ = 0;
					_tmp4_ = i;
					i = _tmp4_ + 1;
				}
				_tmp3_ = FALSE;
				_tmp5_ = i;
				_tmp6_ = keys;
				_tmp6__length1 = keys_length1;
				if (!(_tmp5_ < _tmp6__length1)) {
					break;
				}
				_tmp7_ = schema;
				_tmp8_ = keys;
				_tmp8__length1 = keys_length1;
				_tmp9_ = i;
				_tmp10_ = _tmp8_[_tmp9_];
				configurator_widgets_key_list_add_item (self, _tmp7_, _tmp10_, FALSE, TRUE, FALSE);
			}
		}
	}
	gtk_widget_show_all ((GtkWidget*) self);
	keys = (_vala_array_free (keys, keys_length1, (GDestroyNotify) g_free), NULL);
}


void configurator_widgets_key_list_add_item (configuratorWidgetsKeyList* self, GSettings* settings, const gchar* key, gboolean to_end, gboolean live, gboolean show_schema) {
	configuratorWidgetsKey* item = NULL;
	GSettings* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	GSettings* _tmp2_ = NULL;
	GSettingsSchema* _tmp3_ = NULL;
	GSettingsSchema* _tmp4_ = NULL;
	GSettingsSchema* _tmp5_ = NULL;
	const gchar* _tmp6_ = NULL;
	GSettingsSchemaKey* _tmp7_ = NULL;
	GSettingsSchemaKey* _tmp8_ = NULL;
	gboolean _tmp9_ = FALSE;
	gboolean _tmp10_ = FALSE;
	configuratorWidgetsKey* _tmp11_ = NULL;
	configuratorWidgetsKey* _tmp12_ = NULL;
	gboolean _tmp13_ = FALSE;
	g_return_if_fail (self != NULL);
	g_return_if_fail (settings != NULL);
	g_return_if_fail (key != NULL);
	_tmp0_ = settings;
	_tmp1_ = key;
	_tmp2_ = settings;
	g_object_get (_tmp2_, "settings-schema", &_tmp3_, NULL);
	_tmp4_ = _tmp3_;
	_tmp5_ = _tmp4_;
	_tmp6_ = key;
	_tmp7_ = g_settings_schema_get_key (_tmp5_, _tmp6_);
	_tmp8_ = _tmp7_;
	_tmp9_ = live;
	_tmp10_ = show_schema;
	_tmp11_ = configurator_widgets_key_new (_tmp0_, _tmp1_, _tmp8_, _tmp9_, _tmp10_);
	g_object_ref_sink (_tmp11_);
	_tmp12_ = _tmp11_;
	_g_settings_schema_key_unref0 (_tmp8_);
	_g_settings_schema_unref0 (_tmp5_);
	item = _tmp12_;
	_tmp13_ = to_end;
	if (_tmp13_) {
		configuratorWidgetsKey* _tmp14_ = NULL;
		_tmp14_ = item;
		gtk_box_pack_end ((GtkBox*) self, (GtkWidget*) _tmp14_, FALSE, FALSE, (guint) 0);
	} else {
		configuratorWidgetsKey* _tmp15_ = NULL;
		_tmp15_ = item;
		gtk_box_pack_start ((GtkBox*) self, (GtkWidget*) _tmp15_, FALSE, FALSE, (guint) 0);
	}
	_g_object_unref0 (item);
}


void configurator_widgets_key_list_clear_list (configuratorWidgetsKeyList* self) {
	GList* childs = NULL;
	GList* _tmp0_ = NULL;
	g_return_if_fail (self != NULL);
	_tmp0_ = gtk_container_get_children ((GtkContainer*) self);
	childs = _tmp0_;
	{
		gint i = 0;
		i = 0;
		{
			gboolean _tmp1_ = FALSE;
			_tmp1_ = TRUE;
			while (TRUE) {
				gint _tmp3_ = 0;
				GList* _tmp4_ = NULL;
				guint _tmp5_ = 0U;
				GList* _tmp6_ = NULL;
				gint _tmp7_ = 0;
				gconstpointer _tmp8_ = NULL;
				if (!_tmp1_) {
					gint _tmp2_ = 0;
					_tmp2_ = i;
					i = _tmp2_ + 1;
				}
				_tmp1_ = FALSE;
				_tmp3_ = i;
				_tmp4_ = childs;
				_tmp5_ = g_list_length (_tmp4_);
				if (!(((guint) _tmp3_) < _tmp5_)) {
					break;
				}
				_tmp6_ = childs;
				_tmp7_ = i;
				_tmp8_ = g_list_nth_data (_tmp6_, (guint) _tmp7_);
				gtk_container_remove ((GtkContainer*) self, (GtkWidget*) _tmp8_);
			}
		}
	}
	gtk_widget_show_all ((GtkWidget*) self);
	_g_list_free0 (childs);
}


static void configurator_widgets_key_list_class_init (configuratorWidgetsKeyListClass * klass) {
	configurator_widgets_key_list_parent_class = g_type_class_peek_parent (klass);
}


static void configurator_widgets_key_list_instance_init (configuratorWidgetsKeyList * self) {
}


GType configurator_widgets_key_list_get_type (void) {
	static volatile gsize configurator_widgets_key_list_type_id__volatile = 0;
	if (g_once_init_enter (&configurator_widgets_key_list_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (configuratorWidgetsKeyListClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) configurator_widgets_key_list_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (configuratorWidgetsKeyList), 0, (GInstanceInitFunc) configurator_widgets_key_list_instance_init, NULL };
		GType configurator_widgets_key_list_type_id;
		configurator_widgets_key_list_type_id = g_type_register_static (gtk_box_get_type (), "configuratorWidgetsKeyList", &g_define_type_info, 0);
		g_once_init_leave (&configurator_widgets_key_list_type_id__volatile, configurator_widgets_key_list_type_id);
	}
	return configurator_widgets_key_list_type_id__volatile;
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
}


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}


