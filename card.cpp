#include <iostream>
#include <string>

using namespace std;

// THIS IS DONE BY LUHN ALGORITHEM
// eg no: 5234821334101298
bool validateCreditCard(const string cardNumber) {

    // Check if the input is NUMBERS    
    for(int i=0; i< cardNumber.length(); i++)
    {
        if(! isdigit(cardNumber[i]))
        {
            return false;
        }
    }

    // Check if the credit card number has a valid length
    if (cardNumber.length() < 13) {
        return false;
    }

    // Reverse the credit card number for easier processing
    string reversedCardNumber = "";
    for (int i = cardNumber.length() - 1; i >= 0; --i) {
        reversedCardNumber += cardNumber[i];
    }

    int sum = 0;

    // Going through the reversed digits, doubling every second digit
    for (int i = 0; i < reversedCardNumber.length(); i++) {
        int digit = reversedCardNumber[i] - '0';

        if(i%2 == 0){
            sum += digit;
        }
        else
        {   
            digit *= 2;
            if(digit < 10)
            {
                sum+= digit;
            }
            else
            {
                // Extracting individual digits
                int digit1 = digit / 10; // Gets the tens digit
                sum+= digit1;
                int digit2 = digit % 10; // Gets the ones digit
                sum+= digit2;
            }
        }       
    }


    // The credit card is valid if the remainder is Zero after dividing by 10
    return (sum%10 == 0);
}

int main() {
    string cardNumber;

    cout << "Enter credit card number: ";
    cin >> cardNumber;

    if (validateCreditCard(cardNumber)) {
        cout << "Valid credit card number.\n";
    } else {
        cout << "Invalid credit card number.\n";
    }

    return 0;
}
