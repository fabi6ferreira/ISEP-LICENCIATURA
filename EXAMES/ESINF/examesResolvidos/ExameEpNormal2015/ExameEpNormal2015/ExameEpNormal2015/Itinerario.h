

using namespace std;

class Itinerario{

private:
	float preco;
	int duracao;
public:
	Itinerario();
	Itinerario(float preco, int duracao);
	Itinerario(const Itinerario &i);
	~Itinerario();
	float getPreco();
	int getDuracao();
	
};

Itinerario::Itinerario()
{
}

Itinerario::Itinerario(float preco, int duracao)
{
	this->preco=preco;
	this->duracao=duracao;
}

Itinerario::Itinerario(const Itinerario &i)
{
	preco=i.preco;
	duracao=i.duracao;

}

Itinerario::~Itinerario()
{
}

 float Itinerario::getPreco()
 {
	 return this->preco;
 }

 int Itinerario::getDuracao()
 {
	 return duracao;
 }