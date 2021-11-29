//ESINF TP4_Graph 
package TP4_Graph;

/**
 *
 * @author user
 */
public class LabrynthCheater {
	
    private AdjacencyMatrixGraph<Room,Door> map;
    
    public Iterable<String> rooms (String room){
		if(!map.checkVertex()){
			new room(room,false);
			return null;
		}
		LinkedList<Room> rooms = GraphAlgoritms.DFS(map,new Room(room,false));
		LinkedList<String> nomes = new ...
		for(Room r = nomes){
			nomes.add(r.nome);			
		}
		return nomes;
	}
	
	
	
	/*
	Para BFS:
	
	1 - Checkvertex(new ROom(...))
	2 - BFS
	3 - O 1º na lista do BFS com exit == true;
	
	
	*/
	
	public LinkedList<String> PathToExit(String Room){
		if(!map.checkVertex(new Room(room,false)){
			return null;
		}
		LinkedList<LinkedList<Room>> paths = new LinkedList<LinkedList>();
		String name = nearestExit(room);
		// boolean result -> todos os caminhos entre room e exit;
		boolean result = GraphsAlgorithms.allPaths(map,new Room(room,false), new Room(name,true),paths);
		if(result == false) return null;
		if(paths.isEmpty()) = return null;
		
		//menor dos caminhos
		Iterator<Room> it = paths.iterator();
		LinkedList<Room> min = it.next();
		while(it.hasNext()){
			LinkedList<Room> list = it.next();
			if(list.size()<min.size()){
				min=list;
			}
		}
		LinkedList<String> names = new LinkedList<String>();
		for(Room r :min){
			names.add(r.name);
		}
		return names;
	}
    


//----------------------- PRIVATE CLASS ROOM -------------------------
	
private class Room {
    private String idRoom;
    
	public boolean hasExit(){
		return;
	}
	
	public boolean equals(Object Obj){
		if(obj ==null){
			return false;
		}
		if(this == obj){
			return true;
		}
		if(this.class != obj.class){
			return false;
		}
		Room r = (Room) obj;
		return this.idRoom.equalsIgnoreCase(r.getIdRoom);
	}
	
    public String getIdRoom(){
        return this.idRoom;
    }
    
    public void setIdRoom(String id){
        this.idRoom=id;
    }
}


//----------------------- PRIVATE CLASSE DOOR -------------------------
private class Door{
}

}


