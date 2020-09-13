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
        if (slow == NULL || slow->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
```

This would be the two-pointer approach.
This will have a complexity of: O(1)


## 
