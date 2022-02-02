#include<iostream>
#include "pupil.h"

//implement constructor
Pupil::Pupil(std::string pupilID_, std::string firstName_, std::string lastName_, std::string email_, int age_, int daysInCourse_[3], Subject subject_)
	: pupilID{ pupilID_ }, firstName{ firstName_ }, lastName{ lastName_ }, email{ email_ }, age{ age_ }, daysInCourse{ daysInCourse_[3] }, subject{ subject_ } {for (int i = 0; i < 3; i++) {
	daysInCourse[i] = daysInCourse_[i];
		};};

//impliment destructor
Pupil::~Pupil() {};

//getters

std::string Pupil::getPupilID() const {
	return pupilID;
};

std::string Pupil::getFirstName() const {
	return firstName;
};

std::string Pupil::getLastName() const {
	return lastName;
};

std::string Pupil::getEmail() const {
	return email;
};

int Pupil::getAge() const {
	return age;
};


int* Pupil::getDays() const {
	int arrayDays[3]{};
	for (int i = 0; i < 3; i++) {
		if (i != 2) {
			arrayDays[i] = daysInCourse[i];
		}
		else {
			arrayDays[i] = daysInCourse[i];
		}
	}
	return arrayDays;
};


std::string Pupil::getSubject() const {
	std::string subject_{};
	if (subject == Subject::NETWORK) {
		subject_ = "Network";
	}
	else if (subject == Subject::SECURITY) {
		subject_ = "Security";
	}
	else if (subject == Subject::SOFTWARE) {
		subject_ = "Software";
	}
	else {
		subject_ = "error, incorrect subject";
	}

	return subject_;
};

//setters:
void Pupil::setPupilID(std::string pupilID) {
	this->pupilID = pupilID;
};

void Pupil::setFirstName(std::string firstName) {
	this->firstName = firstName;
};

void Pupil::setLastName(std::string lastName) {
	this->lastName = lastName;
};

void Pupil::setEmail(std::string email) {
	this->email = email;
};

void Pupil::setAge(int age) {
	this->age = age;
};


void Pupil::setDaysInCourse(int daysInCourse[3]) {
	for (int i = 0; i < 3; i++) {
		this->daysInCourse[i] = daysInCourse[i];
	}
};

void Pupil::setSubject(Subject subject) {
	this->subject = subject;
};
void Pupil::print() {
	std::cout << getPupilID() << '\t';
	std::cout << "First Name: " << getFirstName() << '\t';
	std::cout << "Last Name: " << getLastName() << '\t';
	std::cout << "Email: " << getEmail() << '\t';
	std::cout << "Age: " << getAge() << '\t';
	std::cout << "Days in Course: ";
	int* arrayDays = this->getDays();
	std::cout << "{" << arrayDays[0] << "," << arrayDays[1] << "," << arrayDays[2] << "}" << "\t";
	std::cout << "Subject: ";
	std::cout << this->getSubject() << "\t";
}