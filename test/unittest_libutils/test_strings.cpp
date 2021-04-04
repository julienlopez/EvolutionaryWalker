#include <catch2/catch.hpp>

#include "strings.hpp"

TEST_CASE("Basic uses of Utils::Strings", "[utils]")
{
    using namespace EvolutionaryWalker::LibUtils::Strings;

    using namespace std::string_literals;

    using Catch::Matchers::Equals;

    SECTION("splitPerLine")
    {
        CHECK_THAT(splitPerLine(L"ab"s), Equals<std::wstring>({{L"ab"s}}));
        CHECK_THAT(splitPerLine(L"a\nb"s), Equals<std::wstring>({{L"a"s, L"b"s}}));
        CHECK_THAT(splitPerLine(L"\na\nb"s), Equals<std::wstring>({{L""s, L"a"s, L"b"s}}));
        // CHECK_THAT(splitPerLine("\na\nb\n"s), Equals<std::wstring>({{""s, "a"s, "b"s, ""s}})); // TODO restore?
    }

    SECTION("startsWith")
    {
        CHECK(startsWith(L"ab"s, L"a"s));
        CHECK(startsWith(L"ab"s, L"b"s) == false);
        CHECK(startsWith(L" ab"s, L"a"s) == false);
    }

    SECTION("endsWith")
    {
        CHECK(endsWith(L"ab"s, L"b"s));
        CHECK(endsWith(L"ab"s, L"a"s) == false);
        CHECK(endsWith(L"ab "s, L"b"s) == false);
    }

    SECTION("trim")
    {
        CHECK(trim(L"ab"s) == L"ab"s);
        CHECK(trim(L" ab"s) == L"ab"s);
        CHECK(trim(L"ab "s) == L"ab"s);
        CHECK(trim(L" ab "s) == L"ab"s);
        CHECK(trim(L" \t ab "s) == L"ab"s);
    }

    SECTION("join")
    {
        CHECK(join({{L"a"s, L"b"s}}, L"_"s) != L"a b"s);
        CHECK(join({{L"a"s, L"b"s}}, L"_"s) == L"a_b"s);
    }

    SECTION("replaceOccurences")
    {
        CHECK(replaceOccurences(L"abcd", L"b", L"K") == L"aKcd"s);
        CHECK(replaceOccurences(L"abcd", L"b", L"KU") == L"aKUcd"s);
        CHECK(replaceOccurences(L"abcd", L"bc", L"KU") == L"aKUd"s);
        CHECK(replaceOccurences(L"abcd", L"bc", L"K") == L"aKd"s);
        CHECK(replaceOccurences(L"__abcd__", L"bc", L"K") == L"__aKd__"s);
    }
}
