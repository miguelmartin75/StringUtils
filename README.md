# String Utils

A header-only library that has common string functions.

# Features

Functions for:

- Centering a string
- Converting a string to lower/upper case
- Converting from a string to a type (using streams)
- Converting a type to a string (using streams)
- Getting an extension from a string (e.g. `txt`)

# Usage

Usage is simple and straight-foward, you may want to look into the actual header file.

## EXAMLPE USAGE:

```c++
// converting to upper case
std::string tryingToYell = "you'RE grounDED";
auto actuallyYelling = util::to_upper(tryingToYell);

// converting to lower case
std::string notSoQuietMessage "PSST... I aM trYin' to WISper 'ere";
auto quietMessage = util::to_lower(notSoQuietMessage); 

// converting an int to a string
int x = 3;
auto str = util::to_string<std::string>(x);

// converting a string to an int
std::string twentyTwo = "22";
auto actuallyTwentyTwo = util::from_string<int>(twentyTwo);

// centering a string
std::string text = "THE END";
auto centeredText = util::center_string(text, 80, '=');

// getting the extension of a string
std::string whatIsTheExtension = "this.is.very.complicated.png.txt.jpg";
auto ext = util::get_extension(whatIsTheExtension); // == "jpg"
```

# Building Tests

To build the tests and to make sure everything is working properly, simply:

```
make test
```

and to clean the binary(ies) up, simply:

```
make clean
```

# License
Copyright (C) 2013 Miguel Martin (miguel.martin7.5@hotmail.com)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
