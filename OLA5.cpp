/*
 * Author: Norris, Joel R.
 * Date: Mar 18, 2017
 * File: ola5.cpp
 * As a part of the 3110 assignment, this file
 * contains the main program logic for the recursive functions
 * as well as their function definitions and output
 */
#pragma once
#include <iostream>
#include <string>
#include "parameters.h"

using std::cout;
using std::endl;
using std::string;

// function definitions
int fibonacci(int n);
int sum(int n);
int longest(const int *longestArray, int activeIndex, int arraySize, int currentSequence, int longestSequence);
void shortest(string someString, int shortestVal);

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
	
	// call the shortest function
	cout << endl;
	cout << "the shortest word in the given sentence is of length : " << endl;
	shortest(SentenceVal, 9999);
	cout << endl;
	cout << "the end." << endl;


    return 0;
	
}

// fibonacci: a recursive function that computes the fibonacci series.
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

// shortest: a recursive function that finds the shortest word in a given sentence.
void shortest(string SentenceVal, int shortestVal) {

	string::size_type pos;
	pos = SentenceVal.find(' ', 0);	// find the position of the next whitespace char in the string

	// base cases : end of the string is reached
	// string.find returns huge value
	if (pos > 9999) {
		cout << shortestVal << endl;
		return;
	}
	// there can't be a string shorter than 1 so best to just stop.
	if (shortestVal == 1) {
		cout << shortestVal << endl;
		return;
	}
	
	// split the existing string
	string second = SentenceVal.substr(pos+1);
	string first = SentenceVal.substr(0,pos); 

	/*
	cout << "first : " << first << endl;
	cout << "first.length : " << first.length() << endl;
	cout << "second : " << second << endl;
	cout << "shortestVal : " << shortestVal << endl;
	cout << "---------------------------------------------" << endl;
	*/

	// check the length of the first word in the string.
	// if it's shorter than the currently tracked shortest value, 
	// assign it as the new shortest value
	if ( int(first.length()) < shortestVal) shortestVal = int(first.length());

	// pass the rest of the string and the parameters through to the next function call
	shortest(second, shortestVal);
	
}