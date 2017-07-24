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

namespace configurator.Widgets.Fields {
	public class ArrayInput : Gtk.Button {
		private Gtk.Popover popover;

		private Gtk.Box box;

		private Gtk.ListBox listbox;

		private Gtk.ActionBar action_bar;

		private Gtk.Entry add_entry;
		private Gtk.Button add_button;

		public ArrayInput (Settings settings, string key) {
			popover = new Gtk.Popover (this);

			this.clicked.connect (() => popover.show_all ());

			box = new Gtk.Box (Gtk.Orientation.VERTICAL, 0);

			listbox = new Gtk.ListBox ();
			listbox.margin_top = 3;
			listbox.margin_bottom = 3;

			box.pack_start (listbox, true, true);

			action_bar = new Gtk.ActionBar ();

			add_entry = new Gtk.Entry ();
			add_entry.hexpand = true;
			add_entry.placeholder_text = _("New element");

			action_bar.pack_start (add_entry);

			add_button = new Gtk.Button.from_icon_name ("list-add-symbolic", Gtk.IconSize.BUTTON);
			add_button.clicked.connect (() => {
				Variant? new_child = null;

				var type = settings.get_value (key).get_type ().dup_string ();

				assert (type.has_prefix ("a") && type.length == 2);

				switch (type.substring (1)) {
					case "b":
						new_child = new Variant.boolean (add_entry.text.down () == "true" || add_entry.text.down () == "on" || add_entry.text.down () == "enabled" || add_entry.text.down () == _("Enabled").down ());
						break;
					case "y":
						new_child = new Variant.byte ((uchar)int.parse (add_entry.text));
						break;
					case "n":
						new_child = new Variant.int16 ((int16)int.parse (add_entry.text));
						break;
					case "q":
						new_child = new Variant.uint16 ((uint16)int.parse (add_entry.text));
						break;
					case "i":
						new_child = new Variant.int32 ((int32)int.parse (add_entry.text));
						break;
					case "u":
						new_child = new Variant.uint32 ((uint32)int.parse (add_entry.text));
						break;
					case "x":
						new_child = new Variant.int64 ((int64)int.parse (add_entry.text));
						break;
					case "t":
						new_child = new Variant.uint64 ((uint64)int.parse (add_entry.text));
						break;
					case "h":
						new_child = new Variant.int32 ((int32)int.parse (add_entry.text));
						break;
					case "s":
					case "o":
					case "g":
						new_child = new Variant.string (add_entry.text);
						break;
					default:
						warning (_("Unsupported type \"%s\". Can't create new entry."), type);
						break;
				}

				if (new_child != null) {
					var childs = settings.get_value (key).n_children ();
					Variant[] new_child_list = new Variant[childs + 1];

					for (int c = 0; c < childs; c++) {
						new_child_list[c] = settings.get_value (key).get_child_value (c);
					}

					new_child_list[childs] = new_child;

					var new_val = new Variant.array (new_child.get_type (), new_child_list);

					settings.set_value (key, new_val);

					add_entry.text = "";
				}
			});

			action_bar.pack_end (add_button);

			box.pack_end (action_bar, true, false);

			popover.add (box);

			display_value (settings, key, settings.get_value (key));

			settings.changed.connect ((k) => {
				if (k == key) {
					listbox.get_children ().foreach ((item) => listbox.remove (item));
					display_value (settings, key, settings.get_value (key));
				}
			});
		}

		private void display_value (Settings settings, string key, Variant val) {
			assert (val.is_container ());

			var childs = val.n_children ();

			this.label = _("%s elements").printf (childs.to_string ());

			if (childs < 1) {
				var no_items_label = new Gtk.Label (_("No items found."));
				no_items_label.get_style_context ().add_class ("h3");
				no_items_label.hexpand = true;
				no_items_label.vexpand = true;
				no_items_label.halign = Gtk.Align.CENTER;
				no_items_label.valign = Gtk.Align.CENTER;
				no_items_label.margin_start = 6;
				no_items_label.margin_end = 6;
				no_items_label.set_size_request (-1, 60);
				no_items_label.sensitive = false;

				listbox.add (no_items_label);
			} else {
				for (int i = 0; i < childs; i++) {
					var child_index = i;
					var child = val.get_child_value (child_index);

					var item = new Gtk.Box (Gtk.Orientation.HORIZONTAL, 6);
					item.margin_start = 6;
					item.margin_end = 6;

					var item_number = new Gtk.Label ("<b>%s</b>".printf (child_index.to_string ()));
					item_number.use_markup = true;
					item_number.halign = Gtk.Align.END;
					item_number.valign = Gtk.Align.CENTER;

					item.pack_start (item_number, false, false);

					var item_content = new Gtk.Label (Utils.variant_to_string (child));
					item_content.halign = Gtk.Align.START;
					item_content.valign = Gtk.Align.CENTER;

					item.pack_start (item_content, true, true);

					var item_remove_button = new Gtk.Button.from_icon_name ("list-remove-symbolic", Gtk.IconSize.BUTTON);
					item_remove_button.relief = Gtk.ReliefStyle.NONE;
					item_remove_button.clicked.connect (() => {
						Variant[] new_child_list = new Variant[childs - 1];
						var new_child_list_counter = 0;

						for (int c = 0; c < childs; c++) {
							if (c != child_index) {
								new_child_list[new_child_list_counter++] = val.get_child_value (c);
							}
						}

						var new_val = new Variant.array (child.get_type (), new_child_list);

						settings.set_value (key, new_val);
					});

					item.pack_end (item_remove_button, false, false);

					listbox.add (item);
				}
			}

			listbox.show_all ();
		}
	}
}
