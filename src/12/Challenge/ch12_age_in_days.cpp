// C++ Code Challenges, LinkedIn Learning

// Challenge #12: Age in Days Calculator
// Write an application that asks the user's birth date and responds with the user's age in days. 
// If the user claims to be over 120 years old, output a message calling the bluff.

#include <iostream>
#include <string>
#include <ctime>

// Age in Days, main()
// Summary: This application asks the user's birth date and prints their age in days.
int main(){
    int birth_y, birth_m, birth_d, today_y, today_m, today_d, age;
    age = 0;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1) birth_m = 1;
    if(birth_m > 12) birth_m = 12;

    if(birth_d < 1) birth_d = 1;
    if(birth_d > 31) birth_d = 31;

    time_t now = time(0);
    tm *ltm = localtime(&now);
    int current_y = 1900 + ltm->tm_year;
    int current_m = 1 + ltm->tm_mon;
    int current_d = ltm->tm_mday;

    birth_y=birth_y+1;
    int diff = current_y - birth_y;
    for(int i=0; i<diff;i++){
        if(birth_y%4 == 0) age += 366;
        else age += 365;
        birth_y+=1;
    }

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Adjust February for leap year
    if (birth_y % 4 == 0) days_in_month[1] = 29;

    int remaining_days = 0;
    for (int i = birth_m - 1; i < 12; i++) {
        remaining_days += (i == birth_m - 1) ? (days_in_month[i] - birth_d) : days_in_month[i];
    }
    age += remaining_days;
    days_in_month[1] = 28;

    // Adjust February for leap year
    if (current_y % 4 == 0) days_in_month[1] = 29;
    age += current_d;
    
    remaining_days =0;
    for (int i = 0; i < current_m-1; i++) {
        remaining_days += days_in_month[i];
    }
    age += remaining_days;

    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
