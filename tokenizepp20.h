
#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <concepts>

namespace
{
	// string concept
	template<typename T>
	concept string = std::is_same_v<T, std::string> ||
		std::is_same_v<T, std::wstring> ||
		std::is_same_v<T, std::u16string> ||
		std::is_same_v<T, std::u32string>;

	// tokenize functions
	template<string T>
	auto tokenize(const T& str, const T& delimiters, std::vector<T>& tokens) -> void
	{
		// skip delimiters at begining
		auto last_pos = str.find_first_not_of(delimiters, 0);

		// find first non-delimiter
		auto pos = str.find_first_of(delimiters, last_pos);

		while (pos != T::npos || last_pos != T::npos)
		{
			// find a token, add it to the vector
			tokens.emplace_back(str.substr(last_pos, pos - last_pos));

			// skip delimiters
			last_pos = str.find_first_not_of(delimiters, pos);

			// find next non-delimiter
			pos = str.find_first_of(delimiters, last_pos);
		}
	}
	template<string T>
	auto tokenize(const T& str, const T& delimiters, std::unordered_set<T>& tokens) -> void
	{
		// skip delimiters at begining
		auto last_pos = str.find_first_not_of(delimiters, 0);

		// find first non-delimiter
		auto pos = str.find_first_of(delimiters, last_pos);

		while (pos != T::npos || last_pos != T::npos)
		{
			// find a token, add it to the vector
			tokens.emplace(str.substr(last_pos, pos - last_pos));

			// skip delimiters
			last_pos = str.find_first_not_of(delimiters, pos);

			// find next non-delimiter
			pos = str.find_first_of(delimiters, last_pos);
		}
	}
	template<string T>
	auto tokenize(const T& str, const T& delimiters, std::unordered_map<T, size_t>& tokens)->void
	{
		// skip delimiters at begining
		auto last_pos = str.find_first_not_of(delimiters, 0);

		// find first non-delimiter
		auto pos = str.find_first_of(delimiters, last_pos);

		while (pos != T::npos || last_pos != T::npos)
		{
			// find a token, add it to the vector
			tokens[str.substr(last_pos, pos - last_pos)]++;

			// skip delimiters
			last_pos = str.find_first_not_of(delimiters, pos);

			// find next non-delimiter
			pos = str.find_first_of(delimiters, last_pos);
		}
	}
}
