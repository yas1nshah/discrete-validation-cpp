#include <iostream>

bool isLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool validateEuroSerialNumber(const std::string& serialNumber) {
    // Check if the serial number has the correct length
    if (serialNumber.length() != 10) {
        return false;
    }

    // Check if the first character is a letter
    if (!isLetter(serialNumber[0])) {
        return false;
    }

    // Check if the remaining characters are digits
    for (size_t i = 1; i < serialNumber.length(); ++i) {
        if (!isDigit(serialNumber[i])) {
            return false;
        }
    }

    // All checks passed
    return true;
}

int main() {
    std::string serialNumber;

    std::cout << "Enter EURO currency note serial number: ";
    std::cin >> serialNumber;

    if (validateEuroSerialNumber(serialNumber)) {
        std::cout << "Valid EURO currency note serial number.\n";
    } else {
        std::cout << "Invalid EURO currency note serial number.\n";
    }

    return 0;
}
