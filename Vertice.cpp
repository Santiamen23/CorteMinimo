#include "Vertice.h"
#include "Arista.h"

Vertice::Vertice(string verticeId,int padre)
{
	this->verticeId = verticeId;
	marca = false;
	this->padre = padre;
}

Vertice::~Vertice()
{
}

string Vertice::getVerticeId()
{
	return verticeId;
}

bool Vertice::getMarca()
{
	return marca;
}

void Vertice::setMarca(bool marca)
{
	this->marca = marca;
}

int Vertice::getPadre()
{
	return padre;
}

void Vertice::setPadre(int padre)
{
	this->padre = padre;
}



string Vertice::verticeToJson(Vertice* v)
{
	return v->verticeToJson();
}

bool Vertice::operator==(Vertice* v)
{
	return false;
}


string Vertice::verticeToJson()
{
	stringstream ss;
	ss << "{\"VerticeId\": " << verticeId <<"}";
	return ss.str();
}