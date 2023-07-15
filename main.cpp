/*
 *Course: CS216-003
 *Project: Project 1
 *Purpose: to implement a Gradebook Report
 *         it allows the user to input students' scores
 *         until the user types "q" or "Q" to quit
 *         then displays the average
 *         it allows the user to input desired curve
 *         until the user types "q" or "Q" to quit
 *         then displays all the valid scores from user input
 *                       and the corresponding letter grades;
 *                       the original and new average scores, highest score and lowest score.
 *Author: Sabbyasachi Dhar
 */

#include <iostream>     // std::cout, std::fixed
#include <iomanip>      // std::setprecision
#include <string>
#include <vector>
#include <cmath>
#include "FinalGrade.h"
#include "Gradebook.h"

using namespace std;


int main()
{
	Gradebook CS216gradebook_original;
    Gradebook CS216gradebook_curved;
	double input_score;
    double input_curve;

    // Ask user to input students' scores
	while (true)
	{
	    cout << "Please enter a score for CS216 (type 'Q' or 'q' to quit): " << endl;
		cin >> input_score;
		cin.ignore(256, '\n');

		// check if the user input is invalid
		if (cin.fail())
		{
			string check_input;
			cin.clear();
			cin >> check_input;
            		cin.ignore(256, '\n');
			if (check_input == "Q" || check_input == "q")
				break;
			else {
				cout << "Invalid input, please try again..." << endl;
				continue;
			}
		}

		// check if the input score is in the correct range: [0,100]
		if (input_score < 0 || input_score > 100)
		{
			cout << "The score is not in the correct range, please try again..." << endl;
		}
		else  // valid user input, store into gradeList object
       	 	{
            		FinalGrade inputFG(input_score);
            		CS216gradebook_original.insert(inputFG);
        	}
	}

    // Check if the gradebook is empty
    // If it is empty, report it then quit the program
    if  (CS216gradebook_original.getSize() == 0)
    {
        cout << "The gradebook for CS216 is empty!" << endl;
        cout << "Thank you for using the Grade Curve Calculator.\n";
        return 1;
    }

    // Ask user to input desired average
    while (true)
    {
        // Print original average then ask for desired average
        cout << endl << "The original average score is: "; 
        cout << fixed << setprecision(2) << CS216gradebook_original.getAverage() << endl;
        cout << "Please enter a score for CS216 (type 'Q' or 'q' to quit): " << endl;

        cin >> input_curve;
		cin.ignore(256, '\n');

		// check if the user input is invalid
		if (cin.fail())
		{
			string check_input;
			cin.clear();
			cin >> check_input;
            		cin.ignore(256, '\n');
			if (check_input == "Q" || check_input == "q")
				break;
			else {
				cout << "Invalid input, please try again..." << endl;
				continue;
			}
		}

        // Find the difference to imcrement the scores by
        double increment = input_curve - CS216gradebook_original.getAverage();
        const double EPSILON = 1.0e-2;
        if (abs(increment) < EPSILON)
            cout << "The scores are perfect, no need for the grading curve!" << endl;
        else
        {
            // check if the expected average is in the correct range: (original average,100]
            if (increment < MIN_SCORE || input_curve > MAX_SCORE)
            {
                cout << "The expected average is not in the correct range, please try again..." << endl;
            }
            else  // valid expected average, adjust scores accordingly
            {
                // Print original Gradebook
                cout << "The curved gradebook for CS216: " << endl;
                CS216gradebook_original.print();
                cout << "The number of scores is:\t" << CS216gradebook_original.getSize() << endl;
                cout << "The maximum score is:\t";
                CS216gradebook_original.getMax().print();
                cout << "The minimum score is:\t";
                CS216gradebook_original.getMin().print();
                cout << "The actual average score is:\t" << CS216gradebook_original.getAverage() << endl;

                // Make the new gradebook and increment the scores
                CS216gradebook_curved = CS216gradebook_original;
                CS216gradebook_curved.incrementScore(increment);

                // Print curved Gradebook
                cout << "The curved gradebook for CS216: " << endl;
                CS216gradebook_curved.print();
                cout << "The number of scores is:\t" << CS216gradebook_curved.getSize() << endl;
                cout << "The maximum score is:\t";
                CS216gradebook_curved.getMax().print();
                cout << "The minimum score is:\t";
                CS216gradebook_curved.getMin().print();
                cout << "The actual average score is:\t" << CS216gradebook_curved.getAverage() << endl;
            }
        }
	}

    cout << "Thank you for using the Grade Curve Calculator.\n";
	return 0;
}

