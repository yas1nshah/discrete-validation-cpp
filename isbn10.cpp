#include <iostream>
#include <string>
using namespace std;

// eg no: 1932698183
bool isISBN10Valid( string isbn) {
    // Check if the ISBN-10 has 10 digits
    if (isbn.length() != 10) {
        return false;
    }

    // Calculate the total digit
    int total = 0;
    for (int i = 0; i < 9; i++) {
        int digit = isbn[i] - '0';
        total += (i + 1) * digit;
    }
    total %= 11;

    // Validate the check digit
    if (total == 10) {
        return (isbn[9] == 'X' || isbn[9] == 'x');
    } else {
        return (total == isbn[9] - '0');
    }
}

int main() {
    string isbn;

    // Input ISBN-10 from the user
    cout << "Enter ISBN-10 number: ";
    cin >> isbn;

    // Validate ISBN-10
    if (isISBN10Valid(isbn)) {
        cout << "Valid ISBN-10.\n";
    } else {
        cout << "Invalid ISBN-10.\n";
    }

    return 0;
}
