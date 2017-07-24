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
	public class BrowserView : Gtk.Paned {
		private SchemaList schema_list;

		private Gtk.ScrolledWindow scrolled;
		private KeyList key_list;

		public BrowserView () {
			schema_list = new SchemaList ();
			schema_list.set_size_request (200, -1);
			schema_list.item_selected.connect ((item) => {
				if (item.get_type () == typeof (Schema))
					key_list.show_keys_for_schema ((item as Schema).get_schema ());
				else if (item.get_type () == typeof (SchemaFolder))
					key_list.show_keys_for_schema ((item as SchemaFolder).get_schema ());
				else
					key_list.clear_list ();
			});

			this.pack1 (schema_list, false, false);

			scrolled = new Gtk.ScrolledWindow (null, null);
			scrolled.hscrollbar_policy = Gtk.PolicyType.NEVER;

			key_list = new KeyList ();
			key_list.valign = Gtk.Align.START;
			key_list.margin_start = 12;
			key_list.margin_end = 12;

			scrolled.add (key_list);

			this.pack2 (scrolled, true, false);
		}
	}
}
