#include <sstream>
#include "thpe02.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("cleanWord - no punctuation")
{
    std::string word = "word";
    cleanWord(word);
    REQUIRE(word == "word");
}

TEST_CASE("cleanWord - front punctuation")
{
    std::string word = ".word";
    cleanWord(word);
    REQUIRE(word == "word");
}

TEST_CASE("cleanWord - back punctuation")
{
    std::string word = "word,";
    cleanWord(word);
    REQUIRE(word == "word");
}

TEST_CASE("cleanWord - front and back punctuation")
{
    std::string word = ",word.";
    cleanWord(word);
    REQUIRE(word == "word");
}

TEST_CASE("cleanWord - multiple front and back punctuation")
{
    std::string word = ",,.,..!word!!,.,.!!!";
    cleanWord(word);
    REQUIRE(word == "word");
}

TEST_CASE("cleanWord - non ASCII punctuation")
{
    std::string word = "word&!'}}[]";
    cleanWord(word);
    REQUIRE(word == "word");
}

TEST_CASE("cleanWord - punctuation in the middle")
{
    std::string word = "wo.rd";
    cleanWord(word);
    REQUIRE(word == "wo.rd");
}

TEST_CASE("intoTracker - put new word into tracker")
{
    StringTracker tester;
    std::ostringstream oss;
    std::string word = "word";
    intoTracker(word, tester);
    tester.print(oss);
    REQUIRE(oss.str() == "word(1)");
}

TEST_CASE("intoTracker - word in tracker, increment counter")
{
    StringTracker tester;
    std::ostringstream oss;
    std::string word = "word";
    intoTracker(word, tester);
    intoTracker(word, tester);
    tester.print(oss);
    REQUIRE(oss.str() == "word(2)");
}
