#pragma once
#include<iostream>
#include "subject.h"

class Pupil {
private:
	std::string pupilID;
	std::string firstName;
	std::string lastName;
	std::string email;
	int age;
	int daysInCourse[3];
	Subject subject;

public:
	//constructor
	Pupil(std::string pupilID_, std::string firstName_, std::string lastName_, std::string email, int age, int* daysInCourse, Subject subject);

	//desctructor
	~Pupil();

	//getters
	std::string getPupilID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getEmail() const;
	int getAge() const;
	int* getDays() const;
	std::string getSubject() const;

	//Setters
	void setPupilID(std::string PupilID);
	void setFirstName(std::string firstName);
	void setLastName(std::string lastName);
	void setEmail(std::string email);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[3]);
	void setSubject(Subject subject);


	void print();
};