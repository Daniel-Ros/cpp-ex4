#pragma once
#include "Game.hpp"

#include <string>
namespace coup
{
    class Player
    {
    public:
        ~Player();
        //actions
        void income();
        void foreign_aid();
        void coup(Player&);
        //getters
        int coins();
        std::string getLastAction(){return lastAction;}
        std::string getName(){return name;}
        //setters
        void addMoney(int m){ money += m;}
        //virtual functions
        virtual std::string role() = 0;
    protected:
        Player(Game& ,std::string);
        std::string lastAction;
        int money;
        std::string name;
        Game& game;
    };
} // namespace coup

