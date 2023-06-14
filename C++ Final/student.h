#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student {

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAdd;
	int age;
	int daysToComplete[3];
	DegreeProgram degreeProgram;

public:
	/* parameterless constructor */
	Student();
	/* constructor using all parameters provided in the table */
	Student(string studentID, string firstName, string lastName, string emailAdd, int age, int daysToComplete[], DegreeProgram degreeProgram);
	/* destructor */
	~Student();

	/* getters */
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAdd();
	int getAge();
	int* getDaysToComplete();
	DegreeProgram getDegreeProgram();

	/* setters */
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAdd(string emailAdd);
	void setAge(int age);
	void setDaysToComplete(int daysToComplete[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	/* print variables */
	void print();
	void printStudentID();
	void printFirstName();
	void printLastName();
	void printEmailAdd();
	void printAge();
	void printDaysToComplete();
	void printDegreeProgram();

};

#endif /* STUDENT_H */
