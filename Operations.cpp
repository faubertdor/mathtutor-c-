#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Operations.h"
using namespace std;

const int MIN = 1, MAX = 99;

////////////////////////////// Prints the title ////////////////////////////////////
void printTitle()
{
	cout
		<< "\n\t      This program tests your arithmetic abilities       \n"
		<< "\t for addition/substration/multiplication/division/modulo   \n"
		<< "\t                   by Jean F. Dorancy                      \n\n";
}

////////////////////////////// Prints the menu ////////////////////////////////////
void printMenu()
{
	cout
		<< "\t 1-  Addition only                                               \n"
		<< "\t 2-  Substraction only                                           \n"
		<< "\t 3-  Multiplication only                                         \n"
		<< "\t 4-  Integer division only                                       \n"
		<< "\t 5-  Real division only                                          \n"
		<< "\t 6-  Modulo only                                                 \n"
		<< "\t 7-  Addition and Substraction                                   \n"
		<< "\t 8-  Addition, Substraction and Multiplication                   \n"
		<< "\t 9-  Addition, Substraction, Multiplication and Integer division \n"
		<< "\t 10- All Operators                                               \n"
		<< "\t 11- End the program                                             \n\n";
}

////////////////////////////// Get an integer in a given range ////////////////////
int getIntegerInRange(int start, int end)
{
	int number = getInteger();
	while (number < start || number > end)
	{
		cout << "\t Your number must be " << (number < start ? "greater" : "less")
			<< " or equal to " << (number < start ? start : end) << ".\n";
		cout << "\t Try again: ";
		number = getInteger();
	}
	return number;
}

////////////////////////////// Get a an integer //////////////////////////////////  
int getInteger()
{
	double x = getNumber();
	while (x != int(x))
	{
		cout << "\t Your number is NOT an integer! \n"
			<< "\t Try again: ";
		x = getNumber();
	}
	return int(x);
}

////////////////////////////// Validate a number //////////////////////////////                  
double getNumber()
{
	double x;

	while (!(cin >> x))
	{
		cout << "\t Please no inapropriate characters! \n"
			<< "\t Try again: ";
		cin.clear();			cin.ignore(80, '\n');
	}
	cin.ignore(80, '\n');
	return x;
}

/////////////////////// Clears the screen and hit ENTER to continue ///////////////////
void clearScreenToContinue()
{
	cin.ignore(80, '\n');
	system("cls");
}

////////////////////////////// Multiple operation quiz //////////////////////////////  
double multipleOperationQuiz(int nbOfQuestions, int nbOfOperations, int operation)
{
	int i, nbOfCorrect = 0, nbOfPartiallyCorrect = 0;
	double totalScore = 0, score = 0;
	unsigned seed = unsigned(time(0));

	// Seeding using srand();
	srand(seed);

	for (i = 1; i <= nbOfQuestions; i++)
	{
		cout << "\nQuestion " << i << " of " << nbOfQuestions << endl;
		if (nbOfOperations != 1)
			operation = randIntegerGenerator(1, nbOfOperations);
		score = singleOperation(operation);
		if (score == 1)
			nbOfCorrect++;
		else if (score == 0.5)
			nbOfPartiallyCorrect++;
		totalScore += score;
		score = 0;

		cout << "Press ENTER to continue.";
		clearScreenToContinue();
	}

	cout
		<< "\nYou got " << nbOfCorrect << " correct answer" << (nbOfCorrect > 1 ? "s" : "")
		<< " and " << nbOfPartiallyCorrect << " partially correct answer" 
		<< (nbOfPartiallyCorrect > 1 ? "s" : "") << "\nout of " << nbOfQuestions << " question"
		<< (nbOfQuestions > 1 ? "s" : "") << " asked. \n\n";

	return totalScore;
}

/////////////////////// Convert operation const to character ////////////////////
char operationConstToChar(int operation)
{
	switch (operation)
	{
		case ADD: return '+';
		case SUB: return '-';
		case MULT: return 'x';
		case INT_DIV:
		case DIV: return '/';		// Real division
		default: return '%';
	}
}

////////////////////////////// Print the operation //////////////////////////
void printOperation(int number1, int number2, int operation)
{
	if (operation == DIV)
		cout
			<< "\n   ***  IMPORTANT NOTE: \n"
			<< "\tFor division please provide the answer to two decimal places ONLY.  *** \n\n"
			<< "\nREAL division:\n";

	cout 
		 << "\n\t   " << (number1 < 10 ? " " : "") << number1 << endl
		 << "\t " << operationConstToChar(operation)
		 << " " << (number2 < 10 ? " " : "") << number2 << endl
	     << "\t ------\n"
	     << "\t  ";
}

////////////////////////////// Random integer generator ////////////////////
int randIntegerGenerator(int Min, int Max)
{
	return (rand() % (Max - Min + 1)) + Min;
}

////////////////////////////// Get an integer greater than x //////////////
int getIntegerBiggerThan(int x)
{
	int next = getInteger();
	while (next <= x)
	{
		cout << "\t Enter an integer bigger than " << x << ".\n"
			<< "\t Try again: ";
		next = getInteger();
	}
	return next;
}

//// Operation between two randomly generated numbers and returns the score /////////
double singleOperation(int operation)
{
	int nbOfAttempt = 0, number1, number2;
	double typedAnswer, correctAnswer, score = 0;

	number1 = randIntegerGenerator(MIN, MAX);
	number2 = randIntegerGenerator(MIN, MAX);
	printOperation(number1, number2, operation);
	typedAnswer = getNumber();			nbOfAttempt++;
	switch (operation)
	{
		case ADD	: correctAnswer = number1 + number2;	break;
		case SUB	: correctAnswer = number1 - number2;	break;
		case MULT	: correctAnswer = number1 * number2;	break;
		case INT_DIV: correctAnswer = number1 / number2;	break;
		case MOD	: correctAnswer = number1 % number2;	break;
		case DIV	: correctAnswer = number1 / double(number2);
					  correctAnswer *= 1000;
				      correctAnswer = int(correctAnswer) / 10;
				      correctAnswer /= 100;			
	}

	if (typedAnswer != correctAnswer)
	{
		cout << "\nIncorrect. Please try again. \n";
		printOperation(number1, number2, operation);
		typedAnswer = getNumber();			nbOfAttempt++;
	}

	if (typedAnswer == correctAnswer)
	{
		cout << "\nCongratulations!!! ";
		score = nbOfAttempt == 1 ? 1 : 0.5;
	}
	else
		cout << "\nIncorrect. The answer is " << correctAnswer << "\n\n";
	return score;
}