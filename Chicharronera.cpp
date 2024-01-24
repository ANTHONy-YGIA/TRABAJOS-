#include <iostream>
#include <cmath>

using namespace std;

int main (){
	int a, b, c;
	cin >> a;
	cin >> b;
	cin >> c;


	float result;


	result = (-b + sqrt ( b * b - 4 * a * c )) / 2 * a;
	cout << result << " ";

	result = (-b - sqrt ( b * b - 4 * a * c )) / 2 * a;
	cout << result;


	return 0;
}
