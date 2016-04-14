// This program generates quizzes to test arithmetics skills
// Math Tutuor
// by Jean Faubert Dorancy
// Last modified: 04-22-2015

#include <iostream>
#include "Operations.h"
using namespace std;

void main()
{
	int choice, nbOfQuestions;
	double  totalScore;

	while (true)
	{
		printTitle();
		printMenu();

		cout << "\t Choice : ";
		choice = getIntegerInRange(1, 11);
		if (choice != 11)
		{
			cout << "\t How many questions? ";
			nbOfQuestions = getIntegerBiggerThan(0);
		}
		switch (choice)
		{
			case 1: totalScore = multipleOperationQuiz(nbOfQuestions, 1);			break;
			case 2: totalScore = multipleOperationQuiz(nbOfQuestions, 1, SUB);		break;
			case 3: totalScore = multipleOperationQuiz(nbOfQuestions, 1, MULT);		break;
			case 4: totalScore = multipleOperationQuiz(nbOfQuestions, 1, INT_DIV);	break;
			case 5: totalScore = multipleOperationQuiz(nbOfQuestions, 1, DIV);		break;
			case 6: totalScore = multipleOperationQuiz(nbOfQuestions, 1, MOD);		break;
			case 7: totalScore = multipleOperationQuiz(nbOfQuestions, 2);			break;
			case 8: totalScore = multipleOperationQuiz(nbOfQuestions, 3);			break;
			case 9: totalScore = multipleOperationQuiz(nbOfQuestions, 4);			break;
			case 10:totalScore = multipleOperationQuiz(nbOfQuestions, 6);			break;
			case 11:
				cout << " \t Thank you for using our program! \n\n";
				system("pause");
				exit(0);
		}
		cout << "Your score is " << (totalScore / nbOfQuestions) * 100 << "% \n\n";

		cout << "Hit ENTER for the next quiz.";
		clearScreenToContinue();
	}
}