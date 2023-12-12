#include <iostream>
#include <string>
using namespace std;

bool isISBN13Valid(const string isbn) {
    // Check if the ISBN-13 has 13 digits
    if (isbn.length() != 13) {
        return false;
    }

    // Calculate the check digit
    int total = 0;
    for (int i = 0; i < 12; ++i) {
        int digit = isbn[i] - '0';
        
        if(i %2 == 0)
        {
            total += digit;
        }
        else
        {
            total += (3*digit);
        }
    }

    total = (10 - (total % 10));
    int checkDigit = isbn[12] - '0';

    if (checkDigit == 10)
    {
        checkDigit = 0;
    }

    // Validate the check digit
    return (total == checkDigit);
}

int main() {
    string isbn;
    
    // Input ISBN-13 from the user
    cout << "Enter ISBN-13 number: ";
    cin >> isbn;

    // Validate ISBN-13
    if (isISBN13Valid(isbn)) {
        cout << "Valid ISBN-13.\n";
    } else {
        cout << "Invalid ISBN-13.\n";
    }

    return 0;
}
