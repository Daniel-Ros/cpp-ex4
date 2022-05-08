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
        std::string winner();
        Player* getPlayer(const std::string&);

        void coup(const std::string&);
        void uncoup(const std::string&);

        void advance();
        void cancelTurn();
    private:
        friend class Player;
        void addPlayer(Player&);
        std::vector<Player*> playersNames;

        int currentPlayer;
        bool gameStarted;
    };
} // namespace coup