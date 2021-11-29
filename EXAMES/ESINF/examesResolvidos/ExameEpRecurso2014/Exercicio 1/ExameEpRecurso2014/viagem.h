#ifndef viagem_
#define viagem_

#include "pais.h"

using namespace std;

class viagem{
	queue<pais> paises;
public:
	viagem();
	viagem(const viagem& t);
	~viagem();

	void escreve(ostream &out) const;

	void adicionarPais(const pais* p);
	int getNIdiomasViagem() const;
	
};

// Construtor por defeito

viagem::viagem()
{
	
}

// Construtor Cópia

viagem::viagem(const viagem& t)
{
	
}

//  Destrutor

viagem::~viagem()
{
}


void viagem::escreve(ostream &out) const
{
	queue<pais>aux = paises;

	while (!aux.empty())
	{
		out << " Paises: " << aux.front() << endl;
		aux.pop();
	}
	
}

ostream & operator <<(ostream &out, const viagem &t)
{
	t.escreve(out);
	return out;
}

//Adicionar à viagem um país a visitar,
//mantendo a informação organizada por ordem alfabética do nome do país.
void viagem::adicionarPais(const pais* p)
{
	paises.push(*p);

	pais aux;
	vector<pais>vec;
	while (!paises.empty())
	{
		vec.push_back(paises.front());
		paises.pop();
	}
	int tam = vec.size();
	for (int i = 0; i<tam - 1; i++)

		for (int j = i + 1; j<tam; j++)
		{

		string sa = vec[i].getNome();
		string sb = vec[j].getNome();

		if (sa.compare(sb)>0)
		{
			aux = vec[i];
			vec[i] = vec[j];
			vec[j] = aux;
		}

		}

	for (int i = 0; i<vec.size(); i++)
	{
		paises.push(vec[i]);
	}
}

// Indicar quantos idiomas diferentes se poderão falar numa viagem.
int viagem::getNIdiomasViagem() const
{
	set<string> todosIdiomas;
	queue<pais> paisesCopia = paises;
	set<string>::iterator it;

	while (!paisesCopia.empty())
	{
		set<string> idiomasPais = paisesCopia.front().getIdiomas();
		for (it = idiomasPais.begin(); it != idiomasPais.end(); it++)
			//todosIdiomas.insert(it);// .insert(*it);
		todosIdiomas.insert(*it);

		paisesCopia.pop();
	}

	//todosIdiomas.sort();
	//todosIdiomas.unique();

	cout << todosIdiomas.size();

	return todosIdiomas.size();
}


#endif