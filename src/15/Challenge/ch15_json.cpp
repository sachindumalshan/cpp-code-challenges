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

std::stack <std::string> sentences1,sentences2,sentences3;
std::stack <char> curly,square,quate;

int is_valid_JSON(std::string filename){
    std::string line;
    bool quotes = false;

    std::fstream file (filename, std::ios::in);
    if(file.is_open()){
 
        while(!file.eof()){
            getline(file,line);
            //std::cout << line << std::endl;
            sentences1.push(line);
            sentences2.push(line);
            sentences3.push(line);
        }        
        file.close();
    }
    else
        return -1;
    
    int cv = sentences1.size();
    for(int i=0;i<cv;i++){
        line = sentences1.top();
        sentences1.pop();
        for(int j=0; j<line.length();j++){
            if(!curly.empty()){
                // std::cout << curly.top() << std::endl;
                char temp = curly.top();
                char temp2 = line[j];
                if(temp == temp2){
                    curly.push(temp2);
                }
                else if(temp2 == '}' || temp2 == '{') curly.pop();
                else continue;
            }
            else{
                if(line[j] == '}' || line[j] == '{')
                    curly.push(line[j]);
            }
        }
    }

    std::cout << curly.size() << " ";

    cv = sentences3.size();
    for(int i=0;i<cv;i++){
        line = sentences3.top();
        sentences3.pop();
        for(int j=0; j<line.length();j++){
            if(!square.empty()){
                // std::cout << square.top() << std::endl;
                char temp = square.top();
                char temp2 = line[j];
                if(temp == temp2){
                    square.push(temp2);
                }
                else if(temp2 == ']' || temp2 == '[') square.pop();
                else continue;
            }
            else{
                if(line[j] == ']' || line[j] == '[')
                    square.push(line[j]);
            }
        } 
    }

    std::cout << square.size() << " ";

    cv = sentences3.size();
    for(int i=0;i<cv;i++){
        line = sentences3.top();
        sentences3.pop();
        for(int j=0; j<line.length();j++){
            if(!quate.empty()){
                // std::cout << quate.top() << std::endl;
                char temp = quate.top();
                char temp2 = line[j];
                if(temp == temp2){
                    quate.push(temp2);
                }
                else if(temp2 == '"') quate.pop();
                else continue;
            }
            else{
                if(line[j] == '"')
                    quate.push(line[j]);
            }
        } 
    }
    std::cout << quate.size() << std::endl;

    if(curly.size() == 0 && square.size() == 0 && quate.size() == 0) return 1;
    else return 0;
}

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
 