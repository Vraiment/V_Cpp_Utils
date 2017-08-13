#include "catch.hpp"

#include "vector_utils.hpp"

#include <sstream>

using namespace std;
using namespace VCppUtils;

TEST_CASE("Test join vector")
{
    SECTION("Test with several elements")
    {
        auto input = vector<char>{
            'h', 'e', 'l', 'l', 'o'
        };
        
        auto stream = stringstream{};
        
        join(stream, '_', input);
        
        REQUIRE(stream.str() == "h_e_l_l_o");
    }
}
