//Write a program where the program chooses a number between 1 and 100. The player is then asked to enter a guess.
//If the player guesses wrong, then the program gives feedback and ask to enter an other guess until the guess is correct.

//Make the range customizable (ask for it before starting the guessing).
//You can add lives. (optional)

#include <iostream>
#include <time.h>

int main() {

    int lowest;
    int biggest;

    std::cout << "Give me the lowest number you wanna guess between! " << std::endl;
    std::cin >> lowest;
    std::cout << "And then give me the biggest number! " << std::endl;
    std::cin >> biggest;

    srand (time(NULL));
    int number;
    number = rand() % biggest + lowest;
    int guess;
    do {
        std::cout << "Now make a guess! " << std::endl;
        std::cin >> guess;
        if (guess < number)
            std::cout << "The random number is bigger! " << std::endl;
        if (guess > number)
            std::cout << "The random number is smaller! " << std::endl;
        if (guess == number)
            std::cout << "Congratulations, you guessed the number right! " << std::endl;
    } while (guess != number);
    return 0;
}