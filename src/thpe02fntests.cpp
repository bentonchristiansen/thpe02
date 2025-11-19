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

TEST_CASE("intoTracker - put new word into tracker")
{

}

TEST_CASE("intoTracker - word in tracker, increment counter")
{
    
}
