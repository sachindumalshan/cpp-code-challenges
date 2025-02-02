#include <iostream>

// vowel_count()
// Summary: This function counts the number of vowels in an incoming string.
// Returns: An integer with the vowel count.
int vowel_count(const std::string str){
    int count=0;
    for(int i=0; i<str.length(); i++)
        switch(str[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            count++;
        }
    return count;
}

// Faulty code, main()
// Summary: This application ask the user for a string, and prints the number of vowels in it.
int main(){
    std::string input; 
    std::cout << "Enter some text: " << std::flush;
    getline(std::cin,input);
    std::cout << "\nThe text you entered contains " << vowel_count(input) << " vowels.\n\n";
}