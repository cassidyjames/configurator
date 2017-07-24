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

namespace configurator.Widgets {
	public class KeyInfo : Gtk.Grid {
		private Gtk.Label type_label;
		private Gtk.Label type_field;

		private Gtk.Label default_label;
		private Gtk.Label default_field;

		private Gtk.Label code_label;
		private Gtk.Label code_field;

		private Gtk.Label command_label;
		private Gtk.Label command_field;

		private Gtk.Label description_label;
		private Gtk.Label description_field;

		private Gtk.Button reset_button;

		public KeyInfo (Settings settings, string name, SettingsSchemaKey key) {
			this.column_spacing = 12;
			this.row_spacing = 12;
			this.margin_top = 18;

			type_label = new Gtk.Label (_("<b>Property type</b>"));
			type_label.use_markup = true;
			type_label.halign = Gtk.Align.END;
			this.attach (type_label, 0, 0, 1, 1);

			type_field = new Gtk.Label (Utils.type_to_string (key.get_value_type ()));
			type_field.use_markup = true;
			type_field.selectable = true;
			type_field.wrap = true;
			type_field.halign = Gtk.Align.START;
			type_field.hexpand = true;
			this.attach (type_field, 1, 0, 1, 1);

			default_label = new Gtk.Label (_("<b>Default value</b>"));
			default_label.use_markup = true;
			default_label.halign = Gtk.Align.END;
			this.attach (default_label, 0, 1, 1, 1);

			default_field = new Gtk.Label (Utils.variant_to_string (key.get_default_value ()));
			default_field.use_markup = true;
			default_field.selectable = true;
			default_field.wrap = true;
			default_field.halign = Gtk.Align.START;
			default_field.hexpand = true;
			this.attach (default_field, 1, 1, 1, 1);

			code_label = new Gtk.Label (_("<b>Vala code</b>"));
			code_label.use_markup = true;
			code_label.halign = Gtk.Align.END;
			this.attach (code_label, 0, 2, 1, 1);

			code_field = new Gtk.Label ("<tt><span foreground=\"#000000\" stretch=\"condensed\"><span foreground=\"#FF420B\" weight=\"bold\">var</span> val = <span foreground=\"#FF420B\" weight=\"bold\">new</span> Settings (<span foreground=\"#13A50B\">\"%s\"</span>).get_value (<span foreground=\"#13A50B\">\"%s\"</span>);</span></tt>".printf (settings.schema_id, name));
			code_field.use_markup = true;
			code_field.selectable = true;
			code_field.wrap = true;
			code_field.halign = Gtk.Align.START;
			code_field.hexpand = true;
			this.attach (code_field, 1, 2, 1, 1);

			command_label = new Gtk.Label (_("<b>Command</b>"));
			command_label.use_markup = true;
			command_label.halign = Gtk.Align.END;
			this.attach (command_label, 0, 3, 1, 1);

			command_field = new Gtk.Label ("<tt><span foreground=\"#000000\" stretch=\"condensed\">dconf read %s</span></tt>".printf (settings.path + name));
			command_field.use_markup = true;
			command_field.selectable = true;
			command_field.wrap = true;
			command_field.halign = Gtk.Align.START;
			command_field.hexpand = true;
			this.attach (command_field, 1, 3, 1, 1);

			description_label = new Gtk.Label (_("<b>Description</b>"));
			description_label.use_markup = true;
			description_label.halign = Gtk.Align.END;
			this.attach (description_label, 0, 4, 1, 1);

			description_field = new Gtk.Label (key.get_description ());
			description_field.use_markup = true;
			description_field.selectable = true;
			description_field.wrap = true;
			description_field.halign = Gtk.Align.START;
			description_field.hexpand = true;
			this.attach (description_field, 1, 4, 1, 1);

			reset_button = new Gtk.Button.with_label (_("Reset to default"));
			reset_button.get_style_context ().add_class ("destructive-action");
			reset_button.halign = Gtk.Align.END;
			reset_button.clicked.connect (() => settings.reset (name));
			this.attach (reset_button, 0, 5, 2, 1);
		}

		public void set_reset_enabled (bool enabled) {
			reset_button.sensitive = enabled;
		}
	}
}
