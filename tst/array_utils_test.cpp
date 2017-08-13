#include "catch.hpp"

#include "array_utils.hpp"

#include <sstream>

using namespace std;
using namespace VCppUtils;

TEST_CASE("Test join array")
{
    SECTION("Test with several elements")
    {
        auto input = array<int, 5>{
            { 3, 1, 4, 1, 6 }
        };
        
        auto stream = stringstream{};
        
        join(stream, '.', input);
        
        REQUIRE(stream.str() == "3.1.4.1.6");
    }
    
    SECTION("Test with inline array")
    {
        auto stream = stringstream{};
        
        join(stream, '-', array<int, 3>{ {1, 2, 3} });
        
        REQUIRE(stream.str() == "1-2-3");
    }
}
