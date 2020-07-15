#include <gtest/gtest.h>

#include <LeapYear.h>

TEST(LeapYearTests, 1IsOdd_IsNotLeapYear) {
LeapYearCalendar leapYearCalendar;
ASSERT_FALSE(leapYearCalendar.isLeap(1));
}
