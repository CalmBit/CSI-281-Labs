/*
*  Author: Silver Needle
*	Class : CSI-281-02
*	Assignment : PA 1
*	Date Assigned : 2016-08-29
*	Due Date : 2016-09-05
*	Description :
*		Generates a report of statistics related to student data.
*			Certification of Authenticity :
*		I certify that this is entirely my own work, except where I have given fully - documented references to the work of others.
*      I understand the definition and consequences of plagiarism and acknowledge that the assessor of this assignment may, for the purpose of assessing this assignment:
*			-Reproduce this assignment and provide a copy to another member of academic staff; and / or
*			-Communicate a copy of this assignment to a plagiarism checking service (which may then retain a copy of this assignment on its database for the purpose of
*           future plagiarism checking)
*/

#include "Semester.h"
#include <iostream>
#include <fstream>
#include <exception>

/*		 
*		 Pre:	std::istream with semester data, and an empty Semester object to parse data into.
*		Post:	Semester fully parsed, with Semester object containing parsed data.
*	 Purpose:	Load semester data from stream and fill empty Semester object with said data.
*/
std::istream& operator>> (std::istream& stream, Semester& rhs)
{
	std::string yearString,
				semesterFormString; //basic semester metadata

	std::string studentCountString; // semester student count, directly from stream

	// Read the year/form line from the semester's header
	std::getline(stream, yearString, ' ');

	// Now, let's parse that information out
	semesterFormString = yearString.substr(yearString.length() - 2);
	rhs.mYear = yearString.substr(0, yearString.length() - 2);


	/* 
	 * Check to see whether this semester is a Spring semester or a Fall semester, fails
	 * if it's found to be neither of these.
	*/
	if (semesterFormString == "SP")
	{
		rhs.mSemesterForm = SPRING_SEMESTER;
	}
	else if (semesterFormString == "FA")
	{
		rhs.mSemesterForm = FALL_SEMESTER;
	}
	else
	{
		throw std::runtime_error{ "Invalid semester type detected, unable to continue parsing." };
	}

	// We'll get the student count for the semester next
	std::getline(stream, studentCountString, '\n');

	// Convert this into a usable format - fail if it's a bad integer string
	rhs.mStudentCount = std::stoi(studentCountString);

	rhs.mStudentArray = new Student[rhs.getStudentCount()];

	for (size_t i = 0; i < rhs.getStudentCount(); i++)
	{
		std::string studentIdentifier,
					studentFirstName,
					studentLastName,
					studentYearString; // student metadata

		StudentYear studentYear; // student's year designation

		// First, parse out the student's ID number
		std::getline(stream, studentIdentifier, ' ');

		// Next, their first and last name
		std::getline(stream, studentFirstName, ' ');
		std::getline(stream, studentLastName, ' ');

		// Finally, their current year
		std::getline(stream, studentYearString, '\n');

		// Check to see if the year designation fits any of the categories, fail if it doesn't
		if (studentYearString == "FY")
		{
			studentYear = FIRST_YEAR;
		}
		else if (studentYearString == "SO")
		{
			studentYear = SOPHOMORE;
		}
		else if (studentYearString == "JR")
		{
			studentYear = JUNIOR;
		}
		else if (studentYearString == "SR")
		{
			studentYear = SENIOR;
		}
		else
		{
			throw std::runtime_error{ "Invalid student year designation detected, unable to continue parsing." };
		}

		// We'll put all of this information into the proper place in the students array
		rhs.mStudentArray[i].identifier = studentIdentifier;
		rhs.mStudentArray[i].studentYear = studentYear;
	}
}


SemesterForm Semester::getSemesterForm()
{
	return this->mSemesterForm;
}

Student* Semester::getStudentArray()
{
	return this->mStudentArray;
}

size_t Semester::getStudentCount()
{
	return this->mStudentCount;
}

std::string Semester::getYear()
{
	return this->mYear;
}

/*
*		 Pre:	Semester object filled with Student objects, and an identifier to search for
*		Post:	Returned value states whether or not the queried identifier exists within the
*				Semester object.
*	 Purpose:	Find an identifier within the calling semester
*/
bool Semester::searchForStudentIdentifier(std::string identifier)
{
	Student* studentArray = this->getStudentArray();
	for (size_t i = 0; i < this->getStudentCount(); i++)
	{
		if (identifier == studentArray[i].identifier) return true;
	}
	return false;
}

Semester::Semester()
{
	delete[] this->mStudentArray;
}

Semester::~Semester()
{

}
