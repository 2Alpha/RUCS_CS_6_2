
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

const string PROGRAM_DESCRIPTION = " Program to test for Happy numbers"; 
const string PROMPT_4_1ST_NUMBER  = " Enter the first number to test: ";
const string PROMPT_4_LAST_NUMBER = " Enter the last number to test: ";

const int NOTHING = 0; 
const int LOWEST_NUMBER = 1.0; 
const int HIGHEST_NUMBER = 999.0;

const int IGNORE_BUFFER = 100; 


const int BEEP_1_FREQ = 400; // Variable used to store the value for the frequency of beep 1
const int BEEP_1_TIME = 200; // Variable used to store the duration of beep 1
const int BEEP_2_FREQ = 300; // Variable used to store the value for the frequency of beep 2
const int BEEP_2_TIME = 200;

void getTwoNumbers(string firstQuestion, string secondQuestion, int highestNumber, int& firstNumber, int& lastNumber);
unsigned int sumSquaredDigits(unsigned int n);

int main()
{
	int firstNumber = 0; 
	int lastNumber = 0; 

	cout << PROGRAM_DESCRIPTION;
	cout << "\n\n"; 


	getTwoNumbers(PROMPT_4_1ST_NUMBER, PROMPT_4_LAST_NUMBER, HIGHEST_NUMBER, firstNumber, lastNumber);

	cout << "\n now first number is " << firstNumber << endl;
	cout << "\n now last number is " << lastNumber << endl;

	cout << "\n\n";


	cout << sumSquaredDigits(firstNumber); 

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
		cout << " Error -- Must be a number greater than " << LOWEST_NUMBER << " and up to " << highestNumber << " - Please try again" << endl << endl;
		cout << firstQuestion;
		cin.clear();
		cin.ignore(IGNORE_BUFFER, '\n');
	}
	
	
	cout << PROMPT_4_LAST_NUMBER; 

	while ((!(cin >> lastNumber)) || (lastNumber <= NOTHING) || (lastNumber >= firstNumber))
	{
		errorBeep();
		cout << " Error -- Must be a number greater than " << NOTHING << " and less than " << firstNumber << " - Please try again" << endl << endl;
		cout << secondQuestion;
		cin.clear();
		cin.ignore(IGNORE_BUFFER, '\n');
	}


}

		unsigned int sumSquaredDigits(unsigned int n) 

		while (n != 1){
		{
			unsigned int result = 0;
			while (n) {
				unsigned int t = n % 10;
				result += t * t;
				n /= 10;
			}
			return result;
		}



	
