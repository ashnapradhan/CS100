#include <iostream>
#include <string>
#include <stdexcept>

using std::string;

class equipmentEncounter {
    private:
        string prompt;
        string option1;
        string option2;
        int outcomeIndex1;
        int outcomeIndex2;
    public:
        equipmentEncounter(string, string, string, int, int);
        const string& getPrompt() const;
        const string& getOption1() const;
        const string& getOption2() const;
        int getResult(int choice) const;

};
