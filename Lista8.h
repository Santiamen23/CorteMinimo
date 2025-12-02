#pragma once
#include "Tripla.h"
template <class T>
class Lista8
{
private:
	Tripla<T>* primer;
	Tripla<T>* ultimo;
public:
	Lista8();
	~Lista8();
	void insertarPrincipio(T* elem);
	void insertarFinal(T* elem);
	void eliminarPrincipio();
	void eliminarFinal();
	bool eliminarDado(T* elem);
	string mostrarListaClase(string(*f)(T*));
	bool buscarR(T* el, Tripla<T>* trip);
	bool buscarS(T* el);
	Tripla<T>* getPrimero();
};

template<class T>
inline Lista8<T>::Lista8()
{
	primer = nullptr;
	ultimo = nullptr;
}

template<class T>
inline Lista8<T>::~Lista8()
{
	Tripla<T>* actual = primer;
	while (actual != nullptr) {
		Tripla<T>* siguiente = actual->getSig();
		delete actual;
		actual = siguiente;
	}
	primer = nullptr;
	ultimo = nullptr;
}

template<class T>
inline void Lista8<T>::insertarPrincipio(T* elem)
{
	if (primer == nullptr) {
		primer = new Tripla<T>(elem, nullptr, nullptr);
		ultimo = primer;
	}
	else {
		primer = new Tripla<T>(elem, nullptr, primer);
		primer->getSig()->setAnt(primer);
	}
}

template<class T>
inline void Lista8<T>::insertarFinal(T* elem)
{
	if (ultimo == nullptr) {
		ultimo = new Tripla<T>(elem, nullptr, nullptr);
		primer = ultimo;
	}
	else {
		ultimo = new Tripla<T>(elem, ultimo, nullptr);
		ultimo->getAnt()->setSig(ultimo);
	}
}

template<class T>
inline void Lista8<T>::eliminarPrincipio()
{
	if (primer == ultimo) {
		delete primer;
		primer = nullptr;
		ultimo = nullptr;
	}
	else if (primer != nullptr) {
		Tripla<T>* temp = primer->getSig();
		primer->setSig(nullptr);
		delete primer;
		primer = temp;

	}

}

template<class T>
inline void Lista8<T>::eliminarFinal()
{
	if (ultimo == primer) {
		delete ultimo;
		ultimo = nullptr;
		primer = nullptr;
	}
	else if (ultimo != nullptr) {
		Tripla<T>* temp = ultimo->getAnt();
		ultimo->setAnt(nullptr);
		delete ultimo;
		ultimo = temp;
		ultimo->setSig(nullptr);
	}
}

template<class T>
inline bool Lista8<T>::eliminarDado(T* elem)
{
	bool resp = true;
	if (primer == nullptr) {
		resp = false;
	}
	else {

		if (primer == ultimo) {
			if (elem == primer->getDato()) {
				eliminarPrincipio();
			}
			else {
				resp = false;
			}
		}
		else {
			Tripla<T>* temp = primer;
			while (temp->getDato() != elem && temp != nullptr) {
				temp = temp->getSig();
			}
			if (temp == primer) {
				eliminarPrincipio();
			}
			else if (temp == ultimo) {
				eliminarFinal();
			}
			else if (temp != nullptr) {
				temp->getAnt()->setSig(temp->getSig());
				temp->getSig()->setAnt(temp->getAnt());
				temp->setAnt(nullptr);
				temp->setSig(nullptr);
				delete temp;
			}
			else {
				resp = false;
			}
		}
	}
	return resp;
}


template<class T>
inline string Lista8<T>::mostrarListaClase(string(*f)(T*))
{
	stringstream ss;
	if (primer != nullptr) {
		Tripla<T>* temp = primer;
		while (temp != nullptr) {
			ss << (*f)(temp->getDato());
			if (temp->getSig() != nullptr) {
				ss << ",";
			}
			temp = temp->getSig();
		}

	}
	return ss.str();
}

template<class T>
inline bool Lista8<T>::buscarR(T* el, Tripla<T>* trip)
{
	bool resp;
	if (trip == nullptr) {
		resp = false;
	}
	else {
		if (*(trip->getDato()) == el) {
			resp = true;
		}
		else resp = buscarR(el, trip->getSig());
	}
	return resp;
}

template<class T>
inline bool Lista8<T>::buscarS(T* el)
{
	bool resp = false;
	Tripla<T>* temp = primer;
	while (temp != nullptr) {
		if (*(temp->getDato()) == el) {
			resp = true;
		}
		temp = temp->getSig();
	}
	return resp;
}

template<class T>
inline Tripla<T>* Lista8<T>::getPrimero()
{
	return primer;
}

