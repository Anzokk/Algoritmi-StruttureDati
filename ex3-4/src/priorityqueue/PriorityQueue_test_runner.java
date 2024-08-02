package priorityqueue;

import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;

public class PriorityQueue_test_runner {
    public static void main(String[] args) {
        Result result = JUnitCore.runClasses(PriorityQueue_test.class);
        for (Failure failure : result.getFailures()) {
            System.out.println(failure.toString());
        }
  
    System.out.println("Tutto corretto: "+ result.wasSuccessful());
    }
}
