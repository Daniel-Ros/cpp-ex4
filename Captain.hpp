#pragma once
#include "Player.hpp"
namespace coup
{
    class Captain : public Player
    {
    public:
        Captain(Game&,std::string);
        ~Captain();

        virtual std::string role(){return "Captain";}

        void steal(Player&){}
        void block(Player&){}
    private:

    };
} // namespace coup