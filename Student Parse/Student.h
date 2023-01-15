#pragma once
#include <iostream>
#include <string>
#include "Degree.h"

using namespace std;

class classStudent {
public:
	const static int sizeArrDays = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int ArrOfNumDays[sizeArrDays];
	DegreeProgram degreeProgram;

public:
	classStudent(); // Default Constructor
	classStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int ArrofNumDays[], DegreeProgram degreeProgram); // Constructor

	/**********************************************
	* Accessors
	***********************************************/
	string getID();
	string getFirst();
	string getLast();
	string getEmail();
	int getAge();
	int* getArrOfNumDays();
	DegreeProgram getDegreeProgram();

	/************************************************
	* Mutators
	*************************************************/
	void setID(string ID);
	void setFirst(string First);
	void setLast(string Last);
	void setEmail(string Email);
	void setAge(int Age);
	void setArrOfNumDays(int ArrOfNumDays[]);
	void setDegreeProgram(DegreeProgram dp);

	void print();

	~classStudent(); // Destructor

};