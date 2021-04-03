#pragma once

#include <utility>

namespace EvolutionaryWalker::LibUtils
{

template <class T, class TAG> struct StrongType
{
    using value_type = T;

    explicit StrongType() = default;

    explicit StrongType(const T index)
        : m_value(std::move(index))
    {
    }

    operator T() const
    {
        return m_value;
    }

    T m_value;
};

template <class T> struct Eq
{
    friend constexpr bool operator==(const T& l, const T& r) noexcept
    {
        const auto& vl = l.m_value;
        const auto& vr = r.m_value;
        return {vl == vr};
    }

    friend constexpr bool operator!=(const T& l, const T& r) noexcept
    {
        return !(l == r);
    }
};

template <class T> struct Inc
{
    friend constexpr T& operator++(T& rv) noexcept
    {
        auto& val = rv.m_value;
        ++rv.m_value;
        return rv;
    }

    friend constexpr T operator++(T& rv, int) noexcept
    {
        auto res = rv.m_value;
        ++rv.m_value;
        return res;
    }
};

template <class T> struct Comp
{
    friend constexpr bool operator<(const T& l, const T& r) noexcept
    {
        const auto& vl = l.m_value;
        const auto& vr = r.m_value;
        return {vl < vr};
    }
};

template <class T> struct Add
{
    friend constexpr T operator+(const T& l, const T& r) noexcept
    {
        const auto& vl = l.m_value;
        const auto& vr = r.m_value;
        return T{vl + vr};
    }
};

template <typename U, template <class...> class... BS> struct Ops : BS<U>...
{
};

} // namespace EvolutionaryWalker::Utils
