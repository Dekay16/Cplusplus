#include <iostream>
#include <string>
#include "Roster.h"


using namespace std;

void classRoster::parse(string data) 
{
	// Student ID
	int rhs = data.find(",");
	string sID = data.substr(0, rhs);

	// First name
	int lhs = rhs + 1; // Moves past last comma to the next
	rhs = data.find(",", lhs);
	string sFirst = data.substr(lhs, rhs - lhs); // Finds the students first name

	// Last name
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string sLast = data.substr(lhs, rhs - lhs);

	// Email
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string sEmail = data.substr(lhs, rhs - lhs);

	// Age
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int sAge = stod(data.substr(lhs, rhs - lhs)); // Converts to Integer

	// Days 1
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int sDays1 = stod(data.substr(lhs, rhs - lhs));

	// Days 2
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int sDays2 = stod(data.substr(lhs, rhs - lhs));

	// Days 3
	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int sDays3 = stod(data.substr(lhs, rhs - lhs));

	string sDegree = data.substr(rhs + 1);
	DegreeProgram dDegree = DegreeProgram::NETWORK;
	if (sDegree == "SECURITY") 
	{
		dDegree = DegreeProgram::SECURITY;
	}
	if (sDegree == "SOFTWARE")
	{
		dDegree = DegreeProgram::SOFTWARE;
	}

	this->add(sID, sFirst, sLast, sEmail, sAge, sDays1, sDays2, sDays3, dDegree);
}

void classRoster::add(string sID, string sFirst, string sLast, string sEmail, int sAge, int sDays1, int sDays2, int sDays3, DegreeProgram dp) 
{
	int parr[3] = { sDays1, sDays2, sDays3 }; // Puts the three days into an array to simplify the output

	studentRosterArray[++lastIndex] = new classStudent(sID, sFirst, sLast, sEmail, sAge, parr, dp);
};

void classRoster::printAll() 
{
	for (int i = 0; i <= classRoster::lastIndex; i++)
	{
		studentRosterArray[i]->print();
	}
};

void classRoster::printAverageDaysInCourse(string studentID) 
{
	for (int i = 0; i <= classRoster::lastIndex; i++)
	{
		if (studentRosterArray[i]->getID() == studentID)
		{
			cout << "Student ID : " << studentRosterArray[i]->getID() << ", averrage days in course is: ";
			cout << (studentRosterArray[i]->getArrOfNumDays()[0] + studentRosterArray[i]->getArrOfNumDays()[1] + studentRosterArray[i]->getArrOfNumDays()[2]) / 3 << endl;
		}
	}
};

void classRoster::printByDegreeProgram(DegreeProgram dp) 
{
	for (int i = 0; i <= classRoster::lastIndex; i++) {
		if (classRoster::studentRosterArray[i]->getDegreeProgram() == dp) studentRosterArray[i]->print();
	}
	cout << endl;
};

void classRoster::remove(string studentID) 
{
	bool success = false;
	for (int i = 0; i <= classRoster::lastIndex; i++)
	{
		if (studentRosterArray[i]->getID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				classStudent* temp = studentRosterArray[i];
				studentRosterArray[i] = studentRosterArray[numStudents - 1];
				studentRosterArray[numStudents - 1] = temp;
			}
			classRoster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentID << " removed from the repository." << endl << endl;
		
	}
	else cout << "The student with ID: " << studentID << " was not found." << endl << endl;
};

void classRoster::printInvalidEmails() 
{
	bool any = false;
	for (int i = 0; i <= classRoster::lastIndex; i++)
	{
		string sEmail = (studentRosterArray[i]->getEmail());
		if (sEmail.find('@') == string::npos || (sEmail.find('.') == string::npos) || (sEmail.find(' ') != string::npos))
		{
			any = true;
			cout << sEmail << " - Invalid Email" << endl;
		}
	}
	if (any == false) cout << "No invalid emails." << endl;
};

classRoster::~classRoster() 
{
	cout << "Destructor Called" << endl << endl;
	for (int i = 0; i < numStudents; i++)
	{
		cout << "Destroying " << i + 1 << endl;
		delete studentRosterArray[i];
		studentRosterArray[i] = nullptr;
	}
};
