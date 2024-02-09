```cpp
#include <iostream> // Header for input/output operations

// Define the Node structure for linked list elements
struct Node {
  int data;     // Holds the data value of the node
  Node* next;   // Pointer to the next node in the list
};

// Function for iterative search using a loop
bool iterativeSearch(Node* head, int target) {
  Node* current = head; // Start from the head of the list
  while (current != nullptr) { // Continue until we reach the end (null)
    if (current->data == target) { // Check if current node's data matches target
      return true;  // Element found! Return true
    }
    current = current->next; // Move to the next node
  }
  return false; // Element not found in the list, return false
}

// Function for recursive search using function calls
bool recursiveSearch(Node* head, int target) {
  if (head == nullptr) { // Base case: empty list, element not found
    return false;
  }
  if (head->data == target) { // Base case: current node's data matches target
    return true;  // Element found! Return true
  }
  return recursiveSearch(head->next, target); // Recursive call to search the rest
}

int main() {
  // Create a sample linked list (replace with your data)
  Node* head = new Node{1, new Node{2, new Node{3, new Node{4, nullptr}}}};
  int target = 3; // Element to search for

  // Perform iterative search and print result
  if (iterativeSearch(head, target)) {
    std::cout << "Element found using iterative search!" << std::endl;
  } else {
    std::cout << "Element not found using iterative search." << std::endl;
  }

  // Perform recursive search and print result
  if (recursiveSearch(head, target)) {
    std::cout << "Element found using recursive search!" << std::endl;
  } else {
    std::cout << "Element not found using recursive search." << std::endl;
  }

  // Memory deallocation (important!)
  Node* current = head;
  while (current != nullptr) {
    Node* next = current->next;
    delete current;
    current = next;
  }

  return 0;
}
```
