#include "Captain.hpp"
namespace coup{
    Captain::Captain(Game& g,std::string name):Player(g,std::move(name))
    {

    }

    Captain::~Captain()
    {

    }

    void Captain::steal(Player& player)
    {   
        checkMyTurn();
        if(player.getMoney() < 2){
            addMoney(player.getMoney());
            player.addMoney( 0 - player.getMoney());
            lastAction = "steal_" + player.getName() + "-" + std::to_string(player.getMoney()); 
        }else{
            player.addMoney(-2);
            addMoney(2);
            lastAction = "steal_" + player.getName() + "-" + std::to_string(2); 
        }
    }

    void Captain::block(Player& p)
    {
        if(p.getLastAction().starts_with("steal"))
        {
            std::string str = p.getLastAction();
            Player* player =  game.getPlayer(str.substr(str.find('_') +1,str.find('-')));
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