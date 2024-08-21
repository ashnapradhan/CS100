#include "../header/healthEncounter.hpp"

healthEncounter::healthEncounter(string p, string o1, string o2, int h1, int h2) {
    string prompt = p;
    string option1 = o1;
    string option2 = o2;
    int healAmount1 = h1;
    int healAmount2 = h2;
}

const string& healthEncounter::getPrompt() const{
    return prompt;
}

const string& healthEncounter::getOption1() const{
    return option1;
}

const string& healthEncounter::getOption2() const{
    return option2;
}

int healthEncounter::gethealAmount1() {
    return healAmount1;
}

int healthEncounter::gethealAmount2() {
    return healAmount2;
}

int healthEncounter::getResult(int choice) {
    return 1;
}