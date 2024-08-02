package graph;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

public class Graph_test {

    private Graph<String, Float> g_not_directed_labelled = new Graph<>(false,true);
    private Graph<String, Float> g_directed_not_labelled = new Graph<>(false,true);

    @Before
    public void createPriorityQueue(){
        g_not_directed_labelled = new Graph<>(false,true);
        g_directed_not_labelled = new Graph<>(true,false);
    }

    @Test
    public void test_not_isDirected_graph_on_graph_not_directed(){
        assertFalse(g_not_directed_labelled.isDirected());
    }

    @Test
    public void test_isDirected_on_graph_directed(){
        assertTrue(g_directed_not_labelled.isDirected());
    }

    @Test
    public void test_not_isLabelled_graph_on_graph_not_labelled(){
        assertFalse(g_directed_not_labelled.isLabelled());
    }

    @Test
    public void test_isLabelled_on_graph_labelled(){
        assertTrue(g_not_directed_labelled.isLabelled());
    }

    @Test
    public void test_add_Node_in_empty_graph(){
        assertTrue(g_directed_not_labelled.addNode("A"));
    }

    @Test
    public void test_add_Node_contained_in_graph(){
        g_directed_not_labelled.addNode("A");
        assertFalse(g_directed_not_labelled.addNode("A"));
    }

    @Test
    public void test_add_Node_not_empty_not_contained_in_graph(){
        g_directed_not_labelled.addNode("B");
        assertTrue(g_directed_not_labelled.addNode("A"));
    }

    @Test
    public void test_add_loop_Edge_not_Directed(){
        g_not_directed_labelled.addNode("A");
        assertFalse(g_not_directed_labelled.addEdge("A", "A", (float) 0));
    }

    @Test
    public void test_add_loop_Edge_Directed(){
        g_directed_not_labelled.addNode("A");
        assertTrue(g_directed_not_labelled.addEdge("A", "A", (float) 0));
    }

    @Test
    public void test_add_Edge_not_exists_first_Node(){
        g_not_directed_labelled.addNode("B");
        assertFalse(g_not_directed_labelled.addEdge("A", "B", (float) 1));
    }

    @Test
    public void test_add_Edge_not_exists_second_Node(){
        g_not_directed_labelled.addNode("A");
        assertFalse(g_not_directed_labelled.addEdge("A", "B", (float) 1));
    }

    @Test
    public void test_contains_Node_when_is_true(){
        g_not_directed_labelled.addNode("A");
        assertTrue(g_not_directed_labelled.containsNode("A"));
    }

    @Test
    public void test_contains_Node_when_is_false_no_empty(){
        g_not_directed_labelled.addNode("B");
        assertFalse(g_not_directed_labelled.containsNode("A"));
    }

    @Test
    public void test_contains_Node_when_is_false_empty(){
        assertFalse(g_not_directed_labelled.containsNode("A"));
    }

    @Test
    public void test_contains_Edge_when_is_true(){
        g_not_directed_labelled.addNode("A");
        g_not_directed_labelled.addNode("B");
        g_not_directed_labelled.addEdge("A","B",(float) 1);
        assertTrue(g_not_directed_labelled.containsEdge("A","B"));
    }

    @Test
    public void test_contains_Edge_when_is_false(){
        g_not_directed_labelled.addNode("B");
        g_not_directed_labelled.addNode("C");
        g_not_directed_labelled.addEdge("B","C",(float) 1);
        assertFalse(g_not_directed_labelled.containsEdge("A","B"));
    }

    @Test
    public void test_contains_Edge_when_empty(){
        assertFalse(g_not_directed_labelled.containsEdge("A","B"));
    }

    @Test
    public void test_remove_Node_when_exists(){
        g_not_directed_labelled.addNode("A");
        assertTrue(g_not_directed_labelled.removeNode("A"));
    }

    @Test
    public void test_remove_Node_when_not_exists_no_empty(){
        g_not_directed_labelled.addNode("B");
        assertFalse(g_not_directed_labelled.removeNode("A"));
    }

    @Test
    public void test_remove_Node_when_not_exists_empty(){
        assertFalse(g_not_directed_labelled.removeNode("A"));
    }

    @Test
    public void test_remove_Edge_when_exists(){
        g_not_directed_labelled.addNode("A");
        g_not_directed_labelled.addNode("B");
        g_not_directed_labelled.addEdge("A","B",(float) 1);
        assertTrue(g_not_directed_labelled.removeEdge("A","B"));
    }

    @Test
    public void test_remove_Edge_when_not_exists_no_empty(){
        g_not_directed_labelled.addNode("A");
        g_not_directed_labelled.addNode("B");
        g_not_directed_labelled.addEdge("A","B",(float) 1);
        assertFalse(g_not_directed_labelled.removeEdge("B","C"));
    }

    @Test
    public void test_remove_Edge_when_not_exists_empty(){
        assertFalse(g_not_directed_labelled.removeEdge("B","C"));
    }

    @Test
    public void test_num_Nodes_no_elem() {
        assertEquals(0,g_not_directed_labelled.numNodes());
    }
    

    @Test
    public void test_num_Nodes_one_elem() {
        g_not_directed_labelled.addNode("A");
        assertEquals(1,g_not_directed_labelled.numNodes());
    }

    @Test
    public void test_num_Edges_no_elem() {
        assertEquals(0,g_not_directed_labelled.numEdges());
    }
    

    @Test
    public void test_num_Edges_one_elem() {
        g_not_directed_labelled.addNode("A");
        g_not_directed_labelled.addNode("B");
        g_not_directed_labelled.addEdge("A","B",(float) 1);
        assertEquals(1,g_not_directed_labelled.numEdges());
    }
    
}
