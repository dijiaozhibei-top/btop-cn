/* Copyright 2021 Aristocratos (jakob@qvantnet.com)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

indent = tab
tab-size = 4
*/

#pragma once

#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

//* Internationalization / Localization support for btop++
namespace Locale {

	//* Initialize locale system, load translations for language code (e.g. "zh", "en")
	bool init(const std::string& lang);

	//* Get translated string for key, falls back to key (English) if not found
	const std::string& get(const std::string& key);

	//* Get current language code
	const std::string& currentLanguage();

	//* List available language codes
	std::vector<std::string> availableLanguages();

	//* Reload translations (e.g. after config change)
	bool reload();

}
