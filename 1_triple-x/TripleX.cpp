#include <iostream>
#include <ctime>

// Functions (that aren't acccessors) are named with
// UpperCamelCase according to Google C++ style guide
void PrintIntroduction(int difficulty) 
{
    std::cout << "You are a secret agent breaking into a secure server room #" << difficulty << std::endl;
    std::cout << "Enter the correct code to continue...";
}

bool PlayGame(int difficulty) {
    // We need to initialize rand() with a different seed
    // This is essentially shuffling a deck of cards.
    // Best way to do this is based on your computer's time
    srand(time(NULL)); // creates new random sequence based on time of day
    // If you don't add that, you'll get the same sequence 
    // every time

    PrintIntroduction(difficulty);


    // The correct code that the user is trying to guess
    const int a = rand()%difficulty + difficulty;
    const int b = rand()%difficulty + difficulty;
    const int c = rand()%difficulty + difficulty;

    const int sum = a + b + c;
    const int product = a * b * c;

    std::cout << std::endl;
    std::cout << "There are 3 digits in the code.\n";
    std::cout << "The sum of the digits are: " << sum << "\n";
    std::cout << "The product of the digits are: " << product << "\n";

    int guess_a, guess_b, guess_c;
    std::cout << "Enter your guess: ";
    // You don't have to enter these separately; you can
    // type out each digit separated by a space
    std::cin >> guess_a;
    std::cin >> guess_b;
    std::cin >> guess_c;
    std::cout << "You entered " << guess_a << guess_b << guess_c << std::endl;

    // Calculate sum and product of the guess
    int guess_sum = guess_a + guess_b + guess_c;
    int guess_prod = guess_a * guess_b * guess_c;

    if (guess_sum == sum && guess_prod == product)
    {
        std::cout << "You win! Proceeding to next level.\n";
        return true;
    }
    else
    {
        std::cout << "***You entered the wrong code, careful! Let's try again.\n";
        return false;
    }
}

int main()
{
    // Google C++ style guide: leading "k" followed by
    // mixed case for all constants
    const int kMaxLevel = 5;
    int level_difficulty = 1;
    while (level_difficulty <= 5) 
    {
        // All boolean variables should be prefixed with b
        bool b_level_complete = PlayGame(level_difficulty);
        std::cin.clear(); // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (b_level_complete)
        {
            // Increase the level difficulty
            ++level_difficulty;

        }
    }

    std::cout << "CONGRATS ON WINNING!" << std::endl;

    // A zero means that the program has run successfully
    return 0;
}