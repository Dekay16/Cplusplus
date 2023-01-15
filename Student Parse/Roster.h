#pragma once
#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

class classRoster {
public:
	int lastIndex = -1; // Starts at 0
	const static int numStudents = 5; // 5 students
	classStudent* studentRosterArray[numStudents];
	void parse(string data);
	void add(string sID, string sFirst, string sLast, string sEmail, int sAge, int sDays1, int sDays2, int sDays3, DegreeProgram dp);
	void remove(string studentID);
	void printAll();
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(DegreeProgram dp);
	~classRoster();
};