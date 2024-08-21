#include "../header/prompter.hpp"
#include "../header/enemy.hpp"
#include "../header/healthEncounter.hpp"
#include "../header/fightEncounter.hpp"

Prompter::Prompter() {
    fightEncounterList.push_back(FightEncounter("prompt",
    "option1", "option2", "response1", "response2", Enemy("Cyclops", 15, 3, 1), Enemy("Sphinx", 20, 2, 1)));

    healthEncounterList.push_back( healthEncounter("prompt", "option1", "option2", 2, 3));
}

void Prompter::runFightEncounter(int dist, Player &player) { //parameters: distance and player
    int playerChoice;
    //int randNum = rand() % fightEncounterList.size();
    int index = 0;

    //Determine the encounter's dfficulty based off distance (Tackle this later)


    std::cout << fightEncounterList[index].getPrompt() << std::endl; //output prompt

    std::cout << "Do you:" << std::endl;
    std::cout << "1. " << fightEncounterList[index].getChoice1() << std::endl;
    std::cout << "2. " << fightEncounterList[index].getChoice2() << std::endl;

    if (!(std::cin >> playerChoice)) {
        throw std::runtime_error("Error reading choice.");
    } else if (playerChoice != 1 && playerChoice != 2) {
        throw std::runtime_error("Did not enter 1 or 2.");
    }

    if (playerChoice == 1) {
        std::cout << fightEncounterList[index].getResponse1() << std::endl;
        //getEnemy1 and player?, run it through fightSystem start
    } else {
        std::cout << fightEncounterList[index].getResponse2() << std::endl;
        //getEnemy2 and player?, run it through fightSystem start
    }
}

void Prompter::runHealthEncounter( Player &player) {
    int playerChoice;
    int index = 0;

    std::cout << healthEncounterList[index].getPrompt() << std::endl;
    
    std::cout << "Do you:" << std::endl;
    std::cout << "1. " << healthEncounterList[index].getOption1() << std::endl;
    std::cout << "2. " << healthEncounterList[index].getOption1() << std::endl;

    if (!(std::cin >> playerChoice)) {
        throw std::runtime_error("Error reading choice.");
    } else if (playerChoice != 1 && playerChoice != 2) {
        throw std::runtime_error("Did not enter 1 or 2.");
    }

    std::cout << "You've healed by "; 
    if (playerChoice == 1) {
        std::cout << healthEncounterList[index].gethealAmount1() << std::endl;
        // update player health with healAmount1
    } else {
        std::cout << healthEncounterList[index].gethealAmount2() << std::endl;
        // update player health with healAmount2
    }
    std::cout << " health points!" << std::endl;
}
