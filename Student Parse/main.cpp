#include <iostream>
#include <string>
#include "Roster.h"
#include "Degree.h"

using namespace std;


int main()
{
    const string studentData[] =
    { 
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Dekan,Peterson,dpet295@wgu.edu,23,20,30,22,SOFTWARE" 
    };

    cout << "Scripting and Programming - Applications - C867" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID : #009488313" << endl;
    cout << "Dekan Peterson" << endl;
    cout << endl;

    const int numStudents = 5;
    classRoster classRoster;


    // Parse
    for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);                    


    //Print All
    cout << "Displaying all students: " << endl;
    classRoster.printAll();                                                                     
    cout << endl;


    //Invalid Emails
    cout << "Displaying invalid emails:" << endl;
    cout << endl;
    classRoster.printInvalidEmails();                                                           
    cout << endl;

    //Average day in course
    for (int i = 0; i < numStudents; i++)
    {
        classRoster.printAverageDaysInCourse(classRoster.studentRosterArray[i]->getID());       
    }
    cout << endl;

    //DegreeProgram
    cout << "Showing students in degree program:" << endl;
    cout << endl;
    classRoster.printByDegreeProgram(SOFTWARE);                                                 


    //Remove
    cout << "Removing A3:" << endl;
    cout << endl;
    classRoster.remove("A3");                                                                   


    //Print All again
    classRoster.printAll(); 
    cout << endl;


    //Remove Again
    cout << "Removing A3 again" << endl;
    cout << endl;
    classRoster.remove("A3");                                                                    

    cout << "DONE." << endl;

    system("pause");
    return 0;
}

