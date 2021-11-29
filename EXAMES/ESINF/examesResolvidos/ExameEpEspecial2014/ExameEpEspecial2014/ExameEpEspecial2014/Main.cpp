#include <iostream>
#include <string>

#include <stack>
#include <list>

#include "tree.h"
#include "F_Argumentos.h"
#include "Invoc_par.h"



using namespace std;

int main()
{

	F_Argumentos *fa1 = new F_Argumentos();
	F_Argumentos *fa2 = new F_Argumentos();


	fa1->setNum_ordem(1);
	fa1->setArgumentos("ola");

	fa2->setNum_ordem(2);
	fa2->setArgumentos("o caraças");
	fa2->setArgumentos("hmmmm...");

	Invoc_par in;

	in.push_back(*fa1);
	in.push_back(*fa2);

	cout << in.size()<<endl;
	in.eliminaPilhaArg(1);

	cout << in.size() << endl;
	cin.get();
	return 0;
}
