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
	public class EventsView : Gtk.Box {
		private Gtk.Stack stack;

		private InfoScreen info_screen;

		private Gtk.ScrolledWindow scrolled;
		private KeyList key_list;

		public EventsView () {
			stack = new Gtk.Stack ();

			info_screen = new InfoScreen (_("No events logged yet"),
					_("On this page you'll see a list of settings-keys that have changed since you have started this application.") + "\n\n" +
					_("You could use this feature to search for keys that are changed by the preferences of another program. Thanks to the code-examples you're then\nable to integrate these keys into your own applications and scripts."),
					"dialog-information");

			stack.add_named (info_screen, "info-screen");

			scrolled = new Gtk.ScrolledWindow (null, null);
			scrolled.hscrollbar_policy = Gtk.PolicyType.NEVER;

			key_list = new KeyList ();
			key_list.valign = Gtk.Align.START;
			key_list.margin_start = 12;
			key_list.margin_end = 12;

			scrolled.add (key_list);

			stack.add_named (scrolled, "key-list");

			this.pack_start (stack, true, true);

			Services.EventManager.get_default ().event.connect ((type, settings, key) => {
				if (type == Services.EventType.KEY_CHANGED) {
					stack.set_visible_child_name ("key-list");

					key_list.add_item (settings, key, true, false, true);
					key_list.show_all ();
				} else {
					warning (_("Unsupported event type \"%s\""), type.to_string ());
				}
			});
		}
	}
}
