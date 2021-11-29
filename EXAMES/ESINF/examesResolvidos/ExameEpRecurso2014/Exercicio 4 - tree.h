bool treeHas(TN elementoX) const;


template<class TN>
bool tree<TN> treeHas(TN elementoX) const
{
	for (bstIteratorLevel<TN> it = this->begin(); it != this->end(); it++){
		if (*it==elementoX) {
			return true;
		}
	}
return false;
}