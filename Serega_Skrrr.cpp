#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

class Queue
{
    int* arr;
    int capacity;
    int front;
    int rear;
    int count;

public:
    Queue(int size = 10000000) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
        count = 0;
    }
    ~Queue() {
        delete[] arr;
    }

    int dequeue() {
        if (isEmpty())
        {
            cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        int x = arr[front];
        cout << "Removing " << x << endl;

        front = (front + 1) % capacity;
        count--;

        return x;
    }

    void enqueue(int item) {
        if (isFull())
        {
            cout << "Overflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Inserting " << item << endl;

        rear = (rear + 1) % capacity;
        arr[rear] = item;
        count++;
    }

    int peek() {
        if (isEmpty())
        {
            cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }
        return arr[front];
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return (size() == 0);
    }

    bool isFull() {
        return (size() == capacity);
    }
};

class Stack
{
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size = 10000000) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (isFull())
        {
            cout << "Overflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Добавили " << x << endl;
        arr[++top] = x;
    }

    int pop() {

        if (isEmpty())
        {
            cout << "Underflow\nProgram Terminated\n";
            exit(EXIT_FAILURE);
        }

        cout << "Убрали " << peek() << endl;

        return arr[top--];
    }

    int peek() {
        if (!isEmpty()) {
            return arr[top];
        }
        else {
            exit(EXIT_FAILURE);
        }
    }

    int size() {
        return top + 1;
    }

    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    setlocale(LC_ALL, "Ru");
    srand(time(NULL));


}