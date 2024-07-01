#include <iostream>
#include <unordered_map>
#include <ctime>
using namespace std;

class SnakeAndLadder {
private:
    unordered_map<int, int> snakes;//to store the position of snakes for constant time lookup on avg
    unordered_map<int, int> ladders;

public:
    void addSnake(int head, int tail) {
        snakes[head] = tail;
    }

    void addLadder(int start, int end) {
        ladders[start] = end;
    }

    int rollDice() {
        return (rand() % 6) + 1;//rand is random
    }

    void playGame() {
        int playerPosition = 0;
        srand(time(0));//srand is unsigned int 

        while (playerPosition < 100) {
            int dice;
            cout << "Press Enter to roll the dice: ";
            cin.ignore(); // Ignore the newline character
            dice = rollDice();
            cout << "You rolled a " << dice << endl;

            playerPosition += dice;

            if (snakes.find(playerPosition) != snakes.end()) {
                cout << "Oops! You landed on a snake. You move down to " << snakes[playerPosition] << endl;
                playerPosition = snakes[playerPosition];
            } else if (ladders.find(playerPosition) != ladders.end()) {
                cout << "Yay! You landed on a ladder. You move up to " << ladders[playerPosition] << endl;
                playerPosition = ladders[playerPosition];
            }

            if (playerPosition > 100) {
                playerPosition = 100 - (playerPosition - 100);
            }

            cout << "Your current position is " << playerPosition << endl;
        }

        cout << "Congratulations! You won!" << endl;
    }
};

int main() {
    SnakeAndLadder game;
    game.addSnake(16, 6);
    game.addSnake(47, 26);
    game.addSnake(49, 11);
    game.addSnake(56, 53);
    game.addSnake(62, 19);
    game.addSnake(64, 60);
    game.addSnake(87, 24);
    game.addSnake(93, 73);
    game.addLadder(1, 38);
    game.addLadder(4, 14);
    game.addLadder(9, 31);
    game.addLadder(21, 42);
    game.addLadder(28, 84);
    game.addLadder(36, 44);
    game.addLadder(51, 67);
    game.addLadder(71, 91);
    game.addLadder(80, 100);

    cout << "Welcome to Snake and Ladder game!" << endl;
    cout << "Try to reach position 100." << endl;

    game.playGame();

    return 0;
}
