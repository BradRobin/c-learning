//1.Write a cpp program that will prompt the user to enter admission number, name, and
//  marks any 5 subjects/units of your choice, the details should be saved to studentMarks.txt
//  file. You should also implement a way to read the data from studentMarket.txt and display 
//  them in the terminal
//2. (i)add a function to edit the data.
//   (ii)display the results in a sorted manner.
//   (iii)search function to search the results of a specific student and display it.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

// Function to create the file and write student details
void createFile(const string& name, const string& admissionNumber, const string& unitsChosen) {
    ofstream outFile("studentMarks.txt", ios::app); // Append mode to add new entries without overwriting

    if (outFile.is_open()) {
        outFile << "Name: " << name << endl;
        outFile << "Admission Number: " << admissionNumber << endl;
        outFile << "Units Chosen: " << unitsChosen << endl;
        outFile << "-------------------------" << endl;
        outFile.close();
        cout << "Details saved successfully!" << endl;
    } else {
        cout << "Unable to open file" << endl;
    }
}

void displayUnits(const string& name, const string& admissionNumber, const map<int, string>& unitMap) {
    ifstream inFile("studentMarks.txt");
    string line;
    bool found = false;

    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            if (line.find("Name: " + name) != string::npos && getline(inFile, line) && 
                line.find("Admission Number: " + admissionNumber) != string::npos && getline(inFile, line)) {
                found = true;
                cout << "Units registered for " << name << " (Admission Number: " << admissionNumber << "):\n";

                // Split the line into unit numbers
                istringstream ss(line);
                string unitNumberStr;
                vector<int> unitNumbers;
                while (ss >> unitNumberStr) {
                    try {
                        int unitNumber = stoi(unitNumberStr); // Convert string to int
                        unitNumbers.push_back(unitNumber);
                    } catch (const std::invalid_argument& e) {
                        cerr << "Invalid unit number: " << unitNumberStr << ". Skipping..." << endl;
                    }
                }

                // Display unit names corresponding to unit numbers
                for (int unitNumber : unitNumbers) {
                    cout << unitMap.at(unitNumber) << endl;
                }
                cout << endl;
                break;
            }
        }
        inFile.close();
        if (!found) {
            cout << "No record found for the provided name and admission number." << endl;
        }
    } else {
        cout << "Unable to open file" << endl;
    }
}


int main() {
    int choice;
    string name, admissionNumber, unitsChosen;

    // Map unit numbers to their names
    map<int, string> unitMap = {
        {1, "Object oriented programming"},
        {2, "Software Design"},
        {3, "Communication skills"},
        {4, "Operating systems"},
        {5, "Discrete math"},
        {6, "Basic Math"},
        {7, "Computer Organization"}
    };

    cout << "1. Register units\n"
         << "2. Display units registered\n"
         << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // Ignore the newline character left by cin

    switch (choice) {
        case 1:
            cout << "Enter your name: ";
            getline(cin, name); // Allowing spaces in name

            cout << "Enter your admission number: ";
            getline(cin, admissionNumber); // Allowing spaces in admission number

            cout << "Choose the units to register (enter the numbers separated by spaces):\n";
            for (const auto& pair : unitMap) {
                cout << pair.first << ". " << pair.second << endl;
            }
            getline(cin, unitsChosen); // Allowing spaces in unit choices

            // Write the details to the file
            createFile(name, admissionNumber, unitsChosen);
            break;

        case 2:
            cout << "Enter your name: ";
            getline(cin, name); // Allowing spaces in name

            cout << "Enter your admission number: ";
            getline(cin, admissionNumber); // Allowing spaces in admission number

            // Display units registered for the given name and admission number
            displayUnits(name, admissionNumber, unitMap);
            break;

        default:
            cout << "Invalid choice" << endl;
            break;
    }

    return 0;
}
