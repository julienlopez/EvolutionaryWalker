#include "engine.hpp"

namespace EvolutionaryWalker::Physics
{

void Engine::step(TimeQuantity /*time_step*/)
{
}

NodeIndex Engine::addFixedNode()
{
    return NodeIndex{0};
}

NodeIndex Engine::adddNode()
{
    return NodeIndex{0};
}

SpringIndex Engine::addSpring(const NodeIndex /*node1*/, const NodeIndex /*node2*/)
{
    return SpringIndex{0};
}

} // namespace EvolutionaryWalker::Physics
