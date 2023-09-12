

// Implement stack using Queue interface , Code by kks


 import java.util.Queue;
 import java.util.LinkedList;

 class Main {

     public static void main(String[] args) {
         // Creating Queue using the LinkedList class
         Queue<Integer> numbers = new LinkedList<>();

         // enqueue
         // insert element at the rear of the queue
         numbers.offer(1);
         numbers.offer(2);
         numbers.offer(3);
         System.out.println("Queue: " + numbers);

         // dequeue
         // delete element from the front of the queue
         int removedNumber = numbers.poll();
         System.out.println("Removed Element: " + removedNumber);

         System.out.println("Queue after deletion: " + numbers);
     }
 }