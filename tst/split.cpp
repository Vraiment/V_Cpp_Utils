#include "catch.hpp"

#include "split.hpp"

#include <deque>
#include <vector>

using namespace std;
using namespace VCppUtils;

TEST_CASE("Test basic_split with a string")
{
    SECTION("To a vector")
    {
        auto output = vector<string>{};
        
        SECTION("With an empty string and empty pattern")
        {
            auto const input = string{""};
            auto const pattern = regex{};
            
            basic_split(output, input, pattern);
            
            REQUIRE(output.size() == 0);
        }
        
        SECTION("With a non empty string and an empty pattern")
        {
            auto const input = string{"string"};
            auto const pattern = regex{};
            
            basic_split(output, input, pattern);
            
            REQUIRE(output.size() == 1);
            REQUIRE(output[0] == input);
        }
        
        SECTION("With a non empty string and a non found pattern")
        {
            auto const input = string{"some string"};
            auto const pattern = regex{"x"};
            
            basic_split(output, input, pattern);
            
            REQUIRE(output.size() == 1);
            REQUIRE(output[0] == input);
        }
        
        SECTION("With several matches")
        {
            auto const input = string{"my string with spaces"};
            auto const pattern = regex{" "};
            
            basic_split(output, input, pattern);
            
            REQUIRE(output.size() == 4);
            REQUIRE(output[0] == "my");
            REQUIRE(output[1] == "string");
            REQUIRE(output[2] == "with");
            REQUIRE(output[3] == "spaces");
        }
    }
    
    SECTION("To a dequeue")
    {
        auto output = deque<string>{};
        auto input = string{"my string with spaces"};
        auto pattern = regex{" "};
        
        basic_split(output, input, pattern);
        
        REQUIRE(output.size() == 4);
        REQUIRE(output[0] == "my");
        REQUIRE(output[1] == "string");
        REQUIRE(output[2] == "with");
        REQUIRE(output[3] == "spaces");
    }
}

TEST_CASE("Test split with a string")
{
    SECTION("To a vector")
    {
        auto output = vector<string>{};
        
        split(output, "my_string_with_spaces", regex{"_"});
        
        REQUIRE(output.size() == 4);
        REQUIRE(output[0] == "my");
        REQUIRE(output[1] == "string");
        REQUIRE(output[2] == "with");
        REQUIRE(output[3] == "spaces");
    }
}
