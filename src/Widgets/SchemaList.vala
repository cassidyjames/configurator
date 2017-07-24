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
	public class SchemaList : Granite.Widgets.SourceList {
		private Granite.Widgets.SourceList.ExpandableItem root_item;

		private List<string> schemas;

		private Gee.ArrayList<string> proc_schemas;

		public SchemaList () {
			root_item = new Granite.Widgets.SourceList.ExpandableItem ();

			this.root = root_item;

			try {
				string[] data;

				var source = new SettingsSchemaSource.from_directory ("/usr/share/glib-2.0/schemas/", null, false);
				source.list_schemas (true, out data, null);

				schemas = new List<string> ();

				int i = 0;
				while (data[i] != null) {
					schemas.append (data[i]);
					i++;
				}

				schemas.sort ((a, b) => {
					return a.collate (b);
				});

				proc_schemas = new Gee.ArrayList<string> ();

				fill_folder ("", root_item, 0);
			} catch (Error e) {
				warning (e.message);
			}
		}

		private bool fill_folder (string folder, Granite.Widgets.SourceList.ExpandableItem parent_item, int level) {
			int sub_items = 0;

			foreach (string schema in schemas) {
				if (!proc_schemas.contains (schema)) {
					if (schema.has_prefix (folder) && is_schema (schema)) {
						var parts = schema.split (".");
						var is_folder = false;

						if (parts.length > level + 1) {
							var folder_path = schema.substring (0, schema.length - (parts[parts.length - 1].length + 1));
							var folder_name = parts[level];
							Granite.Widgets.SourceList.ExpandableItem folder_item;

							if (is_in_schema_list (folder_path))
								folder_item = new SchemaFolder (folder_path, folder_name);
							else
								folder_item = new Granite.Widgets.SourceList.ExpandableItem (folder_name);

							is_folder = fill_folder (folder != "" ? folder + "." + folder_name : folder_name, folder_item, level + 1);

							if (is_folder)
								parent_item.add (folder_item);
						}

						if (!is_folder && parts.length > 0) {
							var schema_item = new Schema (schema, parts[parts.length -1]);
							parent_item.add (schema_item);
						}

						proc_schemas.add (schema);

						sub_items++;
					}
				}
			}

			return sub_items > 0;
		}

		private bool is_schema (string s) {
			foreach (string schema in schemas) {
				if (schema.length != s.length && schema.has_prefix (s)) {
					return false;
				}
			}

			return true;
		}

		private bool is_in_schema_list (string s) {
			foreach (string schema in schemas) {
				if (schema == s)
					return true;
			}

			return false;
		}
	}
}
