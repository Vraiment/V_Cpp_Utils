#include "catch.hpp"

#include "ostream_utils.hpp"

#include <array>
#include <sstream>
#include <string>

using namespace std;
using namespace VCppUtils;

constexpr auto TAGS = "";

TEST_CASE("Test basic join", TAGS)
{
    auto stream = stringstream{};
    auto const character = ',';
    
    SECTION("With an empty container")
    {
        auto input = array<string, 0>{};
        
        basic_join(stream, character, input.begin(), input.end());
        
        auto const result = stream.str();
        REQUIRE(result.empty());
    }
    
    SECTION("With a container with a single element")
    {
        auto input = array<string, 1>{ {"element_1"} };
        
        basic_join(stream, character, input.begin(), input.end());
        
        auto const result = stream.str();
        REQUIRE(result == *input.begin());
    }
    
    SECTION("With a container with several elements")
    {
        auto input = array<string, 4>{
            {"element_a", "element_b", "element_c", "element_d"}
        };
        
        basic_join(stream, character, input.begin(), input.end());
        
        auto const result = stream.str();
        auto const expected = input[0] + character + input[1] + character +
            input[2] + character + input[3];
        REQUIRE(result == expected);
    }
}

TEST_CASE("Test get basic size", TAGS)
{
    auto input = stringstream{};
    
    SECTION("With an empty stream")
    {
        auto result = get_stream_size(input);
        
        REQUIRE(result == 0);
    }
    
    SECTION("With a single element in the stream")
    {
        input << 'a';
        
        auto result = get_stream_size(input);
        
        REQUIRE(result == 1);
    }
    
    SECTION("With several elements in the stream")
    {
        auto const elements = string{"Hello world"};
        input << elements;
        
        auto result = get_stream_size(input);
        
        REQUIRE(result == elements.size());
    }
}
