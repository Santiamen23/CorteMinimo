#pragma once
#include "Vertice.h"
#include <string>
#include <sstream>
using namespace std;
class Arista
{
private:
	int vDestino;
	int vOrigen;
public:
	Arista(int vOrigen,int vDestino);
	~Arista();
	int getVDestino();
	int getVOrigen();

};