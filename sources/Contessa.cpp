#include "Contessa.hpp"

namespace coup
{
    Contessa::Contessa(Game& g,std::string name):Player(g,std::move(name))
    {

    }

    Contessa::~Contessa()
    {

    }

    void Contessa::block(Player& player)
    {
        if(player.getLastAction().starts_with("coup_"))
        {
            std::string str = player.getLastAction();
            std::string playerName = str.substr(str.find('_') +1,str.length());
            game.uncoup(playerName);
        }
        else
        {
            throw std::logic_error("what?");
        } 
    }

} // namespace coup