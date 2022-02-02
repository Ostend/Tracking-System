#include "register.h"
#include <sstream>

Register::Register() {};
Register::~Register() {};

//Implementation of function to add the parsed pupil string to classRegisterArray
void Register::addPupil(int i, std::string pupilID, std::string firstName, std::string lastName, std::string email, int age, int days1, int days2, int days3, std::string subject) {
	int daysInCours[3] = { days1, days2, days3 };
	Subject subject_{};
	if (subject == "SECURITY") {
		subject_ = Subject::SECURITY;
	}
	else if (subject == "NETWORK") {
		subject_ = Subject::NETWORK;
	}
	else if (subject == "SOFTWARE") {
		subject_ = Subject::SOFTWARE;
	}
	else {
		std::cout << "error, incorrect subject" << std::endl;
	}
	classRegisterArray[i] = new Pupil(pupilID, firstName, lastName, email, age, daysInCours, subject_);
};

//Implementation of function to parse the string array of pupil data. 
void Register::parse(int i, std::string data) {
	int count = i;
	size_t rhs = data.find(",");
	std::string pupilID = data.substr(0, rhs);
	size_t lhs = rhs + 1;
	rhs = data.find(",", lhs);
	std::string firstName = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	std::string lastName = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	std::string email = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int age = std::stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int day1 = std::stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int day2 = std::stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int day3 = std::stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	std::string subject = (data.substr(lhs, rhs - lhs));

	//calling addPupil to add the parsed pupil data to the classRegisterArray as a new Pupil instance.
	addPupil(count, pupilID, firstName, lastName, email, age, day1, day2, day3, subject);

}
void Register::printAll() {
	for (int i = 0; i < classRegisterArraySize; i++) {
		classRegisterArray[i]->print();
		std::cout << "\n" << std::endl;
	}
};

void Register::remove(std::string pupilID) {
	bool exists = false;
	for (int i = 0; i < classRegisterArraySize;i++) {
		if (classRegisterArray[i]->getPupilID() == pupilID) {
			exists = true;
			for (int j = i; j < classRegisterArraySize;j++) {
				classRegisterArray[j] = classRegisterArray[j + 1];
			}
			classRegisterArraySize--;
		};
	}

	if (!exists) {
		std::cout << "Error, Pupil with PupilID " << pupilID << " was not found." << std::endl;
	}
}

void Register::printAverageDaysInCourse(std::string pupilID) {
	int averageDays{};

	for (int i = 0; i < classRegisterArraySize;i++) {
		if (classRegisterArray[i]->getPupilID() == pupilID) {
			int* arrayDays = classRegisterArray[i]->getDays();
			averageDays = (arrayDays[0] + arrayDays[1] + arrayDays[2]) / 3;
		}
	}
	std::cout << "Pupil with ID: " << pupilID << " has an average of " << averageDays << " days in the course.";
}

void Register::printInvalidEmails() {
	for (int i = 0; i < classRegisterArraySize;i++) {
		std::string email = classRegisterArray[i]->getEmail();
		if (email.find('@') == std::string::npos || email.find(".") == std::string::npos || email.find(" ") != std::string::npos) {
			std::cout << "Invalid email: " << email << std::endl;
		}
	}

}

std::string  Register::getID(int arrayElement) {
	return classRegisterArray[arrayElement]->getPupilID();
}

void Register::printBySubjectProgram(Subject subject) {
	std::string result{};
	switch (subject) {
	case Subject::NETWORK:
		result = "Network";
		break;
	case Subject::SECURITY:
		result = "Security";
		break;
	case Subject::SOFTWARE:
		result = "Software";
		break;

	};
	for (int i = 0; i < classRegisterArraySize; i++) {
		std::string subject_ = classRegisterArray[i]->getSubject();
		if (result == subject_) {
			classRegisterArray[i]->print();
			std::cout << "\n";
		};
	};

}