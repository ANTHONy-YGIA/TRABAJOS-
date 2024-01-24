#include <iostream>

using namespace std;

int main()
{
    cout<<"======================================================"<<endl;
	cout<<"NOMBRE: ANTHONY JOEL LARICO VELASQUEZ "<<endl;
	cout<<"CODIGO: 236561"<<endl;
	cout<<"======================================================"<<endl;
	cout<<"PARA HALLAR EL PROMEDIO DE LAS EDADES DE 5 PERSONAS"<<endl;
	//Un programa para hallar el promedio de edades
	//Declarar variables
    float p1, p2, p3 ,p4, p5, promedio;
    cout<<"Ingrese la edad de p1:";
    cin>>p1;
    cout<<"Ingrese la edad de p2:";
    cin>>p2;
    cout<<"Ingrese la edad de p3:";
    cin>>p3;
    cout<<"Ingrese la edad de p4:";
    cin>>p4;
    cout<<"Ingrese la edad de p5:";
    cin>>p5;
    //realizar promedio
    promedio=(p1+p2+p3+p4+p5)/5;
    cout<<"El promedio de las 5 personas es :"<<promedio<<endl;
    return 0;
}
