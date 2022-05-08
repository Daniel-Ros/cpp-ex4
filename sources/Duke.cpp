#include "Duke.hpp"

namespace coup
{
    Duke::Duke(Game& g,std::string name):Player(g,std::move(name))
    {

    }

    Duke::~Duke()
    {

    }

    void Duke::block(Player& p)
    {
        if(p.getLastAction() == "foreign_aid")
        {
            p.addMoney(-2);
        }
        else
        {
            throw std::logic_error("what?");
        }
        lastAction = getLastAction(); // got tidy
    }
    void Duke::tax()
    {
        checkMyTurn();
        addMoney(3);
        lastAction = "tax";
    }
} // namespace coup