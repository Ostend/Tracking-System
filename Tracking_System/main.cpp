#include<iostream>
#include<sstream>
#include "pupil.h"
#include "subject.h"
#include "register.h"

Register* parse(std::string);
int main() {
	const std::string pupilData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Scarlette,Magnolia,aaaaaaa@google.edu,32, 30,35,40,SOFTWARE" };


	Register classRegister;

	std::cout << "C867" << "\n" << "Scripting and Programming - Applications" << "\n" << "c++" << "\n" << "Pupil ID: #001543222" << "\n" << "Stephanie Mennear" << "\n" << std::endl;

	for (int i = 0; i < 5; i++) {
		classRegister.parse(i, pupilData[i]);

	};


	std::cout << "****************************" << std::endl;
	std::cout << "Printing class roster: " << std::endl;
	classRegister.printAll();
	std::cout << "\n";
	std::cout << "****************************" << std::endl;
	std::cout << "Printing invalid emails: " << std::endl;
	classRegister.printInvalidEmails();
	std::cout << "\n";
	std::cout << "****************************" << std::endl;
	std::cout << "Printing average of days in course per pupil: " << std::endl;
	for (int i = 0; i < 5;i++) {
		std::cout << "\n";
		std::string pupil = classRegister.getID(i);
		classRegister.printAverageDaysInCourse(pupil);
	};
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "****************************" << std::endl;
	std::cout << "Printing by subject program Software: " << std::endl;
	classRegister.printBySubjectProgram(Subject::SOFTWARE);
	std::cout << "\n";

	classRegister.remove("A3");
	std::cout << "****************************" << std::endl;
	std::cout << "Printing after removal of pupil A3: " << std::endl;
	classRegister.printAll();
	std::cout << "\n";
	classRegister.remove("A3");
};





