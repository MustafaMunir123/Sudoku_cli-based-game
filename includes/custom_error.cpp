#include "custom_error.h"

using namespace std;

CustomError::CustomError(const string& errorMessage) : message(errorMessage) {}

const string& CustomError::getMessage() const {
    return message;
}
