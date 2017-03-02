#ifndef __LIBROS_H
#define __LIBROS_H
#include <iostream>
#include <time.h>
#include <stdexcept>
#include "List.h"
#include "TreeMap.h"
#include "HashMap.h"
using namespace std;

typedef string Titulo;

class Libros{
private:
	struct infoLibro{
		int cantidad;
		int numVenta;
		int antiguedad;
		//struct tm *fecha;

		bool operator<(const infoLibro& l2) const{
			if (numVenta > l2.numVenta)
				return false;
			else if (numVenta < l2.numVenta)
				return true;
			else{	// numero de venta igual
				if (antiguedad >= l2.antiguedad)
					return false;
				else
					return true;
			}
		}

		bool operator==(const infoLibro& l2) const {
			return (numVenta == l2.numVenta) && (antiguedad == l2.antiguedad);
		}
	};


	//time_t now;
	int _ant;
	HashMap<Titulo, infoLibro> _libreria;

public:
	/*
	Anade n ejemplares de un libro x al sistema. Si n toma el valor cero significa que
	el libro est´a en el sistema, aunque no se tienen ejemplares disponibles. Si el libro ya esta en el sistema
	se a˜naden los ejemplares.
	*/
	void nuevoLibro(string libro, int cantidad){
		if (_libreria.contains(libro)){
			_libreria.find(libro).value().cantidad += cantidad;
		}
		else{
			infoLibro aux;
			aux.cantidad = cantidad;
			aux.numVenta = 0;
			aux.antiguedad = 0;
			//aux.fecha = localtime(&now);
			_libreria.insert(libro, aux);
		}
	}

	/*
	Un usuario compra un libro x. Si no existen ejemplares disponibles del libro x se produce
	un error de tipo out of range con el mensaje No hay ejemplares. Si el libro no est´a dado de alta en el
	sistema se produce un error de tipo invalid argument con el mensaje Libro no existente.
	*/
	void comprar(string libro){
		if (!_libreria.contains(libro))
			throw invalid_argument("Libro no existente");
		if (_libreria.at(libro).cantidad == 0)
			throw out_of_range("No hay ejemplares");
		_libreria.find(libro).value().cantidad -= 1;
		_libreria.find(libro).value().numVenta++;
		_ant++;
		_libreria.find(libro).value().antiguedad = _ant;
		//_libreria.find(libro).value().fecha = localtime(&now);
	}

	/*
	Indica si un libro x se ha a˜nadido al sistema. El resultado ser´a cierto si el libro est´a en
	el sistema, aunque no haya ejemplares disponibles y ser´a falso si no est´a en el sistema.
	*/
	bool estaLibro(string libro){
		return _libreria.contains(libro);
	}

	/*
	Elimina el libro x del sistema. Si el libro no existe la operaci´on no tiene efecto.
	*/
	void elimLibro(string libro){
		if (_libreria.contains(libro)){
			_libreria.erase(libro);
		}
	}

	/*
	Devuelve el n´umero de ejemplares de un libro x que hay disponibles en el sistema.
	Si el libro no est´a dado de alta se produce un error de tipo invalid argument con el mensaje Libro no
	existente.
	*/
	int numEjemplares(string libro){
		if (!_libreria.contains(libro))
			throw invalid_argument("Libro no existente");
		return _libreria.find(libro).value().cantidad;
	}

	/*
	Obtiene una lista con los 10 libros que m´as se han vendido. Si hay mas de 10 libros distintos
	con un m´aximo n´umero de ventas la aplicaci´on obtiene los 10 de venta m´as reciente. Si no se han vendido
	10 libros distintos se listar´an todos ellos. La lista estar´a ordenada por n´umero de ventas primero los m´as
	vendidos y los libros que se hayan vendido el mismo n´umero de veces se ordenan del que tenga la venta
	m´as moderna a la m´as antigua.
	*/
	List<Titulo> top10(){
		HashMap<Titulo, infoLibro>::ConstIterator it = _libreria.cbegin();
		//TreeMap<HashMap<Titulo, infoLibro>::ConstIterator,int> mapLibro;
		TreeMap<infoLibro, Titulo> topMap;
		while (it != _libreria.cend()){
			topMap.insert(it.value(),it.key());
			it++;
		}

		TreeMap<infoLibro, Titulo>::ConstIterator topit = topMap.cbegin();
		List<Titulo> top;

		//while (topit != topMap.cend() && top.size() < 10)
		while (topit != topMap.cend())
		{
			if (topit.key().numVenta != 0)
				top.push_front(topit.value());
			topit++;
		}
		return top;
	}

};
#endif