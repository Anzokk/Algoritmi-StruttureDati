package graph;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import priorityqueue.PriorityQueue;

public class Prim {
    public static <V, L extends Number> Collection<Edge<V, L>> minimumSpanningForest(Graph<V, L> graph) {
        Set<V> visited = new HashSet<>();
        PriorityQueue<Edge<V, L>> pq = new PriorityQueue<>(Comparator.comparingDouble(e -> e.getLabel().doubleValue()));
        List<Edge<V, L>> result = new ArrayList<>();

        for (V startNode : graph.getNodes()) {
            if (!visited.contains(startNode)) {
                visited.add(startNode);
                for (AbstractEdge<V, L> edge : graph.getEdges()) {
                    if (edge.getStart().equals(startNode) || edge.getEnd().equals(startNode)) {
                        pq.push(new Edge<>(edge.getStart(), edge.getEnd(), edge.getLabel()));
                    }
                }

                while (!pq.empty()) {
                    Edge<V, L> edge = pq.top();
                    pq.pop();
                    V node = visited.contains(edge.getStart()) ? edge.getEnd() : edge.getStart();

                    if (!visited.contains(node)) {
                        visited.add(node);
                        result.add(edge);

                        for (AbstractEdge<V, L> nextEdge : graph.getEdges()) {
                            if ((nextEdge.getStart().equals(node) && !visited.contains(nextEdge.getEnd())) || (nextEdge.getEnd().equals(node) && !visited.contains(nextEdge.getStart()))) {
                                pq.push(new Edge<>(nextEdge.getStart(), nextEdge.getEnd(), nextEdge.getLabel()));
                            }
                        }
                    }
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        if (args.length < 1) {
            System.err.println("Path not found!");
            System.exit(1);
        }

        String csvFile = args[0];
        Graph<String, Float> graph = new Graph<>(false, true);

        try (BufferedReader br = new BufferedReader(new FileReader(csvFile))) {
            String line;
            while ((line = br.readLine()) != null) {
                String[] parts = line.split(",");
                String place1 = parts[0].trim();
                String place2 = parts[1].trim();
                float distance = Float.parseFloat(parts[2].trim());

                graph.addNode(place1);
                graph.addNode(place2);
                graph.addEdge(place1, place2, distance);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        Collection<Edge<String, Float>> mst = minimumSpanningForest(graph);

        // Print results to standard output
        for (Edge<String, Float> edge : mst) {
            System.out.println(edge.getStart() + "," + edge.getEnd() + "," + edge.getLabel());
        }

        // Additional information to standard error
        double totalWeight = 0;
        for (Edge<String, Float> edge : mst) {
            totalWeight += edge.getLabel();
        }
        System.err.println("Number of nodes: " + graph.numNodes());
        System.err.println("Number of edges: " + mst.size());
        System.err.println("Total weight: " + totalWeight / 1000 + " Km");
    }
};
