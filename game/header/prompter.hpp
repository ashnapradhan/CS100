#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include "../header/fightEncounter.hpp"
#include "../header/player.hpp"
#include "../header/healthEncounter.hpp"

using std::vector;

class Prompter {
    private: 
        // vector<equipmentEncounter> equipmentEncounterList;
        vector<healthEncounter> healthEncounterList;
        vector<FightEncounter> fightEncounterList;
    public:
        Prompter();
        // void runRandomEncounter(int);
        // void runEquipmentEncounter();
        void runHealthEncounter(Player& player); // need player parameter
        void runFightEncounter(int x, Player& p); //need distance and player as parameter
};