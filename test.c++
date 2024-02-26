//create a simple program that will prompt the user to
// enter a number the program will then output the number
// in roman numericals

#include <iostream>
#include <string>
#include <unordered_map> // Include for unordered_map
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> m;

        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        int ans = 0;

        for(int i = 0; i < s.length(); i++){
            if(m[s[i]] < m[s[i+1]]){
                ans -= m[s[i]];
            } else {
                ans += m[s[i]];
            }
        }
        return ans;
    }
};

int main() {
    Solution solution; // Create an instance of the Solution class
    string romanNumeral;
    cout << "Enter a Roman numeral: ";
    cin >> romanNumeral;

    int result = solution.romanToInt(romanNumeral);
    cout << "Equivalent integer: " << result << endl;

    return 0;
}
