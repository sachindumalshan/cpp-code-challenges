// C++ Code Challenges, LinkedIn Learning

// Challenge #16: The Birthday Problem
// The birthday problem consists in finding the probability of having at least two people with the same birthday in a group of n people.
// Create an application that simulates the Birthday Problem 1 million times, with the number of people specified by the user.
// Use this application to prove (empirically) that the probability of having at least 2 people with the same birthday is approximately 0.5 for a group of 23 people. 
// https://en.wikipedia.org/wiki/Birthday_problem 

#include <iostream>
#include <chrono>

// The Birthday Problem, main()
// Summary: This application simulates the birthday problem a large number of times to reveal the probability of a birthday match in a groupd of a given number of people.
int main(){    
    const int total = 1000000;
    int n, matches=0;
    int b_dates[n];
    bool match_found = false;

    std::cout << "Enter the number of people in the group: " << std::flush;
    std::cin >> n;

    if(n > 366)
        matches = total;
    else{
        for(int i=0; i<total;i++){
            for(int j=0; j<n; j++){
                b_dates[j] = 1 + rand() % 367; 
            }        
        
            for(int m=0; m<n; m++){
                for(int k=m+1; k<n; k++){
                    if(b_dates[m] == b_dates[k]){
                        matches++;
                        break;
                    }
                }
                break;
            }
        }
    }

    

    std::cout << std::endl;
    std::cout << "The probability of a birthday match is " << (double)matches/total << "\n\n" << std::flush;  

    return 0;
}
