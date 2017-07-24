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

namespace configurator.Utils {
	public string type_to_string (VariantType variant_type) {
		var type = variant_type.dup_string ();

		if (type.has_prefix ("a") && type.length >= 2)
			return "Array of %s".printf (dup_type_to_string (type.substring (1)).down ());

		return dup_type_to_string (type);
	}

	public string dup_type_to_string (string type) {
		switch (type) {
			case "b":
				return "Boolean";
			case "y":
				return "Byte";
			case "n":
				return "Integer";
			case "q":
				return "Unsigned integer";
			case "i":
				return "Int32";
			case "u":
				return "Unsigned Int32";
			case "x":
				return "Int64";
			case "t":
				return "Unsigned Int64";
			case "h":
				return "Handle";
			case "s":
			case "o":
			case "g":
				return "String";
		}

		return "\"%s\"".printf (type);
	}

	public string variant_to_string (Variant variant) {
		var type = variant.get_type ().dup_string ();

		switch (type) {
			case "b":
				return variant.get_boolean () ? _("Enabled") : _("Disabled");
			case "y":
				return variant.get_byte ().to_string ();
			case "n":
				return variant.get_int16 ().to_string ();
			case "q":
				return variant.get_uint16 ().to_string ();
			case "i":
				return variant.get_int32 ().to_string ();
			case "u":
				return variant.get_uint32 ().to_string ();
			case "x":
				return variant.get_int64 ().to_string ();
			case "t":
				return variant.get_uint64 ().to_string ();
			case "h":
				return variant.get_handle ().to_string ();
			case "s":
			case "o":
			case "g":
				return "\"%s\"".printf (variant.get_string ().to_string ());
			case "as":
				var strings = variant.get_strv ();
				var text = "";

				if (strings.length == 0)
					return _("Empty array");

				for (int i = 0; i < strings.length; i++) {
					text += "\"%s\"".printf (strings[i]);

					if (i < strings.length -1)
						text += ", ";
				}

				return text;
		}

		return _("Preview not supported.");
	}
}
