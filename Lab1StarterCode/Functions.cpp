#include "Functions.h"
using namespace std;

string createPyramid(int num) // Creates a string pyramid.
{
    string Answer = ""; // Final return object
    if (num >= 500) // Checks if the value is too large.
    {
        return "Pyramid size too large.";
    }
    else if (num < 0) // Checks if the value is negative.
    {
        return "Negative pyramid size.";
    }
    else if (num == 0) // Checks if the value is invalid.
    {
        return "Invalid pyramid size.";
    }
    else // Creates the string pyramid.
    {
        int floor = 1; 
        int pillar = 2;
        int pillarTotal = num + 1;
        int floorTotal = (pillarTotal - 2) * 2 + 1;
        for(int pyramidSize = 0 ; pyramidSize < num ; pyramidSize++) // Loops from 0 to valid input value.
            {
                for(int space = 0 ; space < floorTotal / 2 - (pyramidSize) + 1; space++) // Adds spaces to the left of the pyramid.
                {
                    Answer = Answer + " ";
                }
                for(int dash = 0 ; dash < floor ; dash++) // Adds dashes to the bottom of the pyramid blocks.
                {
                    Answer = Answer + "-";
                }
                Answer = Answer + "\n"; // Adds a new line.
                floor = floor + 2; // Adds additional dashes due to growing pyramid size.
                for(int space = 0 ; space < floorTotal / 2 - (pyramidSize); space++) // Adds more spaces to the pyramid side.
                {
                    Answer = Answer + " ";
                }
                for(int lines = 0 ; lines < pillar -1; lines++) // Adds pillars to the sides of the pyramid.
                {
                    Answer = Answer + "| ";
                }
                Answer = Answer + "|"; // Adds the final pyramid pillar.
                pillar = pillar + 1; // Adds additional pillar to the next line.
                Answer = Answer + "\n"; // Adds new line at the end.
            }
        floor = floor - 2; // Adds the final dashes and spaces.
        Answer = Answer + " ";
        for(int dash = 0 ; dash < floor ; dash++)
        {
            Answer = Answer + "-";
        }
    }
    return Answer; // Returns the string pyramid.
}
    

int getUserInput() // Gets user int user input.
{
    int Value;
    cin >> Value;
    return Value; // Returns the Value inputted
}

