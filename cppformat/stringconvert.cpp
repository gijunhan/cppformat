#include "stringconvert.h"
#include <Windows.h>
#include <vector>

namespace fmt {
namespace StringConverter {
	enum CodePageID : unsigned int
	{
		ANSI = CP_ACP,	// ANSI
		OEM = CP_OEMCP,	// OEM
		MAC = CP_MACCP,	// MAC
		UTF7 = CP_UTF7,	// UTF-7
		UTF8 = CP_UTF8	// UTF-8
	};

	static void SetGlobalLocale(const std::string localeName = "")
	{
		std::locale::global(std::locale(localeName));
		setlocale(LC_ALL, std::locale().c_str());
	}
	std::wstring StringToWString(const std::string& refSrc)
	{
		unsigned int codePage = CodePageID::ANSI;
		std::vector<wchar_t> buffer(MultiByteToWideChar(codePage, 0, refSrc.c_str(), -1, nullptr, 0));
		MultiByteToWideChar(codePage, 0, refSrc.c_str(), -1, &buffer.front(), buffer.size());
		return std::wstring(buffer.begin(), buffer.end());
	}

	std::string WStringToString(const std::wstring& refSrc)
	{
		unsigned int codePage = CodePageID::OEM;
		int size = refSrc.size() == 0 ? -1 : refSrc.size();
		std::vector<char> buffer(WideCharToMultiByte(codePage, 0, refSrc.c_str(), size, nullptr, 0, nullptr, nullptr));
		WideCharToMultiByte(codePage, 0, refSrc.c_str(), -1, &buffer.front(), buffer.size(), nullptr, nullptr);
		return std::string(buffer.begin(), buffer.end());
	}
}
}
