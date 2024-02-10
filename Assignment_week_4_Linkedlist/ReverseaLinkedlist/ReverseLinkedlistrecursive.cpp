#include <iostream>

struct Node {
    int data;
    Node* next;
};

// Function to reverse a linked list iteratively
Node* reverseListIterative(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next;

    while (current != nullptr) {
        next = current->next; // Store next node temporarily
        current->next = prev; // Reverse link: point current to previous
        prev = current;      // Move previous to current
        current = next;      // Move current to stored next
    }

    return prev; // New head is the previous pointer (pointing to last node)
}

// Function to reverse a linked list recursively
Node* reverseListRecursive(Node* head) {
    // Base case: empty list or single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    // Recursive call to reverse the rest of the list
    Node* newHead = reverseListRecursive(head->next);

    // Connect the reversed list to the current node
    head->next->next = head;

    // Set the current node's next to null (new tail)
    head->next = nullptr;

    // Return the new head (previously the second node)
    return newHead;
}

int main() {
    // Sample linked list (replace with your data)
    Node* head = new Node{ 1, new Node{2, new Node{3, new Node{4, nullptr}}} };

    // Choose either iterative or recursive approach:

    // 1. Iterative approach
    // Node* reversedHead = reverseListIterative(head);

    // 2. Recursive approach
    Node* reversedHead = reverseListRecursive(head);

    // Print the reversed list
    Node* current = reversedHead;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Memory deallocation (important!)
    current = reversedHead;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}

/*
Explanation:

Headers: #include <iostream> includes the header for input/output operations.
Node structure: Defines the Node structure with data and next members.
reverseListRecursive function:
Base Case: If the list is empty (head == nullptr) or has only one node (head->next == nullptr), it's already reversed, so return the head.
Recursive Call: For a longer list, make a recursive call to reverseListRecursive with head->next, passing the rest of the list for reversal.
Connect Reversed List: After the rest is reversed, link the new head (previously the second node) to the current node by setting head->next->next = head.
Set New Tail: Set head->next to nullptr as it becomes the new tail of the reversed list.
Return New Head: Return the newHead obtained from the recursive call, which is the actual new head of the entire reversed list.
Exploring the Recursive Method for Reversing a Linked List
Comparison with Iterative Approach:

Feature	Iterative Approach	Recursive Approach
Logic	Uses a loop to traverse the list and reverse links one by one.	Breaks down the problem into smaller sub-problems by making recursive calls.
Space Complexity	O(1) - constant extra space for variables.	O(n) - space used for function call stack in the worst case.
Suitability	Generally preferred for large lists due to better space complexity and avoids potential stack overflow.	Can be more elegant for some, but space complexity might be an issue for large lists.
Tail Recursion	Can be implemented with tail recursion for O(1) space complexity (not shown).	Difficult to implement tail recursion without language support.
Potential Challenges of Recursive Approach:

Stack Overflow: Recursive calls can overflow the stack memory with very large lists, leading to crashes.
Tail Recursion: While not implemented here, tail recursion requires compiler support and might not be readily available.
Summary:

The recursive approach can be more concise and elegant for smaller lists. However, its space complexity (O(n)) due to the function call stack makes it less suitable for large lists compared to the iterative approach's O(1) space complexity. Consider the size of your list and potential stack limitations when choosing between these approaches.
*/
