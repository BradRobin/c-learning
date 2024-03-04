#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string rearrangePairs(const string& input) {
    unordered_map<char, int> charCount;

    // Count the occurrences of each character
    for (char ch : input) {
        charCount[ch]++;
    }

    string rearrangedString;

    // Iterate through the character counts and add characters to the output string
    for (auto& pair : charCount) {
        char ch = pair.first;
        int count = pair.second;

        // Add pairs of characters to the output string
        for (int i = 0; i < count / 2; ++i) {
            rearrangedString += ch;
            rearrangedString += ch;
        }

        // If there's an odd count, add one more character to maintain pairs
        if (count % 2 == 1) {
            rearrangedString += ch;
        }
    }

    return rearrangedString;
}

int main() {
    string input = "aefzmdbmctabcetfdz";
    string rearranged = rearrangePairs(input);
    
    cout << "Original string: " << input << endl;
    cout << "Rearranged string: " << rearranged << endl;

    return 0;
}

