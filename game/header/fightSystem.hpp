#pragma once

#include "../header/enemy.hpp"
#include "../header/player.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class fightSystem {
 private:
    int GAME_SCREEN_SIZE = 75;
 public:
    void fighting(Enemy enemy, Player& player);
    void fightDisplay(Enemy& enemy, Player& player);
    void playerTurn(Enemy& enemy, Player& player);
    void enemyTurn(Enemy& enemy, Player& player);
};