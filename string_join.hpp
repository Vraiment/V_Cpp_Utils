// string_join.hpp
// Copyright (c) 2016 Vraiment
//
// This software is provided 'as-is', without any express or implied
// warranty.  In no event will the authors be held liable for any damages
// arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented; you must not
//    claim that you wrote the original software. If you use this software
//    in a product, an acknowledgment in the product documentation would be
//    appreciated but is not required.
// 2. Altered source versions must be plainly marked as such, and must not be
//    misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution
#ifndef V_STRING_JOIN_HPP
#define V_STRING_JOIN_HPP

#include <initializer_list>
#include <string>

namespace V
{
    std::string join(std::string const& separator, std::initializer_list<std::string const> const strings)
    {
        auto result = std::string{};
        auto iterator = strings.begin();
        auto const end = strings.end();

        if (end != iterator)
        {
            result += *iterator;
            while (end != ++iterator)
            {
                result += separator + *iterator;
            }
        }

        return result;
    }
}

#endif // V_STRING_JOIN_HPP
