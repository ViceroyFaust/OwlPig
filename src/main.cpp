#include <iostream>
#include <stdlib.h>
#include <time.h>

class Player {
private:
public:
    int bankedPoints;
    int currentPoints;
    Player() : bankedPoints(0), currentPoints(0) {};
};

// A standard 6-sided die
class Die {
private:
public:
    Die() {
        srand(time(NULL));
    }
    
    int roll() {
        return 1 + rand() % 6;
    }
};

void turn();

int main() {
    Player p1;
    Player p2;
    Die die;
    bool gameOver = false;
    for (unsigned int i = 1; !gameOver; i = 1 + i % 2) {
        std::cout << "Player " << i << "'s turn\n"
            << "----------------\n";
        bool finished = false;
        std::string choice = ""; 
        Player& curPlayer = (i == 1) ? p1 : p2;
        while (!finished) {
            std::cout << "Points: " << curPlayer.currentPoints << "; Banked Points: " << curPlayer.bankedPoints
                << "\nroll or bank?\n";
            std::cin >> choice;
            if (choice == "roll") {
                int roll = die.roll();
                std::cout << roll << "\n";
                if (roll > 1) {
                    curPlayer.currentPoints += roll;
                } else {
                    curPlayer.currentPoints = 0;
                    finished = true;
                    std::cout << "\n";
                }
            } else if (choice == "bank") {
                curPlayer.bankedPoints += curPlayer.currentPoints;
                curPlayer.currentPoints = 0;
                finished = true;
                std::cout << "\n";
            } else if (choice == "quit") {
                finished = true;
                gameOver = true;
            } else {
                std::cout << "Unrecognised command\n";
            }
        }
        if (curPlayer.bankedPoints >= 100) {
            std::cout << "player " << i << " wins!\n";
            finished = true;
            gameOver = true; 
        }
    }
    return 0;
}