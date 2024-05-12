#include <iostream>
using namespace std;

template<typename T>

class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    size_t size;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        size--;
    }

    /*T front() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            exit(1);
        }
        return frontNode->data;
    }

    T peek() const {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            exit(1);
        }
        return rearNode->data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {

        return false;
    }

    size_t getSize() const {
        return size;
    }
};

template<typename T>
class Stack {
private:
    T* array;
    int topIndex;
    int capacity;

public:
    Stack(int capacity) : topIndex(-1), capacity(capacity) {
        array = new T[capacity];
    }

    ~Stack() {
        delete[] array;
    }

    void push(const T& item) {
        if (isFull()) {
            cerr << "Stack is full. Cannot push.\n";
            return;
        }
        array[++topIndex] = item;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        topIndex--;
    }

    T peek() const {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            exit(1);
        }
        return array[topIndex];
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    bool isFull() const {
        return topIndex == capacity - 1;
    }
};

int main() {
    Queue<int> myQueue;
    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(15);

    cout << "Front element: " << myQueue.front() << endl;
    cout << "Rear element: " << myQueue.peek() << endl;
    cout << "Queue size: " << myQueue.getSize() << endl;

    myQueue.dequeue();
    cout << "Front element after dequeue: " << myQueue.front() << endl;

    Stack<int> myStack(5);
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    cout << "Top element: " << myStack.peek() << endl;
    cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is stack full? " << (myStack.isFull() ? "Yes" : "No") << endl;

    myStack.pop();
    cout << "Top element after pop: " << myStack.peek() << endl;

    return 0;
}


