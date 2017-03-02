#ifndef __CONSULTORIO_H
#define __CONSULTORIO_H
#include <iostream>
#include "TreeMap.h"
#include "Fecha.h"
#include "List.h"
using namespace std;

typedef string Medico;
typedef string Paciente;

class Consultorio{
public:

	// constructor
	Consultorio() : _consultorio(TreeMap<Medico, TreeMap<Fecha, Paciente>>()) {};

	/*
	da de alta un nuevo medico en el consultorio
	si el medico ya esta en el consultorio este no se modifica.
	*/
	void nuevoMedico(const Medico &medico){
		if (!_consultorio.contains(medico)){
			
			_consultorio.insert(medico, TreeMap<Fecha, Paciente>());
		}
	}

	/*
	un paciente pide consulta con un medico para una fecha
	si el medico no esta dado de alta se lanzara una excepcion con el mensaje Medico no existe.
	si la fecha ya esta reservada, se lanzara una excepcion con el mensaje Fecha ocupada.
	un paciente puede tener varias citas con el mismo medico,
	siempre que sean en distinto momento
	*/
	void pideConsulta(const Paciente p, const Medico &m, const Fecha& f){
		if (!_consultorio.contains(m)){
			throw Excepcion("Medico no existente");
		}
		else if (_consultorio.at(m).contains(f)){
			throw Excepcion("Fecha ocupada");
		}
		else {
			TreeMap<Fecha,Paciente> aux = _consultorio.at(m);
			aux.insert(f, p);
			_consultorio.insert(m, aux);
		}
	}

	/*
	consulta el paciente al que le toca el turno de ser atendido por un medico.
	suponemos que el siguiente paciente es el que tiene una fecha menor.
	si el medico no esta dado de alta se lanzara una excepcion con el mensaje Medico no existente.
	si el medico no tiene pacientes asignados se lanzara una excepcion con mensaje No hay pacientes.
	*/
	TreeMap<Fecha,Paciente>::ConstIterator siguientePaciente(const Medico &m){
		if (!_consultorio.contains(m)){
			throw Excepcion("Medico no existente");
		}
		if (_consultorio.at(m).empty()){
			throw Excepcion("No hay pacientes");
		}
		TreeMap<Fecha, Paciente>::ConstIterator it = _consultorio.at(m).cbegin();
		return it;
	}

	/*
	elimina el siguiente paciente de un medico.
	suponemos que el siguiente paciente es el que tiene una fecha menor.
	si el medico no esta dado de alta se lanzara una excepcion con el mensaje Medico no existente.
	si el medico no tiene pacientes asignados se lanzara una excepcion con mensaje No hay pacientes.
	*/
	void atiendeConsulta(const Medico &m){
		TreeMap<Fecha, Paciente>::ConstIterator it = siguientePaciente(m);
		_consultorio.begin().value().erase(it.key());
	}

	/*
	devuelve la lista de pacientes de un cierto medico que tiene cita el dia.
	se supone que el dia es un numero entero correcto.
	si el medico no esta dado de alta se lanzara una excepcion con mensaje Medico no existente.
	si el medico no tiene pacientes ese dia, la lista de retorno sera vacia.
	*/
	List<TreeMap<Fecha, Paciente>::ConstIterator> listaPacientes(const Medico &m, const Fecha &f){
		List<TreeMap<Fecha, Paciente>::ConstIterator> lista = List<TreeMap<Fecha, Paciente>::ConstIterator>();
		if (!_consultorio.contains(m)){
			throw Excepcion("Medico no existente");
		}
		TreeMap<Fecha, Paciente>::ConstIterator it = _consultorio.at(m).cbegin();
		TreeMap<Fecha, Paciente>::ConstIterator itend = _consultorio.at(m).cend();

		Fecha fecha;
		Fecha fecha2 = f;

		while (it != itend)
		{
			fecha = it.key();
			if (fecha.dia() == fecha2.dia())
				lista.push_back(it);
			it.next();
		}
		return lista;
	}

private:

	TreeMap<Medico, TreeMap<Fecha,Paciente>> _consultorio;
};
#endif