#include "Grafo.h"

Grafo::Grafo()
{
	ultimoVer = 0; 
}

Grafo::~Grafo()
{
	for (auto const& par : vertices) {
		delete par.second;
	}
	for (Arista* a : aristas) delete a;
}

void Grafo::InsertarVertice(string id)
{
	vertices[ultimoVer] = new Vertice(id, ultimoVer);
	ultimoVer++;
}

int Grafo::getVertice(string i)
{

	if (tablaIds.find(i) != tablaIds.end()) {
		return tablaIds[i];
	}
	int nuevoId = ultimoVer;
	tablaIds[i] = nuevoId;
	Vertice* v = new Vertice(i, nuevoId);
	vertices[nuevoId] = v;
	ultimoVer++;

	return nuevoId;
}

bool Grafo::existeArista(string nodoP, string nodoH)
{
	bool resp = false;
	if (tablaIds.find(nodoP) == tablaIds.end() || tablaIds.find(nodoH) == tablaIds.end()) {
		resp = false;
	}
	else {
		int idOrigen = tablaIds[nodoP];
		int idDestino = tablaIds[nodoH];
		for (size_t i = 0; i < aristas.size(); i++) {
			Arista* a = aristas[i];
			int u = a->getVOrigen();
			int v = a->getVDestino();
			if ((u == idOrigen && v == idDestino) || (u == idDestino && v == idOrigen)) {
				resp = true;
			}
		}
	}

	return resp;
}

void Grafo::InsertarArista(string nodoP, string nodoH)
{
	if (!existeArista(nodoP, nodoH)) {
		int vOrigen = getVertice(nodoP);
		int vDestino = getVertice(nodoH);
		Arista* a = new Arista(vOrigen, vDestino);
		aristas.push_back(a); 
	}

}
void Grafo::mostrarGrafo() {
	int id=0;
	string destino,origen;
	bool primero = true;
	for (Arista* a : aristas) {
		if (id != a->getVOrigen()|| primero==true)
		{
			if(id != a->getVOrigen())
			{
				cout << "]" << endl;
			}
			id = a->getVOrigen();
			origen = vertices[a->getVOrigen()]->getVerticeId();
			destino = vertices[a->getVDestino()]->getVerticeId();
			if (primero == true){
				primero = false;
			}
			cout << "Origen: " << origen << " ----- " << " Destinos: ["<<destino << ", ";
		}
		else {
			destino = vertices[a->getVDestino()]->getVerticeId();
			cout << destino<<", ";
		}
	}
}

void Grafo::setMarcasYPadres()
{
	for (auto const& par : vertices) {
		Vertice* v = par.second;
		v->setMarca(false);
		v->setPadre(par.first);
	}
}

void Grafo::_union(int ori, int des)
{
	if (ori != des) {
		Vertice* vDes = vertices[des];
		vDes->setPadre(ori);
	}
}

int Grafo::_find(int x)
{
	Vertice* v = vertices[x];
	if (v->getPadre() == x) {
		return x;
	}
	int representate = _find(v->getPadre());
	v->setPadre(representate);
	return representate;
}

int Grafo::corteMinimo()
{

	if (ultimoVer < 2) return 0;

	std::random_device rd;

	std::mt19937 gen(rd());

	int min = 99999999;
	int iteraciones = (ultimoVer + 1) * (ultimoVer + 1) * log(ultimoVer + 1);

	for (int it = 0; it < iteraciones; it++) {

		setMarcasYPadres();

		vector<Arista*> aristasTotal;
		aristasTotal.reserve(aristas.size()); 

		aristasTotal = aristas;

		int gruposRestantes = ultimoVer;

		while (gruposRestantes > 2 && !aristasTotal.empty()) {

			std::uniform_int_distribution<> distrib(0, aristasTotal.size() - 1);
			int rand = distrib(gen);

			Arista* arista = aristasTotal[rand];

			int padreU = _find(arista->getVOrigen());
			int padreV = _find(arista->getVDestino());

			if (padreU != padreV) {
				_union(padreU, padreV);
				gruposRestantes--;
			}
			aristasTotal[rand] = aristasTotal.back();
			aristasTotal.pop_back();
		}
		int act = 0;
		for (int i = 0; i < aristas.size(); i++) {
			Arista* a = aristas[i];
			int raizOrigen = _find(a->getVOrigen());
			int raizDestino = _find(a->getVDestino());

			if (raizOrigen != raizDestino) {
				act++;
			}
		}

		if (act < min) {
			min = act;
		}
	}

	return min;
}