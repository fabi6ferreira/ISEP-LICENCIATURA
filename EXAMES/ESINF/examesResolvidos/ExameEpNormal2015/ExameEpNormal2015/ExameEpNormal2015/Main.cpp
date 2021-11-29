#include <cstdlib>
#include <iostream>
#include <string>

#include <list>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap

#include "bst.h"
#include "bstIteratorPreOrder.h"
#include "tree.h"

#include "Mensagem.h"
#include "Servidor.h"
#include "Itinerario.h"
#include "Viagem.h"


using namespace std;


int outroMisterio(vector<int> v, int x, int y) {

	int r = 0;

	for (int i = x; i < x + y; i++) // 1 a 5
	{
		r = r + v[i];
	}
	int aux = r / y;
	cout << aux;
	return aux;
}

/*
alinea a)

int outroMisterio(vector<int> v, int x, int y)

Faz o somatorio dos elementos
do vector entre duas posicoes passadas como parametro,
e devolve a média desses elementos.

*/

void misterio(vector <int> vi, vector<int> &vo)
{
	int s = 3;

	for (int i = 0; i < vi.size() - s; i++) //n
	{
		vo[i] = outroMisterio(vi, i, s); //1
	}
}
/*
alinea b)

void misterio(vector <int> vi, vector<int> &vo)

Complexidade Temporal O(n);

*/
// 3 , 10


int main()
{
	cout << "Exame Epoca Normal 2015" << endl;
	Mensagem m1,m0,m2,m3,m4,m5;
	
	Servidor server;
	
	// Mensagens de Teste para Alinea a)
	m0.setAssunto("bbsszza");
	m0.setTexto("bla bla bla");
	m0.setRemetente("Rita");
	m0.setDestinatario("Pedro");
	server.insereOut(&m0);

	m1.setAssunto("assunto1");
	m1.setTexto("bla bla bla");
	m1.setRemetente("Rita");
	m1.setDestinatario("Pedro");
	server.insereOut(&m1);

	m2.setAssunto("assunto2");
	m2.setTexto("hihi hihhi hihi");
	m2.setRemetente("Rita");
	m2.setDestinatario("Jose");
	server.insereOut(&m2);

	m3.setAssunto("000");
	m3.setTexto("Ola ...");
	m3.setRemetente("Jose");
	m3.setDestinatario("Ana");
	m3.setDestinatario("Pedro");
	server.insereOut(&m3);

	// Mensagens de Teste para Alinea c)
	m4.setAssunto("xpto");
	m4.setTexto("Ola ...");
	m4.setRemetente("Jose");
	m4.setDestinatario("Ana");
	m4.setDestinatario("Pedro");
	server.insereIn(&m4);

	m5.setAssunto("oi");
	m5.setTexto("Ola ...");
	m5.setRemetente("Jose");
	m5.setDestinatario("Ana");
	server.insereIn(&m5);

	cout <<" ------ Exercicio 1 ------- "<<endl<< endl;

	cout << " Alinea a) " << endl << endl;
	server.mensagensEnviadasByUser("Rita");

	cout << " Alinea b) " << endl << endl;
	server.mensagensEnviadasMaiorNumDestinatarios();

	cout << " Alinea c) " << endl << endl;

	server.apagarMensagensByAssunto("xpto");


	cout << endl << " ------ Exercicio 2 ------- " << endl << endl;


	vector<int> v;

	
	v.push_back(2);
	v.push_back(2); // 1
	v.push_back(4);
	v.push_back(2);
	v.push_back(30); // 4

	int x = 1;
	int y = 4;
	
	outroMisterio(v, x, y);

	cout << endl << endl << " Alinea a)" << endl << endl;

	cout <<endl<< " int outroMisterio(vector<int> v, int x, int y) " << endl <<endl;

	cout << " Faz somatorio dos elementos do vector entre a posicao x," << endl;
	cout << " e a posicao somada de x com y, e no fim retorna a divisao por y," << endl;
	cout << " desse somatorio."<< endl;

	cout << endl << " Alinea b)" << endl <<endl;

	cout << endl << "void misterio(vector <int> vi, vector<int> &vo) " << endl;
	
	cout << endl << " Complexidade Temporal O(n) no Melhor Caso, "<< endl;
	cout << endl << "  no Pior Caso n log(n) " << endl;

	/* Exercicio 5

	“Considere a estrutura de informação designada por fila de prioridade ou HEAP,
	Ilustre a execução do algoritmo heapsort sobre os valores 1, 4, 10, 2, 23, 5, 20, 22.
	Considere que o heap está organizado por máximos.”

	*/
	//int vec2[] = { 65, 45, 90, 20, 120, 10};
	//int vec[] = { 2, 15, 7, 1, 14, 6, 10, 8, 3, 9, 13, 5, 16, 4, 11 };


	int vec2[] = { 1, 4, 10, 2, 23, 5, 20, 22 };


	cout << endl << " ------ Exercicio 5 ------- " << endl << endl;
	vector <int> hv(begin(vec2), end(vec2));

	cout << "Make heap da STL " << endl << endl;
	make_heap(hv.begin(), hv.end()); // STL library equivalent 

	for (auto el : hv) cout << el << " , ";
	cout << endl;


	cin.get();
	return 0;
}