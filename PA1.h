#ifndef PA1_H
#define PA1_H

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

void compareSemesters(Semester* currentSemester, Semester* lastSemester, int* lossCount, int* gainCount, int *actualCount);
void loadStudentData(const char* fileName);


#endif