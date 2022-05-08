#pragma once
#include "Player.hpp"
namespace coup
{
    class Contessa : public Player
    {
    public:
        Contessa(Game&,std::string);
        ~Contessa();

        virtual std::string role(){return "Contessa";}

        void block(Player&);
    private:

    };
} // namespace coup