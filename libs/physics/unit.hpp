#pragma once

#include <boost/units/quantity.hpp>

#include <boost/units/systems/si/acceleration.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/mass.hpp>
#include <boost/units/systems/si/time.hpp>
#include <boost/units/systems/si/velocity.hpp>
#include <boost/units/systems/si/force.hpp>

namespace EvolutionaryWalker::Physics
{

using TimeQuantity = boost::units::quantity<boost::units::si::time, double>;
using LengthQuantity = boost::units::quantity<boost::units::si::length, double>;
using VelocityQuantity = boost::units::quantity<boost::units::si::velocity, double>;
using AccelerationQuantity = boost::units::quantity<boost::units::si::acceleration, double>;
using MassQuantity = boost::units::quantity<boost::units::si::mass, double>;
using ForceQuantity = boost::units::quantity<boost::units::si::force, double>;

} // namespace EvolutionaryWalker::Physics
