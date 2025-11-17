#include <sstream>
#include "stringtracker.h"
#include <catch2/catch_test_macros.hpp>

// This is where my test cases go when I grade.
TEST_CASE("StringTracker::addString - add to empty list")
{
    bool retValue;
    std::string addValue = "The Banana";
    std::ostringstream sout;

    StringTracker myTracker;

    retValue = myTracker.addString(addValue);
    REQUIRE(retValue);

    // check printout with output string stream
    myTracker.print(sout);
    REQUIRE(sout.str() == "The Banana(1)");
}

TEST_CASE("StringTracker::addString - RS try duplicates being added to list")
{
    bool retValue;
    std::string addValue = "Bananas";
    std::ostringstream sout;

    StringTracker myTracker;
    retValue = myTracker.addString(addValue);
    REQUIRE(retValue);

    retValue = myTracker.addString(addValue);
    REQUIRE(retValue);

    // check printout with output string stream
    myTracker.print(sout);
    REQUIRE(sout.str() == "Bananas(1)");
}