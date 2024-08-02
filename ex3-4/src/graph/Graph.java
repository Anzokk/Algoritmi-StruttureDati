package graph;

import java.util.*;

public class Graph<V, L> implements AbstractGraph<V, L> {
    private final boolean directed;
    private final boolean labelled;
    private final Map<V, Map<V, L>> adjacencyMap;
    private int numEdges;

    public Graph(boolean directed, boolean labelled) {
        this.directed = directed;
        this.labelled = labelled;
        this.adjacencyMap = new HashMap<>();
        this.numEdges = 0;
    }

    public boolean isDirected() {
        return directed;
    }

    public boolean isLabelled() {
        return labelled;
    }

    public boolean addNode(V a) {
        if (adjacencyMap.containsKey(a)) {
            return false;
        }
        adjacencyMap.put(a, new HashMap<>());
        return true;
    }

    public boolean addEdge(V a, V b, L l) {
        if (!containsNode(a) || !containsNode(b) || containsEdge(a, b) || (!directed && a==b)) {
            return false;
        }

        if (!labelled) {
            l = null;
        }

        if (adjacencyMap.get(a).put(b, l) == null) {
            numEdges++;
        }
        
        if (!directed) {
            adjacencyMap.get(b).put(a, l);
        }

        return true;
    }

    public boolean containsNode(V a) {
        return adjacencyMap.containsKey(a);
    }

    public boolean containsEdge(V a, V b) {
        return adjacencyMap.containsKey(a) && adjacencyMap.get(a).containsKey(b);
    }

    public boolean removeNode(V a) {
        if (!adjacencyMap.containsKey(a)) {
            return false;
        }

        // Remove all edges to this node
        for (V neighbor : adjacencyMap.keySet()) {
            removeEdge(neighbor,a);
        }

        numEdges -= adjacencyMap.get(a).size();

        // Remove the node
        adjacencyMap.remove(a);

        return true;
    }

    public boolean removeEdge(V a, V b) {
        if (!containsEdge(a, b)) {
            return false;
        }
        
        adjacencyMap.get(a).remove(b);
        numEdges--;
        
        if (!directed) {
            adjacencyMap.get(b).remove(a);
        }

        return true;
    }

    public int numNodes() {
        return adjacencyMap.size();
    }

    public int numEdges() {
        return numEdges;
    }

    public Collection<V> getNodes() {
        return adjacencyMap.keySet();
    }

    public Collection<AbstractEdge<V, L>> getEdges() {
        List<AbstractEdge<V, L>> edges = new ArrayList<>();
        for (Map.Entry<V, Map<V, L>> entry : adjacencyMap.entrySet()) {
            V start = entry.getKey();
            for (Map.Entry<V, L> edgeEntry : entry.getValue().entrySet()) {
                V end = edgeEntry.getKey();
                L label = edgeEntry.getValue();
                edges.add(new Edge<>(start, end, label));
            }
        }
        return edges;
    }

    public Collection<V> getNeighbours(V a) {
        if (!containsNode(a)) {
            return Collections.emptyList();
        }
        return adjacencyMap.get(a).keySet();
    }

    public L getLabel(V a, V b) {
        if (!containsEdge(a, b)) {
            return null;
        }
        return adjacencyMap.get(a).get(b);
    }
};