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
	public class Schema : Granite.Widgets.SourceList.Item {
		private Settings settings;

		public Schema (string schema, string name) {
			this.settings = new Settings (schema);
			this.name = name;

			settings.changed.connect ((key) => Services.EventManager.get_default ().key_changed (settings, key));
		}

		public Settings get_schema () {
			return settings;
		}
	}
}
