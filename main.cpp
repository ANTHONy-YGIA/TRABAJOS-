#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout<<"======================================================"<<endl;
	cout<<"NOMBRE: ANTHONY JOEL LARICO VELASQUEZ "<<endl;
	cout<<"CODIGO: 236561"<<endl;
	cout<<"======================================================"<<endl;
	cout<<"PARA RESOLVER LA  FORMULA GENERAL DE LAS ECUACIONES DE 2DO GRADO"<<endl;
    //PROGRAMA PARA RESOLVER ECUACION DE 2DO GRADO
    //DECLARAR VARIABLES
    float a, b, c, x1, x2, raiz ;
    cout<<"Introduzca la variavble a:";
    cin>>a;
    cout<<"Introduzca la variavble b:";
    cin>>b;
    cout<<"Introduzca la variavble c:";
    cin>>c;
    //OPERACION
    raiz= sqrt(pow(b,2)-4*a*c);
    x1=(-b + raiz)/(2 * a);
    x2=(-b - raiz)/(2 * a);
    cout<<" Las soluciones son :"<<x1<<"y"<<x2<<endl;
    return 0;
}
