// C++ Code Challenges, LinkedIn Learning

// Challenge #11: Finding Relatives
// Write an application that reads a list of people's names in a CSV file and outputs the first pair of people it finds to be possibly related based on their family names.
// Assume that all entries have one name and one family name.
// Entries are separated by commas.
// Names and family names are separated by spaces.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Finding Relatives, main()
// Summary: This application displays the first pair of possible relatives from a list of names in a CSV file.
int main(){
    std::string str;
    std::vector <std::string> names;
    std::vector <std::string> names2;
    std::vector <std::string> finall;
    std::fstream file ("names.csv", std::ios::in);
    // Read the CSV file.
    if(file.is_open()){

        while(!file.eof()){
            getline(file,str);
            //std::cout << str << std::endl;
        }

        std::stringstream ss(str);

        while(ss.good()){
            std::string substr;
            getline(ss,substr,',');
            names.push_back(substr);
        }    
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    // for(int i=0;i<names.size();i++){
    //     std::cout << names[i] << std::endl;
    // }

    for(int i=0;i<names.size();i++){
        std::stringstream ss(names[i]);
        while(ss.good()){
            std::string substr;
            getline(ss,substr,' ');
            names2.push_back(substr);
        }
    }

    // for(int i=0;i<names2.size();i++){
    //     std::cout << names2[i] << std::endl;
    // }

    for(int i=1;i<names2.size();i+=2){
        for(int j=i+2;j<names2.size();j+=2){
            if(names2[i]==names2[j]){
                finall.push_back(names2[i-1] + " " + names2[i]);
                finall.push_back(names2[j-1] + " " + names2[j]);
                break;
            }
        }
    }

    // for(int i=1;i<names2.size();i=+2){
    //      for(int j=i+2;j<names2.size();j=+2){
    //         if(names2[i]==names2[j]){
    //             std::string newname1 = names2[i-1] + " " + names2[i];
    //             std::string newname2 = names2[j-1] + " " + names2[j];
    //             finall.push_back(newname1);
    //             finall.push_back(newname2);
    //             break;
    //         }
    //      }
    // }

    // for(int i=0;i<finall.size();i++){
    //     std::cout << finall[i] << std::endl;
    // }

    if(finall.size() > 0) std::cout << finall[0] << "," << finall[1] << std::endl;
    else std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 