#pragma once
#include "Arista.h"
#include <vector>
#include "unordered_map"
#include <ctime>
#include <random>
#include <cmath>
#define TAM 6000


class Grafo
{
private:
	unordered_map<int, Vertice*> vertices;
	unordered_map<string, int> tablaIds;
	vector<Arista*> aristas;
	int ultimoVer ;
public:
	Grafo();
	~Grafo();
	void InsertarVertice(string id);
	int getVertice(string i);
	bool existeArista(string nodoP, string nodoH);
	void InsertarArista(string nodoP, string nodoH);
	void setMarcasYPadres();
	void _union(int ori, int des);
	int _find(int x);
	int corteMinimo();
};