#pragma once
using namespace std;
class Mensagem {
private:
	string remetente;
	list<string> lista_destinatarios;
	string assunto;
	string texto;

public:
	Mensagem();
	Mensagem(const Mensagem& m);
	~Mensagem();

	
	/*Metodos Auxiliares Necessários*/

	string getRemetente()  const;
	void setRemetente(string remetente);

	string getTexto()  const;
	void setTexto(string texto);

	string getAssunto()  const;
	void setAssunto(string assunto);

	void escreve(ostream &out) const;

	list<string>getDestinatario()const;
	void setDestinatario(string destinatario);

	// Declaração da sobrecarga  do operador == que compare o assunto de duas Mensagens
	bool operator==(const Mensagem& m) const;
	
	bool operator <(const Mensagem& m);

	/*bool operator >(const Mensagem&m)const;
	bool operator <(const Mensagem&m)const;*/
};

Mensagem::Mensagem() {}

Mensagem::Mensagem(const Mensagem &m){}

Mensagem::~Mensagem(){}

list<string>Mensagem::getDestinatario()const
{

	return lista_destinatarios;
}

void Mensagem::setDestinatario(string destinatario)
{
	lista_destinatarios.push_back(destinatario);

}

string Mensagem::getRemetente()  const
{
	return remetente;
}

void Mensagem::setTexto(string texto)
{
	this->texto = texto;
}

string Mensagem::getTexto()  const
{
	return texto;
}

void Mensagem::setRemetente(string remetente)
{
	this->remetente = remetente;
}

string Mensagem::getAssunto()  const
{
	return assunto;
}


void Mensagem::setAssunto(string assunto)
{
	this->assunto = assunto;
}


void Mensagem::escreve(ostream &out) const
{
	out <<endl << "Remetente: "<< remetente <<endl << "Assunto: "<< assunto <<endl <<"Texto: " << texto <<endl << " ---------- " <<endl;
}

ostream & operator <<(ostream &out, const Mensagem &m)
{
	m.escreve(out);
	return out;
}

// Implementação da sobrecarga do operador == que compara assunto de duas Mensagens.

bool Mensagem::operator==(const Mensagem& m) const
{
	if (assunto == m.assunto)
		return true;
	else
		return false;
}

bool Mensagem::operator <(const Mensagem& m)
{
	return (this->assunto<m.assunto);
}


//
//bool Mensagem ::operator >(const Mensagem &m) const
//{
//	int i = 0;
//	while (this->assunto[i] == m.assunto[i])
//	{
//		i++;
//	}
//	return(this->assunto[i] > m.assunto[i]);
//}



//bool Mensagem ::operator <(const Mensagem &m) const
//{
//	int i = 0;
//	while (this->assunto[i] == m.assunto[i])
//	{
//		i++;
//	}
//	return(this->assunto[i] < m.assunto[i]); // devolve false
//}



