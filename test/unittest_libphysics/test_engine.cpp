#include <catch2/catch.hpp>

#include "engine.hpp"

using EvolutionaryWalker::LibUtils::Point;
using EvolutionaryWalker::Physics::Engine;
using EvolutionaryWalker::Physics::LengthQuantity;

namespace
{

}

TEST_CASE("Basic uses of Physics::Engine", "[physics]")
{
    using boost::units::si::meters;
    using boost::units::si::seconds;
    using boost::units::si::kilograms;
    using boost::units::si::meters_per_second_squared;

    SECTION("Basic spring oscillator")
    {
        Engine e;
        const auto ref = e.addFixedNode({{0 * meters, 10 * meters}});
        const auto p = e.addNode({{0 * meters, 0 * meters}}, 1 * kilograms);
        e.addSpring(ref, p, {5 * meters, 1 * meters_per_second_squared});

        e.init();
        e.step(.0001 * seconds);
    }
}