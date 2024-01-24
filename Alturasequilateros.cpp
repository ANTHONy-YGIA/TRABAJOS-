#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
  int r0;
  float r1, r2, r3;
  
  cin >> r0;
  
  
  for ( int n = 0; n < r0; n++ ){
    cin >> r1;
    
    r2 = r1 / 2;
    
    r3 = r1 * r1 - r2 * r2;
    r3 = sqrt( r3 );
    
    printf ( "%.2f\n", r3 );
    
    
    
  }
  
  
  
  return 0;
}
