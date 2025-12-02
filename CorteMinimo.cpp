#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"
#include <chrono>

using namespace std;

Grafo* grafo = new Grafo();
ifstream arch;
string ori;
string dest;
int minC=0;
int op;

void tiempoCorteMinimo() {

	auto inicio = std::chrono::high_resolution_clock::now();
	minC = grafo->corteMinimo();
	auto fin = std::chrono::high_resolution_clock::now();
	auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio);
	cout << "El numero minimo de cortes necesarios es: " << minC << endl;
	cout << "Tiempo de ejecución: " << duracion.count()/1000.0 << " s" << endl;
}
int main()
{
	while (true) {
		system("cls");
		cout << "1. Cargar Aristas desde Archivo (.txt)" << endl;
		cout << "2. Calcular Corte Minimo" << endl;
		cout << "3. Mostrar Grafo" << endl;
		cout << "4. Salir" << endl;
		cout << "Seleccione una opcion: ";
		cin >> op;

		system("cls");

		switch (op) {

		case 1:
			arch.open("archivo.txt");
			while (arch >> ori) {
				while (arch >> dest) {
					if (dest == "-1") {
						break;
					}
					grafo->InsertarArista(ori, dest);
				}
			}
				arch.close();
			break;

		case 2:
			tiempoCorteMinimo();
			break;
		case 3:
			grafo->mostrarGrafo();
			break;
		case 4:
			delete grafo;
			exit(0);
			break;
		}

		cout << "\n";
		system("pause");
		system("cls");
	}

	return 0;
}