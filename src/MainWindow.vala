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

namespace configurator {
	public class MainWindow : Gtk.Window {
		public configuratorApp app;

		private Gtk.Box box;

		private Widgets.TitleBar title_bar;

		private Gtk.Stack stack;

		private Widgets.BrowserView browser_view;
		private Widgets.EventsView events_view;

		public MainWindow (configuratorApp app) {
			this.app = app;
			this.set_application (app);

			this.set_size_request (1000, 650);
			this.set_has_resize_grip (false);
			this.window_position = Gtk.WindowPosition.CENTER;

			setup_ui ();

			if (Services.Settings.get_default ().maximized)
				this.maximize ();
			else
				this.unmaximize ();

			this.window_state_event.connect ((e) => {
				Services.Settings.get_default ().maximized = (get_window ().get_state () & Gdk.WindowState.MAXIMIZED) != 0;
				return false;
			});

			this.show_all ();
		}

		private void setup_ui () {
			box = new Gtk.Box (Gtk.Orientation.VERTICAL, 0);

			title_bar = new Widgets.TitleBar (this);

			this.set_titlebar (title_bar);
			box.pack_start (title_bar, false, true);

			stack = new Gtk.Stack ();

			browser_view = new Widgets.BrowserView ();

			stack.add_titled (browser_view, "browser", _("Schemas"));

			events_view = new Widgets.EventsView ();

			stack.add_titled (events_view, "events", _("Events"));

			box.pack_start (stack, true, true);

			title_bar.show_stack (stack);

			this.add (box);
		}
	}
}
