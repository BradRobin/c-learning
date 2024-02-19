#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Polygon {
    private:
        float width;
        float height;
        float radius;
        float side;
        float base;
        float length;
        float result;
    public:
        float calculateAreaCircle(float r){
            const float pi = 3.142;
            radius = r;
            result = pi * r * r;
            return result;
        }
        float calculateAreaSquare(float s){
            side = s;
            result = s * s;
            return result;
        }
        float calculateAreaRectangle(float l, float w){
            length = l;
            width = w;
            result = l * w;
            return result;
        }
};

float calculateCircle(){
    Polygon circle;
    float radius;
    cout << "Enter radius: ";
    cin >> radius;
    cout << "Area of circle: " << circle.calculateAreaCircle(radius) << endl;
    return 0;
}

float calculateSquare(){
    Polygon square;
    float side;
    cout << "Enter side: ";
    cin >> side;
    cout << "Area of square: " << square.calculateAreaSquare(side) << endl;
    return 0;
}

float calculateRectangle(){
    Polygon rectangle;
    float length;
    float width;
    cout << "Enter length: ";
    cin >> length;
    cout << "Enter width: ";
    cin >> width;
    cout << "Area of rectangle: " << rectangle.calculateAreaRectangle(length, width) << endl;
    return 0;
}

int main() {
    int choice;

    cout << "-------------------------------" << endl;
    cout << "|   Menu Choice               |" << endl;
    cout << "|-----------------------------|" << endl;
    cout << "|1. Circle                    |" << endl;
    cout << "|2. Rectangle                 |" << endl;
    cout << "|3. Square                    |" << endl;
    cin >> choice;
    cout << "|-----------------------------|" << endl;

    switch (choice) {
        case 1:
            calculateCircle();
            break;
        case 2:
            calculateRectangle();
            break;
        case 3:
            calculateSquare();
            break;
        default:
            cout << "Invalid entry";
            break;
    }
    return 0;
}