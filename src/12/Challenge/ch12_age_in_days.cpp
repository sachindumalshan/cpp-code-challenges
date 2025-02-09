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
    age =0;

    std::cout << "Enter your birth date's month as a number: " << std::flush;
    std::cin >> birth_m;
    std::cout << "Enter your birth date's day: " << std::flush;
    std::cin >> birth_d;
    std::cout << "Enter your birth date's year: " << std::flush;
    std::cin >> birth_y;
    
    if(birth_m < 1)
        birth_m = 1;
    if(birth_m > 12)
        birth_m = 12;

    if(birth_d < 1)
        birth_d = 1;
    if(birth_d > 31)
        birth_d = 31;

    time_t timestamp = time(NULL);
    struct tm datetime = *localtime(&timestamp);
    
    char output[10];
    strftime(output, 50, "%Y,%m,%d", &datetime);
    std::cout << output << std::endl;
    //std::cout << typeid(output).name() << std::endl;

    int cy = 2025;
    int cm = 2;
    int cd = 9;

    int diff = cy-birth_y;
    //std::cout << diff << std::endl;
    birth_y=birth_y+1;

    for(int i=0; i<diff-1;i++){
        //std::cout << birth_y << std::endl;
        if(birth_y%4 == 0) age += 366;
        else age += 365;
        birth_y+=1;
    }


    if(birth_y%4 == 0){
        if(birth_m==1) age = age + 365 - 31 + (31-birth_d);
        else if(birth_m==2)  age = age + 365 - 31 - 29 + (29-birth_d);
        else if(birth_m==3)  age = age + 365 - 31 - 29 - 31 + (31-birth_d);
        else if(birth_m==4)  age = age + 365 - 31 - 29 - 31  -30 + (30-birth_d);
        else if(birth_m==5)  age = age + 365 - 31 - 29 - 31  -30 - 31 + (31-birth_d);
        else if(birth_m==6)  age = age + 365 - 31 - 29 - 31  -30 - 31 - 30 + (30-birth_d);
        else if(birth_m==7)  age = age + 365 - 31 - 29 - 31  -30 - 31 - 30 - 31 + (31-birth_d);
        else if(birth_m==8)  age = age + 365 - 31 - 29 - 31  -30 - 31 - 30 - 31 - 31 + (31-birth_d);
        else if(birth_m==9)  age = age + 365 - 31 - 29 - 31  -30 - 31 - 30 - 31 - 31 - 30 + (30-birth_d);
        else if(birth_m==10) age = age + 365 - 31 - 29 - 31  -30 - 31 - 30 - 31 - 31 - 30 - 31 + (31-birth_d);
        else if(birth_m==11) age = age + 365 - 31 - 29 - 31  -30 - 31 - 30 - 31 - 31 - 30 - 31 - 30 + (30-birth_d);
        else if(birth_m==12) age = age + 365 - 31 - 29 - 31  -30 - 31 - 30 - 31 - 31 - 30 - 31 - 30 - 31 + (31-birth_d);
    }else{
        if(birth_m==1) age = age + 365 - 31 + (31-birth_d);
        else if(birth_m==2)  age = age + 365 - 31 - 28 + (28-birth_d);
        else if(birth_m==3)  age = age + 365 - 31 - 28 - 31 + (31-birth_d);
        else if(birth_m==4)  age = age + 365 - 31 - 28 - 31  -30 + (30-birth_d);
        else if(birth_m==5)  age = age + 365 - 31 - 28 - 31  -30 - 31 + (31-birth_d);
        else if(birth_m==6)  age = age + 365 - 31 - 28 - 31  -30 - 31 - 30 + (30-birth_d);
        else if(birth_m==7)  age = age + 365 - 31 - 28 - 31  -30 - 31 - 30 - 31 + (31-birth_d);
        else if(birth_m==8)  age = age + 365 - 31 - 28 - 31  -30 - 31 - 30 - 31 - 31 + (31-birth_d);
        else if(birth_m==9)  age = age + 365 - 31 - 28 - 31  -30 - 31 - 30 - 31 - 31 - 30 + (30-birth_d);
        else if(birth_m==10) age = age + 365 - 31 - 28 - 31  -30 - 31 - 30 - 31 - 31 - 30 - 31 + (31-birth_d);
        else if(birth_m==11) age = age + 365 - 31 - 28 - 31  -30 - 31 - 30 - 31 - 31 - 30 - 31 - 30 + (30-birth_d);
        else if(birth_m==12) age = age + 365 - 31 - 28 - 31  -30 - 31 - 30 - 31 - 31 - 30 - 31 - 30 - 31 + (31-birth_d);
    }


    if(cy%4==0){
        if(cm==1) age = age + cd;
        else if(cm==2)  age = age + 31 + cd;
        else if(cm==3)  age = age + 31 + 29 + cd;
        else if(cm==4)  age = age + 31 + 29 + 31  + cd;
        else if(cm==5)  age = age + 31 + 29 + 31  + 30 + cd;
        else if(cm==6)  age = age + 31 + 29 + 31  + 30 + 31 + cd;
        else if(cm==7)  age = age + 31 + 29 + 31  + 30 + 31 + 30 + cd;
        else if(cm==8)  age = age + 31 + 29 + 31  + 30 + 31 + 30 + 31 + cd;
        else if(cm==9)  age = age + 31 + 29 + 31  + 30 + 31 + 30 + 31 + 31 + cd;
        else if(cm==10) age = age + 31 + 29 + 31  + 30 + 31 + 30 + 31 + 31 + 30 + cd;
        else if(cm==11) age = age + 31 + 29 + 31  + 30 + 31 + 30 + 31 + 31 + 30 + 31 + cd;
        else if(cm==12) age = age + 31 + 29 + 31  + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + cd;
    }else{
        if(cm==1) age = age + cd;
        else if(cm==2)  age = age + 31 + cd;
        else if(cm==3)  age = age + 31 + 28 + cd;
        else if(cm==4)  age = age + 31 + 28 + 31  + cd;
        else if(cm==5)  age = age + 31 + 28 + 31  + 30 + cd;
        else if(cm==6)  age = age + 31 + 28 + 31  + 30 + 31 + cd;
        else if(cm==7)  age = age + 31 + 28 + 31  + 30 + 31 + 30 + cd;
        else if(cm==8)  age = age + 31 + 28 + 31  + 30 + 31 + 30 + 31 + cd;
        else if(cm==9)  age = age + 31 + 28 + 31  + 30 + 31 + 30 + 31 + 31 + cd;
        else if(cm==10) age = age + 31 + 28 + 31  + 30 + 31 + 30 + 31 + 31 + 30 + cd;
        else if(cm==11) age = age + 31 + 28 + 31  + 30 + 31 + 30 + 31 + 31 + 30 + 31 + cd;
        else if(cm==12) age = age + 31 + 28 + 31  + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + 31 + cd;
    }

    if(age < 43830)
        std::cout << "You are " << age << " days old.";
    else
        std::cout << "Come on. You can't be " << age << " days old!";
    std::cout << "\n\n" << std::flush;
}
