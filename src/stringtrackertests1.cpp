#include <sstream>
#include "stringtracker.h"
#include <catch2/catch_test_macros.hpp>

//Test Cases for findString  
TEST_CASE("StringTracker::findString - Empty StringTracker")
{
    StringTracker testCase;

    REQUIRE( testCase.findString("Goat") == false );
}

TEST_CASE("StringTracker::findString - One in StringTracker - false")
{
    StringTracker testCase;
    testCase.addString("Goats");

    REQUIRE( testCase.findString("Goat") == false );
}

TEST_CASE("StringTracker::findString - One in StringTracker - true")
{
    StringTracker testCase;
    testCase.addString("Goat");

    REQUIRE( testCase.findString("Goat") == true );
}

TEST_CASE("StringTracker::findString - Four in StringTracker - true")
{
    StringTracker testCase;
    testCase.addString("Banana");
    testCase.addString("Bananana");
    testCase.addString("GoatBanananas");
    testCase.addString("Goat");

    REQUIRE( testCase.findString("Goat") == true );
}

TEST_CASE("StringTracker::findString - Four in StringTracker - false")
{
    StringTracker testCase;
    testCase.addString("Banana");
    testCase.addString("Bananana");
    testCase.addString("GoatBanananas");
    testCase.addString("Goat");

    REQUIRE( testCase.findString("Goats") == false );
}

//Test Cases for Empty
TEST_CASE("StringTracker::empty - Empty StringTracker")
{
    StringTracker testCase;

    REQUIRE( testCase.empty() == true );
}

TEST_CASE("StringTracker::empty - Not Empty StringTracker")
{
    StringTracker testCase;

    std::string testword = "word";

    testCase.addString(testword);

    REQUIRE(testCase.empty() == false);
}
//Test Cases for Size
TEST_CASE("StringTracker::size - Empty StringTracker")
{
    StringTracker testCase;

    REQUIRE( testCase.size() == 0 );
}

TEST_CASE("StringTracker::size - One in StringTracker")
{
    StringTracker testCase;

    std::string testword = "word";

    testCase.addString(testword);

    REQUIRE( testCase.size() == 1 );
}

TEST_CASE("StringTracker::size - Five in StringTracker")
{
    StringTracker testCase;

    testCase.addString("Word");
    testCase.addString("Super");
    testCase.addString("Wild");
    testCase.addString("Superb");
    testCase.addString("Superbly");

    REQUIRE( testCase.size() == 5 );
}

TEST_CASE("StringTracker::size - Add Five, Remove One in StringTracker")
{
    StringTracker testCase;

    testCase.addString("Word");
    testCase.addString("Super");
    testCase.addString("Wild");
    testCase.addString("Superb");
    testCase.addString("Superbly");
    testCase.removeString("Super");

    REQUIRE( testCase.size() == 4 );
}

TEST_CASE("StringTracker::size - Add One, Remove One in StringTracker")
{
    StringTracker testCase;

    testCase.addString("Word");
    testCase.removeString("Word");

    REQUIRE( testCase.size() == 0 );
}


//Test Cases for clear.
TEST_CASE("StringTracker::clear - Clear with 0 in StringTracker")
{
    StringTracker testCase;

    testCase.clear();

    REQUIRE( testCase.size() == 0 );
}

TEST_CASE("StringTracker::clear - Clear with 1 in StringTracker")
{
    StringTracker testCase;

    testCase.addString("Word");
    testCase.clear();

    REQUIRE( testCase.size() == 0 );
}

TEST_CASE("StringTracker::clear - Clear with 5 in StringTracker")
{
    StringTracker testCase;

    testCase.addString("Word");
    testCase.addString("Super");
    testCase.addString("Wild");
    testCase.addString("Superb");
    testCase.addString("Superbly");
    testCase.clear();


    REQUIRE( testCase.size() == 0 );
}