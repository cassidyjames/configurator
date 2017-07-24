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
	public class Key : Gtk.Grid {
		private Gtk.Image info_image;
		private Gtk.ToggleButton info_button;

		private Gtk.Label label_name;
		private Gtk.Label label_description;

		private Gtk.Widget? widg = null;

		private Gtk.Revealer revealer;
		private KeyInfo key_info;

		private Gtk.Separator separator;

		private Gtk.Image readonly_image;

		public Key (Settings settings, string name, SettingsSchemaKey key, bool live, bool show_schema) {
			this.column_spacing = 12;
			this.margin_top = 18;

			info_image = new Gtk.Image.from_icon_name ("help-info-symbolic", Gtk.IconSize.BUTTON);
			info_image.margin = 0;

			info_button = new Gtk.ToggleButton ();
			info_button.image = info_image;
			info_button.vexpand = true;
			info_button.valign = Gtk.Align.CENTER;
			info_button.halign = Gtk.Align.START;
			info_button.toggled.connect (() => revealer.set_reveal_child (info_button.active));

			this.attach (info_button, 0, 0, 1, 2);

			label_name = new Gtk.Label (show_schema ? "%s -> <b>%s</b>".printf (settings.schema_id, name) : "<b>%s</b>".printf (name));
			label_name.get_style_context ().add_class ("h3");
			label_name.use_markup = true;
			label_name.selectable = true;
			label_name.wrap = true;
			label_name.halign = Gtk.Align.START;
			label_name.valign = Gtk.Align.END;
			label_name.hexpand = true;

			this.attach (label_name, 1, 0, 1, 1);

			if (key.get_summary () != null) {
				label_description = new Gtk.Label (key.get_summary ());
				label_description.use_markup = true;
				label_description.selectable = true;
				label_description.wrap = true;
				label_description.halign = Gtk.Align.START;
				label_description.valign = Gtk.Align.START;
				label_description.hexpand = true;

				this.attach (label_description, 1, 1, 1, 1);
			} else {
				label_name.valign = Gtk.Align.CENTER;
			}

			var type = key.get_value_type ().dup_string ();

			if (type == "b") {
				widg = new Fields.BoolInput ();

				settings.bind (name, widg, "active", live ? GLib.SettingsBindFlags.DEFAULT : GLib.SettingsBindFlags.GET_NO_CHANGES);
			} else if (type == "s") {
				if (key.get_range ().get_child_value (0).get_string () == "enum") {
					widg = new Fields.SelectInput (key.get_range ().get_child_value (1).get_variant ());

					settings.bind (name, widg, "active_id", live ? GLib.SettingsBindFlags.DEFAULT : GLib.SettingsBindFlags.GET_NO_CHANGES);
				} else {
					widg = new Fields.StringInput ();
					widg.set_size_request (350, -1);

					settings.bind (name, widg, "text", live ? GLib.SettingsBindFlags.DEFAULT : GLib.SettingsBindFlags.GET_NO_CHANGES);
				}
			} else if (type == "i") {
				widg = new Fields.IntegerInput ();

				settings.bind (name, widg, "value", live ? GLib.SettingsBindFlags.DEFAULT : GLib.SettingsBindFlags.GET_NO_CHANGES);
			} else if (type == "u") {
				widg = new Fields.UIntegerInput ();

				settings.bind (name, widg, "value", live ? GLib.SettingsBindFlags.DEFAULT : GLib.SettingsBindFlags.GET_NO_CHANGES);
			} else if (type == "x") {
				widg = new Fields.Int64Input ();

				settings.bind (name, widg, "value", live ? GLib.SettingsBindFlags.DEFAULT : GLib.SettingsBindFlags.GET_NO_CHANGES);
			} else if (type == "t") {
				widg = new Fields.UInt64Input ();

				settings.bind (name, widg, "value", live ? GLib.SettingsBindFlags.DEFAULT : GLib.SettingsBindFlags.GET_NO_CHANGES);
			} else if (type == "d") {
				// FIXME: The SpinButton gets very big when setting the Min- and Max- values for double.
				//widg = new Gtk.SpinButton.with_range (double.MIN, double.MAX, double.EPSILON);

				widg = new Fields.DoubleInput ();
				widg.set_size_request (350, -1);

				(widg as Gtk.Entry).text = settings.get_double (name).to_string ();

				if (live) {
					(widg as Gtk.Entry).changed.connect (() => {
						double parsed;
						if (double.try_parse ((widg as Gtk.Entry).text, out parsed)) {
							settings.set_double (name, parsed);
							(widg as Gtk.Entry).set_icon_from_icon_name (Gtk.EntryIconPosition.SECONDARY, null);
						} else {
							(widg as Gtk.Entry).set_icon_from_icon_name (Gtk.EntryIconPosition.SECONDARY, "dialog-warning-symbolic");
						}
					});

					settings.changed.connect ((key) => {
						if (key == name)
							(widg as Gtk.Entry).text = settings.get_double (name).to_string ();
					});
				}
			} else if (type.has_prefix ("a") && type.length == 2) {
				widg = new Fields.ArrayInput (settings, name);
			} else {
				widg = new Gtk.Label (_("This settings type is not supported yet."));
				widg.get_style_context ().add_class ("h3");

				warning (_("Unsupported type \"%s\" in %s->%s"), type, settings.schema_id, name);
			}

			if (widg != null) {
				widg.vexpand = true;
				widg.valign = Gtk.Align.CENTER;
				widg.halign = Gtk.Align.END;
				widg.sensitive = live;

				this.attach (widg, 2, 0, 1, 2);
			}

			revealer = new Gtk.Revealer ();
			revealer.transition_type = Gtk.RevealerTransitionType.SLIDE_DOWN;

			key_info = new KeyInfo (settings, name, key);

			revealer.add (key_info);

			this.attach (revealer, 0, 2, 3, 1);

			separator = new Gtk.Separator (Gtk.Orientation.HORIZONTAL);
			separator.margin_top = 18;

			this.attach (separator, 0, 3, 3, 1);

			if (!settings.is_writable (name)) {
				if (widg != null)
					widg.sensitive = false;

				key_info.set_reset_enabled (false);

				readonly_image = new Gtk.Image.from_icon_name ("changes-prevent-symbolic", Gtk.IconSize.BUTTON);
				readonly_image.vexpand = true;
				readonly_image.valign = Gtk.Align.CENTER;
				readonly_image.halign = Gtk.Align.END;

				this.attach (readonly_image, 3, 0, 1, 2);
			}
		}
	}
}
