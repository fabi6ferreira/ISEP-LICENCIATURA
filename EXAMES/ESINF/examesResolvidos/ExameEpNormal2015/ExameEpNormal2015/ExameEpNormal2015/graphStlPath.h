/***************************************
 * graphStlPath.h
 *
 * Created on 19 de Julho de 2013, 11:51
 *
 * @author Nuno Malheiro
 * rev1: g++ compatibility 23/10/2013
 * rev2: mac compatibility 29/10/2013
 ***************************************/

#ifndef _graphStlPath_
#define _graphStlPath_

#include <string.h> // memset include for g++
#include <stack>
#include <queue>
#include <bitset>
#include <type_traits>


using namespace std;

#include "graphStl.h"
#include "graphVertex.h"
#include"graphEdge.h"


template<class TV,class TE>
class graphStlPath : public graphStl <TV,TE>
{
protected:	
	void lengthFirstVisitRecursive(typename list < graphVertex <TV,TE> >::iterator itv, bitset <MAX_VERTICES> &taken, queue <TV> &q) const;
	void distinctPathsRecursive(typename list < graphVertex <TV,TE> >::iterator itvo,typename list < graphVertex <TV,TE> >::iterator itvd, bitset <MAX_VERTICES> &taken, stack <TV> &s,  queue < stack <TV> > &qr);
	  void distinctPathsRecursiveWithTime(typename list < graphVertex <TV,TE> >::iterator itvo,typename list < graphVertex <TV,TE> >::iterator itvd, bitset <MAX_VERTICES> &taken, stack <TV> &s,  queue < stack <TV> > &qr, int timeIni, int timeEnd);
	
public:
	graphStlPath();

	queue <TV> lengthFirstVisit(const TV &vContent);
	queue <TV> breadthFirstVisit(const TV &vContent);
	queue < stack <TV> > distinctPaths(const TV &vOrigin,const TV &vDestination);	
	bool dijkstrasAlgorithm(const TV &vContent, vector <int> &pathKeys, vector <TE> &dist);
	queue <TV> getDijkstrasPath(int vKeyOrigin, vector <int> pathKeys);
	queue<TV> breadthFirstVisitWithTime(const TV &vContent, int *time);
    queue < stack <TV> > distinctPathsWithTime(const TV &vOrigin,const TV &vDestination, int time);
	 TV devolveVerticeMaiorLigacao();
     



};

template<class TV,class TE>
graphStlPath<TV,TE>::graphStlPath() : graphStl<TV,TE>()
{
}


template<class TV,class TE>
void graphStlPath<TV,TE>::lengthFirstVisitRecursive(typename list < graphVertex <TV,TE> >::iterator itv, bitset <MAX_VERTICES> &taken, queue <TV> &q) const
{
	taken[itv->getVKey()]=true; 
	q.push(itv->getVContent());

	for (typename list < graphEdge <TV,TE> >::iterator ite=itv->getAdjacenciesBegin() ; ite!=itv->getAdjacenciesEnd() ; ite++)	
		if (!taken[ite->getVDestination()->getVKey()]) lengthFirstVisitRecursive(ite->getVDestination(), taken, q );
}

template<class TV,class TE>
queue <TV> graphStlPath<TV,TE>::lengthFirstVisit(const TV &vContent)
{
	bitset <MAX_VERTICES> taken;
	queue < TV > q;

	typename list < graphVertex <TV,TE> >::iterator itv;
	if (!(graphStl<TV,TE>::getVertexIteratorByContent(itv, vContent))) return q;

	lengthFirstVisitRecursive(itv, taken, q);
	return q;
}

template<class TV,class TE>
queue <TV> graphStlPath<TV,TE>::breadthFirstVisit(const TV &vContent)
{
	bitset <MAX_VERTICES> taken;
	queue <TV> qr;
	
	typename list < graphVertex <TV,TE> >::iterator itv;
	if (!(graphStl<TV,TE>::getVertexIteratorByContent(itv, vContent))) return qr;

	queue <typename list < graphVertex <TV,TE> >::iterator> qi;
	
	qi.push(itv);
	taken[itv->getVKey()]=true;

	while (!qi.empty())
	{
		itv = qi.front();
		qr.push(itv->getVContent());

		for (typename list < graphEdge <TV,TE> >::iterator ite=itv->getAdjacenciesBegin() ; ite!=itv->getAdjacenciesEnd() ; ite++)		
			if (!taken[ite->getVDestination()->getVKey()]) 
			{
				qi.push(ite->getVDestination());
				taken[ite->getVDestination()->getVKey()]=true;
			}
		qi.pop();
	}
	return qr;
}

template<class TV,class TE>
void graphStlPath<TV,TE>::distinctPathsRecursive(typename list < graphVertex <TV,TE> >::iterator itvo,typename list < graphVertex <TV,TE> >::iterator itvd, bitset <MAX_VERTICES> &taken, stack <TV> &s, queue < stack <TV> > &qr)
{
	if (itvo==itvd) {
		s.push(itvo->getVContent());
		qr.push(s);
		s.pop();
		return;
	}

	taken[itvo->getVKey()]=true;
	s.push(itvo->getVContent());

	for (typename list < graphEdge <TV,TE> >::iterator ite=itvo->getAdjacenciesBegin() ; ite!=itvo->getAdjacenciesEnd() ; ite++)
	{
		if (!taken[ite->getVDestination()->getVKey()]) distinctPathsRecursive(ite->getVDestination(), itvd, taken, s, qr);
	}

	taken[itvo->getVKey()]=false;
	s.pop();
}

template<class TV,class TE>
queue < stack <TV> > graphStlPath<TV,TE>::distinctPaths(const TV &vOrigin,const TV &vDestination)
{
	bitset <MAX_VERTICES> taken;
	stack < TV > s;
	queue < stack <TV> > qr;

	typename list < graphVertex <TV,TE> >::iterator itvo, itvd;
	if (!(graphStl<TV,TE>::getVertexIteratorByContent(itvo, vOrigin) && graphStl<TV,TE>::getVertexIteratorByContent(itvd, vDestination))) return qr;

	distinctPathsRecursive(itvo, itvd, taken, s, qr);
	return qr;
}

template<class TV,class TE>
bool graphStlPath<TV,TE>::dijkstrasAlgorithm(const TV &vContent, vector <int> &pathKeys, vector <TE> &dist)
{
	vector <typename list < graphVertex <TV,TE> >::iterator> path;
	bitset <MAX_VERTICES> process; // Starts with all false

	pathKeys.clear(); dist.clear();
	for (typename list < graphVertex <TV,TE> >::iterator it=graphStl<TV,TE>::vlist.begin(); it!=graphStl<TV,TE>::vlist.end() ; it++ )
	{
		path.push_back(it);
		pathKeys.push_back(-1);
		dist.push_back(graphStl<TV,TE>::getInfinite());
	}

	typename list < graphVertex <TV,TE> >::iterator itv;
	if (!(graphStl<TV,TE>::getVertexIteratorByContent(itv, vContent))) return false;

	TE zeroValue;
	if ( (is_integral<TE>::value ) || (is_floating_point<TE>::value ) ) memset(&zeroValue, 0, sizeof(zeroValue)); //tipos primitivos

	dist[itv->getVKey()] = zeroValue; // Inicialização com valores nulos :	dist[itv->getVKey()] = 0;

	while (itv!=graphStl<TV,TE>::vlist.end())
	{
		process[itv->getVKey()]=true;
		for (typename list < graphEdge <TV,TE> >::iterator ite=itv->getAdjacenciesBegin() ; ite!=itv->getAdjacenciesEnd() ; ite++)
		{
			int destKey = ite->getVDestination()->getVKey();
			if ( (!process[destKey]) && dist[destKey]>dist[itv->getVKey()]+ite->getEContent() )
			{
				path[destKey]=itv;
				pathKeys[destKey]=itv->getVKey();
				dist[destKey]=dist[itv->getVKey()]+ite->getEContent();
			}
		}
		
		TE min = graphStl<TV,TE>::getInfinite();
		int vmin = -1;
		for (size_t i=0;i<dist.size() ; i++)
		{
			if (!process[i] && dist[i] < min) {
				min = dist[i];
				vmin = i;
			}
		}
		if (vmin==-1) itv=graphStl<TV,TE>::vlist.end(); else graphStl<TV,TE>::getVertexIteratorByKey(itv, vmin);
	}

	return true;
}

template<class TV,class TE>
queue <TV> graphStlPath<TV,TE>::getDijkstrasPath(int vKeyOrigin, vector <int> pathKeys)
{
	queue <TV> path;

	if (pathKeys[vKeyOrigin]!=-1) {
		TV dest; this->getVertexContentByKey(dest, vKeyOrigin);

		int vi = vKeyOrigin;
		while (vi!=-1)
		{
			this->getVertexContentByKey(dest, vi);
			path.push(dest);
			vi=pathKeys[vi];
		}
	}

	return path;
}

template<class TV,class TE>
queue <TV> graphStlPath<TV,TE>::breadthFirstVisitWithTime(const TV &vContent, int *time) {
    bitset <MAX_VERTICES> taken;
    queue <TV> qr;
    int t = 0;
    
    typename list < graphVertex <TV,TE> >::iterator itv;
    if (!(graphStl<TV,TE>::getVertexIteratorByContent(itv, vContent))) {
        return qr;
    }
    
    queue <typename list < graphVertex <TV,TE> >::iterator> qi;
    qi.push(itv);
    taken[itv->getVKey()]=true;
    
    while (!qi.empty()) {
        itv = qi.front();
        qr.push(itv->getVContent());
        t += itv->getVContent().getTempoMedioVisita();
        
        for (typename list < graphEdge <TV,TE> >::iterator ite=itv->getAdjacenciesBegin() ; ite!=itv->getAdjacenciesEnd() ; ite++) {
            if (!taken[ite->getVDestination()->getVKey()]) {
                qi.push(ite->getVDestination());
                taken[ite->getVDestination()->getVKey()] = true;
            }
        }
        qi.pop();
    }
    
    if(t != 0) {
        *time = t;
    }
    
    return qr;
}

template<class TV,class TE>
void graphStlPath<TV,TE>::distinctPathsRecursiveWithTime(typename list < graphVertex <TV,TE> >::iterator itvo,typename list < graphVertex <TV,TE> >::iterator itvd, bitset <MAX_VERTICES> &taken, stack <TV> &s, queue < stack <TV> > &qr, int timeIni, int timeEnd) {
    
    timeIni += itvo->getVContent().getTempoMedioVisita();
    if (itvo==itvd && timeIni < timeEnd) {
        s.push(itvo->getVContent());
        qr.push(s);
        s.pop();
        return;
    }
    
    taken[itvo->getVKey()]=true;
    s.push(itvo->getVContent());
    
    for (typename list < graphEdge <TV,TE> >::iterator ite=itvo->getAdjacenciesBegin() ; ite!=itvo->getAdjacenciesEnd() ; ite++) {
        if (!taken[ite->getVDestination()->getVKey()]) {
            distinctPathsRecursiveWithTime(ite->getVDestination(), itvd, taken, s, qr, timeIni, timeEnd);
        }
    }
    
    taken[itvo->getVKey()]=false;
    s.pop();
}

template<class TV,class TE>
queue < stack <TV> > graphStlPath<TV,TE>::distinctPathsWithTime(const TV &vOrigin,const TV &vDestination, int time) {
    bitset <MAX_VERTICES> taken;
    stack < TV > s;
    queue < stack <TV> > qr;
    
    typename list < graphVertex <TV,TE> >::iterator itvo, itvd;
    if (!(graphStl<TV,TE>::getVertexIteratorByContent(itvo, vOrigin) && graphStl<TV,TE>::getVertexIteratorByContent(itvd, vDestination))) {
        return qr;
    }
    
    distinctPathsRecursiveWithTime(itvo, itvd, taken, s, qr, 0, time);
    return qr;
}






template<class TV,class TE>
  TV graphStlPath<TV, TE>::devolveVerticeMaiorLigacao()
  {
	   list< graphVertex<TV,TE> >::iterator itv;
    int conta = 0;
	int max=0;
    TV verticeMaior;
    
    for (itv=vlist.begin(); itv != vlist.end(); itv++)
	{
        list< graphEdge<TV,TE>>::iterator ite;
        for (ite = itv->getAdjacenciesBegin(); ite != itv->getAdjacenciesEnd(); ite++)
		{
        conta++;    

        }
		if(conta>max)
		{
			max=conta;
			verticeMaior=itv->getVContent();
		}
		conta=0;
    }
    
    return verticeMaior;


  }









#endif