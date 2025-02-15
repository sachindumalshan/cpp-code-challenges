// C++ Code Challenges, LinkedIn Learning

// Challenge #15: JSON File Validation
// Write an application that reads a JSON file and checks if it's valid or not.
// Test the bracket balance (curly and square), and quote balance. 
// Assume simple content with no escape characters inside strings.
// Only count double quotes ("), not single quotes (').
// The application outputs a message indicating if the JSON file passed the tests or not.

#include <iostream>
#include <fstream>
#include <string>
#include <stack>


// is_valid_JSON()
// Summary: This function returns true if the file in the argument is a valid JSON file based on its balance of braces, brackets, and quotes.
// Arguments:
//           filename: A string with the name of the file to open.
// Returns: An integer enconding: 1 for valid JSON files, 0 for invalid, and -1 on failure to open file.

std::stack <std::string> sentences;
std::stack <char> signs;


int is_valid_JSON(std::string filename){
    std::string line;
    bool quotes = false;

    std::fstream file (filename, std::ios::in);
    if(file.is_open()){
 
        while(!file.eof()){
            getline(file,line);
            //std::cout << line << std::endl;
            sentences.push(line);
        }        
        file.close();
    }
    else
        return -1;
    
    int cv = sentences.size();
    for(int i=0;i<cv;i++){
        line = sentences.top();
        sentences.pop();
        for(int j=0; j<line.length();j++){
            if(!signs.empty()){
                // std::cout << signs.top() << std::endl;
                char temp = signs.top();
                char temp2 = line[j];
                if(temp == temp2){
                    signs.push(temp2);
                }
                else if(temp2 == '}' || temp2 == '{') signs.pop();
                else continue;
            }
            else{
                if(line[j] == '}' || line[j] == '{')
                    signs.push(line[j]);
            }
        }        
    }
    std::cout << signs.size() << std::endl;
}

//|| line[j] == '[' || line[j] == ']' || line[j] == '"'

// JSON File Validation, main()
int main(){
    int x = is_valid_JSON("jason.json");

    if(x == 1)
        std::cout << "The JSON file is valid!\n\n";
    else if(x == 0)
        std::cout << "The JSON file is invalid!\n\n";
    else
        std::cout << "Could not open the file!\n\n";  
    std::cout << std::flush;
    return 0;
}
 