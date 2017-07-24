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
	public class InfoScreen : Gtk.Frame {
		private Gtk.Grid grid;

		private Gtk.Image image;
		private Gtk.Label title;
		private Gtk.Label description;

		// Stolen from my other application: switchboard-plug-notifications ;)
		public InfoScreen (string header, string desc, string icon_name) {
			this.expand = true;
			this.get_style_context ().add_class (Gtk.STYLE_CLASS_VIEW);
			this.shadow_type = Gtk.ShadowType.NONE;

			grid = new Gtk.Grid ();
			grid.vexpand = false;
			grid.valign = Gtk.Align.CENTER;
			grid.halign = Gtk.Align.CENTER;
			grid.border_width = 24;
			grid.row_spacing = 12;
			grid.column_spacing = 12;

			image = new Gtk.Image.from_icon_name (icon_name, Gtk.IconSize.DIALOG);
			image.valign = Gtk.Align.START;
			image.halign = Gtk.Align.END;

			grid.attach (image, 0, 0, 1, 2);

			title = new Gtk.Label (header);
			title.halign = Gtk.Align.START;
			title.set_line_wrap (true);
			title.justify = Gtk.Justification.FILL;
			title.get_style_context ().add_class ("h2");

			grid.attach (title, 1, 0, 1, 1);

			description = new Gtk.Label (desc);
			description.halign = Gtk.Align.START;
			description.set_line_wrap (true);
			description.justify = Gtk.Justification.FILL;

			grid.attach (description, 1, 1, 1, 1);

			grid.show_all ();

			this.add (grid);
		}
	}
}
