#include "Functions.h"
#include "Functions.cpp"

int main() 
{
	string pyramid = createPyramid(getUserInput()); // Creates a string with returned values from createPyramid and getUserInput.
	cout << pyramid; // Prints out the string pyramid or error messages.
}
