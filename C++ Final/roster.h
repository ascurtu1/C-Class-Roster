#pragma once
#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <array>
#include <string>
#include "student.h"
using namespace std;

class Roster {

public:
	Roster(); /* constructor */
	int arrayIndex = -1;
	const static int numStudents = 5;
	/* create array to hold data provided in student table*/
	Student* classRosterArray[numStudents];
	void parse(string studentDataRow); /* goes through string data in the studentData Table and creates objects to add to classRosterArray */
	void add(
		string studentID,
		string firstName,
		string lastName,
		string emailAdd,
		int age,
		int daysToComplete1,
		int daysToComplete2,
		int daysToComplete3,
		DegreeProgram degreeprogram
	);
	void remove(string studentID); /* remove students from the class roster */
	void printAll();/* calls the print() function for each student */
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	
	~Roster(); /* destructor */
};

#endif /* ROSTER_H */