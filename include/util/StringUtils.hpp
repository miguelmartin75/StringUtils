///
/// String Utils
/// 
/// Copyright (C) 2013 Miguel Martin (miguel.martin7.5@hotmail.com)
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

#ifndef __STRINGUTILS_HPP__
#define __STRINGUTILS_HPP__

#include <cstring>

#include <string>
#include <algorithm>
#include <sstream>

namespace util
{
	template <typename Str = std::string, class UnaryOperator>
	Str ConvertString(const Str& str, UnaryOperator unaryOp)
	{
		std::string temp(str);
		std::transform(temp.begin(), temp.end(), temp.begin(), unaryOp);
		
		return temp;
	}
	
	template <typename Str>
	Str StringToUpper(const Str& str)
	{
		return ConvertString(str, ::toupper);
	}
	
	template <typename Str = std::string>
	Str StringToLower(const Str& str)
	{
		return ConvertString(str, ::tolower);
	}
	
	
	template <typename Str = std::string>
	Str CenterString(const Str& str, int amountOfCharactersInLine, char fillChar)
	{
		int halfStringSize = str.length() / 2;
		int amountOfFillCharactersRequired = (amountOfCharactersInLine / 2) - halfStringSize;
		
		std::string fillCharacter(amountOfFillCharactersRequired, fillChar);
		
		return fillCharacter + str + fillCharacter;
	}
	
	
	template <typename T, typename Str = std::string>
	T ConvertFromString(const std::string& str)
	{
		std::istringstream stream(str);
		T temp;
		stream >> temp;
		
		return temp;
	}
	
	
	
	
	/// Gets an Extension from a string.
	/// \param str The string you wish to get the extension from.
	/// \return The extension from the string you parsed in.
	template <typename Str>
	Str GetExtensionFromString(const Str& str)
	{
		std::string extension; // Holds the extension
		
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

#endif // __STRINGUTILS_HPP__