#pragma once
#include "Player.hpp"
namespace coup
{
    class Duke : public Player
    {
    public:
        Duke(Game&,std::string);
        ~Duke();

        virtual std::string role(){return "Duke";}

        void block(Player&);
        void tax();
    private:

    };
} // namespace coup