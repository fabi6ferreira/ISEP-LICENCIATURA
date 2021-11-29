#pragma once

using namespace std;

class F_Argumentos {   //classe representativa da pilha de argumentos 
private:
	unsigned int num_ordem;    // Nº de ordem da pilha 
	stack<string> stack_args;    // stack com endereços de argumentos 

public:
	F_Argumentos();
	F_Argumentos(const F_Argumentos& fa);
	~F_Argumentos();

	//…

	int getNum_ordem()  const;
	void setNum_ordem(unsigned int num_ordem);

	stack<string>getArgumentos()const;
	void setArgumentos(string arg);

	//alinea b metodos auxiliares
	bool operator >(const F_Argumentos &m) const;
	bool operator <(const F_Argumentos &m) const;
};

F_Argumentos::F_Argumentos() {}

F_Argumentos::F_Argumentos(const F_Argumentos &fa) 
{
	this->num_ordem = fa.num_ordem;
	this->stack_args = fa.stack_args;
}

F_Argumentos::~F_Argumentos() {}


void F_Argumentos::setNum_ordem(unsigned int num_ordem)
{
	this->num_ordem = num_ordem;

}

int F_Argumentos::getNum_ordem()  const
{
	return num_ordem;
}


stack<string>F_Argumentos::getArgumentos()const
{

	return stack_args;
}

void F_Argumentos::setArgumentos(string arg)
{
	stack_args.push(arg);

}


bool F_Argumentos ::operator >(const F_Argumentos &fa) const
{
	
	return(this->num_ordem > fa.num_ordem);
}


bool F_Argumentos ::operator <(const F_Argumentos &fa) const
{

	return(this->num_ordem <fa.num_ordem);
}
