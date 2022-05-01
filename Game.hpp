#pragma once
#include <string>
#include <vector>
#include <algorithm>
namespace coup
{
    class Player;
    class Game
    {
    public:
        Game() = default;
        ~Game() = default;

        std::vector<std::string> players() const;
        std::string turn();
        Player* getPlayer(std::string);

    private:
        friend class Player;

        void addPlayer(Player&);
        void coup(std::string,std::string);
        std::vector<Player*> playersNames;

        int currentPlayer;
    };
} // namespace coup