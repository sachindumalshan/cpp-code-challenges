// C++ Code Challenges, LinkedIn Learning

// Challenge #5: Factorial Sequence
// Write a recursive function to print a sequence of factorials from 0! to n!
// n is received as an argument.
// n = 4 : {1, 1, 2, 6, 24}
// Only calculate each element once.
// Print the sequence on the screen.

#include <iostream>

// print_factorials()
// Summary: This function receives a (small) positive integer n and prints out a sequence from 0! through n!.
// Arguments:
//           n: The argument of the last factorial to print.
// Returns: n!, the last calculated factorial.
int fact =0;
int print_factorials(int n){
    fact = n == 0 ? 1 : n * print_factorials(n-1);
    std::cout << fact << " ";
    return fact;

    // if(n <= 1) return 1;
    // else return n * print_factorials(n-1);
}

// Main function
int main(){
    //std::cout << print_factorials(10) << std::endl;
    print_factorials(10);
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}
