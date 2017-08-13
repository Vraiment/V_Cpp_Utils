#include "catch.hpp"

#include "string_utils.hpp"

using namespace std;
using namespace VCppUtils;

TEST_CASE("Test string starting with")
{
    SECTION("Test with empty input and to search strings")
    {
        auto const input = string{};
        auto const toSearch = string{};
        
        auto const result = str_starts_with(input, toSearch);
        
        REQUIRE(result == true);
    }

    SECTION("Test with empty input string")
    {
        auto const input = string{};
        auto const toSearch = string{"Some string to search"};
        
        auto const result = str_starts_with(input, toSearch);
        
        REQUIRE(result == false);
    }
    
    SECTION("Test with non empty input string and empty search string")
    {
        auto const input = string{"some input string"};
        auto const toSearch = string{};
        
        auto const result = str_starts_with(input, toSearch);
        
        REQUIRE(result == true);
    }
    
    SECTION("Test with a shorter non matching string")
    {
        auto const input = string{"some input string"};
        auto const toSearch = string{"some string"};
        
        auto const result = str_starts_with(input, toSearch);
        
        REQUIRE(result == false);
    }
    
    SECTION("Test with a longer non matching string")
    {
        auto const input = string{"some input string"};
        auto const toSearch = string{"some string to search"};
        
        auto const result = str_starts_with(input, toSearch);
        
        REQUIRE(result == false);
    }
    
    SECTION("Test with a matching string")
    {
        auto const input = string{"some input string"};
        auto const toSearch = string{"some"};
        
        auto const result = str_starts_with(input, toSearch);
        
        REQUIRE(result == true);
    }
    
    SECTION("Test with an equal string")
    {
        auto const input = string{"some input string"};
        auto const toSearch = string{"some input string"};
        
        auto const result = str_starts_with(input, toSearch);
        
        REQUIRE(result == true);
    }
    
    SECTION("Test with the same string")
    {
        auto const str = string{"some input string"};
        
        auto const result = str_starts_with(str, str);
        
        REQUIRE(result == true);
    }
}
