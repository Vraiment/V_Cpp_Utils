#include "catch.hpp"

#include "initializer_list_utils.hpp"

#include <sstream>

using namespace std;
using namespace VCppUtils;

constexpr auto TAGS = "";

TEST_CASE("Test join initializer list")
{
    SECTION("Test with inline list")
    {
        auto stream = stringstream{};
        
        join(stream, '/', { 2017, 10, 20 });
        
        REQUIRE(stream.str() == "2017/10/20");
    }
    
    SECTION("Test with list in variable")
    {
        auto input = initializer_list<int>{ 33, 44, 55 };
        
        auto stream = stringstream{};
        
        join(stream, '+', input);
        
        REQUIRE(stream.str() == "33+44+55");
    }
}
