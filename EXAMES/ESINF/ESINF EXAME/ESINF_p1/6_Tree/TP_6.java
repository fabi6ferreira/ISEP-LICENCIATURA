public BST<E> autumnTree(){

BST<E> new Tree = new TREE();
newTree.root=copyRec(root);
return newTree;
}

private Node<E> copyRec(Node<E> node){
		if(node ==null){
			return node;
		}
		if(!isLeaf(node.getElement()))
			return (new Node(node.getElement(),copyRec(node.getLeft()), copyRec(node.getRigth())));
}else return null;
}


//Numero por nível




public Map<Integer, List<E>> nodesByLevel(){
	Map<Integer,List<E> result = new HashMap();
	processBstByLevel(root,result,0);
	return result;
}



private int[] numNodesByLevel(){
	int v[] new int [height()+1];
	int i = 0;
	Map<Integer,List<E>> levels = nodesByLevel();
	for(List<E> l : levels.values()){
		v[i++] = l.size();
	}
	return v;
}