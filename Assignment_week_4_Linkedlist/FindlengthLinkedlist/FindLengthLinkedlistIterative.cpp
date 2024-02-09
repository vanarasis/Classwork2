// Include header for input/output operations
#include <iostream>

// Define the structure for a node in a linked list
struct Node {
    int data;     // Holds the data value of the node
    Node* next;   // Pointer to the next node in the list
};

// Function to find the length of a linked list iteratively
int iterativeLength(Node* head) {
    int length = 0;         // Initialize counter variable for length
    Node* current = head;   // Start traversal from the head of the list

    // Traverse the linked list and count the number of nodes
    while (current != nullptr) {
        length++;             // Increment counter for each visited node
        current = current->next;  // Move to the next node
    }

    // Return the total length of the list
    return length;
}

int main() {
    // Create a sample linked list (replace with your data)
    Node* head = new Node{ 1, new Node{2, new Node{3, new Node{4, nullptr}}} };

    // Find the length of the list
    int listLength = iterativeLength(head);
    std::cout << "Length of the list: " << listLength << std::endl;

    // Memory deallocation for the linked list
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    // Return 0 to indicate successful program execution
    return 0;
}
