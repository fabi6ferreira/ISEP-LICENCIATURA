#ifndef pais_
#define pais_

using namespace std;

class pais{

private: 
	string nome;
	string continente;
	set<string>idiomas;

public:
	pais();// Construtor por defeito
	pais(string nome, string continente/* set<string> idiomas*/);// Construtor com parâmetros
	pais(const pais& a);// Construtor Cópia
	~pais();//  Destrutor

	string getNome() const;
	string getContinente()  const;

	void setNome(string nome);
	void setContinente(string continente);

	set<string>getIdiomas()const;
	void setIdiomas(string idioma);


	void escreve(ostream &out) const;

	const pais& operator=(const pais &p);
};

// Construtor por defeito

pais::pais()
{
	nome = "";
	continente ="";
}

// Construtor com parâmetros

pais::pais(string nome, string continente/* set<string> idiomas*/)
{
	this->nome=nome;
	this->continente=continente;
	//this->idiomas = idiomas;
}


// Construtor Cópia

pais::pais(const pais& p)
{
	nome = p.nome;
	continente = p.continente;
	idiomas = p.idiomas;
}

//  Destrutor

pais::~pais()
{
}

string pais::getNome()  const
{
	return nome;
}

string pais::getContinente()  const
{
	return continente;
}

void pais::setNome(string nome)
{
	this->nome = nome;
}

void pais::setContinente(string continente)
{
	this->continente = continente;
}

const pais& pais::operator=(const pais &p)
{
	nome = p.nome;
	continente = p.continente;

	return *this;
}
set<string>pais::getIdiomas() const
{
	return idiomas;
}

void pais::setIdiomas(string idioma)
{
	idiomas.insert(idioma);
}

void pais::escreve(ostream &out) const
{
	out << " ( " << nome << " , " << continente << " ) ";
}

ostream & operator <<(ostream &out, const pais &p)
{
	p.escreve(out);
	return out;
}

#endif