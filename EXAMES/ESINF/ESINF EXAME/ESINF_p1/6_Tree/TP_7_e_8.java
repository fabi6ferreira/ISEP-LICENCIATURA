//TP7

//2- Find if AVL is perfectly balanced

public boolean pf(){
	if(root == null){
		return
	}
	return pf(root);
}


private boolean pf(Node<E> node){
	if(node == null){
			return true;
	}
	if(balanceFactor(node) != 0)
		return false;
	}
	return pf(node.getLeft()) && pf(node.getRigth());
}


// TP8-------------------------------------------------------

//1 - perculate up


protected void perculateUp(int j){
	while(j>0){
		int p = parent(j);
		if(compare(heap.get(j), heao.get(p)) >=0) break;
		swap(j,p);
		
	}
}


protected void perculateDown(int j){
	while (hasLeft(j)){
		int leftIndex = left(j);
		int smallChildIndex = leftIndex;
		if(hasRigth(j)){
			
		}
	}
	
}

protected void buildHeap(){
	int startIndex = parent(size()-1));
	
	}