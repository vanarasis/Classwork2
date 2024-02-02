#include <iostream>
#include <queue>

using namespace std;

// Function to display the elements of a queue
void showq(queue<int> gq)
{
    // Create a copy of the original queue
    queue<int> g = gq;

    // Iterate through the queue and print each element
    while (!g.empty()) {
        cout << '\t' << g.front(); // Print the front element of the queue
        g.pop(); // Remove the front element from the queue
    }
    cout << '\n';
}

// Driver Code
int main()
{
    // Initialize a queue named gquiz
    queue<int> gquiz;

    // Add elements to the queue
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);

    // Print the message indicating the queue is being displayed
    cout << "The queue gquiz is : ";
    // Call the showq function to display the elements of the queue
    showq(gquiz);

    // Display the size of the queue
    cout << "\ngquiz.size() : " << gquiz.size();
    // Display the front element of the queue
    cout << "\ngquiz.front() : " << gquiz.front();
    // Display the back element of the queue
    cout << "\ngquiz.back() : " << gquiz.back();

    // Display the message indicating the removal of an element from the queue
    cout << "\ngquiz.pop() : ";
    // Remove an element from the queue
    gquiz.pop();
    // Display the updated queue after removing an element
    showq(gquiz);

    return 0;
}