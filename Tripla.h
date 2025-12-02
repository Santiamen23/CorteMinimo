#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
template <class T>
class Tripla
{
private:
	Tripla<T>* sig;
	Tripla<T>* ant;
	T* elem;
public:
	Tripla(T* elem, Tripla* ant, Tripla* sig);
	~Tripla();
	Tripla<T>* getSig();
	Tripla<T>* getAnt();
	void setSig(Tripla* sig);
	void setAnt(Tripla* ant);
	T* getDato();
};

template<class T>
inline Tripla<T>::Tripla(T* elem, Tripla* ant, Tripla* sig)
{
	this->elem = elem;
	this->ant = ant;
	this->sig = sig;
}

template<class T>
inline Tripla<T>::~Tripla()
{
	if (sig == nullptr) {
		delete sig;
	}
	if (ant == nullptr) {
		delete ant;
	}
}

template<class T>
inline Tripla<T>* Tripla<T>::getSig()
{
	return sig;
}

template<class T>
inline Tripla<T>* Tripla<T>::getAnt()
{
	return ant;
}

template<class T>
inline void Tripla<T>::setSig(Tripla<T>* sig)
{
	this->sig = sig;
}

template<class T>
inline void Tripla<T>::setAnt(Tripla<T>* ant)
{
	this->ant = ant;
}


template<class T>
inline T* Tripla<T>::getDato()
{
	return elem;
}
