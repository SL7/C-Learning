# Data-Structures

## Cycles in Linked-Lists

When you take a linked-list and want to iterate throug it, you will see that you will sometime reach the end where the node or the node-\>next is NULL.  
But there also can be unintentional or maybe even intentional cycles in the List.  
What is a cycle?

lets say you have: `2 -> 3 -> 5 -> 10 -> 15`.  
When you iterate throug it, at the end the 15's next node will point to 0.  
but when you take:  

```
     ┌────<────┐ 
2 -> 3 -> 5 -> 10 -> 15
```

Here 10's next points to the '3' node, so you will never reach the end of the linked-list.  
So when you want to check if ther linked-list contains a cycle, the first approach would be to get a Hashmap running 
and put and count every node inside the hashmap and when you have a duplicate, it contains a cycle.  

The approach would be O(n).

Put there is another method, the two-pointer method.  
Lets assume you have two runners running. One runner is faster then the other. And when it is a straight line to run, the
faster runner will just finish first.  
But if they run a cycle, the faster runner will be meeting again with the slow runner.  
So if you meet with the slow runner, there is a cycle.  

```c
bool hasCycle(struct ListNode *head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head->next;
    while (slow != head) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
```

This would be the two-pointer approach.

**Complexity analysis:**  

* List has no Cycle:  
    The faster pointer reaches the end first and the runtime depends on the lists length which is O(n)

* List has a cycle:
    We break down the movement of the slow pointer into two steps, the non-cyclic part and the cyclic.  
    1. The slow pointer takes the "non-cyclic" length steps to enter the cycle. At this point the fast pointer already reached the cycle. **Number of Iterations = non-cyclic length = N**.  
    2. Both pointers are now in the cycle. The fast runner moves 2 steps at a time and the slow one 1 step at a time, so the speed difference is 1. So it takes **distance between the two/speed difference** loops for the fast runner to catch up to the 


## 
