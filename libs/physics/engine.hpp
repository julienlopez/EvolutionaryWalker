#pragma once

#include "unit.hpp"

#include "strongtype.hpp"

namespace EvolutionaryWalker::Physics
{

struct NodeIndex : LibUtils::StrongType<std::size_t, NodeIndex>,
                   LibUtils::Ops<NodeIndex, LibUtils::Eq>,
                   LibUtils::Ops<NodeIndex, LibUtils::Comp>
{
    explicit NodeIndex(const std::size_t val)
        : LibUtils::StrongType<std::size_t, NodeIndex>(val)
    {
    }
};

struct SpringIndex : LibUtils::StrongType<std::size_t, SpringIndex>,
                     LibUtils::Ops<SpringIndex, LibUtils::Eq>,
                     LibUtils::Ops<SpringIndex, LibUtils::Comp>
{
    explicit SpringIndex(const std::size_t val)
        : LibUtils::StrongType<std::size_t, SpringIndex>(val)
    {
    }
};

class Engine
{
public:
    Engine() = default;

    ~Engine() = default;

    void step(TimeQuantity time_step);

    NodeIndex addFixedNode();

    NodeIndex adddNode();

    SpringIndex addSpring(const NodeIndex node1, const NodeIndex node2);
};

} // namespace EvolutionaryWalker::Physics
