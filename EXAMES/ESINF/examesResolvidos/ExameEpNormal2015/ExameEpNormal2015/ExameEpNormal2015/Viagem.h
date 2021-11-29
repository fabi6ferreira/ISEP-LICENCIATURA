#pragma once

#include "graphStlPath.h"
#include <map>

using namespace std;

class Viagem :  public graphStlPath <string, Itinerario*> 
{

private:
	/*queue<stack<string>>q;*/
	vector<queue<stack<string>>>vq;

public:
	Viagem();
	Viagem(const Viagem &v);
	queue<string>devolveItinerarios(string cidade, float precoEst,int durEst);

};


Viagem::Viagem()
{
}
Viagem::Viagem(const Viagem &v)
{

}

//queue<string> Viagem::devolveItinerarios(string cidade, float precoEst, int durEst)
//{
//	list<graphVertex<string, Itinerario*>>::iterator it = vlist.begin();
//	stack<string>s;
//	float contPrec = 0.0;
//	int contDur = 0.0;
//	for (it; it != vlist.end(); it++)
//	{
//		if (it->getVContent() != cidade)
//			vq.push_back(distinctPaths(cidade, it->getVContent()));
//	}
//
//	for (int i = 0; i<vq.size(); i++)
//	{
//		if (vq[i].front().size()>2)
//		{
//			s = vq[i].front();
//
//			while (!s.empty())
//			{
//				string cid = s.top();
//
//			}
//		}
//	}
//} 

//ir agora buscar o TE getPreco e getDuracao...não sei fazer isso

//o problema é verificar se o caminho das cidades 
//não ultrapassam o preco e a duração definidos