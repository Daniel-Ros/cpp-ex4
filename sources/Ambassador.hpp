#pragma once
#include "Player.hpp"
namespace coup
{
    class Ambassador : public Player
    {
    public:
        Ambassador(Game&,std::string);
        ~Ambassador();

        virtual std::string role(){return "Ambassador";}

        void transfer(Player&,Player&);
        void block(Player&);
    private:

    };
} // namespace coup