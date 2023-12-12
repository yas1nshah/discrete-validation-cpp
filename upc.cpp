#include <iostream>
#include <string>
using namespace std;

// eg : 705632441947
bool isUPCAValid(string upc) {
    // Check if th has 12 digits
    if (upc.length() != 12) {
        return false;
    }

    // Calculate the total digit
   int total = 0;

    for (int i = 0; i < 11; ++i) {
        int digit = upc[i] - '0';

        if (i % 2 == 0) {
            total += 3*digit;
        } else {
            total += digit;
        }
    }

    total = (10 - (total %10)) % 10;

    int checkDigit = upc[11] - '0';
    if(checkDigit == 10){
        checkDigit = 0;
    }

    // Validate the check digit
    return (total == checkDigit);
}

int main() {
    string upc;

    // Input UPC-A from the user
    cout << "Enter UPC-A number: ";
    cin >> upc;

    // Validate UPC-A
    if (isUPCAValid(upc)) {
        cout << "Valid UPC-A.\n";
    } else {
        cout << "Invalid UPC-A.\n";
    }

    return 0;
}
