#include "SemesterReport.h"
#include "Student.h"


std::ostream& operator<< (std::ostream& stream, const SemesterReport& rhs)
{
	std::string semesterFormTitle; // the actual "human readable" form of the semester form

	// Check to see what kind of semester is being reported on
	switch (rhs.mSemesterForm)
	{
	case SPRING_SEMESTER:
		semesterFormTitle = "Spring";
		break;
	case FALL_SEMESTER:
		semesterFormTitle = "Fall";
		break;
	default:
		semesterFormTitle = "Invalid";
		break;
	}

	stream << semesterFormTitle << " semester of " << rhs.mYear << " statistics: " << std::endl << std::endl;


}

SemesterReport::SemesterReport(int lossCount[4], int gainCount[4], int actualCount[4])
{
	for (int i = 0; i < 4; i++)
	{
		this->mLossCount[i] = lossCount[i];
		this->mGainCount[i] = gainCount[i];
		this->mActualCount[i] = actualCount[i];
	}
}

SemesterReport::~SemesterReport()
{

}