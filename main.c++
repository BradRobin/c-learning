#include <iostream>
#include <string>

using namespace std;

int number = 1;

string convert(int number){

    if (number >= 1 && number <=10){
        switch (number){
            case 1:
                return "I";
            case 2:
                return "II";
            case 3:
                return "III";
            case 4:
                return "IV";
            case 5:
                return "V";
            case 6:
                return "VI";
            case 7:
                return "VII";
            case 8:
                return "VIII";
            case 9:
                return "IX";
            case 10:
                return "X";
        }
    } else if (number > 10 && number <= 100){
        string result;
        int tens = number / 10;
        int ones = number % 10;

        switch (tens){
            case 1:
                result += "X";
                break;
            case 2:
                result += "XX";
                break;
            case 3:
                result += "XXX";
                break;
            case 4:
                result += "XL";
                break;
            case 5:
                result += "L";
                break;
            case 6:
                result += "LX";
                break;
            case 7:
                result += "LXX";
                break;
            case 8:
                result += "LXXX";
                break;
            case 9:
                result += "XC";
                break;
            case 10:
                result += "C";
                break;
        }
        result += convert(ones);

        return result;
    } else if (number > 100 && number <= 1000){
        string result;
        int hundreds = number / 100;
        int remainder = number % 100;

        switch (hundreds){
            case 1:
                result += "C";
                break;
            case 2:
                result += "CC";
                break;
            case 3:
                result += "CCC";
                break;
            case 4:
                result += "CD";
                break;
            case 5:
                result += "D";
                break;
            case 6:
                result += "DC";
                break;
            case 7:
                result += "DCC";
                break;
            case 8:
                result += "DCCC";
                break;
            case 9:
                result += "CM";
                break;
            case 10:
                result += "M";
                break;
        }
        result += convert(remainder);

        return result;
    } else {
        return "Number is larger than 1000";
    }
}


int main() {
    int number;
    string romanNumeral;

    cout << "Enter number to be converted: ";
    cin >> number;
    
    romanNumeral = convert(number);
    cout << "Roman numeral: " << romanNumeral << endl;
    return 0;
}