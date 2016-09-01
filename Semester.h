#ifndef SEMESTER_H
#define SEMESTER_H

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

#include <string>
#include <istream>
#include "Student.h"

// The time at which the semester takes place: either the spring, or the fall.
enum SemesterForm
{
	FALL_SEMESTER,
	SPRING_SEMESTER
};

class Semester
{
	public:
		SemesterForm getSemesterForm() { return this->mSemesterForm; }
		Student* getStudentArray() { return this->mStudentArray; }
		size_t getStudentCount() { return this->mStudentCount;  }
		std::string getYear() { return this->mYear;  }
		friend std::istream& operator>> (std::istream& stream, Semester& rhs);
		bool searchForStudentIdentifier(std::string identifier);
		Semester();
		~Semester();

	private:
		SemesterForm mSemesterForm;
		Student* mStudentArray;
		size_t mStudentCount;
		std::string mYear;
};

#endif