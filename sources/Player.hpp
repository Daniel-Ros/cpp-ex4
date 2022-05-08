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
        void checkMyTurn(bool isCoup = false);
        //getters
        int coins() const ;
        std::string getLastAction() const {return lastAction;}
        std::string getName() const {return name;}
        bool isAlive() const {return Alive;}
        int getMoney() const {return money;}
        //setters
        void addMoney(int m){ money += m;}
        void kill(){Alive = false;}
        void Restore(){Alive = true;}

        //virtual functions
        virtual std::string role() = 0;
    protected:
        bool Alive;
        Player(Game& ,std::string);
        std::string lastAction;
        int money;
        std::string name;
        Game& game;
    };
} // namespace coup

