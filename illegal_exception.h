#include <iostream>
#include <string>
using namespace std;

class illegal_exception: std::exception
{
    public:
    const char* what() const noexcept override {
        return "illegal argument";
    }
};