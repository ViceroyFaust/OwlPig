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
    std::cout << "Player 1's turn\n";
    bool finished = false;
    std::string choice = ""; 
    while (!finished) {
        std::cout << "Points: " << p1.currentPoints << "; Banked Points: " << p2.bankedPoints
            << "\nroll or bank?\n";
        std::cin >> choice;
        if (p1.bankedPoints >= 100) {
            std::cout << "player 1 wins!\n";
            break;
        } 
        if (choice == "roll") {
            int roll = die.roll();
            std::cout << roll << "\n";
            if (roll > 1) {
                p1.currentPoints += roll;
            } else {
                p1.currentPoints = 0;
                finished = true;
            }
        } else if (choice == "bank") {
            p1.bankedPoints = p1.currentPoints;
            p1.currentPoints = 0;
            finished = true;
        }
    }
    return 0;
}