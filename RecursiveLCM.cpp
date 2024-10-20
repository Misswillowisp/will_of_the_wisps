// RecursiveLCM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <iomanip>
#include <string>
#include <math.h>

using namespace std;
//function 
void userInput(int&, int&, int&);
void multiples(int[], const int, int);
void lcm(int[], int[], const int, int, int);
void lcm2(int arr1[], int arr2[], const int size, int num1, int num2);
void lcm3(int[], int[], int[], const int, int, int, int);
void displayArray(int[], int const, int);
int isLcm(int arr1[], int arr2[], int i, int size);

int main()
{
	//variables
	int const SIZE = 100;
	int firstNumber;        //holds user entered first number
	int secondNumber;       //holds user entered second number
	int thirdNumber;		//holds user entered third number

	int multiplesFirstNumber[SIZE];		//array to hold the multiples of the first number
	int multiplesSecondNumber[SIZE];	//array to hold the multiples of the second number
	int multiplesThirdNumber[SIZE];		//array to hold the multiples of the third number

	//obtain input from user
	userInput(firstNumber, secondNumber, thirdNumber);

	//calculate and add to the array the first number multipes 
	multiples(multiplesFirstNumber, SIZE, firstNumber);

	//display the contents of the first number multiples array
	displayArray(multiplesFirstNumber, SIZE, firstNumber);

	//calculate and add to the array the second number multipes
	multiples(multiplesSecondNumber, SIZE, secondNumber);

	//display the contents of the second number multiples array
	displayArray(multiplesSecondNumber, SIZE, secondNumber);

	//calculate and add to the array the third number multipes
	//multiples(multiplesThirdNumber, SIZE, thirdNumber);

	//display the contents of the third number multiples array
	//displayArray(multiplesThirdNumber, SIZE, thirdNumber);

	//calculate and display the lowest common multiple	
	lcm(multiplesFirstNumber, multiplesSecondNumber, SIZE, firstNumber, secondNumber);
	//lcm(multiplesFirstNumber, multiplesSecondNumber, multiplesThirdNumber, SIZE, firstNumber, secondNumber, thirdNumber);
	lcm2(multiplesFirstNumber, multiplesSecondNumber, SIZE, firstNumber, secondNumber);

}//ends main

/*******************************************************************
Function userInput obtains a pair of integers to find their
lowest common multiple.
*******************************************************************/
void userInput(int& first, int& second, int& third) {

	bool good;		//flags bad input

	cout << "Enter the first integer: ";
	do {
		//enter option and validate
		good = true;
		cin >> first;
		//if not an integer or  is a negative number
		if (!cin || first < 0) {
			good = false;
			cin.clear();
			cin.ignore(1000, '\n');
		}//ends if
		else //if not a number
		{
			string validate;
			getline(cin, validate);
			if (validate.find_first_not_of(" ") != string::npos)
				good = false;
		}//ends else

		if (!good) cout << "Please enter an integer number: ";

	} while (!good);

	cout << "\nEnter the second integer: ";
	do {
		//enter option and validate
		good = true;
		cin >> second;
		//if not an integer or  is a negative number
		if (!cin || second < 0) {
			good = false;
			cin.clear();
			cin.ignore(1000, '\n');
		}//ends if
		else //if not a number
		{
			string validate;
			getline(cin, validate);
			if (validate.find_first_not_of(" ") != string::npos)
				good = false;
		}//ends else

		if (!good) cout << "Please enter an integer number: ";

	} while (!good);


	cout << "\nEnter the third integer: ";
	do {
		//enter option and validate
		good = true;
		cin >> third;
		//if not an integer or  is a negative number
		if (!cin || third < 0) {
			good = false;
			cin.clear();
			cin.ignore(1000, '\n');
		}//ends if
		else //if not a number
		{
			string validate;
			getline(cin, validate);
			if (validate.find_first_not_of(" ") != string::npos)
				good = false;
		}//ends else

		if (!good) cout << "Please enter an integer number: ";

	} while (!good);

	cout << "\nThank you!";

}//ends userInput

/*******************************************************************
Function multiples fills an integer array with the multiples
of the number sent in the parameter list.
*******************************************************************/
void multiples(int arr[], const int size, int number) {

	//asign number to the first element of the array
	arr[0] = number;

	for (int index = 1; index < size; index++) {
		arr[index] = arr[index - 1] + number;
	}//ends for

}//ends multiples

/*******************************************************************
Function findMultiple compares the elements of two arrays until
it finds the common lowest multiple
******************************************************************/
void lcm(int arr1[], int arr2[], const int size, int num1, int num2) {
	//variables
	int lcm = 0;
	for (int index = 0; index < size; index++) {

		int result = isLcm(arr1, arr2, index, size);
		
		//cout << endl << "REsult: " << result << endl;

		if (result != 0) {
			cout << "\n\nThe lowest common multiple of " << num1 << " and " << num2 << " is: " << result << endl;
			break;
		}//end if
		//else
			//cout << endl<< "no lcm" << endl;
	}//ends for

}//ends lcm

/*******************************************************************
Function findMultiple compares the elements of two arrays until
it finds the common lowest multiple
******************************************************************/
void lcm2(int arr1[], int arr2[], const int size, int num1, int num2) {
	//variables
	
	for (int index = 0; index < size; index++) {
		int secondLoop = 0;
		cout << "secondLoop outer loop is: " << secondLoop << endl;
		int value = arr1[index];
		for (int count = 0; count < size; count++) {
			if (arr2[count] == value) {

				cout << "\n\nThe lowest common multiple of lmc2 " << num1 << " and " << num2 << " is: " << value << endl;

				
				break;
			}//end if

			secondLoop++;
			cout << "secondLoop inner loop is: " << secondLoop << endl;
		//else
			//cout << endl<< "no lcm" << endl;
		}
		if (value == arr2[secondLoop]) {
			break;
		}
	}//ends for

}//ends lcm2

/*******************************************************************
Function isLcm reursively compares the elements of two arrays until
it finds the common lowest multiple
******************************************************************/
int isLcm(int arr1[], int arr2[], int i, int size) {

	if (size == 0)
		return 0;
	if (arr1[i] == arr2[size - 1])
		return arr2[size - 1];
	else
		return isLcm(arr1, arr2, i, size - 1);

}//ends isMultiple


/*******************************************************************
Function findMultiplethreeNumbers compares the elements of two arrays until
it finds the common lowest multiple
******************************************************************/
void lcm3(int arr1[], int arr2[], int arr3[], const int size, int num1, int num2, int num3) {
	//variables
	int element = 0;
	int lcm = 0;

	for (int index = 0; index < size; index++) {

		for (int count = 0; count < size; count++) {

			if (arr1[index] == arr2[count]) {
				element = arr1[index];
			}//ends if		

		}//ends count loop for

		for (int third = 0; third < size; third++) {

			if (element == arr3[third]) {
				lcm = arr3[third];
			}//ends if			
		}//ends third loop for

		//stop loop when lcm is found
		if (lcm != 0) {
			cout << "\nThe lowest common multiple of " << num1 << ", " << num2 << " and ";
			cout << num3 << " is: " << lcm << endl;
			break;
		}//ends if
	}//ends index loop for	

}//ends findMultipleThreeNumbers

/*******************************************************************
Function displayArray displays the contents of an array of multiples
******************************************************************/
void displayArray(int arr[], int const size, int number) {

	cout << "\n\nThe multiples of " << number << " are: ";
	for (int i = 0; i < size; i++) {

		cout << arr[i] << ", ";
	}//ends for

}//ends displayArray

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
