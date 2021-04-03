#pragma once

#include <string>
#include <vector>

namespace EvolutionaryWalker::LibUtils::Strings
{

std::vector<std::wstring> splitPerLine(const std::wstring& str);

bool startsWith(const std::wstring& str, const std::wstring& token);

bool endsWith(const std::wstring& str, const std::wstring& token);

std::wstring trim(std::wstring str);

std::wstring join(const std::vector<std::wstring>& lines, const std::wstring& token);

std::wstring replaceOccurences(std::wstring str, const std::wstring& token, const std::wstring& replacement);

} // namespace EvolutionaryWalker::LibUtils::Strings
