#include <sstream>
#include "stringtracker.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("StringTracker::addString", "[addString]") {
    StringTracker tracker;
    
    SECTION("Add to empty list") {
        REQUIRE(tracker.addString("banana"));
        REQUIRE(!tracker.empty());
        REQUIRE(tracker.size() == 1);
        REQUIRE(tracker.getCount("banana") == 1);
    }

    SECTION("Add in ascending order (head, middle, tail)") {
        REQUIRE(tracker.addString("banana"));
        REQUIRE(tracker.addString("apple"));
        REQUIRE(tracker.addString("cherry"));
        REQUIRE(tracker.size() == 3);

        std::ostringstream oss;
        tracker.print(oss);
        REQUIRE(oss.str() == "apple(1),banana(1),cherry(1)");
    }

    SECTION("Add duplicate string (should do nothing)") {
        tracker.addString("apple");
        REQUIRE(tracker.getCount("apple") == 1);
        REQUIRE(tracker.size() == 1);

        REQUIRE(tracker.addString("apple"));
        REQUIRE(tracker.size() == 1);
        REQUIRE(tracker.getCount("apple") == 1); 
    }
}

TEST_CASE("StringTracker::removeString", "[removeString]") {
    StringTracker tracker;
    tracker.addString("apple");
    tracker.addString("banana");
    tracker.addString("cherry");

    SECTION("Remove from middle") {
        REQUIRE(tracker.removeString("banana"));
        REQUIRE(tracker.size() == 2);
        REQUIRE(!tracker.findString("banana"));
        std::ostringstream oss;
        tracker.print(oss);
        REQUIRE(oss.str() == "apple(1),cherry(1)");
    }

    SECTION("Remove from head") {
        REQUIRE(tracker.removeString("apple"));
        REQUIRE(tracker.size() == 2);
        REQUIRE(!tracker.findString("apple"));
        std::ostringstream oss;
        tracker.print(oss);
        REQUIRE(oss.str() == "banana(1),cherry(1)");
    }

    SECTION("Remove from tail") {
        REQUIRE(tracker.removeString("cherry"));
        REQUIRE(tracker.size() == 2);
        REQUIRE(!tracker.findString("cherry"));
        std::ostringstream oss;
        tracker.print(oss);
        REQUIRE(oss.str() == "apple(1),banana(1)");
    }

    SECTION("Remove non-existent string") {
        REQUIRE(!tracker.removeString("date"));
        REQUIRE(tracker.size() == 3);
    }
}

TEST_CASE("StringTracker::Count functions", "[count]") {
    StringTracker tracker;
    tracker.addString("apple");
    tracker.addString("banana");

    SECTION("getCount") {
        REQUIRE(tracker.getCount("apple") == 1);
        REQUIRE(tracker.getCount("banana") == 1);
        REQUIRE(tracker.getCount("cherry") == 0);
    }

    SECTION("incrementCount") {
        REQUIRE(tracker.incrementCount("apple"));
        REQUIRE(tracker.getCount("apple") == 2);
        
        REQUIRE(tracker.incrementCount("apple"));
        REQUIRE(tracker.getCount("apple") == 3);
        
        REQUIRE(!tracker.incrementCount("cherry"));
        REQUIRE(tracker.getCount("cherry") == 0);
    }

    SECTION("decrementCount") {
        REQUIRE(tracker.incrementCount("apple"));
        REQUIRE(tracker.getCount("apple") == 2);
        
        REQUIRE(tracker.decrementCount("apple"));
        REQUIRE(tracker.getCount("apple") == 1);
        
        REQUIRE(tracker.decrementCount("apple"));
        REQUIRE(tracker.getCount("apple") == 0);

        REQUIRE(tracker.decrementCount("apple"));
        REQUIRE(tracker.getCount("apple") == -1);

        REQUIRE(!tracker.decrementCount("cherry"));
    }
}

TEST_CASE("StringTracker::getMaximumCount", "[max]") {
    StringTracker tracker;

    SECTION("Get max from empty list") {
        REQUIRE(tracker.getMaximumCount() == 0);
    }

    SECTION("Get max from list") {
        tracker.addString("apple");
        tracker.addString("banana");
        tracker.incrementCount("banana");
        tracker.addString("cherry");
        tracker.incrementCount("cherry");
        tracker.incrementCount("cherry");
        
        REQUIRE(tracker.getMaximumCount() == 3);
    }

    SECTION("Get max after changes") {
        tracker.addString("apple");
        tracker.incrementCount("apple");
        REQUIRE(tracker.getMaximumCount() == 2);
        
        tracker.decrementCount("apple");
        tracker.decrementCount("apple");
        REQUIRE(tracker.getMaximumCount() == 0); 
    }
}

TEST_CASE("StringTracker::print", "[print]") {
    StringTracker tracker;
    std::ostringstream oss;

    SECTION("Print empty list") {
        tracker.print(oss);
        REQUIRE(oss.str() == "");
    }

    SECTION("Print list with one item") {
        tracker.addString("apple");
        tracker.incrementCount("apple");
        tracker.print(oss);
        REQUIRE(oss.str() == "apple(2)");
    }

    SECTION("Print list with multiple items") {
        tracker.addString("banana");
        tracker.addString("apple");
        tracker.incrementCount("apple");
        tracker.addString("cherry");
        
        tracker.print(oss);
        REQUIRE(oss.str() == "apple(2),banana(1),cherry(1)");
    }
}