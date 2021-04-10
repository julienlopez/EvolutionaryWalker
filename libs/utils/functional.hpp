#pragma once

#include <utility>

namespace EvolutionaryWalker::LibUtils::Functional
{

template <class T> struct Not
{
    Not(T t)
        : m_t(std::move(t))
    {
    }

    template <class... Args> bool operator()(Args&&... args) const
    {
        return !m_t(std::forward<Args>(args)...);
    }

private:
    T m_t;
};

} // namespace EvolutionaryWalker::LibUtils::Functional
