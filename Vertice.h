#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Vertice
{
private:
	bool marca;
	string verticeId;
	int padre;
public:
	Vertice(string verticeId, int padre);
	~Vertice();
	string getVerticeId();
	bool getMarca();
	void setMarca(bool marca);
	int getPadre();
	void setPadre(int padre);
	static string verticeToJson(Vertice* v);
	bool operator==(Vertice* v);
	string verticeToJson();
};