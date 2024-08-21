#include "../header/fightSystem.hpp"
#include "../header/enemy.hpp"

#include <random>
#include <stdexcept>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::string;


void fightSystem::fighting(Enemy enemy, Player& player) {
    fightDisplay(enemy, player);

    while(true) {
        playerTurn(const Enemy& enemy, Player& player);
        if(enemy.getHP() <= 0) {
            break;
        }
        
        cout << "UPDATE FIGHT DISPLAY" << endl;

        enemyTurn(const Enemy& enemy, Player& player);
        if(player.getHP() <= 0) {
            break;
        }

        cout << "UPDATE FIGHT DISPLAY" << endl;
    }

    //DISPLAY WINNER OR LOSER SCREEN

    if (enemy.getHP() == 0) {
        cout << "Congratulations you beat the enemy!" << endl;
    }
    else {
        cout << "You have died" << endl;
        // quit? 
    }
}

void fightSystem::fightDisplay(Enemy& enemy, Player& player) {
    int GAME_SCREEN_SIZE = 80;
    string playerSide, enemySide, playerHPSide, enemyHPSide;

    string playerTitle = player.getName() + " the " + player.getPlayerClass();
    string playerHP = "[HP: " + to_string(player.getHP()) + "/" + to_string(player.getMaxHP()) + "]";
    string enemyHP = "[HP: " + to_string(enemy.getHP()) + "/" + to_string(enemy.getMaxHP()) + "]";

    int playerSideWhiteSpace = (GAME_SCREEN_SIZE/2 - playerTitle.length())/2;
    int enemySideWhiteSpace = (GAME_SCREEN_SIZE/2 - enemy.getName().length())/2;
    int playerHPSideWhiteSpace = (GAME_SCREEN_SIZE/2 - playerHP.length())/2;
    int enemyHPSideWhiteSpace = (GAME_SCREEN_SIZE/2 - enemyHP.length())/2;

    if(playerSideWhiteSpace%2 != 0) { playerSideWhiteSpace++; }
    if(enemySideWhiteSpace%2 != 0) { enemySideWhiteSpace++; }
    if(playerHPSideWhiteSpace%2 != 0) { playerHPSideWhiteSpace++; }
    if(enemyHPSideWhiteSpace%2 != 0) { enemyHPSideWhiteSpace++; }
    
    //First line, player name
    for(int i = 0; i < playerSideWhiteSpace; i++) {
        playerSide += " ";
    }
    playerSide += playerTitle;
    for(int i = 0; i < playerSideWhiteSpace; i++) {
        playerSide += " ";
    }

    //First line, enemy name

    for(int i = 0; i < enemySideWhiteSpace; i++) {
        enemySide += " ";
    }
    enemySide += enemy.getName();
    for(int i = 0; i < enemySideWhiteSpace; i++) {
        enemySide += " ";
    }

    //Second line, player HP

    for(int i = 0; i < playerHPSideWhiteSpace; i++) {
        playerHPSide += " ";
    }
    playerHPSide += playerHP;
    for(int i = 0; i < playerHPSideWhiteSpace; i++) {
        playerHPSide += " ";
    }

    //Second line, enemy HP

    for(int i = 0; i < enemyHPSideWhiteSpace; i++) {
        enemyHPSide += " ";
    }
    enemyHPSide += enemyHP;
    for(int i = 0; i < enemyHPSideWhiteSpace; i++) {
        enemyHPSide += " ";
    }

    //Print name line and HP line
    cout << playerSide << enemySide << endl;
    cout << playerHPSide << enemyHPSide << endl << endl;

    //Print divider
    for(int i = 0; i < GAME_SCREEN_SIZE; i++) {
        cout << "=";
    }

    cout << endl;
}


void fightSystem::playerTurn(Enemy& enemy, Player& player) { //Missing funcitonality for move2 (snipe) turn skip
    int moveChoice;

    cout << "Your Moves:" << endl;
    cout << "1. " << player.getMove1Name() << " - (" << player.getATK() << ")" << endl;
    cout << "2. " << player.getMove2Name() << " - (" << player.getATK()*3 << ", Skip Next Turn)" << endl;

    if (!(cin >> moveChoice)) { //check if moveChoice is either 1 or 2 b/c player is stupid
        throw runtime_error("fightSystem playerTurn cin_read_error");
    }

    if(moveChoice == 1) {
        enemy.setHP(enemy.getHP()-player.getATK());
    } else if(moveChoice == 2) {
        enemy.setHP(enemy.getHP()-(player.getATK()*3));
    }

    //output weapon options
    //output stats
    //damage enemy
    //output damage to enemy
}

void fightSystem::enemyTurn(Enemy& enemy, Player& player) {
    
    player.setHP(player.getHP()-enemy.getATK());

    cout << "UPDATE FIGHT DISPLAY" << endl;

    cout << "The ENEMYNAME dealt X damage to you!" << endl;



    // cout << "The "<< /*[enemy name] << */" takes damage! " << endl;
    //use the change function and change HP by a player's ATK * -1
    //int damage = player.getAtk() * -1;
    //enemy.changeHP(damage);
    //
    //maybe print out how much damage done?
    // cout << "The "<< /*[enemy name] << */ "strikes back! " << endl;
    //int damage2 = enemy.getAtk
    //decrease hp of player and enemy
    //include enemy class?
    //getAtk to inflict damage upon player

    //decrease distance? only during fight end
    //

}

// void createEnemy(int x) {
//     Enemy newEnemy;

//     if (x <= 50 && x >= 40) {
//         newEnemy.setName("Sphinx");
//         newEnemy.setATK(2);
//         newEnemy.setHP(20);
//     }

//     if (x < 40 && x >= 30) {
//         newEnemy.setName("Cyclops");
//         newEnemy.setATK(4);
//         newEnemy.setHP(30);
//     }

//     if (x < 30 && x >= 20) {
//         newEnemy.setName("Chimera");
//         newEnemy.setATK(6);
//         newEnemy.setHP(40);
//     }

//     if (x < 20 && x >= 10) {
//         newEnemy.setName("Sphinx");
//         newEnemy.setATK(8);
//         newEnemy.setHP(50);
//     }

//     if (x = 10 && x > 0) {
//         newEnemy.setName("Medusa");
//         newEnemy.setATK(10);
//         newEnemy.setHP(80);
//     }

//     if (x == 0) {
//         newEnemy.setName("Typhon");
//         newEnemy.setATK(15);
//         newEnemy.setHP(100);
//     }
// }
