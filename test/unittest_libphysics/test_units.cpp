#include <catch2/catch.hpp>

#include "unit.hpp"

#include "point.hpp"

using EvolutionaryWalker::LibUtils::Point;
using EvolutionaryWalker::Physics::AccelerationQuantity;
using EvolutionaryWalker::Physics::LengthQuantity;
using EvolutionaryWalker::Physics::TimeQuantity;
using EvolutionaryWalker::Physics::VelocityQuantity;

TEST_CASE("Basic uses of Physics units", "[physics]")
{
    using boost::units::si::kilograms;
    using boost::units::si::meters;
    using boost::units::si::meters_per_second_squared;
    using boost::units::si::seconds;

    SECTION("Basic operations on units")
    {
        const TimeQuantity time_step = 2 * seconds;
        const AccelerationQuantity acc = 5 * meters_per_second_squared;
        const VelocityQuantity vel = acc * time_step;
        const LengthQuantity pos = vel * time_step;
        CHECK(pos == 20 * meters);
        const auto pos2 = 5.0 * pos;
        CHECK(pos2 == 100. * meters);
    }

    SECTION("Basic operations on Points (vectors) of units")
    {
        const TimeQuantity time_step = 2 * seconds;
        const Point<AccelerationQuantity, 2> acc{{5 * meters_per_second_squared, 3 * meters_per_second_squared}};
        const Point<VelocityQuantity, 2> vel = acc * time_step;
        const Point<LengthQuantity, 2> pos = vel * time_step;
        CHECK(pos[0] == 20 * meters);
        CHECK(pos[1] == 12 * meters);
        const auto pos2 = 5.0 * pos;
        CHECK(pos2[0] == 100. * meters);
        CHECK(pos2[1] == 60. * meters);
    }
}
