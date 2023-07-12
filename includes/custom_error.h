#ifndef CUSTOM_ERROR_H
#define CUSTOM_ERROR_H

#include <string>

using namespace std;

class CustomError {
public:
    CustomError(const std::string& errorMessage);
    const string& getMessage() const;

private:
    string message;
};

#endif // CUSTOM_ERROR_H
