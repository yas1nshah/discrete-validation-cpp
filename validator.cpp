# include <iostream>
using namespace std;


// THIS IS DONE BY LUHN ALGORITHEM
// eg no: 5234821334101298
bool validateCreditCard(string cardNumber) {

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

// eg no: 9780735200449
bool isISBN13Valid(string isbn) {
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

// eg no: 1932698183
bool isISBN10Valid(string isbn) {
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

// eg : 705632441947
bool isUPCValid(string upc) {
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


int main(){

    // Making Variables
    string cardNumber; // for Credit card
    string isbn13; // for ISBN 13
    string isbn10; // for ISBN 10
    string upc; // for UPC


    start:
    int n;
    cout<<"What do you want to Validate?";
    cin>>n;

    switch (n)
    {
    case 1: // For ISBN 13
        {
            cout << "Enter ISBN-13 number: ";
            cin >> isbn13;

            // Validate ISBN-13
            if (isISBN13Valid(isbn13)) {
                cout << "Valid ISBN-13.\n";
            } else {
                cout << "Invalid ISBN-13.\n";
            }
            break;
        }
    
    case 2: // For ISBN 10
        {
             // Input ISBN-10 from the user
            cout << "Enter ISBN-10 number: ";
            cin >> isbn10;

            // Validate ISBN-10
            if (isISBN10Valid(isbn10)) {
                cout << "Valid ISBN-10.\n";
            } else {
                cout << "Invalid ISBN-10.\n";
            }
            break;
        }
    
    case 3: // For Master or Visa Card
        {
            cout << "Enter credit card number: ";
            cin >> cardNumber;

            if (validateCreditCard(cardNumber)) {
                cout << "Valid credit card number.\n";
            } else {
                cout << "Invalid credit card number.\n";
            }
            break;
        }
    
    case 4: // For UPC
        {
             // Input UPC-A from the user
            cout << "Enter UPC-A number: ";
            cin >> upc;

            // Validate UPC-A
            if (isUPCValid(upc)) {
                cout << "Valid UPC-A.\n";
            } else {
                cout << "Invalid UPC-A.\n";
            }
            break;
        }

    default:
        cout<<"Enter a valid option!";
        goto start;
    }


    return 0;
}