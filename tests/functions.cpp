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

#include <string>

#include "../include/util/string_utils.hpp"
#include "lest.hpp"

const lest::test specification[] =
{
	"Centering String", []
    {
        const static std::string text = "The";
        EXPECT(util::center_string(text, 11, '*') == "****The****");
    },
    
    "To Upper", []
    {
        const static std::string text = "ThiS iS a teSt";
        EXPECT(util::to_upper(text) == "THIS IS A TEST");
    },
    
    "To Lower", []
    {
        const static std::string text = "ThiS iS a teSt";
        EXPECT(util::to_lower(text) == "this is a test");
    },
    
    "From String", []
    {
        const static std::string one = "1";
        const static std::string fiftySevenPointSix = "57.6";
        const static std::string undefined = "dsa";
        
        EXPECT(util::from_string<int>(one) == 1);
        EXPECT(util::from_string<double>(fiftySevenPointSix) == 57.6);
        EXPECT(util::from_string<int>(undefined) == 0);
        
    },
    
    "To String", []
    {
        const static int one = 1;
        const static double fiftySevenPointSix = 57.6;
        
        EXPECT(util::to_string<std::string>(one) == "1");
        EXPECT(util::to_string<std::string>(fiftySevenPointSix) == "57.6");
    },
    
    "Get Extension", []
    {
        const static std::string imagePng = "image.png";
        const static std::string imagePngTxt = "image.png.txt";
        
        EXPECT(util::get_extension(imagePng) == "png");
        EXPECT(util::get_extension(imagePngTxt) == "txt");
    }
};

int main()
{
	return lest::run(specification);
}