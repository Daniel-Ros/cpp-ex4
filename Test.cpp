/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Daniel
 */

#include "doctest.h"

#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"

#include <exception>

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;


/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.

*/
TEST_CASE("Good input"){
    Game game_1{};

	/* This player drew the "Duke" card, his name is Moshe
	and he is a player in game_1 */
	Duke duke{game_1, "Moshe"};
	Assassin assassin{game_1, "Yossi"};
	Ambassador ambassador{game_1, "Meirav"};
	Captain captain{game_1, "Reut"};
	Contessa contessa{game_1, "Gilad"};

	vector<string> players = game_1.players();

	CHECK(players.size() == 5);

	// prints Moshe
	CHECK(game_1.turn() == "Moshe");

	// throws no exceptions
	CHECK_NOTHROW(duke.income());
	CHECK_NOTHROW(assassin.income());
	CHECK_NOTHROW(ambassador.income());
	CHECK_NOTHROW(captain.income());
	CHECK_NOTHROW(contessa.income());

	// throws exception, it is duke's turn now
	CHECK_THROWS(assassin.income());

	CHECK_NOTHROW(assassin.foreign_aid());
	CHECK_THROWS(captain.block(duke));

	CHECK(duke.coins()==2);
	CHECK(assassin.coins()==2);

	// throws exception, the last operation assassin performed
	// is foreign aid, which cannot be blocked by contessa
	CHECK_THROWS(contessa.block(assassin));


	CHECK_NOTHROW(duke.block(assassin));
	CHECK(assassin.coins()==1);
	CHECK_NOTHROW(ambassador.transfer(duke, assassin));
	CHECK_NOTHROW(contessa.foreign_aid());

	CHECK_NOTHROW(duke.tax());
	CHECK_NOTHROW(assassin.income());
	CHECK_NOTHROW(ambassador.foreign_aid());
	CHECK_NOTHROW(captain.steal(contessa));
	CHECK_NOTHROW(contessa.foreign_aid());

	CHECK_NOTHROW(duke.tax());
	// no exception, assassin can coup with only 3 coins
	CHECK_NOTHROW(assassin.coup(duke));

	players = game_1.players();
	CHECK(players.size() == 4);

	contessa.block(assassin);

	CHECK(players.size() == 5);
}
