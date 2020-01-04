# printf-validation-in-cpp

## The idea:
An idea(plus simple implementation) for a printf validation function that will be evaluated at compile time in c++.

## My implementation:
My implementation is an implementation of this idea but it support only %s and %d in the printf format. 
In addition when parsing %s it expects a string_view argument(so for const char* argument or std::string argument the function will report an error).

## Evaluation of the function at compile time:
This function will work at compile time in case it will be forced to evaluate at compile time
(e.g by assign the result of the function to a constexpr variable and by using literals in the function call,
for example in the following way: constexpr int result = MyPrintf("%d", 213132)).

This function can work also at runtime but it intended to be used at compile time so the user can be notified by the compiler if
he used the function wrong.

## Solution for the problem:
One possible solution to this flaw(that the user need to assing the function result to a constexpr variable to force the compiler 
to evaluate the function at compile time) is to use consteval presented in c++20 in the function declaration and by that make the function
work only at compile time.
