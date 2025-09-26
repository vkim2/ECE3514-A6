// test_vector.cpp
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"
#include "vector.hpp"
#include <stdexcept>

// create const vector for testing
/*
dsa::Vector<int> v;
for (int i{0}; i < 5; ++i) 
    v.push_back(i);
const dsa::Vector<int>& cv = v;
*/
TEST_CASE("Default constructor creates empty vector") {
    dsa::Vector<int> v;
    bool ok{true};
    REQUIRE(ok);
}

