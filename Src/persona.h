#include <iostream>
#include <string>
using namespace std;

class persona{
public:
	persona(){}
	persona(int e, string n){
		edad = e;
		nombre = n;
	}

	int edades(){
		return edad;
	}

	friend ostream& operator<<(ostream& sOut, persona& p){
		sOut << p.nombre << endl;
		return sOut;
	}

	friend istream& operator>>(istream& sIn, persona& p){
		sIn >> p.edad;
		sIn.ignore();
		getline(sIn, p.nombre);
		return sIn;
	}
private:
	int edad;
	string nombre;
};