#pragma once

#include "F_Argumentos.h"

using namespace std;

class Invoc_par : public list<F_Argumentos> {
public:
	Invoc_par();
	Invoc_par(const Invoc_par& ip);
	~Invoc_par();
	//…

	//alinea b
	void addPilhaArg(F_Argumentos args);
	//alinea a
	void eliminaPilhaArg(unsigned int num_ordem);
};

Invoc_par::Invoc_par() {}

Invoc_par::Invoc_par(const Invoc_par &ip) {}

Invoc_par::~Invoc_par() {}

//Eliminar caso exista, uma pilha de argumentos, dando o seu número
void Invoc_par::eliminaPilhaArg(unsigned int num_ordem)
{
	list<F_Argumentos>::iterator it;
	list<F_Argumentos>::iterator aux;

	for (it = this->begin(); it != this->end(); it++)
	{
		if(it->getNum_ordem()==num_ordem)
		{
			aux = it; // guardar a posicao a ser eliminada
			break;
		}
	}
	if (this->size()>0) {
		this->erase(aux);
	}

}

//Guardar os argumentos de uma chamada.
void Invoc_par::addPilhaArg(F_Argumentos args)
{
	this->push_back(args);
	this->sort();
}