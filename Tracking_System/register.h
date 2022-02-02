#pragma once
#include "pupil.h"

class Register {
private: 
	Pupil* classRegisterArray[5];
	int classRegisterArraySize{ 5 };
public:
	//constructor
	Register();
	//destructor
	~Register();

	//Function to add the parsed pupil string to classRegisterArray
	void addPupil(int i, std::string pupilID, std::string firstName, std::string lastName, std::string email, int age, int days1, int days2, int days3, std::string subject);

	//Function to parse the string array of pupil data
	void parse(int i, std::string data);

	std::string getID(int arrayElement);
	void printAll();
	void remove(std::string pupilID);
	void printAverageDaysInCourse(std::string pupilID);
	void printInvalidEmails();
	void printBySubjectProgram(Subject subject);
};
