/* KeyInfo.c generated by valac 0.34.9, the Vala compiler
 * generated from KeyInfo.vala, do not modify */

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
#include <glib/gi18n-lib.h>


#define CONFIGURATOR_WIDGETS_TYPE_KEY_INFO (configurator_widgets_key_info_get_type ())
#define CONFIGURATOR_WIDGETS_KEY_INFO(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), CONFIGURATOR_WIDGETS_TYPE_KEY_INFO, configuratorWidgetsKeyInfo))
#define CONFIGURATOR_WIDGETS_KEY_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), CONFIGURATOR_WIDGETS_TYPE_KEY_INFO, configuratorWidgetsKeyInfoClass))
#define CONFIGURATOR_WIDGETS_IS_KEY_INFO(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), CONFIGURATOR_WIDGETS_TYPE_KEY_INFO))
#define CONFIGURATOR_WIDGETS_IS_KEY_INFO_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), CONFIGURATOR_WIDGETS_TYPE_KEY_INFO))
#define CONFIGURATOR_WIDGETS_KEY_INFO_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), CONFIGURATOR_WIDGETS_TYPE_KEY_INFO, configuratorWidgetsKeyInfoClass))

typedef struct _configuratorWidgetsKeyInfo configuratorWidgetsKeyInfo;
typedef struct _configuratorWidgetsKeyInfoClass configuratorWidgetsKeyInfoClass;
typedef struct _configuratorWidgetsKeyInfoPrivate configuratorWidgetsKeyInfoPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _Block2Data Block2Data;
#define _g_variant_unref0(var) ((var == NULL) ? NULL : (var = (g_variant_unref (var), NULL)))

struct _configuratorWidgetsKeyInfo {
	GtkGrid parent_instance;
	configuratorWidgetsKeyInfoPrivate * priv;
};

struct _configuratorWidgetsKeyInfoClass {
	GtkGridClass parent_class;
};

struct _configuratorWidgetsKeyInfoPrivate {
	GtkLabel* type_label;
	GtkLabel* type_field;
	GtkLabel* default_label;
	GtkLabel* default_field;
	GtkLabel* code_label;
	GtkLabel* code_field;
	GtkLabel* command_label;
	GtkLabel* command_field;
	GtkLabel* description_label;
	GtkLabel* description_field;
	GtkButton* reset_button;
};

struct _Block2Data {
	int _ref_count_;
	configuratorWidgetsKeyInfo* self;
	GSettings* settings;
	gchar* name;
};


static gpointer configurator_widgets_key_info_parent_class = NULL;

GType configurator_widgets_key_info_get_type (void) G_GNUC_CONST;
#define CONFIGURATOR_WIDGETS_KEY_INFO_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), CONFIGURATOR_WIDGETS_TYPE_KEY_INFO, configuratorWidgetsKeyInfoPrivate))
enum  {
	CONFIGURATOR_WIDGETS_KEY_INFO_DUMMY_PROPERTY
};
configuratorWidgetsKeyInfo* configurator_widgets_key_info_new (GSettings* settings, const gchar* name, GSettingsSchemaKey* key);
configuratorWidgetsKeyInfo* configurator_widgets_key_info_construct (GType object_type, GSettings* settings, const gchar* name, GSettingsSchemaKey* key);
static Block2Data* block2_data_ref (Block2Data* _data2_);
static void block2_data_unref (void * _userdata_);
gchar* configurator_utils_type_to_string (const GVariantType* variant_type);
gchar* configurator_utils_variant_to_string (GVariant* variant);
static void __lambda7_ (Block2Data* _data2_);
static void ___lambda7__gtk_button_clicked (GtkButton* _sender, gpointer self);
void configurator_widgets_key_info_set_reset_enabled (configuratorWidgetsKeyInfo* self, gboolean enabled);
static void configurator_widgets_key_info_finalize (GObject* obj);


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static Block2Data* block2_data_ref (Block2Data* _data2_) {
	g_atomic_int_inc (&_data2_->_ref_count_);
	return _data2_;
}


static void block2_data_unref (void * _userdata_) {
	Block2Data* _data2_;
	_data2_ = (Block2Data*) _userdata_;
	if (g_atomic_int_dec_and_test (&_data2_->_ref_count_)) {
		configuratorWidgetsKeyInfo* self;
		self = _data2_->self;
		_g_object_unref0 (_data2_->settings);
		_g_free0 (_data2_->name);
		_g_object_unref0 (self);
		g_slice_free (Block2Data, _data2_);
	}
}


static void __lambda7_ (Block2Data* _data2_) {
	configuratorWidgetsKeyInfo* self;
	GSettings* _tmp0_ = NULL;
	const gchar* _tmp1_ = NULL;
	self = _data2_->self;
	_tmp0_ = _data2_->settings;
	_tmp1_ = _data2_->name;
	g_settings_reset (_tmp0_, _tmp1_);
}


static void ___lambda7__gtk_button_clicked (GtkButton* _sender, gpointer self) {
	__lambda7_ (self);
}


configuratorWidgetsKeyInfo* configurator_widgets_key_info_construct (GType object_type, GSettings* settings, const gchar* name, GSettingsSchemaKey* key) {
	configuratorWidgetsKeyInfo * self = NULL;
	Block2Data* _data2_;
	GSettings* _tmp0_ = NULL;
	GSettings* _tmp1_ = NULL;
	const gchar* _tmp2_ = NULL;
	gchar* _tmp3_ = NULL;
	const gchar* _tmp4_ = NULL;
	GtkLabel* _tmp5_ = NULL;
	GtkLabel* _tmp6_ = NULL;
	GtkLabel* _tmp7_ = NULL;
	GtkLabel* _tmp8_ = NULL;
	GSettingsSchemaKey* _tmp9_ = NULL;
	const GVariantType* _tmp10_ = NULL;
	gchar* _tmp11_ = NULL;
	gchar* _tmp12_ = NULL;
	GtkLabel* _tmp13_ = NULL;
	GtkLabel* _tmp14_ = NULL;
	GtkLabel* _tmp15_ = NULL;
	GtkLabel* _tmp16_ = NULL;
	GtkLabel* _tmp17_ = NULL;
	GtkLabel* _tmp18_ = NULL;
	GtkLabel* _tmp19_ = NULL;
	const gchar* _tmp20_ = NULL;
	GtkLabel* _tmp21_ = NULL;
	GtkLabel* _tmp22_ = NULL;
	GtkLabel* _tmp23_ = NULL;
	GtkLabel* _tmp24_ = NULL;
	GSettingsSchemaKey* _tmp25_ = NULL;
	GVariant* _tmp26_ = NULL;
	GVariant* _tmp27_ = NULL;
	gchar* _tmp28_ = NULL;
	gchar* _tmp29_ = NULL;
	GtkLabel* _tmp30_ = NULL;
	GtkLabel* _tmp31_ = NULL;
	GtkLabel* _tmp32_ = NULL;
	GtkLabel* _tmp33_ = NULL;
	GtkLabel* _tmp34_ = NULL;
	GtkLabel* _tmp35_ = NULL;
	GtkLabel* _tmp36_ = NULL;
	const gchar* _tmp37_ = NULL;
	GtkLabel* _tmp38_ = NULL;
	GtkLabel* _tmp39_ = NULL;
	GtkLabel* _tmp40_ = NULL;
	GtkLabel* _tmp41_ = NULL;
	GSettings* _tmp42_ = NULL;
	gchar* _tmp43_ = NULL;
	gchar* _tmp44_ = NULL;
	gchar* _tmp45_ = NULL;
	const gchar* _tmp46_ = NULL;
	gchar* _tmp47_ = NULL;
	gchar* _tmp48_ = NULL;
	GtkLabel* _tmp49_ = NULL;
	GtkLabel* _tmp50_ = NULL;
	GtkLabel* _tmp51_ = NULL;
	GtkLabel* _tmp52_ = NULL;
	GtkLabel* _tmp53_ = NULL;
	GtkLabel* _tmp54_ = NULL;
	GtkLabel* _tmp55_ = NULL;
	const gchar* _tmp56_ = NULL;
	GtkLabel* _tmp57_ = NULL;
	GtkLabel* _tmp58_ = NULL;
	GtkLabel* _tmp59_ = NULL;
	GtkLabel* _tmp60_ = NULL;
	GSettings* _tmp61_ = NULL;
	gchar* _tmp62_ = NULL;
	gchar* _tmp63_ = NULL;
	gchar* _tmp64_ = NULL;
	const gchar* _tmp65_ = NULL;
	gchar* _tmp66_ = NULL;
	gchar* _tmp67_ = NULL;
	gchar* _tmp68_ = NULL;
	gchar* _tmp69_ = NULL;
	GtkLabel* _tmp70_ = NULL;
	GtkLabel* _tmp71_ = NULL;
	GtkLabel* _tmp72_ = NULL;
	GtkLabel* _tmp73_ = NULL;
	GtkLabel* _tmp74_ = NULL;
	GtkLabel* _tmp75_ = NULL;
	GtkLabel* _tmp76_ = NULL;
	const gchar* _tmp77_ = NULL;
	GtkLabel* _tmp78_ = NULL;
	GtkLabel* _tmp79_ = NULL;
	GtkLabel* _tmp80_ = NULL;
	GtkLabel* _tmp81_ = NULL;
	GSettingsSchemaKey* _tmp82_ = NULL;
	const gchar* _tmp83_ = NULL;
	GtkLabel* _tmp84_ = NULL;
	GtkLabel* _tmp85_ = NULL;
	GtkLabel* _tmp86_ = NULL;
	GtkLabel* _tmp87_ = NULL;
	GtkLabel* _tmp88_ = NULL;
	GtkLabel* _tmp89_ = NULL;
	GtkLabel* _tmp90_ = NULL;
	const gchar* _tmp91_ = NULL;
	GtkButton* _tmp92_ = NULL;
	GtkButton* _tmp93_ = NULL;
	GtkStyleContext* _tmp94_ = NULL;
	GtkButton* _tmp95_ = NULL;
	GtkButton* _tmp96_ = NULL;
	GtkButton* _tmp97_ = NULL;
	g_return_val_if_fail (settings != NULL, NULL);
	g_return_val_if_fail (name != NULL, NULL);
	g_return_val_if_fail (key != NULL, NULL);
	_data2_ = g_slice_new0 (Block2Data);
	_data2_->_ref_count_ = 1;
	_tmp0_ = settings;
	_tmp1_ = _g_object_ref0 (_tmp0_);
	_g_object_unref0 (_data2_->settings);
	_data2_->settings = _tmp1_;
	_tmp2_ = name;
	_tmp3_ = g_strdup (_tmp2_);
	_g_free0 (_data2_->name);
	_data2_->name = _tmp3_;
	self = (configuratorWidgetsKeyInfo*) g_object_new (object_type, NULL);
	_data2_->self = g_object_ref (self);
	gtk_grid_set_column_spacing ((GtkGrid*) self, 12);
	gtk_grid_set_row_spacing ((GtkGrid*) self, 12);
	gtk_widget_set_margin_top ((GtkWidget*) self, 18);
	_tmp4_ = _ ("<b>Property type</b>");
	_tmp5_ = (GtkLabel*) gtk_label_new (_tmp4_);
	g_object_ref_sink (_tmp5_);
	_g_object_unref0 (self->priv->type_label);
	self->priv->type_label = _tmp5_;
	_tmp6_ = self->priv->type_label;
	gtk_label_set_use_markup (_tmp6_, TRUE);
	_tmp7_ = self->priv->type_label;
	gtk_widget_set_halign ((GtkWidget*) _tmp7_, GTK_ALIGN_END);
	_tmp8_ = self->priv->type_label;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp8_, 0, 0, 1, 1);
	_tmp9_ = key;
	_tmp10_ = g_settings_schema_key_get_value_type (_tmp9_);
	_tmp11_ = configurator_utils_type_to_string (_tmp10_);
	_tmp12_ = _tmp11_;
	_tmp13_ = (GtkLabel*) gtk_label_new (_tmp12_);
	g_object_ref_sink (_tmp13_);
	_g_object_unref0 (self->priv->type_field);
	self->priv->type_field = _tmp13_;
	_g_free0 (_tmp12_);
	_tmp14_ = self->priv->type_field;
	gtk_label_set_use_markup (_tmp14_, TRUE);
	_tmp15_ = self->priv->type_field;
	gtk_label_set_selectable (_tmp15_, TRUE);
	_tmp16_ = self->priv->type_field;
	g_object_set (_tmp16_, "wrap", TRUE, NULL);
	_tmp17_ = self->priv->type_field;
	gtk_widget_set_halign ((GtkWidget*) _tmp17_, GTK_ALIGN_START);
	_tmp18_ = self->priv->type_field;
	gtk_widget_set_hexpand ((GtkWidget*) _tmp18_, TRUE);
	_tmp19_ = self->priv->type_field;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp19_, 1, 0, 1, 1);
	_tmp20_ = _ ("<b>Default value</b>");
	_tmp21_ = (GtkLabel*) gtk_label_new (_tmp20_);
	g_object_ref_sink (_tmp21_);
	_g_object_unref0 (self->priv->default_label);
	self->priv->default_label = _tmp21_;
	_tmp22_ = self->priv->default_label;
	gtk_label_set_use_markup (_tmp22_, TRUE);
	_tmp23_ = self->priv->default_label;
	gtk_widget_set_halign ((GtkWidget*) _tmp23_, GTK_ALIGN_END);
	_tmp24_ = self->priv->default_label;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp24_, 0, 1, 1, 1);
	_tmp25_ = key;
	_tmp26_ = g_settings_schema_key_get_default_value (_tmp25_);
	_tmp27_ = _tmp26_;
	_tmp28_ = configurator_utils_variant_to_string (_tmp27_);
	_tmp29_ = _tmp28_;
	_tmp30_ = (GtkLabel*) gtk_label_new (_tmp29_);
	g_object_ref_sink (_tmp30_);
	_g_object_unref0 (self->priv->default_field);
	self->priv->default_field = _tmp30_;
	_g_free0 (_tmp29_);
	_g_variant_unref0 (_tmp27_);
	_tmp31_ = self->priv->default_field;
	gtk_label_set_use_markup (_tmp31_, TRUE);
	_tmp32_ = self->priv->default_field;
	gtk_label_set_selectable (_tmp32_, TRUE);
	_tmp33_ = self->priv->default_field;
	g_object_set (_tmp33_, "wrap", TRUE, NULL);
	_tmp34_ = self->priv->default_field;
	gtk_widget_set_halign ((GtkWidget*) _tmp34_, GTK_ALIGN_START);
	_tmp35_ = self->priv->default_field;
	gtk_widget_set_hexpand ((GtkWidget*) _tmp35_, TRUE);
	_tmp36_ = self->priv->default_field;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp36_, 1, 1, 1, 1);
	_tmp37_ = _ ("<b>Vala code</b>");
	_tmp38_ = (GtkLabel*) gtk_label_new (_tmp37_);
	g_object_ref_sink (_tmp38_);
	_g_object_unref0 (self->priv->code_label);
	self->priv->code_label = _tmp38_;
	_tmp39_ = self->priv->code_label;
	gtk_label_set_use_markup (_tmp39_, TRUE);
	_tmp40_ = self->priv->code_label;
	gtk_widget_set_halign ((GtkWidget*) _tmp40_, GTK_ALIGN_END);
	_tmp41_ = self->priv->code_label;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp41_, 0, 2, 1, 1);
	_tmp42_ = _data2_->settings;
	g_object_get (_tmp42_, "schema-id", &_tmp43_, NULL);
	_tmp44_ = _tmp43_;
	_tmp45_ = _tmp44_;
	_tmp46_ = _data2_->name;
	_tmp47_ = g_strdup_printf ("<tt><span foreground=\"#000000\" stretch=\"condensed\"><span foregroun" \
"d=\"#FF420B\" weight=\"bold\">var</span> val = <span foreground=\"#FF4" \
"20B\" weight=\"bold\">new</span> Settings (<span foreground=\"#13A50B\"" \
">\"%s\"</span>).get_value (<span foreground=\"#13A50B\">\"%s\"</span>)" \
";</span></tt>", _tmp45_, _tmp46_);
	_tmp48_ = _tmp47_;
	_tmp49_ = (GtkLabel*) gtk_label_new (_tmp48_);
	g_object_ref_sink (_tmp49_);
	_g_object_unref0 (self->priv->code_field);
	self->priv->code_field = _tmp49_;
	_g_free0 (_tmp48_);
	_g_free0 (_tmp45_);
	_tmp50_ = self->priv->code_field;
	gtk_label_set_use_markup (_tmp50_, TRUE);
	_tmp51_ = self->priv->code_field;
	gtk_label_set_selectable (_tmp51_, TRUE);
	_tmp52_ = self->priv->code_field;
	g_object_set (_tmp52_, "wrap", TRUE, NULL);
	_tmp53_ = self->priv->code_field;
	gtk_widget_set_halign ((GtkWidget*) _tmp53_, GTK_ALIGN_START);
	_tmp54_ = self->priv->code_field;
	gtk_widget_set_hexpand ((GtkWidget*) _tmp54_, TRUE);
	_tmp55_ = self->priv->code_field;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp55_, 1, 2, 1, 1);
	_tmp56_ = _ ("<b>Command</b>");
	_tmp57_ = (GtkLabel*) gtk_label_new (_tmp56_);
	g_object_ref_sink (_tmp57_);
	_g_object_unref0 (self->priv->command_label);
	self->priv->command_label = _tmp57_;
	_tmp58_ = self->priv->command_label;
	gtk_label_set_use_markup (_tmp58_, TRUE);
	_tmp59_ = self->priv->command_label;
	gtk_widget_set_halign ((GtkWidget*) _tmp59_, GTK_ALIGN_END);
	_tmp60_ = self->priv->command_label;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp60_, 0, 3, 1, 1);
	_tmp61_ = _data2_->settings;
	g_object_get (_tmp61_, "path", &_tmp62_, NULL);
	_tmp63_ = _tmp62_;
	_tmp64_ = _tmp63_;
	_tmp65_ = _data2_->name;
	_tmp66_ = g_strconcat (_tmp64_, _tmp65_, NULL);
	_tmp67_ = _tmp66_;
	_tmp68_ = g_strdup_printf ("<tt><span foreground=\"#000000\" stretch=\"condensed\">dconf read %s</" \
"span></tt>", _tmp67_);
	_tmp69_ = _tmp68_;
	_tmp70_ = (GtkLabel*) gtk_label_new (_tmp69_);
	g_object_ref_sink (_tmp70_);
	_g_object_unref0 (self->priv->command_field);
	self->priv->command_field = _tmp70_;
	_g_free0 (_tmp69_);
	_g_free0 (_tmp67_);
	_g_free0 (_tmp64_);
	_tmp71_ = self->priv->command_field;
	gtk_label_set_use_markup (_tmp71_, TRUE);
	_tmp72_ = self->priv->command_field;
	gtk_label_set_selectable (_tmp72_, TRUE);
	_tmp73_ = self->priv->command_field;
	g_object_set (_tmp73_, "wrap", TRUE, NULL);
	_tmp74_ = self->priv->command_field;
	gtk_widget_set_halign ((GtkWidget*) _tmp74_, GTK_ALIGN_START);
	_tmp75_ = self->priv->command_field;
	gtk_widget_set_hexpand ((GtkWidget*) _tmp75_, TRUE);
	_tmp76_ = self->priv->command_field;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp76_, 1, 3, 1, 1);
	_tmp77_ = _ ("<b>Description</b>");
	_tmp78_ = (GtkLabel*) gtk_label_new (_tmp77_);
	g_object_ref_sink (_tmp78_);
	_g_object_unref0 (self->priv->description_label);
	self->priv->description_label = _tmp78_;
	_tmp79_ = self->priv->description_label;
	gtk_label_set_use_markup (_tmp79_, TRUE);
	_tmp80_ = self->priv->description_label;
	gtk_widget_set_halign ((GtkWidget*) _tmp80_, GTK_ALIGN_END);
	_tmp81_ = self->priv->description_label;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp81_, 0, 4, 1, 1);
	_tmp82_ = key;
	_tmp83_ = g_settings_schema_key_get_description (_tmp82_);
	_tmp84_ = (GtkLabel*) gtk_label_new (_tmp83_);
	g_object_ref_sink (_tmp84_);
	_g_object_unref0 (self->priv->description_field);
	self->priv->description_field = _tmp84_;
	_tmp85_ = self->priv->description_field;
	gtk_label_set_use_markup (_tmp85_, TRUE);
	_tmp86_ = self->priv->description_field;
	gtk_label_set_selectable (_tmp86_, TRUE);
	_tmp87_ = self->priv->description_field;
	g_object_set (_tmp87_, "wrap", TRUE, NULL);
	_tmp88_ = self->priv->description_field;
	gtk_widget_set_halign ((GtkWidget*) _tmp88_, GTK_ALIGN_START);
	_tmp89_ = self->priv->description_field;
	gtk_widget_set_hexpand ((GtkWidget*) _tmp89_, TRUE);
	_tmp90_ = self->priv->description_field;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp90_, 1, 4, 1, 1);
	_tmp91_ = _ ("Reset to default");
	_tmp92_ = (GtkButton*) gtk_button_new_with_label (_tmp91_);
	g_object_ref_sink (_tmp92_);
	_g_object_unref0 (self->priv->reset_button);
	self->priv->reset_button = _tmp92_;
	_tmp93_ = self->priv->reset_button;
	_tmp94_ = gtk_widget_get_style_context ((GtkWidget*) _tmp93_);
	gtk_style_context_add_class (_tmp94_, "destructive-action");
	_tmp95_ = self->priv->reset_button;
	gtk_widget_set_halign ((GtkWidget*) _tmp95_, GTK_ALIGN_END);
	_tmp96_ = self->priv->reset_button;
	g_signal_connect_data (_tmp96_, "clicked", (GCallback) ___lambda7__gtk_button_clicked, block2_data_ref (_data2_), (GClosureNotify) block2_data_unref, 0);
	_tmp97_ = self->priv->reset_button;
	gtk_grid_attach ((GtkGrid*) self, (GtkWidget*) _tmp97_, 0, 5, 2, 1);
	block2_data_unref (_data2_);
	_data2_ = NULL;
	return self;
}


configuratorWidgetsKeyInfo* configurator_widgets_key_info_new (GSettings* settings, const gchar* name, GSettingsSchemaKey* key) {
	return configurator_widgets_key_info_construct (CONFIGURATOR_WIDGETS_TYPE_KEY_INFO, settings, name, key);
}


void configurator_widgets_key_info_set_reset_enabled (configuratorWidgetsKeyInfo* self, gboolean enabled) {
	GtkButton* _tmp0_ = NULL;
	gboolean _tmp1_ = FALSE;
	g_return_if_fail (self != NULL);
	_tmp0_ = self->priv->reset_button;
	_tmp1_ = enabled;
	gtk_widget_set_sensitive ((GtkWidget*) _tmp0_, _tmp1_);
}


static void configurator_widgets_key_info_class_init (configuratorWidgetsKeyInfoClass * klass) {
	configurator_widgets_key_info_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (configuratorWidgetsKeyInfoPrivate));
	G_OBJECT_CLASS (klass)->finalize = configurator_widgets_key_info_finalize;
}


static void configurator_widgets_key_info_instance_init (configuratorWidgetsKeyInfo * self) {
	self->priv = CONFIGURATOR_WIDGETS_KEY_INFO_GET_PRIVATE (self);
}


static void configurator_widgets_key_info_finalize (GObject* obj) {
	configuratorWidgetsKeyInfo * self;
	self = G_TYPE_CHECK_INSTANCE_CAST (obj, CONFIGURATOR_WIDGETS_TYPE_KEY_INFO, configuratorWidgetsKeyInfo);
	_g_object_unref0 (self->priv->type_label);
	_g_object_unref0 (self->priv->type_field);
	_g_object_unref0 (self->priv->default_label);
	_g_object_unref0 (self->priv->default_field);
	_g_object_unref0 (self->priv->code_label);
	_g_object_unref0 (self->priv->code_field);
	_g_object_unref0 (self->priv->command_label);
	_g_object_unref0 (self->priv->command_field);
	_g_object_unref0 (self->priv->description_label);
	_g_object_unref0 (self->priv->description_field);
	_g_object_unref0 (self->priv->reset_button);
	G_OBJECT_CLASS (configurator_widgets_key_info_parent_class)->finalize (obj);
}


GType configurator_widgets_key_info_get_type (void) {
	static volatile gsize configurator_widgets_key_info_type_id__volatile = 0;
	if (g_once_init_enter (&configurator_widgets_key_info_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (configuratorWidgetsKeyInfoClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) configurator_widgets_key_info_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (configuratorWidgetsKeyInfo), 0, (GInstanceInitFunc) configurator_widgets_key_info_instance_init, NULL };
		GType configurator_widgets_key_info_type_id;
		configurator_widgets_key_info_type_id = g_type_register_static (gtk_grid_get_type (), "configuratorWidgetsKeyInfo", &g_define_type_info, 0);
		g_once_init_leave (&configurator_widgets_key_info_type_id__volatile, configurator_widgets_key_info_type_id);
	}
	return configurator_widgets_key_info_type_id__volatile;
}



