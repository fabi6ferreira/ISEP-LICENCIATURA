//tree.h

int min_Max(TN* min, TN* max);

//tree.cpp

template <class TN>
int tree<TN>::min_Max(TN* min, TN* max) {

	TN minaux;
	TN maxaux;

	vector<TN> aux;
	tree<TN>::bsiterator it;

	for (bstIteratorInOrder<TN> it = this->begin(); it != this->end(); it++)
	{
		aux.push_back(*it);
	}
	min = aux[0];
	max = aux[0];
	for (int i = 1; i < aux.size() ; i++)
	{
		if (aux[i] > max) { max[i] = aux[i]; }
		if (aux[i] < min) { min[i] = aux[i]; }
	}
	min = minaux;
	max = maxaux;
}