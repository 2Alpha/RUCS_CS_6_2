
// -------------------------------------------------------
// Author: Andrae Allen
// Class: CS361
// Assignment: Week 6, Program 2
// Discription: 
// -------------------------------------------------------

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

const string PROGRAM_DESCRIPTION = "Program to test for Happy numbers"; 
const string PROMPT_4_1ST_NUMBER  = "Enter the first number to test: ";
const string PROMPT_4_LAST_NUMBER = "Enter the last number to test: ";

const int NOTHING = 0; 
const int LOWEST_NUMBER = 1; 
const int HIGHEST_NUMBER = 999;
const int SETW_4_TABLE = 7; 

const int IGNORE_BUFFER = 100; 


const int BEEP_1_FREQ = 400; // Variable used to store the value for the frequency of beep 1
const int BEEP_1_TIME = 200; // Variable used to store the duration of beep 1
const int BEEP_2_FREQ = 300; // Variable used to store the value for the frequency of beep 2
const int BEEP_2_TIME = 200;

void getTwoNumbers(string firstQuestion, string secondQuestion, int highestNumber, int& firstNumber, int& lastNumber);
int sum(int n);
bool sumOfRoots(int &testNumber);

int main()
{
	int firstNumber = 0; 
	int lastNumber = 0; 

	

	cout << PROGRAM_DESCRIPTION;
	cout << "\n\n"; 


	getTwoNumbers(PROMPT_4_1ST_NUMBER, PROMPT_4_LAST_NUMBER, HIGHEST_NUMBER, firstNumber, lastNumber);

	//cout << "\n now first number is " << firstNumber << endl;
	//cout << "\n now last number is " << lastNumber << endl;

	cout << "\n\n";
	int testNumber = firstNumber;
	
	for (int step = firstNumber; step <= lastNumber; step++)
	{
		testNumber = step;
		sumOfRoots(testNumber);
		
	}


	cout << "\n"; 
	cout << "Testing of numbers " << firstNumber << " to " << lastNumber << " is complete.";
	cout << endl; 
	system("pause");
	
	


	
	

	


	return NOTHING; 

}

void errorBeep()
{
	Beep(BEEP_1_FREQ, BEEP_1_TIME);
	Beep(BEEP_2_FREQ, BEEP_2_TIME);
}

void getTwoNumbers(string firstQuestion, string secondQuestion, int highestNumber, int& firstNumber, int& lastNumber)
{
	

	cout << PROMPT_4_1ST_NUMBER;
	

	while ((!(cin >> firstNumber)) || (firstNumber <= LOWEST_NUMBER) || (firstNumber > highestNumber))
	{
		errorBeep();
		cout << "Error -- Must be a number greater than " << LOWEST_NUMBER << " and up to " << highestNumber << " - Please try again" << endl << endl;
		cout << firstQuestion;
		cin.clear();
		cin.ignore(IGNORE_BUFFER, '\n');
	}
	
	
	cout << PROMPT_4_LAST_NUMBER; 

	while ((!(cin >> lastNumber)) || (lastNumber <= firstNumber) || (lastNumber >= highestNumber))
	{
		errorBeep();
		cout << "Error -- Must be a number greater than " << firstNumber << " and less than " << highestNumber << " - Please try again" << endl << endl;
		cout << secondQuestion;
		cin.clear();
		cin.ignore(IGNORE_BUFFER, '\n');
	}


}
	
int sum(int n)
{
	if (n)
	{
		int d = n % 10;
		return d * d + sum(n / 10);
	}
	return 0;
}
bool sumOfRoots(int &testNumber)
{

	bool happy; 

	//int loopCounter;
	cout << "Test sequence for " << testNumber << " is:" << endl;
	cout << setw(SETW_4_TABLE);
	cout << testNumber;


	for (int loopCounter = 1, columnCounter = 1; ((sum(testNumber) != 1) && (loopCounter < 50)); loopCounter++)
	{

		cout << setw(SETW_4_TABLE);
		testNumber = sum(testNumber);
		cout << testNumber;
		columnCounter++;

		if (columnCounter == 10)
		{
			cout << endl;
			columnCounter = 0;
		}


		if (sum(testNumber) == 1)
	
		{
			cout << endl;
			cout << loopCounter + 2 << " sequences computed";
			cout << "\n\n"; 
		}

		if (loopCounter == 49)
		{

			cout << endl;
			cout << loopCounter + 1 << " sequences computed";
			cout << "\n\n";

		}
		
	}

	if (sum(testNumber) == 1)
	{
		cout << "The above sequence of numbers is happy" << endl; 
		happy = true; 
	}

	else
	{
		cout << "The above sequence of numbers is unhappy" << endl; 
		happy = false;
	}

	cout << "Press any key to continue...\n\n";
	_getch();

	return happy; 

}