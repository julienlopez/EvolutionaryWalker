#pragma once

#include "unit.hpp"

#include "point.hpp"
#include "strongtype.hpp"

#include <memory>

namespace EvolutionaryWalker::Physics
{

using Point2d = LibUtils::Point<LengthQuantity, 2>;

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

struct SpringCharacteristics
{
    LengthQuantity rest_length;
    AccelerationQuantity stiffness;
};

namespace Impl
{
    class Engine;
}

class Engine
{
public:

    Engine(AccelerationQuantity gravity = 0 * boost::units::si::metres_per_second_squared);

    ~Engine();

    void init();

    void step(TimeQuantity time_step);

    NodeIndex addFixedNode(Point2d position);

    NodeIndex addNode(Point2d position, MassQuantity mass);

    SpringIndex addSpring(const NodeIndex node1, const NodeIndex node2, SpringCharacteristics characteristics);

    Point2d node(const NodeIndex i) const;

private:
    std::unique_ptr<Impl::Engine> m_pimpl;
};

} // namespace EvolutionaryWalker::Physics
