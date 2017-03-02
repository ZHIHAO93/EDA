#include <iostream>
#include "Consultorio.h"
#include "Fecha.h"
using namespace std;

bool resuelveCaso(){
	int n;
	Consultorio consultorio;
	string accion, paciente, medico;
	Fecha fecha;

	cin >> n;
	if (!cin){
		return false;
	}
	else{
		for (int i = 0; i < n; i++)
		{
			cin >> accion;
			if (accion == "nuevoMedico"){
				cin >> medico;
				consultorio.nuevoMedico(medico);
			}
			else if (accion == "pideConsulta"){
				cin >> paciente >> medico >> fecha;
				try{
					consultorio.pideConsulta(paciente, medico, fecha);
				}
				catch (Excepcion e){
					cout << e.msg() << endl << "---" << endl;
				}
			}
			else if (accion == "siguientePaciente"){
				cin >> medico;
				cout << "Siguiente Paciente doctor " << medico << endl;
				try{
					TreeMap<Fecha, string>::ConstIterator it = consultorio.siguientePaciente(medico);
					cout << it.value() << endl;
				}
				catch (Excepcion e){
					cout << e.msg() << endl;
				}
				cout << "---" << endl;
			}
			else if (accion == "atiendeConsulta"){
				cin >> medico;
				try{
					consultorio.atiendeConsulta(medico);
				}
				catch (Excepcion e){
					cout << e.msg() << endl << "---" << endl;
				}
			}
			else if (accion == "listaPacientes"){
				int dia;
				cin >> medico >> dia;
				fecha.nuevoFecha(dia, 0, 0);
				try{
					List<TreeMap<Fecha, Paciente>::ConstIterator> lista = consultorio.listaPacientes(medico, fecha);
					cout << "Doctor " << medico << " dia " << dia << endl;
					if (lista.empty())
						cout << endl;
					while (!lista.empty())
					{
						fecha = lista.front().key();
						cout << lista.front().value() << " " << fecha << endl;
						lista.pop_front();
					}
				}
				catch (Excepcion e){
					cout << e << endl;
				}
				cout << "---" << endl;
			}
		}
		cout << "------" << endl;
	}
	return true;
}

int main(){
	while (resuelveCaso());
	return 0;
}