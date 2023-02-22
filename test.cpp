
#include <iostream>
#include <locale>
#include <codecvt>
#include "tokenizepp20.h"

// entry point
auto main() -> int
{
	try
	{
		const std::string str0{ "Hello. ;;Stevie\nMahone!hee[hhe}heee?@a#Ooh" };
		const std::string delimiters0{ "! .,\"'~@#$%^&()\n`\t<}>{?];:[" };
		std::vector<std::string> tokens0{};
		tokenize(str0, delimiters0, tokens0);
		std::cout << "\nstring 0: " << str0 << "\n\ntokenized string: " << [&]()
		{
			for (auto& e : tokens0)
				std::cout << e << ' ';
			return ' ';
		}() << "\n\n";

		std::wstring str1{ L"jrsybhyn, ryjk.lvy;vtv'tv\"rtgrae9verf0)SFb (s\nherah\tshhdf]zh!\n{xxx}" };
		std::wstring delimiters1{ L"! .,\"'~@#$%^&()\n`\t<>?;:" };
		std::unordered_set<std::wstring> tokens1{};
		tokenize(str1, delimiters1, tokens1);
		std::wcout << L"\nstring 1: " << str1 << L"\n\ntokenized string: " << [&]()
		{
			for (auto& e : tokens1)
				std::wcout << e << L" ";
			return L" ";
		}() << L"\n\n";

		const std::string str2{
			"This is the first chapter dealing with the construction of certain algorithms for synchronizing "
			"concurrent processes - the entry and exit protocols to protect critical sections. The "
			"effect of an entry protocol can be intuitively imagined in this way: A process closes access "
			"to a critical section as it passes through a door to it in order to reopen the door after leaving "
			"the critical section in the exit protocol. Therefore, the implementations of these protocols are called lock"
			" algorithms and the corresponding data types are called locks. After "
			"the specification of locks, they are implemented using machine instructions-oriented"
			" to common processors - and these procedures are evaluated. Afterwards, possibilities"
			" are presented, to implement entry and exit protocols for entering critical sections with"
			" elementary methods of sequential programming by accessing shared variables. Many of "
			"these solutions are “classical algorithms”, which have shaped research for years. However, a number of disadvantages and"
			" limitations - both conceptual and practical - also emerge."
		};
		const std::string delimiters2{ "! .,\"_-\n`\t;:" };
		std::unordered_map<std::string, size_t> tokens2{};
		tokenize(str2, delimiters2, tokens2);
		std::cout << "\nstring 2: " << str2 << "\n\ntokenized string:\n" << [&]()
		{
			for (auto& e : tokens2)
				std::cout << e.first << ' ' << e.second << '\n';
			return '\n';
		}() << '\n';

		return EXIT_SUCCESS;
	}
	catch (const std::exception& xxx)
	{
		std::cerr << xxx.what() << std::endl;
		return EXIT_FAILURE;
	}
}