#pragma once

#include <array>

namespace EvolutionaryWalker::LibUtils
{

template <class T, std::size_t N> class Point
{
public:
    static_assert(N >= 2);

    using Container = std::array<T, N>;

    Point() = default;

    Point(Container values)
        : m_values(std::move(values))
    {
    }

    ~Point() = default;

    Point(const Point&) = default;
    Point(Point&&) = default;

    Point& operator=(const Point&) = default;
    Point& operator=(Point&&) = default;

    template <class U> bool operator==(const Point<U, N>& p2) const
    {
        return std::equal(begin(m_values), end(m_values), begin(p2.m_values));
    }

    T& operator[](std::size_t index)
    {
        return m_values[index];
    }

    T operator[](std::size_t index) const
    {
        return m_values[index];
    }

private:
    Container m_values;
};

template <class T, class U, std::size_t N> auto operator+(Point<T, N> p1, const Point<U, N>& p2)
{
    using ResType = Point<decltype(T{} + U{}), N>;
    typename ResType::Container res;
    for(std::size_t i = 0; i < N; i++)
        res[i] = p1[i] + p2[i];
    return ResType{res};
}

template <class T, class U, std::size_t N> auto operator*(Point<T, N> p, const U& factor)
{
    using ResType = Point<decltype(T{} * U{}), N>;
    typename ResType::Container res;
    for(std::size_t i = 0; i < N; i++)
        res[i] = p[i] * factor;
    return ResType{res};
}

template <class T, class U, std::size_t N> auto operator*(const U& factor, Point<T, N> p)
{
    using ResType = Point<decltype(T{} * U{}), N>;
    typename ResType::Container res;
    for(std::size_t i = 0; i < N; i++)
        res[i] = p[i] * factor;
    return ResType{res};
}

} // namespace EvolutionaryWalker::LibUtils
