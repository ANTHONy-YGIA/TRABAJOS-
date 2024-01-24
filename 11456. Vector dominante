#include <iostream>

int main() {
  
  int cantidad;
  std::cin>>cantidad;
  int arreglo[cantidad];
  for (int i = 0; i < cantidad; ++i) {
    std::cin >> arreglo[i];
  }
  int arreglo2[cantidad];
  for (int i = 0; i < cantidad; ++i) {
    std::cin >> arreglo2[i];
  }
  bool compara;
  for(int j = 0; j < cantidad; ++j) {
    if (arreglo[j]>arreglo2[j]){
      compara = true;
    }else {
      std::cout << "0";
      compara = false;
      break;
    }
  }
  if (compara == true){
    std::cout << "1";
  }
  return 0;
}
