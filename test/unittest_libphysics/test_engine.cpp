#include <catch2/catch.hpp>

#include "engine.hpp"

#include <iostream>
#include <boost/units/io.hpp>

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
        Engine e{9.61 * meters_per_second_squared};
        const auto ref = e.addFixedNode({{0 * meters, 10 * meters}});
        const auto p = e.addNode({{0 * meters, 0 * meters}}, 1 * kilograms);
        e.addSpring(ref, p, {5 * meters, 1 * meters_per_second_squared});

        e.init();
        const auto step = .0001 * seconds;
        for(std::size_t i = 0; i < 100; i++)
        {
            e.step(step);
            std::cout << "y(" << ((double)i * step) << ") = " << e.node(p)[1] << std::endl;
        }
    }
}