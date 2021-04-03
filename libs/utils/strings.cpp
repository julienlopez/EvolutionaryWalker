#include "strings.hpp"

#include <cctype>
#include <sstream>

namespace EvolutionaryWalker::LibUtils
{

namespace Impl
{
    template <class STR> STR join(const std::vector<STR>& lines, const STR& token)
    {
        if(lines.empty()) return {};
        STR res = lines.front();
        auto it = begin(lines);
        std::advance(it, 1);
        for(; it != end(lines); ++it)
            res += token + *it;
        return res;
    }

    template <class STR> bool startsWith(const STR& str, const STR& token)
    {
        if(str.size() < token.size()) return false;
        return str.substr(0, token.size()) == token;
    }

    template <class STR> bool endsWith(const STR& str, const STR& token)
    {
        if(str.size() < token.size()) return false;
        return str.substr(str.size() - token.size()) == token;
    }

} // namespace Impl

std::vector<std::wstring> Strings::splitPerLine(const std::wstring& str)
{
    std::wistringstream ss(str);
    std::vector<std::wstring> res;
    std::wstring line;
    while(std::getline(ss, line))
        res.push_back(std::move(line));
    return res;
}

bool Strings::startsWith(const std::wstring& str, const std::wstring& token)
{
    return Impl::startsWith(str, token);
}

bool Strings::endsWith(const std::wstring& str, const std::wstring& token)
{
    return Impl::endsWith(str, token);
}

std::wstring Strings::trim(std::wstring str)
{
    while(!str.empty() && std::isspace(str.front()))
        str.erase(str.begin());
    while(!str.empty() && std::isspace(str.back()))
        str.erase(--str.end());
    return str;
}

std::wstring Strings::join(const std::vector<std::wstring>& lines, const std::wstring& token)
{
    return Impl::join(lines, token);
}

std::wstring Strings::replaceOccurences(std::wstring str, const std::wstring& token, const std::wstring& replacement)
{
    auto pos = str.find(token);
    while(pos != std::wstring::npos)
    {
        str.replace(pos, token.size(), replacement);
        pos = str.find(token);
    }
    return str;
}

} // namespace EvolutionaryWalker::LibUtils
