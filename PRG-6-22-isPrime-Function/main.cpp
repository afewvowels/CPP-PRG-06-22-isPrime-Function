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

bool testPrime(int);

int main() {
    
    bool isPrime;
    
    int intNumberToTest;
    
    
    // Loop to test integers 1 through 100,
    // will return true/false isPrime for this range
    for(int i = 0 ; i <= 100 ; i++)
    {
        intNumberToTest = i;
        
        isPrime = testPrime(intNumberToTest);
    }
    
    return 0;
}

bool testPrime(int intNumberToTest)
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

