# Project 1 README

Student 1: Siyun Chen (921881463)

## Project Status
The project is complete. All functions in StringUtils have been implemented and tested.
* [GitHub Repository](https://github.com/ChenSiyun1234/ECS34-Project1.git)

## Known Issues
No known issues at this time.

## Code References
* [Levenshtein distance - Wikipedia](https://en.wikipedia.org/wiki/Levenshtein_distance) - Used the pseudocode implementation for EditDistance function

## Generative AI Use
I used ChatGPT for Prompts 1-6 and referenced Wikipedia for the EditDistance implementation.

### Prompt 1
How do I convert a string to lowercase in C++?

### Response 1
In C++, you can convert a string to lowercase using the `std::transform` function along with `std::tolower`. Here's an example:
```cpp
#include <algorithm>
#include <cctype>
#include <string>

std::string str = "Hello World";
std::transform(str.begin(), str.end(), str.begin(), ::tolower);
```
Alternatively, you can use a simple loop:
```cpp
for (char &c : str) {
    c = std::tolower(c);
}
```
Both methods will convert all uppercase characters in the string to lowercase.

### Changes 1
I used the loop approach to convert the string to lowercase in my Capitalize function, applying it to all characters except the first one.

### Prompt 2
How do I check if a character is a whitespace in C++?

### Response 2
In C++, you can use the `std::isspace` function from the `<cctype>` header to check if a character is a whitespace. Here's an example:
```cpp
#include <cctype>

char c = ' ';
if (std::isspace(c)) {
    // c is a whitespace character
}
```
The `std::isspace` function returns a non-zero value if the character is a whitespace character (space, tab, newline, etc.), and zero otherwise.

### Changes 2
I used `std::isspace` in my LStrip function to identify and skip leading whitespace characters.

### Prompt 3
What should the LJust function do? What is the expected behavior?

### Response 3
The `LJust` (left justify) function pads a string on the right side to make it a specified width. The original string is left-aligned, and padding characters are added to the right.

For example:
- `LJust("hello", 10, ' ')` returns `"hello     "` (5 spaces added on the right)
- `LJust("hello", 10, '*')` returns `"hello*****"`
- If the string is already longer than or equal to the specified width, it returns the original string unchanged.

### Changes 3
I implemented the LJust function based on this explanation, appending fill characters to the right of the string until it reaches the desired width.

### Prompt 4
When centering a string with an odd total padding, should I add the extra character to the left or right side?

### Response 4
When centering a string and there's an odd amount of total padding needed, the common convention is to add the extra padding character to the right side. This means the left side gets `floor((width - length) / 2)` characters, and the right side gets `ceil((width - length) / 2)` characters.

For example, centering "hi" (length 2) in width 5:
- Total padding needed: 3
- Left padding: 1 character
- Right padding: 2 characters
- Result: `" hi  "`

### Changes 4
I followed this convention in my Center function, adding the extra padding character to the right side when the total padding is odd.

### Prompt 5
How do I add elements to a vector of strings in C++?

### Response 5
In C++, you can add elements to a `std::vector<std::string>` using the `push_back` method:
```cpp
#include <vector>
#include <string>

std::vector<std::string> vec;
vec.push_back("hello");
vec.push_back("world");
```
You can also use `emplace_back` for potentially better performance:
```cpp
vec.emplace_back("hello");
```

### Changes 5
I used `push_back` in my Split function to add each substring to the result vector.

### Prompt 6
What should the ExpandTabs function do? What is the expected behavior?

### Response 6
The `ExpandTabs` function replaces tab characters (`\t`) with spaces to align text to tab stops. Tab stops are typically at fixed intervals (e.g., every 4 or 8 characters).

The key behavior is:
- Each tab character is replaced with enough spaces to reach the next tab stop
- Tab stops are at positions 0, tabsize, 2*tabsize, 3*tabsize, etc.
- The number of spaces inserted depends on the current column position

For example, with tabsize=4:
- `"a\tb"` becomes `"a   b"` (3 spaces to reach column 4)
- `"ab\tc"` becomes `"ab  c"` (2 spaces to reach column 4)
- `"abc\td"` becomes `"abc d"` (1 space to reach column 4)
- `"abcd\te"` becomes `"abcd    e"` (4 spaces to reach column 8)

### Changes 6
I implemented ExpandTabs based on this explanation, calculating the number of spaces needed based on the current column position modulo the tab size.

### Prompt 7
How do I initialize a 2D vector in C++?

### Response 7
In C++, you can initialize a 2D vector with specific dimensions and default values like this:
```cpp
#include <vector>

// Create a 2D vector with m rows and n columns, initialized to 0
int m = 5, n = 10;
std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
```
This creates a vector of `m` vectors, each containing `n` integers initialized to 0.

### Changes 7
I used this approach to initialize the distance matrix `d` in my EditDistance function. The implementation was based on the Levenshtein distance pseudocode from Wikipedia, which I translated to C++.
