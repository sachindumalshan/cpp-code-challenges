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
    std::vector <std::string> double_name;
    std::vector <std::string> single_name;
    std::vector <std::string> name_pairs;
    std::fstream file ("names.csv", std::ios::in);
    
    // Read the CSV file.
    if(file.is_open()){

        while(!file.eof()){
            getline(file,str);
        }

        std::stringstream ss(str);

        while(ss.good()){
            std::string substr;
            getline(ss,substr,',');
            double_name.push_back(substr);
        }    
        file.close();
    }
    else{
        std::cout << "Something went wrong\n" << std::flush;
        return 1;
    }

    for(int i=0;i<double_name.size();i++){
        std::stringstream ss(double_name[i]);
        while(ss.good()){
            std::string substr;
            getline(ss,substr,' ');
            single_name.push_back(substr);
        }
    }

    for(int i=1;i<single_name.size();i+=2){
        for(int j=i+2;j<single_name.size();j+=2){
            if(single_name[i]==single_name[j]){
                name_pairs.push_back(single_name[i-1] + " " + single_name[i]);
                name_pairs.push_back(single_name[j-1] + " " + single_name[j]);
                break;
            }
        }
    }

    if(name_pairs.size() > 0) std::cout << name_pairs[0] << "," << name_pairs[1] << std::endl;
    else std::cout << "No relatives found.\n\n" << std::flush;    
    return 0;
}
 