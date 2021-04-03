#pragma once

#include <boost/units/quantity.hpp>
#include <boost/units/systems/si/time.hpp>

namespace EvolutionaryWalker::Physics
{

	using TimeQuantity = boost::units::quantity<boost::units::si::time, double>;

}
