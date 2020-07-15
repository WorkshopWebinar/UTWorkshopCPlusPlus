#include <gtest/gtest.h>

#include <LeapYear.h>

using namespace std;

class LeapYearParameterizedTestFixture :public::testing::WithParamInterface<int>,public ::testing::Test
{
protected:

    LeapYearCalendar leapYearCalendar;

static void SetUpTestSuite ()
{ }

   void SetUp() override 
   {

   }

};

/*TEST_F(LeapYearParameterizedTestFixture, FixtureTest)
{
 //do nothing
}
*/
TEST_P(LeapYearParameterizedTestFixture, OddYearsAreNotLeapYears) {
    int year = GetParam();
    ASSERT_FALSE(leapYearCalendar.isLeap(year));
    SUCCEED();
}

//INSTANTIATE_TEST_CASE_P(
INSTANTIATE_TEST_CASE_P(LeapYearTests,LeapYearParameterizedTestFixture, ::testing::Values(1,711,1989,2019),testing::PrintToStringParamName());
 
