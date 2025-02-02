// C++ Code Challenges, LinkedIn Learning

// Challenge #8: IP Address Validation
// Write an application that reads a string from the terminal and responds with a message indicating whether the string is a valid IP address or not.
// Assume decimal IP addresses.
// 158.25.0.33
// All numbers between 0 and 255.

#include <iostream>
#include <vector>
#include <string>

// is_valid_ip()
// Summary: This function validates an IP address.
// Arguments:
//           ip: The string to analyze with a potential ip address.
// Returns: A boolean value. True for valid ip addresses, false otherwise.
bool is_valid_ip(std::string ip){
    std::vector <std::string> ip_list;
    std::vector <char> tempc;
    int prev =0;

    for(int i=0; i<ip.size(); i++){
        tempc.push_back(ip[i]);
    }

    for(int i=0; i<tempc.size(); i++){
        if(tempc[i]=='.') continue;
        else if (isdigit(tempc[i])) continue;
        else return false;
    }

    for(int i=0; i<=tempc.size(); i++){
        if(tempc[i]=='.'){
            ip_list.push_back(ip.substr(prev,i-prev));
            prev = i+1;
        }
        if(ip[i] == '\0') ip_list.push_back(ip.substr(prev,i-prev));
    }

    if(ip_list.size() != 4) return false;

    for(int j=0; j<4; j++){
        if( (stoi(ip_list[j]) >=0) && (stoi(ip_list[j]) <=255) ) continue;
        else return false;
    }
    return true;
    
}

// Main function
int main(){
    std::string s;
    std::cout << std::endl << "Enter an IP address in decimal: " << std::flush;
    std::getline(std::cin,s);
    std::cout << " \n" << s << (is_valid_ip(s) ? " is" : " is not" ) << " a valid IP address.\n\n";
    return 0;
}
