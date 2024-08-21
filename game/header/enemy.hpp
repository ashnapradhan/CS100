#pragma once
#include <iostream>
#include <string>
#include <vector>
//#include "character.hpp"

using namespace std;

class Enemy {
 private:
    vector<string> asciiFiles;
    int hp, atk, difficulty;
    string name;
    string defaultMove1Name;
    string defaultMove2Name;
    
 public:
    Enemy();
    Enemy(const string& name, int hp, int atk, int difficulty);
    const string& getName() const;
    //void getEnemyArt();
    int getMaxHP();
    int getHP();
    int getATK();
    void setHP(int n);
    void setATK(int n);
    void setName(string n);
    const string& getMove1Name();
    const string& getMove2Name();
    // move1
    // move2 
    
    int getDifficulty();
    
};