const int ADD = 1,		// Addition
		  SUB = 2,		// Substraction
		  MULT = 3,		// Multiplication
		  INT_DIV = 4,	// Integer Division
		  DIV = 5,		// Real Division
		  MOD = 6;		// Modulo

// Precondition:  valid operation ADD = 1, SUB = 2, MULT = 3, INT_DIV = 4, DIV = 5, MOD = 6
// Postcondition: prints the operation that is taking place
void printOperation(int number1, int number2, int operation);

// Precondition:  NONE
// Postcondition: prints the menu
void printMenu();           

// Precondition:  NONE
// Postcondition: prints the title
void printTitle();

// Precondition:  NONE
// Postcondition: clears the screen
//                removes everything else from the input buffer
void clearScreenToContinue();

// Precondition:  valid operation ADD = 1, SUB = 2, MULT = 3, INT_DIV = 4, DIV = 5, MOD = 6
//				  operation >= 6 is %
// Postcondition: returns the appropriate character
char operationConstToChar(int operation);

// Precondition:  NONE
// Postcondition: returns a number 
//                validates for non numeric input
//                removes everything else from the input buffer
double getNumber();

// Precondition:  start <= end
// Postcondition: returns an integer in the range [start, end]
//                validates for non-numeric input
//                removes everything else from the input buffer
int getIntegerInRange(int start, int end);

// Precondition:  NONE
// Postcondition: returns an integer 
//                validates for non-numeric input
//                removes everything else from the input buffer
int getInteger();

// Precondition:  NONE
// Postcondition: returns an integer bigger than x
//                validates for non-numeric input
//                removes everything else from the input buffer
int getIntegerBiggerThan(int x);

// Precondition:  Min < Max
//				  requires seed and srand() before use
// Postcondition: returns a random integer between Min and Max
int randIntegerGenerator(int Min, int Max);

// Precondition:  valid operation ADD = 1, SUB = 2, MULT = 3, INT_DIV = 4, DIV = 5, MOD = 6		 
// Postcondition: returns the score
//                validates for non-numeric input
//                removes everything else from the input buffer
double singleOperation(int operation);

// Precondition: nbOfQuestions >= 1
//				 nbOfOperations 1: addition
//								2: addition and substraction
//								3: addition, substraction and multiplication
//								4: addition, substraction, multiplication and integer division
//								5: addition, substraction, multiplication, integer division and real division
//								6: addition, substraction, multiplication, integer division, real division and modulo.
//								valid operation ADD = 1, SUB = 2, MULT = 3, INT_DIV = 4, DIV = 5, MOD = 6
// Postcondition: returns the score on the quiz
//                validates for non-numeric input
//                removes everything else from the input buffer
double multipleOperationQuiz(int nbOfQuestions, int nbOfOperations, int operation = ADD);