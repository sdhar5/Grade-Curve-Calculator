 /* 
 * File:   Gradebook.cpp
 * Course: CS216-003
 * Project: Project 1
 * Purpose: provide the implementation of the member functions of Gradebook class
 *
 * Author: Sabbyasachi Dhar
 *
 */
#include <iostream>
#include <iomanip>
#include "Gradebook.h"

// default constructor
Gradebook::Gradebook()
{
}

// return the size of the current vector: scores, 
// which represents current gradebook
int Gradebook::getSize() const
{
	return scores.size();
}
    
// insert a FinalGrade object, newFG, 
// into the end of the current gradebook
void Gradebook::insert(FinalGrade newFG)
{
	scores.push_back(newFG);
}

// return a FinalGrade object, 
// which holds the maximum score in the current gradebook
FinalGrade Gradebook::getMax() const
{
	FinalGrade Max(0);
	for (int i = 0; i < scores.size(); i++)
	{
		if(scores.at(i).getScore() > Max.getScore())
			Max.setScore(scores.at(i).getScore());
	}
	return Max;
}

// return a FinalGrade object,
// which holds the minimum score in the current gradebook
FinalGrade Gradebook::getMin() const
{
	FinalGrade min(100);
	for (int i = 0; i < scores.size(); i++)
	{
		if(scores.at(i).getScore() < min.getScore())
			min.setScore(scores.at(i).getScore());
	}
	return min;
}
    
// return the average score among all scores in the current gradebook
double Gradebook::getAverage() const
{
	double avg = 0;
	for (int i = 0; i < scores.size(); i++)
	{
		avg += scores.at(i).getScore();
	}
	return avg/scores.size();
}

// For each FinalGrade object in the current gradebook, 
// its score will be increased by the given value 
// If the score reaches MAX_SCORE, it does not go beyond
void Gradebook::incrementScore(double value)
{
	for (int i = 0; i < scores.size(); i++)
	{
		// If the curved score is less than the max set it as the new score
		if(scores.at(i).getScore()+value < MAX_SCORE) 
			scores.at(i).setScore(scores.at(i).getScore()+value);
		// If the curve score exceeds the max replace it with the max score
		else
			scores.at(i).setScore(MAX_SCORE);
	}

}
    
// print the FinalGrade objects in the current gradebook
void Gradebook::print() const
{
	cout << fixed << setprecision(2);
	for (int i = 0; i < scores.size(); i++)
	{
		scores.at(i).print();
	}
}

