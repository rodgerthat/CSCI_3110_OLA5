/*
 * Author: Norris, Joel R.
 * Date: Mar 18, 2017
 * File: ola5.cpp
 * As a part of the 3110 assignment, this file
 * contains the main program logic for the recursive functions
 * as well as their function definitions and output
 */

#include <iostream>
#include "parameters.h"

using std::cout;
using std::endl;

// function definitions
int fibonacci(int n);
int sum(int n);
int longest(const int *longestArray, int activeIndex, int arraySize, int currentSequence, int longestSequence);

int main()
{

	cout << endl << endl << "******************* OLA5 : RECURSION ********************" << endl << endl;

	// call the fibonacci function, 
	cout << "fibonacci sequence : " << endl;
	for (int i = 0; i < FibVal; ++i)
	{
		cout << fibonacci(i) << " ";
	}
	cout << endl;

	// call the sum function
	cout << endl;
	cout << "sum of all integers through " << SumVal << endl;
	cout << sum(SumVal) << endl;

	// call the longest value function

	cout << endl;
	cout << "the longest sequence of values in the array is : " << endl;
	int arraySize = sizeof(LongestVal) / sizeof(LongestVal[0]); // determine the size of the array
	cout << longest(LongestVal, 0, arraySize, 0, 0) << endl;
	

    return 0;
	
}

// fibonacci sequence function
int fibonacci(int n) {

	switch (n) {

	case 0: return 0; break;
	case 1: return 1; break;
	default: return fibonacci(n - 1) + fibonacci(n - 2);

	}

}

// sum sequence function
// returns the sum of all the integers in a sequence through n
int sum(int n) {

	switch (n) {
	case 0: return 0; break;
	case 1: return 1; break;
	default: return n + sum(n-1);
	}
}

// longest sequence function
// finds the longest positive sequence in an array
/* 
longest( s[lower .. upper] ) = 
1 if lower = upper and s[lower] > 0
0 if lower = upper and s[lower] <= 0
0 if lower > upper
the larger value of longest(s[lower + 1, upper]) and
the number of values in the longest sequence of positive
values starting at the index lower if lower < upper
*/
int longest(const int *longestArray, int activeIndex, int arraySize, int currentSequence, int longestSequence) {
	
	// base case : end of array reached. return longestSequence 
	if (activeIndex == arraySize) return longestSequence;

	// if the element is > 0, increment the current counter
	if (longestArray[activeIndex] > 0) ++currentSequence;

	// if the element is <= 0, reset the current counter to 0
	if (longestArray[activeIndex] <= 0) currentSequence = 0;

	// if the current counter has gotten longer than the longest recorded sequence, replace it. 
	if (currentSequence > longestSequence) longestSequence = currentSequence;

	++activeIndex;	// increment up the array one element

	longest(longestArray, activeIndex, arraySize, currentSequence, longestSequence); // keep it rollin'

}
