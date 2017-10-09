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
#include <vector>

using namespace std;

// Simple, function tests number then returns
// true/false based on outcome of the test
void testPrime(const int, vector<int> &);
void printPrimes(const vector<int>);

int main() {
    
    // Declare empty to hold testPrime(int) result
    // bool isPrime;
    
    // Define highest number to test here,
    // in this case (according to the prompt)
    // let user decide this number.
    int intHighestNumberToTest;
    
    // Declare number to test and pass along
    // to testPrime(int)
    int intNumberToTest;
    
    // Create empty vector to hold all prime
    // numbers that are discovered
    vector<int> vecPrimesArray;
    
    cout << "Please enter a positive integer. This program\n";
    cout << "finds primes between 1 and your number:\n";
    cin >> intHighestNumberToTest;
    while(!cin || intHighestNumberToTest <= 1 || intHighestNumberToTest > 99999999)
    {
        cout << "Please enter a positive integer:\n";
        cin.clear();
        cin.ignore();
        cin >> intHighestNumberToTest;
    }
    
    // Define intNumberToTest in this for loop.
    // Loop to test integers 1 through 100,
    // will return true/false isPrime for this range
    for(int i = 0 ; i <= intHighestNumberToTest ; i++)
    {
        intNumberToTest = i;
        
        testPrime(intNumberToTest, vecPrimesArray);
    }
    
    printPrimes(vecPrimesArray);
    
    return 0;
}

void testPrime(const int intNumberToTest, vector<int> &refPrimes)
{
    int intRemainder;
    
    for(int j = 1 ; j <= intNumberToTest ; j++)
    {
        if(intNumberToTest != 1)
            {
            intRemainder = intNumberToTest % j;
            
            // First case: a number divides this before we get to
            // the number we're testing so break out.
            if(intRemainder == 0 && j != intNumberToTest && j != 1) // Need to exclude divisible by one
                                                                    // means we can't test 1 here, hence
                                                                    // special case later
            {
                break;
            }
            // Second case: is prime because number we're dividing by (j)
            // and number we're testing (intNumberToTest) are the same
            else if(intRemainder == 0 && j == intNumberToTest && j != 1)
            {
                // Append to vector
                refPrimes.emplace_back(intNumberToTest);
            }
        }
        else
        {
            // Special case for first number not accounted for by loop
            refPrimes.emplace_back(intNumberToTest);
        }
    }
}

// This function is used to print all the prime numbers
// in the range searched through
void printPrimes(const vector<int> vecPrimes)
{
    for(int i = 0 ; i < int(vecPrimes.size()) ; i++)
    {
        cout << vecPrimes[i] << endl;
    }
}
