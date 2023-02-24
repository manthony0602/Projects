#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// Computer Organization - Conversion Assignment 
/* Please create a complete program to convert from numbers from decimal to binary and binary to decimal...up
to 8 bits. The code should ask the user to enter a decimal value or binary value and then display the corresponding 
number. Also ask the user if they would like to convert another value. Remember input validation.....//Comments...
//Comments....//Comments */

// Function Prototypes
int binaryToDecimal(string x);
void decimalToBinary(int x);


// Main Function
int main() {
    // Variable to hold user input 
    int userChoice;

    while (userChoice != 0) {
        // Variables to hold the number that the user wants to convert
        int userDecimalVal;
        int convertedAnswer;
        int arrayHolder;

        cout << setw(50) << "CONVERSION CALCULATOR\n";
        cout << "\n";
        cout << "Select a conversion you would like to do OR exit the program\n";

        // This is a display table, so the user can select what kind of conversion they'd like to do
        cout << setw(2) << "1 - Decimal -> Binary\n";
        cout << setw(2) << "2 - Binary  -> Decimal\n";
        cout << setw(2) << "0 - Exit Program.\n";
        cout << "\n";

        // User Input for what they'd like to do
        cout << "Select Option: ";
        cin >> userChoice;
        cout << "\n";
        cout << "\n";



        // If/else if statements to determine what the user chose and what conversion to do
        if (userChoice == 0) { break; } // Exits and ends the program (0)


        // Decimal -> Binary option (Option 1)
        else if (userChoice == 1) {

            cout << "You have chosen to do a DECIMAL -> BINARY conversion.\n";
            cout << "\n";

            cout << "Now enter a Decimal Value to convert: ";
            cin >> userDecimalVal;
            cout << "\n";

            // Prints the conversion value that we got from the function call to the console
            cout << "By using the Divisional Remainder Method, ";
            cout << userDecimalVal << " = ";
            decimalToBinary(userDecimalVal);  // Function call will print out the converted binary value
            cout << "\n";
        }


        // Binary -> Decimal (Option 2)
        else if (userChoice == 2) {
            // Variables hold the number of bits and the actual value of the binary value the user inputs
            int bitSize;
            string userBinaryVal;

            cout << setw(55) << "* BINARY TO DECIMAL CONVERSION *\n";
            cout << "\n";

            cout << "You have chosen to do a BINARY -> DECIMAL conversion.\n";
            cout << "\n";

            cout << "* No larger than 8 bits *\n";
            cout << "How long will this binary value be? (x bits): ";
            cin >> bitSize;
            // Checks to make sure that the user is entering a valid number of bits for the Binary value
            if (bitSize > 8) {
                while (bitSize > 8) {
                    cout << "\n";
                    cout << "Binary Value can't be greater than 8 bits long.\n";
                    cout << "Enter a valid Binary Value: ";
                    cin >> bitSize;
                }
            }
            cout << "\n";

            cout << "Now enter in the " << bitSize << " bit Binary Value: ";
            cin >> userBinaryVal;
            cout << "\n";

            // Function call will return the converted value 
            convertedAnswer = binaryToDecimal(userBinaryVal);

            // Prints the conversion value that we got from the function to the console
            cout << "** By using Positional Notation, ";
            cout << userBinaryVal << " = " << convertedAnswer << " **";
        }


        cout << "\n";
        cout << "\n";
        cout << "--------------------------------------------------------------";
        cout << "\n";
        cout << "\n";
        cout << "\n";
    }
}



// Function Definitions

// Function definition for converting Decimal Values to Binary
void decimalToBinary(int x) {
    int binaryNum[32];        // An array to store the Binary Value
    int i = 0;
    while (x > 0) {
        binaryNum[i] = x % 2; // Array holds the remainder value of x being divided by 2
        x = x / 2;            // x is divided by 2 since its a BINARY value, just like in DR method
        i++;
    }

    // For loop prints the array backwards just like in the divisional remainder method
    for (int k = i - 1; k >= 0; k--) {
        cout << binaryNum[k];
    }
}


// Function definition for converting Binary Values to Decimal
int binaryToDecimal(string x) {
    int convertedVal = 0;
    int power = 0;
    int stringSize = x.length();

    // The loop reads the string from right to left, just like 
    // in positional notation, and then carries out the same
    // multiplication process (1^i * 1) or (1^i * 0)
    for (int i = stringSize - 1; i >= 0; i--) {
        if (x[i] == '1') {
            convertedVal += (1 << power); // Bitwise operator that shifts bits to the left
        }
        power++;
    }

    return convertedVal;
}