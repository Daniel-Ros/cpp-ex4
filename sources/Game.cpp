#include "Game.hpp"
#include "Player.hpp"
namespace coup
{
    void Game::addPlayer(Player& name)
    {
        const int maxPlayers = 6;
        if(playersNames.size() < maxPlayers && !gameStarted){
            playersNames.push_back(&name);
        }else{
            throw std::logic_error(" to many players");
        }
    }

    void Game::coup(const std::string& player)
    {
        getPlayer(player)->kill();
    }

    void Game::uncoup(const std::string& player)
    {
        getPlayer(player)->Restore();
    }


    std::string Game::winner()
    {
        if(!gameStarted)
        {
            throw std::logic_error("Game not started");
        }
        int i = 0;
        for(auto* player : playersNames)
        {
            if(player->isAlive()){
                i++;
            }
            if(i > 1){
                throw std::logic_error("Game still running");
            }
        }
        for(auto* player : playersNames)
        {
            if(player->isAlive()){
                return player->getName();
            }
        }
        return "";
    }

    std::string Game::turn()
    {
        if(playersNames.size() < 2) {return "";}
        while(!playersNames.at((unsigned long)currentPlayer)->isAlive()){
            advance();
        };
        return playersNames.at((unsigned long)currentPlayer)->getName();
    }

    std::vector<std::string> Game::players() const
    {
        std::vector<std::string> names;
        for(auto* p : playersNames)
        {
            if(p->isAlive()){
                names.push_back(p->getName());
            }
        }
        return names;
    }

    Player* Game::getPlayer(const std::string& name)
    {
        for(auto* p : playersNames)
        {
            if(p->getName() == name)
            {
                return p;
            }
        }
        return nullptr;
    }

    void Game::advance(){
        gameStarted = true;
        currentPlayer = (currentPlayer + 1);
        if(currentPlayer >= playersNames.size()){
            currentPlayer = 0;
        }
    }
    void Game::cancelTurn(){
        currentPlayer = (currentPlayer - 1);
        if(currentPlayer < 0){
            currentPlayer = (int)playersNames.size() - 1;
        }
    }

} // namespace coupcl