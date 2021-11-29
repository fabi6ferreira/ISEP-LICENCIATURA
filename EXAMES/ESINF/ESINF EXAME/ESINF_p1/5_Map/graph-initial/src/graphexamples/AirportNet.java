package graphexamples;

import graphbase.Edge;
import graphbase.Graph;
import static graphbase.GraphAlgorithms.DepthFirstSearch;
import java.util.LinkedList;
import java.util.Queue;

/**
 *
 * @author DEI-ESINF
 */
public class AirportNet {

    private Graph<String, Integer> airport;

    public AirportNet() {
        airport = new Graph<>(false);
    }

    public void addAirport(String a) {

        throw new UnsupportedOperationException("Not supported yet.");
    }

    public void addRoute(String a1, String a2, double miles, Integer npasseng) {

        throw new UnsupportedOperationException("Not supported yet.");
    }

    public int keyAirport(String airp) {

        throw new UnsupportedOperationException("Not supported yet.");
    }

    public String airportbyKey(int key) {

        String[] keysAirport[] = ;
    }

    public Integer trafficAirports(String airp1, String airp2) {
        Edge<String, Integer> edge1 = airport.getEdge(airp2, airp2);
        if (edge1 == null) {
            return null;
        }
        return edge1.getElement();

    }
    

    public Double milesAirports(String airp1, String airp2) {

        Edge<String,Integer> edge = airport.getEdge(airp1,airp2);
        if(edge == null){
            return null;
        }
        return edge.getWeight();
    }

    public String nroutesAirport() {

        throw new UnsupportedOperationException("Not supported yet.");
    }

    public String AirpMaxMiles() {

        throw new UnsupportedOperationException("Not supported yet.");
    }

    public Boolean ConnectAirports(String airp1, String airp2) {

        LinkedList<String> queueAirports = DepthFirstSearch(airport, airp1);
        for(String airp: queueAirports){
            if(airp.equalsIgnoreCase(airp2)){
                return true;
            }
        }
        return false;
    }

    @Override
    public String toString() {
        return airport.toString();
    }
}
