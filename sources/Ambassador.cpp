#include "Ambassador.hpp"

namespace coup{
    Ambassador::Ambassador(Game& g,std::string name):Player(g,std::move(name))
    {

    }

    Ambassador::~Ambassador()
    {

    }

    void Ambassador::transfer(Player& p1,Player& p2)
    {
        checkMyTurn();
        if(p1.getMoney() < 1)
        {
            game.cancelTurn();
            throw std::logic_error("player no mony");
        }
        p1.addMoney(-1);
        p2.addMoney(1);
        lastAction = "transfer";
    }

    void Ambassador::block(Player& p)
    {
        if(p.getLastAction().starts_with("steal"))
        {
            std::string str = p.getLastAction();
            auto f2 = str.find('-');
            auto playerName = str.substr(str.find('_') +1, f2 - str.find('_') - 1);
            Player* player =  game.getPlayer(playerName);
            int money = std::stoi(str.substr(str.find('-') + 1,str.length()));
            player->addMoney(money);
            p.addMoney( 0-money);
        }
        else
        {
            throw std::logic_error("what?");
        } 
    }
}