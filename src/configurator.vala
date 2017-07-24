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
	public class configuratorApp : Granite.Application {
		public MainWindow window;

		construct {
			// App-Properties
			program_name = "Configurator";
			exec_name = "configurator";

			build_data_dir = Constants.DATADIR;
			build_pkg_data_dir = Constants.PKGDATADIR;
			build_release_name = Constants.RELEASE_NAME;
			build_version = Constants.VERSION;
			build_version_info = Constants.VERSION_INFO;

			app_years = "2015";
			app_icon = "configurator";
			app_launcher = "configurator.desktop";
			application_id = "net.launchpad.configurator";
			main_url = "https://launchpad.net/configurator";
			bug_url = "https://bugs.launchpad.net/configurator";
			help_url = "https://answers.launchpad.net/configurator";
			translate_url = "https://translations.launchpad.net/configurator";
			about_authors = {"Marcus Wichelmann <admin@marcusw.de>"};
			about_documenters = {"Marcus Wichelmann <admin@marcusw.de>"};
			about_artists = {"Marcus Wichelmann <admin@marcusw.de>"};
			about_comments = _("A tool to edit your system-settings in elementary OS.");
			about_translators = "Launchpad Translators";
		}

		public configuratorApp () {
			// Translations
			Intl.setlocale (LocaleCategory.ALL, "");
			string langpack_dir = Path.build_filename (Constants.INSTALL_PREFIX, "share", "locale");
			Intl.bindtextdomain (Constants.GETTEXT_PACKAGE, langpack_dir);
			Intl.bind_textdomain_codeset (Constants.GETTEXT_PACKAGE, "UTF-8");
			Intl.textdomain (Constants.GETTEXT_PACKAGE);

			// Debug service
			Granite.Services.Logger.initialize ("configurator");
			Granite.Services.Logger.DisplayLevel = Granite.Services.LogLevel.DEBUG;
		}

		public override void activate () {
			if (get_windows () == null) {
				window = new MainWindow (this);
				window.show_all ();
			} else {
				window.present ();
			}
		}

		public override void open (File[] files, string hint) {
			// Do nothing
		}

		public static void main (string[] args) {
			Gtk.init (ref args);

			var app = new configurator.configuratorApp ();
			app.run (args);
		}
	}
}
