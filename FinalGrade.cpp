/* 
 * File:   FinalGrade.cpp
 * Course: CS216-003
 * Project: Project 1
 * Purpose: provide the implementation of the member functions of the class named FinalGrade
 *
 * Author: Sabbyasachi Dhar
 *
 */
#include <iostream>
#include "FinalGrade.h"

// default constructor
FinalGrade::FinalGrade()
{
    // give initial value to be 0
    score = 0;
}

// constructor: give the initial value to the private data member score 
// to pass-in parameter in_score
FinalGrade::FinalGrade(double in_score)
{
    if (in_score < MIN_SCORE || in_score > MAX_SCORE)
        score = 0;
    else
        score = in_score;
}

// set the private data member: score
// to pass-in parameter in_score
void FinalGrade::setScore(double in_score)
{
    if (in_score < MIN_SCORE || in_score > MAX_SCORE)
        score = 0;
    else
        score = in_score;
}

// return the value of the data member: score
double FinalGrade::getScore() const
{
    return score;
}

// return the corresponding letter grade from score
// based on the grading policy in CS216 syllabus
char FinalGrade::decideLetterGrade() const
{
    char grade;
    if(score >= 90)
	    grade = 'A';
    else if (score >= 80)
	    grade = 'B';
    else if (score >=70)
	    grade = 'C';
    else if (score >=60)
	    grade = 'D';
    else
	    grade = 'E';
    return grade;
}

// print the score and letter grade in the format: (for example)
// Score: 88        Letter Grade: B
void FinalGrade::print() const
{
    cout << "Score: " << score << "\t\tLetter Grade: " << this->decideLetterGrade() << endl;
}

