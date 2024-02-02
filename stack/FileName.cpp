#include <iostream>
#include <stack>
using namespace std;

int main()
{
	// Initialize a stack named "stack"
	// The stack holds integers
	// This is a stack program
	stack<int> stack;

	// Push elements onto the stack
	stack.push(21);
	stack.push(22);
	stack.push(24);
	stack.push(25);

	// Pushing an integer variable 'num' with value 0 onto the stack
	int num = 0;
	stack.push(num);

	// Popping three elements from the stack
	stack.pop();
	stack.pop();
	stack.pop();

	// Printing elements of the stack until it's empty
	while (!stack.empty()) {
		cout << stack.top() << " "; // Print the top element of the stack
		stack.pop(); // Pop the top element from the stack
	}

	return 0;
}