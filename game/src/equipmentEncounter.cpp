#include "../header/equipmentEncounter.hpp"


equipmentEncounter::equipmentEncounter(string p, string o1, string o2, int oi1, int oi2) {
    prompt = p;
    option1 = o1;
    option2 = o2;
    outcomeIndex1 = oi1;
    outcomeIndex2 = oi2;
}

const string& equipmentEncounter::getPrompt() const {
    return prompt;
}

const string& equipmentEncounter::getOption1() const {
    return option1;
}

const string& equipmentEncounter::getOption2() const {
    return option2;
}

int equipmentEncounter::getResult(int choice) const {
    if (choice == 1) {
        return outcomeIndex1;
    }
    else if (choice == 2) {
        return outcomeIndex2;
    }
    throw std::runtime_error("Did not choose option 1 or 2.");
}
