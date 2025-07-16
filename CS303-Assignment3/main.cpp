#include <iostream>
#include "Queue.h"

using namespace std;

int main() {

    // Initialize queue
    Queue<int> queue;
    cout << "Queue created!\n";
    cout << "--------------\n\n";

    // Instantiate queue with 10 integers
    for (int i = 1; i <= 10; i++) {
        queue.push(i);
    }

    // Display current queue
    cout << "Current queue: ";
    queue.display();

    // Queue front
    cout << "The integer at the front is: " << queue.front() << "\n\n";

    // Queue push
    cout << "Pushing value 4..." << endl;
    queue.push(4);
    cout << "Pushing value 11..." << endl;
    queue.push(11);
    cout << "Pushing value 0..." << endl;
    queue.push(0);
    cout << "Pushing value 255..." << endl;
    queue.push(255);
    cout << endl;

    // Queue size after pushing
    cout << "Queue size is: " << queue.size() << "\n\n";

    // Queue pop
    cout << "Popping front value: " << queue.front() << endl;
    queue.pop();
    cout << "Popping front value: " << queue.front() << endl;
    queue.pop();
    cout << "Popping front value: " << queue.front() << endl;
    queue.pop();
    cout << endl;

    // Queue size after popping
    cout << "Queue size is: " << queue.size() << "\n\n";

    // Display current queue
    cout << "Current queue: ";
    queue.display();

    // Move front to rear
    cout << "Moving front value to end of queue...\n\n";
    queue.move_to_rear();

    // Display current queue
    cout << "Current queue: ";
    queue.display();

    // Insertion sort on queue
    cout << "Using insertion sort on queue...\n\n";
    queue.insertion_sort();

    // Display current queue
    cout << "Current queue: ";
    queue.display();

    return 0;
}
