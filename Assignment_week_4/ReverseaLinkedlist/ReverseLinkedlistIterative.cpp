#include <iostream>

// Define the structure for nodes in a linked list
struct Node {
    int data;     // Holds the data value of the node
    Node* next;   // Pointer to the next node in the list
};

// Function to reverse a linked list iteratively
Node* reverseList(Node* head) {
    // Initialize three pointers
    Node* prev = nullptr;  // Pointer to the previous node (initially null)
    Node* current = head;  // Pointer to the current node (starts at head)
    Node* next;            // Temporary pointer to store the next node

    // Iterate through the list until the end (current becomes null)
    while (current != nullptr) {
        // Store the next node temporarily to avoid losing it during reversal
        next = current->next;

        // Reverse the link: point current's next to the previous node
        current->next = prev;

        // Update previous and current pointers for the next iteration
        prev = current;
        current = next;
    }

    // Return the new head, which is now the previous pointer (pointing to the last node)
    return prev;
}

int main() {
    // Create a sample linked list (replace with your data)
    Node* head = new Node{ 1, new Node{2, new Node{3, new Node{4, nullptr}}} };

    // Reverse the list and update the head pointer
    head = reverseList(head);

    // Print the reversed list
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Memory deallocation (important!)
    current = head;
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
reverseList function:
Initialization:
prev starts as nullptr since it will point to the new head (last node).
current starts at the original head.
next is used temporarily to store the next node before overwriting its link.
Loop:
while (current != nullptr): Continues until the end of the list.
Inside the loop:
next = current->next;: Stores the next node as it will be lost after reversing the link.
current->next = prev;: Reverses the link by pointing the current node's next to the previous node.
prev = current;: Updates the previous pointer to point to the current node (new last node).
current = next;: Moves the current pointer to the stored next node for the next iteration.
Return:
return prev;: Returns the prev pointer, which now points to the last node (new head).
main function:
Creates a sample linked list.
Calls reverseList to reverse the list and updates the head pointer.
Prints the reversed list.
Deallocates memory used by the linked list to avoid leaks.
*/
