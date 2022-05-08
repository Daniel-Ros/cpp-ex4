#include "Player.hpp"

namespace coup
{
    Player::Player(Game& game,std::string name ): game{game} ,name{std::move(name)} , money{0}, Alive{true}
    {
        game.addPlayer(*this);
    }

    Player::~Player()
    {

    }

    void Player::income()
    {
        checkMyTurn();
        money++;
        lastAction = "income";
    }

    void Player::foreign_aid()
    {
        checkMyTurn();
        money+=2;
        lastAction = "foreign_aid";
    }

    void Player::coup(Player& player)
    {
        const int min_coup = 7;
        checkMyTurn(true);
        if(!player.isAlive()){
            game.cancelTurn();
            throw std::logic_error("plyer ded");
        }
        if(money >= min_coup){
            game.coup(player.name);
            lastAction = "coup";
            money -= min_coup;
        }else{
            game.cancelTurn();
            throw std::logic_error("not enoghut money to coup");
        }
    }

    int Player::coins() const 
    {
        return money;
    }

    void Player::checkMyTurn(bool isCoup)
    {
        const int maxMoneyTocoup = 10;
        if(money > maxMoneyTocoup && !isCoup)
        {
            throw std::logic_error("player need to coup");
        }
        if(game.turn() != name)
        {
            throw std::logic_error("not player turn");
        }
        game.advance();
    }

} // namespace coup