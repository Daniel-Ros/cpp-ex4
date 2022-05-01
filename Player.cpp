#include "Player.hpp"

namespace coup
{
    Player::Player(Game& game,std::string name ): game{game}
    {

    }

    Player::~Player()
    {

    }

    void Player::income()
    {
    }

    void Player::foreign_aid()
    {
    }

    void Player::coup(Player& player)
    {

    }

    int Player::coins()
    {
        return money;
    }

} // namespace coup