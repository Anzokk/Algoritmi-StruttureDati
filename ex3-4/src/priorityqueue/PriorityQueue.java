package priorityqueue;

import java.util.*;

public class PriorityQueue<E> implements AbstractQueue<E> {

    private final Comparator<E> compar;
    private final List<E> heap;


    public PriorityQueue(Comparator<E> comparator) {
        this.compar = comparator;
        this.heap = new ArrayList<E>();
    }

    public boolean empty() {
        return heap.isEmpty();
    }

    public boolean push(E e) {
        if (e != null && !heap.contains(e)){
            heap.add(e);
            int i=heap.size();
            boolean exit=false;
            while (i>1 && !exit){
                if (compar.compare(heap.get(i/2-1),e)>0){
                    heap.set(i-1,heap.get(i/2-1));
                    i=i/2;
                }else{
                    exit=true;
                }
            }
            heap.set(i-1,e);
            return true;
        }else{
            return false;
        }
    }

    public E top() {
        if (heap.size()>0){
            return heap.get(0);
        }
        return null;
    }

    public void pop() {
        if (heap.size()>1){
            E elem=heap.get(heap.size()-1);
            heap.remove(heap.size()-1);
            heap.set(0,elem);
            int i=2;
            while (i<heap.size()){
                if ((compar.compare(heap.get(i-1),elem)<0 || compar.compare(heap.get(i),elem)<0)){
                    if (compar.compare(heap.get(i-1),heap.get(i))<0){
                        heap.set(i/2-1,heap.get(i-1));
                        heap.set(i-1,elem);
                        i=i*2;
                    }else{
                        heap.set(i/2-1,heap.get(i));
                        heap.set(i,elem);
                        i=(i+1)*2;
                    }
                }else{
                    i=heap.size()+1;
                }
            }
            if (i==heap.size() && compar.compare(heap.get(i-1),elem)<0){
                heap.set(i/2-1,heap.get(i-1));
                heap.set(i-1,elem);
            }
        }else if (heap.size()==1){
            heap.remove(0);
        }else{
            System.err.println("Non ci sono elementi nella Queue");
        }
    }

    public boolean contains(E e) {
        return heap.contains(e);
    }

    public boolean remove(E e) {
         if (heap.contains(e)){
            if (heap.size()>1){
                int i = heap.indexOf(e)+1;
                if(i!=heap.size()){
                    E elem= heap.get(heap.size()-1);
                    heap.remove(heap.size()-1);
                    heap.set(i-1,elem);
                    i=i*2;
                    while (i<heap.size()){
                        if ((compar.compare(heap.get(i-1),elem)<0 || compar.compare(heap.get(i),elem)<0)){
                            if (compar.compare(heap.get(i-1),heap.get(i))<0){
                                heap.set(i/2-1,heap.get(i-1));
                                heap.set(i-1,elem);
                                i=i*2;
                            }else{
                                heap.set(i/2-1,heap.get(i));
                                heap.set(i,elem);
                                i=(i+1)*2;
                            }
                        }else{
                            i=heap.size()+1;
                        }
                    }
                    if (i==heap.size() && compar.compare(heap.get(i-1),elem)<0){
                        heap.set(i/2-1,heap.get(i-1));
                        heap.set(i-1,elem);
                    }
                }else{
                    heap.remove(heap.size()-1);
                }
            }else{
                heap.remove(0);
            }
            return true;
        }else{
            return false;
        }
    }
};
