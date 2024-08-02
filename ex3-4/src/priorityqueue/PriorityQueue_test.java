package priorityqueue;

import java.util.Comparator;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;
import org.junit.Before;
import org.junit.Test;

public class PriorityQueue_test {

    class IntegerComparator implements Comparator<Integer> {
        @Override
        public int compare(Integer i1, Integer i2) {
          return i1.compareTo(i2);
        }
    }

    private PriorityQueue<Integer> pq;

    @Before
    public void createPriorityQueue(){
        pq = new PriorityQueue<>(new IntegerComparator());
    }

    @Test
    public void test_push_one_elem() {
        pq.push(5);
        assertEquals(pq.top(),5,0);
    }

    @Test
    public void test_push_three_elem() {
        pq.push(10);
        pq.push(5);
        pq.push(15);
        assertEquals(5, pq.top(), 0);
    }

    @Test
    public void test_push_null_elem() {
        assertFalse(pq.push(null));
    }

    @Test
    public void test_one_pop_one_elem() {
        pq.push(5);
        pq.pop();
        assertTrue(pq.top()==null);
    }

    @Test
    public void test_one_pop_three_elem() {
        pq.push(10);
        pq.push(5);
        pq.push(15);
        pq.pop();
        assertEquals(pq.top(),10,0);
    }

    @Test
    public void test_remove_elem_not_exists() {
        pq.push(10);
        pq.push(5);
        pq.push(15);
        assertFalse(pq.remove(6));
    }

    @Test
    public void test_remove_elem_exists() {
        pq.push(10);
        pq.push(5);
        pq.push(15);
        pq.push(7);
        pq.push(9);
        pq.push(11);
        assertTrue(pq.remove(7));
    }
    
    @Test
    public void test_remove_no_elem() {
        assertFalse(pq.remove(100));
    }

    @Test
    public void test_remove_null_elem() {
        pq.push(10);
        pq.push(5);
        pq.push(15);
        assertFalse(pq.remove(null));
    }

    @Test
    public void test_contains_exists_elem() {
        pq.push(10);
        pq.push(5);
        pq.push(15);
        assertTrue(pq.contains(10));
    }

    @Test
    public void test_contains_not_exists_elem() {
        pq.push(10);
        pq.push(5);
        pq.push(15);
        assertFalse(pq.contains(6));
    }

    @Test
    public void test_is_empty_no_empty() {
        pq.push(10);
        assertFalse(pq.empty());
    }

    @Test
    public void test_is_empty_empty() {
        assertTrue(pq.empty());
    }

    @Test
    public void test_top_empty() {
        assertTrue(pq.top()==null);
    }

    @Test
    public void test_top_no_empty() {
        pq.push(10);
        assertEquals(pq.top(),10,0);
    }
}
