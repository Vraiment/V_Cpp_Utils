/*
Copyright (c) 2017 Vraiment <https://github.com/Vraiment>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef VCPPUTILS_SPLIT_HPP
#define VCPPUTILS_SPLIT_HPP

#include <algorithm>
#include <iterator>
#include <regex>
#include <string>

namespace VCppUtils
{
    template <typename Container,
              typename CharT,
              typename RegexTraits = std::regex_traits<CharT>,
              typename StringTraits = std::char_traits<CharT>,
              typename Allocator = std::allocator<CharT>>
    void basic_split(Container& output, std::basic_string<CharT, StringTraits, Allocator> const& input, std::basic_regex<CharT, RegexTraits> const& pattern)
    {
        using ConstStringIterator = typename std::basic_string<CharT, StringTraits, Allocator>::const_iterator;
        using TokenizerCharT = typename std::iterator_traits<ConstStringIterator>::value_type;
        using TokenizerTraits = std::regex_traits<TokenizerCharT>;
        using Tokenizer = std::regex_token_iterator<ConstStringIterator, TokenizerCharT, TokenizerTraits>;
        
        if (input.empty())
        {
            return;
        }
        
        auto tokenizer = Tokenizer{input.cbegin(), input.cend(), pattern, -1};
        static auto const end = Tokenizer{};
        
        if (tokenizer != end)
        {
            std::copy(tokenizer, end, std::back_inserter(output));
        }
    }
    
    template <typename Container, typename CharT, typename Traits = std::char_traits<CharT>, typename Allocator = std::allocator<CharT>>
    void basic_split(Container& output, std::basic_string<CharT, Traits, Allocator> const& input, std::basic_string<CharT, Traits, Allocator> const& pattern)
    {
        basic_split(output, input, std::basic_regex<CharT>{pattern});
    }
    
    template <typename Container>
    void split(Container& output, std::string const& string, std::regex const& pattern)
    {
        basic_split(output, string, pattern);
    }
    
    template <typename Container>
    void split(Container& output, std::string const& string, std::string const& pattern)
    {
        basic_split(output, string, std::regex{pattern});
    }
    
    template <typename Container>
    void wsplit(Container& output, std::wstring const& string, std::wregex const& pattern)
    {
        basic_split(output, string, pattern);
    }
    
    template <typename Container>
    void wsplit(Container& output, std::wstring const& string, std::wstring const& pattern)
    {
        basic_split(output, string, std::wregex{pattern});
    }
}

#endif
