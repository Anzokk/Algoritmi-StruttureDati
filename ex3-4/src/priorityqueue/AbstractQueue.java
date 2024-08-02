package priorityqueue;

public interface AbstractQueue<E> {
    public boolean empty();
    public boolean push(E e);
    public E top();
    public void pop();
    public boolean contains(E e); // may be removed
    public boolean remove(E e); // may be removed
  };
  