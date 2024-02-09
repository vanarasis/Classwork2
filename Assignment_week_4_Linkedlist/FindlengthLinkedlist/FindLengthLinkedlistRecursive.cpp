/*
The recursive approach tackles the problem of determining the length of the entire list by dividing it into finding the length of smaller sub-lists. The logic unfolds as follows:

Base case: If the current node is null (indicating the end of the list), the length is 0. Return 0.
Recursive call: Otherwise, initiate a recursive call to ascertain the length of the remaining list starting from the next node.
Increment by 1: Add 1 to the result obtained from the recursive call since it represents the length of the remaining list, and the current node itself contributes 1 to the overall length.
Return: Provide the sum (1 + length of the remaining list).
Termination conditions:

The recursion halts when the base case is encountered, indicating that the current node is null.
*/

#include <iostream> // Including the header for input/output operations

// Define the Node structure for elements in the linked list
struct Node {
    int data;     // Holds the data value of the node
    Node* next;   // Pointer to the next node in the list
};

// Function to determine the length of a linked list recursively
int recursiveLength(Node* head) {
    if (head == nullptr) { // Base case: an empty list (null), so the length is 0
        return 0;
    }
    else {
        // Recursive call: Determine the length of the remaining list + 1 for the current node
        return 1 + recursiveLength(head->next);
    }
}

int main() {
    // Creating a sample linked list (replace with your data)
    Node* head = new Node{ 1, new Node{2, new Node{3, new Node{4, nullptr}}} };

    // Determining the length of the list
    int listLength = recursiveLength(head);
    std::cout << "Length of the list: " << listLength << std::endl;

    // Memory deallocation (essential!)
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}

/*Explanation:

#include <iostream>: This statement includes the header for input/output operations.
Node structure: Defines the Node structure with data and next members.
recursiveLength function:
if (head == nullptr): Base case: if the current node is null (end of list), its length is 0, so return 0.
else: Recursive case:
return 1 + recursiveLength(head->next): Initiates a recursive call to determine the length of the remaining list (starting from the next node) and adds 1 to it, accounting for the current node as well.
main function:
Sample linked list: Generates a sample list with nodes containing values 1, 2, 3, and 4.
Calculate length: Calls the recursiveLength function with the head pointer to find the length and stores it in listLength.
Print length: Outputs the length to the console.
Memory deallocation: Similar to the iterative approach, frees memory utilized by the linked list to prevent memory leaks.
*/
