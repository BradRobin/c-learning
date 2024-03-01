#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool askQuestion(const string& question, const string& correctAnswer, int& score, int& lives) {
    string userAnswer;
    while (true) {
        cout << question;
        cin >> userAnswer;

        // Make a copy of the user's answer and correct answer in lowercase
        string userAnswerLower = userAnswer;
        string correctAnswerLower = correctAnswer;
        transform(userAnswerLower.begin(), userAnswerLower.end(), userAnswerLower.begin(), ::tolower);
        transform(correctAnswerLower.begin(), correctAnswerLower.end(), correctAnswerLower.begin(), ::tolower);

        if (userAnswerLower == correctAnswerLower) {
            cout << "Correct! You gained 5 points." << endl;
            score += 5;
            return true;
        } else {
            lives--;
            cout << "Wrong answer. You have " << lives << " lives left." << endl;
            if (lives == 0) {
                return false;
            }
            cout << "Try again." << endl;
        }
    }
}

int main() {
    int score = 0;
    int lives = 3;

    if (askQuestion("Question 1: What is the capital of Kenya: ", "Nairobi", score, lives) &&
        askQuestion("Question 2: What is the capital of China: ", "Beijing", score, lives) &&
        askQuestion("Question 3: What is the capital of Canada: ", "Ottawa", score, lives) &&
        askQuestion("Question 4: What is the capital of Russia: ", "Moscow", score, lives) &&
        askQuestion("Question 5: What is the capital of Madagascar: ", "Antananarivo", score, lives)) {
        cout << "You've answered all questions correctly!" << endl;
    } else {
        cout << "Out of Lives! Game Over!" << endl;
    }

    cout << "Your final score is: " << score << endl;

    return 0;
}
