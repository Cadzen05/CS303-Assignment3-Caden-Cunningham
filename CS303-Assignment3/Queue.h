#pragma once

using namespace std;

template <typename T1>
struct Node {
    // Data fields
    T1 data;
    Node* next;

    // Constructor
    Node (T1 d, Node *p = nullptr) {
        data = d;
        next = p;
    }
};

template <typename T1>
class Queue {
private:
    // Data fields
    size_t num_items;
    Node<T1>* start;
    Node<T1>* rear;

public:
    // Constructor
    Queue() : num_items(0), start(nullptr), rear(nullptr) {}

    // Desctuctor
    ~Queue() {
        while (!empty()) {
            pop();
        }
    }


    // Queue functions

    void push(const T1& item) {
        // If queue is empty
        if (start == nullptr) {
            rear = new Node<T1>(item, nullptr);
            start = rear;
        }
        // Push node to end
        else {
            rear->next = new Node<T1>(item, nullptr);
            rear = rear->next;
        }
        // Increment num_items
        num_items++;
    }

    void pop() {
        // Pointer to the start node
        Node<T1>* deleted_note = start;
        start = start->next;

        // If only one item
        if (start == nullptr) {
            rear = nullptr;
        }

        // Delete the temp and decrement
        delete deleted_note;
        num_items--;
    }

    const T1& front() const {
        // If empty, throw runtime_error
        if (empty()) {
            throw runtime_error("Queue is currently empty.");
        }

        // Return front data
        return start->data;
    }

    size_t size() const {
        // Return size
        return num_items;
    }

    bool empty() const {
        // If start is null, return true
        return start == nullptr;
    }

    // Display to check functions are valid
    void display() const {
        // Pointer at start then iterate through queue
        Node<T1>* current = start;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        // Last node is pointing to null
        cout << "NULL\n\n";
    }

    void move_to_rear() {
        // If empty, do nothing
        if (empty()) {
            return;
        }

        // Store fronts data, pop front value, then push with stored data
        T1 data = front();
        pop();
        push(data);
    }

    void insertion_sort() {
        // If 0 or 1 values, then return
        if (!start || !start->next) {
            return;
        }

        // Initialize sorted list
        Node<T1>* insertion_list = nullptr;

        // Curr pointer at start, and then loop while curr != null
        Node<T1>* curr = start;
        while (curr != nullptr) {
            Node<T1>* next = curr->next;

            // If first inserted or the curr data is less than first val
            if (!insertion_list || curr->data < insertion_list->data) {
                // Point to next value and then insert curr
                curr->next = insertion_list;
                insertion_list = curr;
            }
            // If inserting in middle/end of list
            else {
                // Temp pointer to insertion_list first val then iterate
                Node<T1>* temp = insertion_list;
                // Stop if temp->next is null or the curr->data is less than temp->next data
                while (temp->next && temp->next->data < curr->data) {
                    temp = temp->next;
                }
                // Insert curr into list
                curr->next = temp->next;
                temp->next = curr;
            }
            curr = next;
        }

        // Set start to insertion_list start
        // Set rear to start
        start = insertion_list;
        rear = start;
        
        // Iterate through queue until rear is at end
        while (rear && rear->next) {
            rear = rear->next;
        }
    }
};
