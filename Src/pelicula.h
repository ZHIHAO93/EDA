#ifndef PELICULA_H_
#define PELICULA_H_
#include <iostream>
#include <string>

#include "hora.h"

using namespace std;

class pelicula{
	public:
		pelicula(){};

		bool operator<(const pelicula& p) const{
			if (_finalizacion < p._finalizacion)
				return true;
			else if (_finalizacion == p._finalizacion && _nombre < p._nombre)
				return true;
			else
				return false;
		}

		friend ostream& operator<<(ostream& sOut, pelicula& p){
			sOut << p._finalizacion << p._nombre;
			return sOut;
		}

		friend istream& operator>>(istream& sIn, pelicula& p) {
			THours comienzo, duracion;
			sIn >> comienzo >> duracion;
			getline(sIn, p._nombre);
			p._finalizacion = comienzo + duracion;
			return sIn;
		}

	private:
		THours _finalizacion;
		string _nombre;
};
#endif