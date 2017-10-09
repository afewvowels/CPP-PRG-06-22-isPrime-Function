//
//  main.cpp
//  PRG-6-22-isPrime-Function
//
//  Created by Keith Smith on 9/21/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  A prime number is a number that is only divisible by itself and 1. For example,
//  the number 5 is prime because it can only be evenly divided by 1 and 5. The number 6,
//  however, is not prime because it can be divided evenly by 1, 2, 3, and 6.
//
//  Write a function name isPrime, which takes an integer as an argument and returns
//  true if the argument is a prime number, or false otherwise. Demonstrate the fucntion
//  in a complete program.
//
//  TIP: Recall that the % operator divides one number by another, and returns the remainder
//  of the division. In an expression such as num1 % num2, the % operator will return 0
//  if num1 is evenly divisible by num2.

#include <iostream>

using namespace std;

// Simple, function tests number then returns
// true/false based on outcome of the test
void testPrime(int);

int main() {
    
    // Declare empty to hold testPrime(int) result
    // bool isPrime;
    
    // Define highest number to test here,
    // in this case (according to the prompt)
    // it's just 100. Easy to modify.
    const int INT_HIGHEST_NUM_TO_TEST = 100;
    
    // Declare number to test and pass along
    // to testPrime(int)
    int intNumberToTest;
    
    // Define intNumberToTest in this for loop.
    // Loop to test integers 1 through 100,
    // will return true/false isPrime for this range
    for(int i = 0 ; i <= INT_HIGHEST_NUM_TO_TEST ; i++)
    {
        intNumberToTest = i;
        
        // isPrime = testPrime(intNumberToTest);
        
        testPrime(intNumberToTest);
    }
    
    return 0;
}

void testPrime(int intNumberToTest)
{
    int intRemainder;
    
    for(int j = 1 ; j <= intNumberToTest ; j++)
    {
        if(intNumberToTest != 1)
            {
            intRemainder = intNumberToTest % j;
            
            // Output result to console
            if(intRemainder == 0 && j != intNumberToTest && j != 1) // Need to exclude divisible by one
                                                                    // means we can't test 1 here, hence
                                                                    // special case later
            {
                cout << intNumberToTest << " is not prime" << endl;
                break;
            }
            else if(intRemainder == 0 && j == intNumberToTest && j != 1)
            {
                cout << intNumberToTest << " is prime" << endl;
            }
        }
        else
        {
           cout << "1 is prime\n"; // Special case for first number not accounted for by loop
        }
    }
    
    return false;
}

