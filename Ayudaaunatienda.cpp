#include <iostream>

using namespace std;

int main(){
	float compra = 0;
	float descuento = 0;
	float descuentototal = 0;

	cin >> compra;

	if ( compra < 500 ){
		cout << compra;
	}

	if ( compra >= 500 && compra <= 1000 ){
		descuento = ( compra * 0.05 );
		descuentototal = compra - descuento;

		cout << descuentototal;
	}


	if ( compra >= 1001 && compra <= 7000 ){
		descuento = ( compra * 0.11 );
		descuentototal = compra - descuento;


		cout << descuentototal;
	}


	if ( compra >= 7001 && compra <= 15000 ){
		descuento = ( compra * 0.18 );
		descuentototal = compra - descuento;


		cout << descuentototal;
	}



	if ( compra > 15000 ){
		descuento = ( compra * 0.25 );
		descuentototal = compra - descuento;


		cout << descuentototal;
	}

	return 0;
}
