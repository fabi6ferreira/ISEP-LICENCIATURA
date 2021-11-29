/*
    Alinea 1) Renomear lista, com strings repetidas!!!
*/

public List<String> renomear (List<String> lst){
    
    List<String> result = new ArrayList<>();
    Map<String,Integer> mapa = new HashMap<>();
    
    for(String palavra : lst){
        if(mapa.containsKey(palavra)){
            Integer cont = mapa.get(palavra)+1;
            mapa.put(palavra, cont);
            result.add(palavra+" "+cont);
        }else{
            mapa.put(palavra,0);
            result.add(palavra);
        }
    }
        return result;
    }
	
	
	
/*
Alinea 4) 
*/

 public Graph<V, E> RNG(Graph<V, E> g) throws CloneNotSupportedException {

        Graph<V, E> rng_graph = new Graph<>(false);

        
        for (V vertice : g.vertices()) {
            rng_graph.insertVertex(vertice);
        }

		
		LinkedList<V> path = new LinkedList<V>();
        
		for (V vert_X : g.vertices()) {

            for (V vert_Y : g.vertices()) {
                if (!vert_X.equals(vert_Y)) {
                    E edge_XY = (E) g.getEdge(vert_X, vert_Y);
                    double dist_min_XY = GraphA	lgorithms.shortestPath(g, vert_X, vert_Y, path);
						

                    for (V vert_Z : g.vertices()) {
                        if (!vert_Z.equals(vert_X) && !vert_Z.equals(vert_Y)) {
							
							
                            double dist_min_XZ = GraphAlgorithms.shortestPath(g, vert_X, vert_Z, path);
                            double dist_min_YZ = GraphAlgorithms.shortestPath(g, vert_Y, vert_Z, path);

                            if (dist_min_XY <= dist_min_XZ + dist_min_YZ) {
                                rng_graph.insertEdge(vert_X, vert_Y, edge_XY, dist_min_XY);
                            }
                        }
                    }
                }
            }
        }

        return rng_graph;

    }
	
	
/*
 Alinea 5) Na classe HeapPriorityQueue<K,V> criar uma funcção que determina e 
 retorna a ordem em que a primeira ocorrencia de um dado valor é processada.
 */
 
 public <K, V extends Comparable<V>> int orderOfService(HeapPriorityQueue<K,V> heap, V value){
     int res;
     for(int i = 0; i<=heap.size()-1;i++){
         Entry<K,V> entry = heap.removeMin();
         V atual = entry.getValue();
         if(atual.equals(value)){
              return res = (Integer) entry.getKey();
         }
     }

     return -1; 
 }
