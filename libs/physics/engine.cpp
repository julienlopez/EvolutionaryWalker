#include "engine.hpp"

#include <cassert>
#include <vector>

#include <boost/numeric/odeint.hpp>

namespace EvolutionaryWalker::Physics
{

namespace Impl
{

    class Engine
    {
    public:
        using VelocityVector = LibUtils::Point<VelocityQuantity, 2>;
        using VelocityVector = LibUtils::Point<VelocityQuantity, 2>;
        using AccelerationVector = LibUtils::Point<AccelerationQuantity, 2>;
        using state_type = std::vector<std::pair<Point2d, VelocityVector>>;
        using deriv_type = std::vector<std::pair<VelocityVector, AccelerationVector>>;
        using StepperType = boost::numeric::odeint::runge_kutta4<state_type, double, deriv_type, TimeQuantity>;
        // using StepperType = boost::numeric::odeint::runge_kutta4<
        //     state_type, double, deriv_type, TimeQuantity,
        //     typename boost::numeric::odeint::algebra_dispatcher<state_type>::algebra_type,
        //     typename boost::numeric::odeint::operations_dispatcher<state_type>::operations_type,
        //     boost::numeric::odeint::never_resizer>;

        struct Node
        {
            bool is_fixed;
            MassQuantity mass;
            Point2d position;
            VelocityVector speed;
        };

        struct Spring
        {
            std::array<NodeIndex, 2> nodes;
            SpringCharacteristics characteristics;
        };

        Engine(AccelerationQuantity gravity)
            : m_gravity(std::move(gravity))
        {
        }

        ~Engine() = default;

        void init()
        {
            m_stepper = std::make_unique<StepperType>(/*currentState()*/);
        }

        void step(TimeQuantity /*time_step*/)
        {
            assert(m_stepper);
            // rk.do_step(sys1, inout, t, dt);
            // rk.do_step( sys1 , inout , dxdtin , t , dt );
            auto x = currentState();
            // m_stepper.do_step(std::cref(*this), x, TimeQuantity{}, time_step);
            // m_stepper->do_step([](const state_type& /*x*/, deriv_type& /*dxdt*/, const TimeQuantity& /* t */) {}, x,
            //                    TimeQuantity{}, time_step);

            applyNewState(x);
        }

        static VelocityVector nullVelocity()
        {
            return {{0 * boost::units::si::meters_per_second, 0 * boost::units::si::meters_per_second}};
        }

        NodeIndex addFixedNode(Point2d position)
        {
            m_nodes.emplace_back(true, 0 * boost::units::si::kilograms, std::move(position), nullVelocity());
            return NodeIndex{m_nodes.size() - 1};
        }

        NodeIndex addNode(Point2d position, MassQuantity mass)
        {
            m_nodes.emplace_back(false, std::move(mass), std::move(position), nullVelocity());
            return NodeIndex{m_nodes.size() - 1};
        }

        SpringIndex addSpring(const NodeIndex node1, const NodeIndex node2, SpringCharacteristics characteristics)
        {
            m_springs.push_back({{node1, node2}, std::move(characteristics)});
            return SpringIndex{m_nodes.size() - 1};
        }

    private:
        const AccelerationQuantity m_gravity;
        std::vector<Node> m_nodes;
        std::vector<Spring> m_springs;
        std::unique_ptr<StepperType> m_stepper = nullptr;

        void operator()(const state_type& x, deriv_type& dxdt, const TimeQuantity& /* t */) const
        {
            assert(x.size() == dxdt.size());
            for(std::size_t i = 0; i < x.size(); i++)
            {
                // dxdt[i].first = x[i].second;
                // dxdt[i].second = -x[0] - gam * x[1];
            }
        }

        state_type currentState() const
        {
            state_type res;
            for(const auto& node : m_nodes)
            {
                if(node.is_fixed) continue;
                res.push_back(std::make_pair(node.position, node.speed));
            }
            return res;
        }

        void applyNewState(const state_type& /*state*/)
        {
        }
    };

} // namespace Impl

Engine::Engine(AccelerationQuantity gravity)
    : m_pimpl(std::make_unique<Impl::Engine>(std::move(gravity)))
{
}

Engine::~Engine() = default;

void Engine::init()
{
    m_pimpl->init();
}

void Engine::step(TimeQuantity time_step)
{
    m_pimpl->step(time_step);
}

NodeIndex Engine::addFixedNode(Point2d position)
{
    return m_pimpl->addFixedNode(std::move(position));
}

NodeIndex Engine::addNode(Point2d position, MassQuantity mass)
{
    return m_pimpl->addNode(std::move(position), std::move(mass));
}

SpringIndex Engine::addSpring(const NodeIndex node1, const NodeIndex node2, SpringCharacteristics characteristics)
{
    return m_pimpl->addSpring(node1, node2, std::move(characteristics));
}

} // namespace EvolutionaryWalker::Physics
