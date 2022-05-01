#include "Game.hpp"
#include "Player.hpp"
namespace coup
{
    void Game::addPlayer(Player& name)
    {
        playersNames.push_back(&name);
    }

    void Game::coup(std::string,std::string)
    {
        
    }

    std::string Game::turn()
    {
        return "";
    }

    std::vector<std::string> Game::players() const
    {
        std::vector<std::string> names{};
        return names;
    }

    Player* Game::getPlayer(std::string name)
    {
        return nullptr;
    }

} // namespace coupcl