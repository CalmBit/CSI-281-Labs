#ifndef SEMESTER_REPORT_H
#define SEMESTER_REPORT_H

#include <ostream>
#include "Semester.h"
class SemesterReport
{
	private:
		int mLossCount[4] = { 0 }; 
		int mGainCount[4] = { 0 };
		int mActualCount[4] = { 0 };
		size_t mStudentCount;
		std::string mYear;
		SemesterForm mSemesterForm;
	public:
		friend std::ostream& operator<<(std::ostream& stream, const SemesterReport& rhs);
		SemesterReport(int lossCount[4], int gainCount[4], int actualCount[4]);
		~SemesterReport();
};

#endif