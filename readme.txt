This is the readme for CS216PA1
In CS216PA1 there are 5 files. There is FinalGrade.cpp and FinalGrade.h. FinalGrade.h is the header file for FinalGrade.cpp. FinalGrade.cpp is the file to provide implementation of the member functions that are necessary for a grade to do. FinalGrade.cpp can get and set its score as well as determine its letter grade and print its score and letter grade. Gradebook.h provides declarations of member functions for Gradebook.cpp. Gradebook.cpp provides implementations of those member functions to ensure it can do the things that are necessary from a gradebook, such as add new grades, get size, get average, get max, get min and increment the scores and print the gradebook. Main.cpp is needed to run the 2 classes of gradebook and finalgrade. Main.cpp asks user for input of student grades and desired average. The main then displays the original grades and the curved grades. 

To compile the source code the following lines need to be typed into a Linux/Unix based terminal
g++ FinalGrade.cpp Gradebook.cpp main.cpp -o CS216PA1
./CS216PA1

