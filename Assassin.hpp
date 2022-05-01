#pragma once
#include "Player.hpp"
namespace coup
{
    class Assassin : public Player
    {
    public:
        Assassin(Game&,std::string);
        ~Assassin();

        virtual std::string role(){return "Assassin";}

        void coup(Player&){}
    private:

    };
} // namespace coup