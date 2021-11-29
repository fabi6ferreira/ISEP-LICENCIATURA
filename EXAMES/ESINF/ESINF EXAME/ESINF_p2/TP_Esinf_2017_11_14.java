private satic string proximaPromocao(Graph<String, Integer> g){
	for(String vs :g.vertices()){
		if(g.inDegree(vs) == 0 return vs;
		return null;
	}
}


public static List<String> calculaPromocoes(Graph<String,Integer> g){
	Graph<String,Integer> gt = g.clone();
	List<String> l = new ArrayList<>();
	
	String nxt = proximaPromocao(gt);
	//nxt != null -> se n inferior ao numero de funcionarios
	for(int i = 0; i<n && nxt != null ; i++){
		gt.removeVertex(nxt);
		l.add(nxt);
		nxt = proximaPromocao(gt);
	}
	return l;
	
}