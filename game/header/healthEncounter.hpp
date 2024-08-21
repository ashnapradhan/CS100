#pragma once

#include <string>
#include <iostream>

using std::string;

class healthEncounter {
 private:
     string prompt;
     string option1;
     string option2;
     int healAmount1;
     int healAmount2;
 public:
    healthEncounter(string p, string o1, string o2, int h1, int h2);
    const string& getPrompt() const;
    const string& getOption1() const;
    const string& getOption2() const;
    int gethealAmount1();
    int gethealAmount2();
    int getResult(int choice);
     
};
