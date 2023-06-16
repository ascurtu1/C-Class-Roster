#include <string>
#include <iostream>
#include <array>
#include "student.h"
#include "roster.h"

using namespace std;

Roster::Roster() {};
void Roster::parse(string studentDataRow) { /* parsing through each row in the student Data Table */
	int i = studentDataRow.find(",");
	string bID = studentDataRow.substr(0, i);

	int j = i + 1;
	i = studentDataRow.find(",", j);
	string first = studentDataRow.substr(j, i - j);

	j = i + 1;
	i = studentDataRow.find(",", j);
	string last = studentDataRow.substr(j, i - j);

	j = i + 1;
	i = studentDataRow.find(",", j);
	string email = studentDataRow.substr(j, i - j);

	j = i + 1;
	i = studentDataRow.find(",", j);
	int age = stoi(studentDataRow.substr(j, i - j));

	j = i + 1;
	i = studentDataRow.find(",", j);
	int daysToComplete1 = stoi(studentDataRow.substr(j, i - j));

	j = i + 1;
	i = studentDataRow.find(",", j);
	int daysToComplete2 = stoi(studentDataRow.substr(j, i - j));

	j = i + 1;
	i = studentDataRow.find(",", j);
	int daysToComplete3 = stoi(studentDataRow.substr(j, i - j));

	j = i + 1; /* parsing through degree program */
	i = studentDataRow.find(",", j);
	DegreeProgram degProg = SECURITY;
	if (studentDataRow.at(j) == 'N') {
		degProg = NETWORK;
	}
	else if (studentDataRow.at(j) == 'S' && studentDataRow.at(j + 1) == 'O') {
		degProg = SOFTWARE;
	}

	/* add the student objects to the roster */
	add(bID, first, last, email, age, daysToComplete1, daysToComplete2, daysToComplete3, degProg);
}



/* use add method to update the roster */
void Roster::add(string studentID, string firstName, string lastName, string emailAdd, int age, int daysToComplete1, int daysToComplete2, int daysToComplete3, DegreeProgram degreeprogram) {
	int daysComp[3] = { daysToComplete1, daysToComplete2, daysToComplete3 };
	classRosterArray[++arrayIndex] = new Student(studentID, firstName, lastName, emailAdd, age, daysComp, degreeprogram);
}

/*  removes students from the roster by student ID */
void Roster::remove(string studentID) {
	bool remove = false;
	for (int i = 0; i <= Roster::arrayIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			remove = true;
			if (i < numStudents - 1) {
				Student* current = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = current;
			}
			Roster::arrayIndex--;

		}
	}
	if (remove) {
		cout << studentID << " was removed successfully" << endl;
		this->printAll();
	}
	else {
		cout << "Error: not found" << endl;
	}
}

void Roster::printAll() {
	for (int i = 0; i <= Roster::arrayIndex; i++)
		Roster::classRosterArray[i]->print();
}


void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::arrayIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << studentID << ':';
			cout << ((classRosterArray[i]->getDaysToComplete()[0]
				+ classRosterArray[i]->getDaysToComplete()[1]
				+ classRosterArray[i]->getDaysToComplete()[2]) / 3) << endl;
		}
	}
}

/* A valid email should include an at sign ('@') and period ('.') and should not include a space (' '). */
void Roster::printInvalidEmails() {
	bool any = false;
	for (int i = 0; i <= Roster::arrayIndex; i++) {
		string emailAdd = (classRosterArray[i]->getEmailAdd());
		if ((emailAdd.find('@') == string::npos) || (emailAdd.find(' ') != string::npos) || (emailAdd.find('.') == string::npos)) {
			any = true;
			cout << emailAdd << ': ' << " is not valid" << endl;
		}

	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= Roster::arrayIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram)
			classRosterArray[i]->print();
	}
}

/* destructor */
Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		cout << "Destroying student # " << classRosterArray[i]->getStudentID() << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
};




























