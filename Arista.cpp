#include "Arista.h"

Arista::Arista(int vOrigen,int vDestino)
{
	this->vDestino = vDestino;
	this->vOrigen = vOrigen;
}

Arista::~Arista()
{
}


int Arista::getVDestino()
{
	return vDestino;
}

int Arista::getVOrigen()
{
	return vOrigen;
}
