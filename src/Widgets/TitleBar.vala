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
	public class TitleBar : Gtk.HeaderBar {
		private Gtk.StackSwitcher stack_switcher;

		public TitleBar (MainWindow parent) {
			this.get_style_context ().add_class ("primary-toolbar");
			this.show_close_button = true;
			this.set_title (_("Configurator"));

			stack_switcher = new Gtk.StackSwitcher ();

			this.set_custom_title (stack_switcher);
		}

		public void show_stack (Gtk.Stack stack) {
			stack_switcher.set_stack (stack);
		}
	}
}
