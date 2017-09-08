#ifndef STRING_CONVERT_H_
#define STRING_CONVERT_H_
#include <string>
namespace fmt {
namespace StringConverter {

	std::wstring StringToWString(const std::string& refSrc);

	std::string WStringToString(const std::wstring& refSrc);
}
}
#endif