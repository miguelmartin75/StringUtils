///
/// String Utils
///
/// Copyright (C) 2014 Miguel Martin (miguel@miguel-martin.com)
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
///
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///

#ifndef UTIL_STRING_UTILS_HPP
#define UTIL_STRING_UTILS_HPP

#include <cstring>
#include <algorithm>
#include <sstream>

namespace util
{
    template <typename Str, class UnaryOperator>
    Str convert_string(const Str& str, UnaryOperator unaryOp)
    {
        Str temp(str);
        std::transform(temp.begin(), temp.end(), temp.begin(), unaryOp);

        return temp;
    }

    template <typename Str>
    Str to_upper(const Str& str)
    {
        return convert_string(str, ::toupper);
    }

    template <typename Str>
    Str to_lower(const Str& str)
    {
        return convert_string(str, ::tolower);
    }


    template <typename Str>
    Str center_string(const Str& str, int amountOfCharactersInLine, char fillChar= ' ')
    {
        std::size_t halfStringSize = str.length() / 2;
        std::size_t amountOfFillCharactersRequired = (amountOfCharactersInLine / 2) - halfStringSize;

        Str fillCharacter(amountOfFillCharactersRequired, fillChar);

        return fillCharacter + str + fillCharacter;
    }


    template <typename T, typename Str>
    T& from_string(const Str& str, T& obj)
    {
        std::basic_istringstream<typename Str::value_type> temp(str);
        temp >> obj;
        return obj;
    }

    template <typename T, typename Str>
    T from_string(const Str& str)
    {
        T temp;
        return from_string(str, temp);
    }

    template <typename Str, typename T>
    Str to_string(const T& var)
    {
        std::basic_ostringstream<typename Str::value_type> temp;
        temp << var;
        return temp.str();
    }

    /// Gets an Extension from a string.
    /// \param str The string you wish to get the extension from.
    /// \return The extension from the string you parsed in.
    template <typename Str>
    Str get_extension(const Str& str)
    {
        Str extension; // Holds the extension

        size_t sizeOfStringUntilExtension = 0;
        size_t sizeOfExtension = 0; // How many characters are in the extension

        for(size_t i = 0; i < str.size(); ++i)
        {
            if(str[i] == '.')
            {
                sizeOfStringUntilExtension = i + 1;
            }
        }

        sizeOfExtension = static_cast<int>(str.size() - sizeOfStringUntilExtension);

        extension = str.substr(str.size() - sizeOfExtension);
        return extension;
    }
}

#endif // UTIL_STRING_UTILS_HPP
