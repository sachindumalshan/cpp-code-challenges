// C++ Code Challenges, LinkedIn Learning

// Challenge #14: The Reflex Game
// Write an application that waits a random delay between 4 and 10 seconds, and then asks the user to type in a random word.
// This random word comes from a list of 10 3-letter words.
// If the user enters the correct word in less than 2 seconds, print a success message on the screen.
// Otherwise, print a failure message.
// Ignore the case ("CAT" = "cat" = "CaT").

#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
 
std::string words[10]={"CAT","RAT","BAT","CAP","BAG","RAG","RAP","BET","BEG","LET"};

// The Reflex Game, main()
// Summary: This application measures the time it takes a user to type in a random 3-letter word.
int main(){
    std::cout << "\n";
    std::cout << "                   The Reflex Game\n";
    std::cout << "                   === ====== ====\n";
    std::cout << "After a random delay, you'll be asked to type in a 3-letter word.\n";
    std::cout << "When that happens, type in the word as fast as you can, and hit Enter.\n";
    std::cout << "Don't worry about the character case (\"CAT\" = \"cat\" = \"CaT\").\n\n";
    std::cout << "            Press Enter when you're ready to start." << std::flush;

    std::string try_again;
    std::cout << '\n';
    do{
        int r_number = rand() % 10;
        std::cout << "Random Word: " << words[r_number] << std::endl;
        std::string input_word;

        auto start = std::chrono::system_clock::now();
        std::cout << "Enter the word: ";
        std::cin >> input_word;
        auto end = std::chrono::system_clock::now();

        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start);

        std::transform(input_word.begin(),input_word.end(),input_word.begin(),::toupper);
        if((words[r_number] == input_word) && elapsed.count() <= 2)
            std::cout << "success" << std::endl;
        else
            std::cout << "failure" << std::endl;

        std::cout << "Try again? (Y/N): ";
        std::cin >> try_again;
    }while(try_again[0]=='Y' || try_again[0]=='y');
    return 0;
}
