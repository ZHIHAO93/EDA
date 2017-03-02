#ifndef __FECHA_H
#define __FECHA_H

#include <iostream>
#include <iomanip>
using namespace std;

class Fecha{
public:

	// constructor
	Fecha() :_dia(0), _hora(0), _minuto(0) {}
	Fecha(int d, int h, int m) :_dia(d), _hora(h), _minuto(m) {}

	const int dia(){
		return _dia;
	}

	const int hora(){
		return _hora;
	}

	const int minuto(){
		return _minuto;
	}

	void nuevoFecha(int d, int h, int m){
		_dia = d;
		_hora = h;
		_minuto = m;
	}

	bool operator ==(const Fecha& f2) const{
		return (_dia == f2._dia) && (_hora == f2._hora) && (_minuto == f2._minuto);
	}
	bool operator <(const Fecha &f2) const {
		if (_dia < f2._dia) {
			return true;
		}
		else if (_dia > f2._dia) {
			return false;
		}
		else {
			if (_hora < f2._hora) {
				return true;
			}
			else if (_hora > f2._hora) {
				return false;
			}
			else {
				if (_minuto < f2._minuto) {
					return true;
				}
				else {
					return false;
				}
			}
		}
	}

	friend std::ostream& operator<<(std::ostream& sOut, Fecha& f){
		sOut << setfill('0');
		sOut << setw(2) << f._hora << ":" << setw(2) << f._minuto;
		return sOut;
	}

	friend std::istream& operator>>(std::istream& sIn, Fecha& f){
		sIn >> f._dia >> f._hora >> f._minuto;
		return sIn;
	}
	
private:
	int _dia;
	int _hora;
	int _minuto;
};
#endif