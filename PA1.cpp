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
#include <fstream>
#include <iostream>

#include "PA1.h"

// TODO: Actual report file.



/*
*		 Pre:	Two Semester objects (chronologically related) setup, along with three counter arrays
*		Post:	Counter data modified according to the comparison
*	 Purpose:	Compare two semesters and output indexed Student count, along with indexed Student gains and losses
*/
void compareSemesters(Semester* currentSemester, Semester* lastSemester, int* lossCount, int* gainCount, int *actualCount)
{
	// Iterate through every student in the last semester to check for students who have left
	for (size_t i = 0; i < lastSemester->getStudentCount(); i++)
	{
		// Get a pointer to the student being looked at
		Student* student = &lastSemester->getStudentArray()[i];

		// Search for the student within the current semester
		bool studentPresent = currentSemester->searchForStudentIdentifier(student->identifier);

		// If the student didn't appear, we should increment the lossCount counter accordingly
		if (!studentPresent)
		{
			lossCount[student->studentYear]++;
		}
	}

	/*
		* Iterate through every student in the current semester to check for students who have joined.
		* Also iterate the actualCount for every student accordingly.
	*/
	for (size_t i = 0; i < currentSemester->getStudentCount(); i++)
	{
		// Get a pointer to the student being looked at
		Student *student = &currentSemester->getStudentArray()[i];

		// Increment actualCount to register this student
		actualCount[student->studentYear]++;

		// Search for the student within the last semester
		bool studentPresent = lastSemester->searchForStudentIdentifier(student->identifier);

		// If the student didn't appear, we should increment the gainCount counter accordingly
		if (!studentPresent)
		{
			gainCount[student->studentYear]++;
		}
	}
}

/*		
*		 Pre:	None
*		Post:	Report file created/truncated and filled with formatted report data.
*	 Purpose:	Load student data from file and format it into a readable report.	
*/
void loadStudentData(const char* fileName)
{
	std::ifstream recordsData{ fileName, std::ios_base::in };

	// Was the file unable to be opened? We can't continue if it was...
	if (!recordsData.good())
	{
		std::cerr << "Record file \"" << fileName << "\" unable to be found. Exiting...";
	}
	else
	{
		bool reading = true;

		Semester lastSemester; // keeps a copy of the last semester addressed for comparison purposes

		do
		{
			Semester semester{}; // temporary semester object

			/* 
			 * Try to read in some data into an empty semester object, printing an error message and stopping
			 * if it fails for any reason.
			*/
			try
			{
				recordsData >> semester;
			}
			catch (std::exception& e)
			{
				if (!recordsData.eof())
				{
					std::cerr << e.what() << std::endl;
				}

				reading = false;
				break;
			}

			int lossCount[4] = { 0 },
				gainCount[4] = { 0 },
				actualCount[4] = { 0 }; // counters for indexing student loss/gain and semester student counts

			// Compare the current and last semester and get back data from the comparison.
			compareSemesters(&semester, &lastSemester, lossCount, gainCount, actualCount);

			// Set the newest semester to be the next "last" semester.
			lastSemester = semester;

		} while (reading);
	}

	recordsData.close();
	
}

int main(int argc, char* argv[])
{
	const char *RECORDS_FILE = "records.txt";

	loadStudentData(RECORDS_FILE);

	std::cout << "Parsing finished!" << std::endl;

	std::cin.get();

	return 0;
}