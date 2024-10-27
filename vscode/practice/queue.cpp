public class MyQueue<T> {
    private static class QueueNode<T>
    {
    private:
        T data;
        QueueNode<T> next;
    public:
        QueueNode(T data){
            this.data = data;
        }
    }
    private:
        QueueNode<T> first;
        QueueNode<T> last;

    public:
        void add(T item) {
            QueueNode<T> t = new QueueNode<T>(item);
            if (last != null) {
                last.next = t;
            }
            last = t;
            if(first == null) {
                first = last;
            }
        }
        T remove() {
            if(first == null) throw new NoSuchElementException();
            T data = first.data;
            first = first.next;
            if(first == null){
                last = null;
            }
            return data;
        }
        T peek() {
            if(first == null) throw new NoSuchElementException();
        }
        boolean isEmpty(){
            return first == null;
        }
    
}
