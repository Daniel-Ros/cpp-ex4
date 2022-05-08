#include "Assassin.hpp"
namespace coup{
    Assassin::Assassin(Game& g,std::string name):Player(g,std::move(name))
    {

    }

    Assassin::~Assassin()
    {

    }

    void Assassin::coup(Player& player)
    {
        const int min_coup = 7;
        const int min_assasin_coup = 3;
        checkMyTurn(true);
        if(!player.isAlive()){
            game.cancelTurn();
            throw std::logic_error("player ded");
        }
        if(money >= min_coup)
        {
            game.coup(player.getName());
            lastAction = "coup";
            money -= min_coup;
        }
        else if(money >=min_assasin_coup)
        {
            game.coup(player.getName());
            lastAction = "coup_" + player.getName();
            money -= min_assasin_coup;
        }
        else{
            game.cancelTurn();
            throw std::logic_error("not enoguht money to coup");
        }
    }
}