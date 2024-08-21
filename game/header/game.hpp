#pragma once

#include <iostream>
#include <string>
#include "../header/player.hpp"

using std::cout;
using std::endl;
using std::string;

class Game {
    private:
        int classNumber;
        int distanceFromFinalBoss = 15;
        Player player; 
    
    public:
        Game();
        void intro(); // ask for and read in player name, ask for and assign player a class
        void outro(); 
        int getDisanceFromFinalBoss(); // return distanceFromFinalBoss
        void travelCloserToFinalBoss(); // subtract 1-2 from distanceFromFinalBoss
        void startEncounter();
        void randomOutcome();
        void startFight();
        void startFinalBoss();
        
        // helper functions
        void printLargerSpacer() { // prints 25 new lines
            for (int i = 0; i < 25; i++) {
                cout << endl;
            }
        }

        void wait(double seconds) { // delays program by n seconds by being stuck in a while loop
            time_t startTime;
            time(&startTime);
            time_t currentTime;
            while (true) {
                time(&currentTime);
                if (difftime(currentTime, startTime) >= seconds) {
                    break;
                }
            }
        }

};
