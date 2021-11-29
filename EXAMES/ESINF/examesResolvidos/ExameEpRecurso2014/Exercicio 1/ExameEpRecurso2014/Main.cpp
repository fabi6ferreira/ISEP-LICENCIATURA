#include <iostream>
#include <string>

#include <queue>
#include <set>
#include <list>

#include "pais.h"
#include "viagem.h"

using namespace std;

int teste(int j, int k)
{
	if (j>k)
		return j;
	else
		return k;
}

int misterio(vector<int> A, int n)
{
	if (n == 1)
		return A[0];
	else if (n > 1)
	{
		int k = n / 2;
		for (size_t i = 0; i<k; i++)
		{
			if (n % 2 == 0)
				A[i] = teste(A[i], A[i + k]);
			else
				A[i] = teste(A[i], A[i + k + 1]);
		}
		// IMprimir conteudo do vector A[]
		for (size_t i = 0; i < n; i++)
		{
			cout << "step1: "<<A[i] << endl;
		}
		if (n / 2 != 0)
			A[0] = teste(A[0], A[(n / 2)]);
		// IMprimir conteudo do vector A[]
		for (size_t i = 0; i < n; i++)
		{
			cout << "step2: " << A[i] << endl;
		}
		return misterio(A, k);
	}
}

int main() 
{
	pais *p1 = new pais();
	pais *p2 = new pais();
	pais *p3=new pais();

	p1->setContinente("Europa");
	p1->setNome("Portugal");
	
	p1->setIdiomas("Portugues");
	
	p2->setContinente("Europa");
	p2->setNome("Espanha");
	
	p2->setIdiomas("Espanhol");

	
	p3->setContinente("Europa");
	p3->setNome("Alemanha");
	
	p3->setIdiomas("Alemão");

	/*cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;*/

	viagem v;
	
	v.adicionarPais(p1);
	v.adicionarPais(p2);
	v.adicionarPais(p3);

	cout << v << endl;


	cout <<endl<<" Idiomas" << endl;
	v.getNIdiomasViagem();

	cout << endl << endl;
	
	cout << "MISTERIOSO EXAME DE ESINF 2014: " << endl << endl;
	vector <int> A;
	A.push_back(10);
	A.push_back(9);
	A.push_back(10);
	A.push_back(4);
	A.push_back(11);
	
	int n = 5;
	
	misterio(A, n);
	// Complexidade O(1) Linear no Melhor Caso no Pior Caso 

	int res = misterio(A, n);
	
	cout << res << endl;

	cin.get();
	return 0;
}
