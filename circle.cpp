#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>
#include <chrono>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Circle
{
	int x;

private:
	double radius;      // Data member (Variable)
	string color;       // Data member (Variable)

public:
	void setCircle(int i) { x = i; }

	//Constructor with default values for data members
	//Circle(double r[], string c[]) {
	//radius = r[x];
	//color = c[x];
	//}

	double getRadius() {  // Member function (Getter)
		return radius;
	}

	string getColor() {   // Member function (Getter)
		return color;
	}

	void displayCircle(){
		Circle C[2];
		int i;
		for (i = 0; i < 2; i++){
			cout << "C[" << i << "].getRadius(): " << C[i].getRadius() << "\n";
			cout << "C[" << i << "].getColor(): " << C[i].getColor() << "\n";
		}
	}

	double calcArea() {    // Member function
		return std::pow(radius, radius)*3.14159;
	}

	void compareCircles(Circle newC){
		Circle C[2];
		int i;
		for (i = 0; i < 2; i++){
			C[i].getRadius();
		}
		if (C[1].getRadius > C[2].getRadius)
		{
			cout << "The: " << C[1].getColor() << "circle is larger than" << C[2].getColor << "circle" << "\n";
		}
		else if (C[1].getRadius < C[2].getRadius)
		{
			cout << "The: " << C[2].getColor() << "circle is larger than" << C[1].getColor << "circle" << "\n";
		}
		else
		{
			cout << "The: " << C[2].getColor() << "circle is same with" << C[1].getColor << "circle" << "\n";
		}
	}


};   // need to end the class declaration with a semi-colon

// Test driver function
int main() {

	Circle C[2];
	int i;

	for (i = 0; i < 2; i++)
		C[i].setCircle(i);

	for (i = 0; i < 2; i++){

		double radius;
		cout << "Enter the radius: ";
		cin >> radius;

		string color;
		cout << "Enter the color: ";
		cin >> color;

		C[i].displayCircle();

		cout << "Area: " << C[i].calcArea() << endl;
	}



	return 0;
}