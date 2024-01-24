#include <iostream>


using namespace std;


int main(){
  int r0, r1;
  cin >> r0;
  
  
  for ( int n = 0; n < 2; n++ ){
    cin >> r1;
    
    
    if ( r1 < r0 ){
      r0 = r1;
      
    }
    
    
  }
  
  
  cout << r0;
  
  
  return 0;
}
