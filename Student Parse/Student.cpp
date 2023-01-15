#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

classStudent::classStudent()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < sizeArrDays; i++) this->ArrOfNumDays[i] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;
};

classStudent::classStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int ArrOfNumDays[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < sizeArrDays; i++) this->ArrOfNumDays[i] = ArrOfNumDays[i];
	this->degreeProgram = degreeProgram;
};

string classStudent::getID() { return this->studentID; }
string classStudent::getFirst() { return this->firstName; }
string classStudent::getLast() { return this->lastName; }
string classStudent::getEmail() { return this->emailAddress; }
int classStudent::getAge() { return this->age; }
int* classStudent::getArrOfNumDays() { return this->ArrOfNumDays; } 
DegreeProgram classStudent::getDegreeProgram() { return this->degreeProgram; }

void classStudent::setID(string ID) { this->studentID = ID; }
void classStudent::setFirst(string First) { this->firstName = First; }
void classStudent::setLast(string Last) { this->lastName = Last; }
void classStudent::setEmail(string Email) { this->emailAddress = Email; }
void classStudent::setAge(int Age) { this->age = Age; }
void classStudent::setArrOfNumDays(int ArrOfNumDays[]) {
	for (int i = 0; i < sizeArrDays; i++) this->ArrOfNumDays[i] = ArrOfNumDays[i];
} 
void classStudent::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp; }

void classStudent::print() {
	cout << this->getID() << '\t';
	cout << this->getFirst() << '\t';
	cout << this->getLast() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << "{" << this->getArrOfNumDays()[0] << ',';
	cout << this->getArrOfNumDays()[1] << ',';
	cout << this->getArrOfNumDays()[2] << "}" << '\t';
	cout << degreeProgramStrings[this->getDegreeProgram()] << '\n'; 
};


classStudent::~classStudent() {}; //Destructor

