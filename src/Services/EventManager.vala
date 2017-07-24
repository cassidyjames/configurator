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

namespace configurator.Services {
	public enum EventType {
		KEY_CHANGED
	}

	public class EventManager : Object {
		public signal void event (EventType type, GLib.Settings settings, string key);

		public static EventManager? instance = null;

		public EventManager () {
			
		}

		public void key_changed (GLib.Settings settings, string key) {
			if (settings.schema_id != "com.github.cassidyjames.configurator")
				event (EventType.KEY_CHANGED, settings, key);
		}

		public static EventManager get_default () {
			if (instance == null) {
				instance = new EventManager ();
			}

			return instance;
		}
	}
}
