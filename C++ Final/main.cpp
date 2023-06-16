#include <iostream>
#include <string>
#include <array>
#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;

int main() {

    cout << "C867 - Scripting and Programming: Applications" << endl;
    cout << "Programming Language : C++" << endl;
    cout << "Student ID:010872975" << endl;
    cout << "Alexandra Scurtu" << endl;

    /* input data into student data table and add my personal information */
    const string studentDataRow[] = {
       "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
       "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
       "A5,Alexandra,Scurtu,ascurtu@wgu.edu,40,25,45,35,SOFTWARE"
    };

    const static int studentDataTable = 5;

    /* Create an instance of the Roster class called classRoster */
    Roster classRoster;

    /* Add each student to classRoster */
    for (int i = 0; i < studentDataTable; i++)
        classRoster.parse(studentDataRow[i]);
    cout << "All students:" << endl;

    /* Converting pseudocode to complete rest of main function */
    cout << "Printing all students: " << endl;
    classRoster.printAll();
    cout << endl;

    cout << "Printing invalid emails: " << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    /* loop through classRosterArray for each element to display average days in course per each student */
    cout << "Printing average days in course per each student: " << endl;
    for (int i = 0; i < studentDataTable; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
        cout << endl;
    }

    /* continue with the main functions */
    cout << "Printing Software Degrees: " << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;

    cout << "Removing student A3: " << endl;
    classRoster.remove("A3");
    cout << endl;

    cout << "Printing all students: " << endl;
    classRoster.printAll();
    cout << endl;

    /* expected: the above line should print a message saying such a student with this ID was not found */
    cout << "Removing student A3: " << endl;
    classRoster.remove("A3");
    cout << endl;

    /* implement destructor */
    classRoster.~Roster();

};
