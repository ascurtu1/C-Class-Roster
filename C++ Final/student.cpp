#include <string>
#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;

/* parameterless constructor */
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAdd = "";
	this->age = 0;
	this->daysToComplete[0] = 0;
	this->daysToComplete[1] = 0;
	this->daysToComplete[2] = 0;
	this->degreeProgram = degreeProgram;
}

/* constructor using all parameters provided in the table */
Student::Student(string studentID, string firstName, string lastName, string emailAdd, int age, int daysToComplete[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAdd = emailAdd;
	this->age = age;
	this->daysToComplete[0] = daysToComplete[0];
	this->daysToComplete[1] = daysToComplete[1];
	this->daysToComplete[2] = daysToComplete[2];
	this->degreeProgram = degreeProgram;
}

Student:: ~Student() {}

/* getters */
string Student::getStudentID() {
	return this->studentID;
}
string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}
string Student::getEmailAdd() {
	return this->emailAdd;
}
int Student::getAge() {
	return this->age;
}
int* Student::getDaysToComplete() {
	return this->daysToComplete;
}
DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

/* setters */
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAdd(string EmailAdd) {
	this->emailAdd = EmailAdd;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDaysToComplete(int daysToComplete[]) {
	for (int i = 0; i < 3; i++) this->daysToComplete[i] = daysToComplete[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}
/* print */
void Student::print() {
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAdd() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysToComplete()[0] << ',';
	cout << this->getDaysToComplete()[1] << ',';
	cout << this->getDaysToComplete()[2] << '\t';
	cout << degreeProgramString[this->getDegreeProgram()] << endl;
};












