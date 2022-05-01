#include "Duke.hpp"
#include "Game.hpp"

#include <iostream>

using namespace coup;
using namespace std;
int main()
{
    Game g{};
    Duke duke{g,"Daniel"};

    vector<string> players = g.players();

    duke.income();
    cout << duke.getLastAction();
}