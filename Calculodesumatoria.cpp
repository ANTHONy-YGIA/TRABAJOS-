#include <iostream>

using namespace std;

int main(){
	int r0, r1 = 0;

	cin >> r0;

	for ( int n = 0; n < r0; n++ ){
		r1 += n + 1;

	}

	cout << r1;

	return 0;
}
