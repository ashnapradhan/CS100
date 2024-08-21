#include "../header/game.hpp"
#include "../header/player.hpp"

#include <random>
#include <stdexcept>
#include <time.h>

using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;
using std::string;

Game::Game() {}

void Game::intro() {
    string name;
    int classNumber;

    printLargerSpacer();
    cout << "Hello adventurer, what is thy name?" << endl;

    if (!(cin >> name)) {
        throw runtime_error("intro read name");
    }
    printLargerSpacer();

    cout << "Greeting " << name << "choose your class. [1-3]" << endl;
    cout <<  "1. Swordsman" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Archer" << endl;

    if (!(cin >> classNumber)) {
        throw runtime_error("intro read class");
    }
    printLargerSpacer();

    Player(classNumber, name);

    cout << "Good luck, " << name << " the ";
    if (classNumber == 1) {
        cout << "Swordsman." << endl;
    }
    else if (classNumber == 2) {
        cout << "Mage." << endl;
    }
    else if (classNumber == 3) {
        cout << "Archer." << endl;
    }

    wait(3);
    printLargerSpacer();
 }

 void Game::outro() {
    printLargerSpacer();
    cout << "Congratulations on beating the boss! You have saved this land" << endl;

 }

 int Game::getDisanceFromFinalBoss() {
    return distanceFromFinalBoss;
 }

 void Game::travelCloserToFinalBoss() {
    if (distanceFromFinalBoss == 1) {
        distanceFromFinalBoss--;
    }
    else {
        srand(time(NULL));
        distanceFromFinalBoss -= ((rand() % 2) + 1);
    }
 }

 void Game::startEncounter() {

    // create a vector of string with 10 or so encounter options to randomly output after the first intro encounter

 }

 void Game::randomOutcome() {
    srand(time(NULL));

    int temp = rand() % 100 + 1;

    if (temp <= 30 ) {
        //int healthInc = getHP() + (rand() % 5 + 1);
        //setHP(healthInc);
        //cout << "Congrats you healed " << healthInc << " hp!" << endl;
    }
    else if (temp > 30 && temp <= 60) { // random weapon drop
        string weapon; 
        cout << "Congrats you've received a new weapon: " << endl;
        // show stats
        cout << "Would you like to equip?" << endl;
        cout << "Enter 1. for yes" << "\n" << " 2. for no" << endl;

        int answer;
        if (!(cin >> answer)) {
              throw runtime_error("weapon equip");
        }

        if (answer == 1) {
            // equip weapon
            //setMaxAtk(getMaxAtk() + weapon attack);
        }

    }
    else if (temp > 60 && temp <= 90) { // random armor drop
        string armor;
        cout << "Congrats you've recieved a new armor: " << endl;
        // show stats
        cout << "Would you like to equip?" << endl;
        cout << "Enter 1. for yes" << "\n" << " 2. for no" << endl;

        int answer;
        if (!(cin >> answer)) {
              throw runtime_error("armor equip");
        }

        if (answer == 1) {
            // equip armor
            //seMAxtHP(getMaxHP() + ar attack);
        }
    }
    else if (temp > 90 && temp <= 97) {
        // pot drop (health pot, temp attack increase, etc)
        int ranPotDrop = rand() % 2 + 1;
        if (ranPotDrop == 1) {
            cout << "You've received a health potion (heals 5 health points)" << endl;
        }
        else {
            cout << "You've received an attack potion (increases attack by 5 for 2 turns)" << endl;
        }
    }
    else {
        // one revive potion
        cout << "You've received a revive potion! Use wisely" << endl;
    }
 }

 void Game::startFinalBoss() {
    cout << "You've reached the final boss." << endl;
    cout << "Good luck " << /*name << */ endl;
    // 
 }
        