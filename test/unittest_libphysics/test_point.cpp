#include <catch2/catch.hpp>

#include "unit.hpp"

#include "point.hpp"

#include <variant>

using EvolutionaryWalker::LibUtils::Point;
using EvolutionaryWalker::Physics::LengthQuantity;

namespace
{

using PointTypes = std::variant<Point<int, 2>, Point<double, 2>/*, Point<LengthQuantity, 2>*/>;

class PointTypesGenerator : public Catch::Generators::IGenerator<PointTypes>
{
public:
    PointTypesGenerator()
        : m_values{Point<int, 2>{{1, 2}}}
    {
    }

    virtual PointTypes const& get() const override
    {
        return m_values[m_current_index];
    }

    virtual bool next() override
    {
        m_current_index++;
        return m_current_index < m_values.size();
    }

private:
    const std::vector<PointTypes> m_values;
    std::size_t m_current_index = 0;
};

Catch::Generators::GeneratorWrapper<PointTypes> allPointsTypes()
{
    return Catch::Generators::GeneratorWrapper<PointTypes>(std::make_unique<PointTypesGenerator>());
}

} // namespace

TEST_CASE("Basic uses of Utils::Point2d", "[utils][physics]")
{
    const auto input = GENERATE(allPointsTypes());
    std::visit([](const auto& input) {
        SECTION("multiplication and addition")
        {
            const auto res1 = 2 * input;
            const auto res2 = input + input;
            CHECK(res1 == res2);
        }
        },
        input);
}
