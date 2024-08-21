#include "../header/fightEncounter.hpp"
#include "../header/enemy.hpp"

FightEncounter::FightEncounter(string p, string o1, string o2, string r1, string r2, Enemy e1, Enemy e2) {
    string prompt = p;
    string option1 = o1;
    string option2 = o2;
    string response1 = r1;
    string response2 = r2;
    Enemy opp1 = Enemy(e1.getName(), e1.getHP(), e1.getATK(), e1.getDifficulty());
    Enemy opp2 = Enemy(e2.getName(), e2.getHP(), e2.getATK(), e2.getDifficulty());
}

    const string& FightEncounter::getPrompt() {
        return prompt;
    }

    const string& FightEncounter::getChoice1() {
        return choice1;
    }

    const string& FightEncounter::getChoice2() {
        return choice2;
    }

    const string& FightEncounter::getResponse1() {
        return response1;
    }

    const string& FightEncounter::getResponse2() {
        return response2;
    }

    Enemy FightEncounter::getEnemy1() {
        return opp1;
    }

    Enemy FightEncounter::getEnemy2() {
        return opp2;
    }