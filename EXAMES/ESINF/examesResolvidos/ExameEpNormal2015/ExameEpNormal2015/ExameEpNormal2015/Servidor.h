#pragma once

using namespace std;

class Servidor {
private:
	vector<Mensagem*> caixaIn; // INBOX
	vector<Mensagem*> caixaOut;  // OUTBOX

public:
	Servidor();
	Servidor(vector <Mensagem>& cxin, vector<Mensagem>& cxot);
	~Servidor();

	//Alinea a)
	void mensagensEnviadasByUser(string remetente);
	//Alinea b)
	void mensagensEnviadasMaiorNumDestinatarios();
	//Alinea c)
	void apagarMensagensByAssunto(string assunto);

	//Metodos Auxiliares Necessários
	void insereOut(Mensagem *m);
	void insereIn(Mensagem *m);

};


// Construtor por defeito

Servidor::Servidor() {}

Servidor::Servidor(vector <Mensagem>& cxin, vector<Mensagem>& cxot) 
{
	
}

Servidor::~Servidor() {}


void Servidor::insereOut(Mensagem *m)
{
	caixaOut.push_back(m);
}
void Servidor::insereIn(Mensagem *m)
{
	caixaIn.push_back(m);
	//cout << *m;
}
/*
Alinea a)

Colocar numa lista todas as mensagens enviadas por um dado utilizador,
ordenadas por ordem alfabética do assunto.

*/
//void Servidor::mensagensEnviadasByUser(string remetente)
//{
//	list <Mensagem*> lista;
//
//	list<Mensagem*>::iterator it;
//
//	int tamanho = caixaOut.size();
//	if (tamanho == 0)
//	{
//		cout << "Nao tem Mensagens na Caixa de Entrada" << endl;
//	}
//	for (int i = 0; i < tamanho; i++)
//	{
//		if (remetente == caixaOut[i]->getRemetente())
//		{
//			lista.push_back(caixaOut[i]);
//		}
//	}
//
//	lista.sort();
//	for (it = lista.begin(); it != lista.end(); it++)
//			{
//						cout << **it;
//			}
//}

void Servidor::mensagensEnviadasByUser(string remetente)
{
	list <Mensagem*> l;
	list<Mensagem*>l2;

	list<Mensagem*>::iterator itr1;
	vector<Mensagem*>vecMensagem;

	Mensagem *aux;

	int tamanho = caixaOut.size();
	if (tamanho == 0)
	{
		cout << "Nao tem Mensagens na Caixa de Entrada" << endl;
	}
	for (int i = 0; i<tamanho; i++)
	{
		if (remetente == caixaOut[i]->getRemetente())

			l.push_back(caixaOut[i]);
	}

	for (itr1 = l.begin(); itr1 != l.end(); itr1++)
	{
		vecMensagem.push_back(*itr1);

	}

	for (int i = 0; i<vecMensagem.size() - 1; i++)
	{
		for (int j = i + 1; j<vecMensagem.size(); j++)
		{
			string sa = vecMensagem[i]->getAssunto();
			string sb = vecMensagem[j]->getAssunto();
			if (sa.compare(sb)>0)
			{
				aux = vecMensagem[i];
				vecMensagem[i] = vecMensagem[j];
				vecMensagem[j] = aux;
			}
		}
	}
	for (int i = 0; i<vecMensagem.size(); i++)
	{
		//cout << *vecMensagem[i] << endl;
		l2.push_back(vecMensagem[i]);
	}
	for (itr1 = l.begin(); itr1 != l.end(); itr1++)
	{
				cout << **itr1;
	}
}

/*
Alinea b)

Devolver um vetor a(s) mensagem(s) enviadas como maior 
nº de destinatários.
*/

void Servidor::mensagensEnviadasMaiorNumDestinatarios()
{
	int numDestinatrarios=0; //aux
	
	vector<Mensagem*> vec_aux;

	int tamanho = caixaOut.size();
	if (tamanho == 0)
	{
		cout << "Nao tem Mensagens na Caixa de Saida" << endl;
	}
	for (int i = 0; i < tamanho; i++)
	{
		if (caixaOut[i]->getDestinatario().size()>=numDestinatrarios)
		{
			numDestinatrarios = caixaOut[i]->getDestinatario().size();
		}

	}
	for (int i = 0; i < tamanho; i++)
	{
		if (caixaOut[i]->getDestinatario().size() == numDestinatrarios)
		{
			vec_aux.push_back(caixaOut[i]);
			cout << *caixaOut[i];
		}
		
	}
}

/*
Alinea c)
Apagar da caixa de entrada as mensagens com um determinado assunto.
*/

void Servidor::apagarMensagensByAssunto(string assunto)
{
	Mensagem *aux;
	vector<Mensagem *> vec_aux;
	int tamanho = caixaIn.size();
	if (tamanho == 0)
	{
		cout << "Nao tem Mensagens na Caixa de Entrada" << endl;
	}
	vector<Mensagem*>::iterator i;

	for (i = caixaIn.begin(); i !=caixaIn.end(); i++)
	{
		aux = *i;
		//select messages to not erase
		// Seleciona as mensagens que nao pretende se apagar
		if (aux->getAssunto()!=assunto)
		{
			// Guarda Mensagens que nao se pretende apagar
			vec_aux.push_back(*i);
		}
	}
	//Apaga o Vector caixaIn
	caixaIn.clear();
	// Adiciona Mensagens Restantes ao Vector caixaIn
	caixaIn = vec_aux;
	cout << "Tamanho: " <<caixaIn.size();
	tamanho = caixaIn.size();
	for (int i = 0; i < tamanho; i++)
	{
		cout << *caixaIn[i];
	}

}