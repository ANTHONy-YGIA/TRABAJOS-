#include <iostream>

using namespace std;

int main(){
    int r1;
    
    string r0;

    cin >> r0;
    
    if ( r0.size() > 4 ){
        r1 = 4;
    }
    else{
        r1 = r0.size();
    }
    

    for ( int n = 0; n < r1; n++ ){
    	cout << r0[n] << " ASCII value is " << int ( r0[n] ) << endl;
    }

    
    return 0;
}
