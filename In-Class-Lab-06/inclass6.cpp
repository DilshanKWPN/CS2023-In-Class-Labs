// Lab 6 inclass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;


class ArrayStack {
private:
    const static int ARRAYSIZE = 10;

    int top = -1;
    int arr[ARRAYSIZE];

public:
    void push(int e)
    {
        if (this->is_Full())
        {
            throw 0;
        }
        top++;
        arr[top] = e;

    }
    int pop()
    {
        if (this->is_Empty())
        {
            throw 1;
        }
        top--;
        return arr[top + 1];
    }
    int Stack_Top()
    {
        if (this->is_Empty())
        {
            throw 3;
        }
        return arr[top];
    }
    void Display()
    {
        for (int i = top; i >= 0; --i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool is_Empty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
    bool is_Full()
    {
        if (top == ARRAYSIZE - 1)
        {
            return true;
        }
        return false;
    }

};

class Node {
public:
    int data;
    Node* next;

    Node(int e)
    {
        this->data = e;
        next = nullptr;
    }
};
class LinkedListStack {
private:
    Node* top;
public:
    LinkedListStack()
    {
        this->top = nullptr;
    }

    void push(int e)
    {
        Node* nextItem = new Node(e);
        nextItem->next = top;
        top = nextItem;
    }
    int pop()
    {
        if (this->is_Empty())
        {
            throw 1;
        }
        int e = this->top->data;
        this->top = top->next;
        return e;
    }
    bool is_Empty()
    {
        if (top == nullptr)
        {
            return true;
        }
        return false;
    }
    int Stack_Top()
    {
        if (this->is_Empty())
        {
            throw 2;
        }
        return top->data;
    }
    void Display()
    {
        if (!this->is_Empty())
        {
            Node* thisItem = this->top;
            while (thisItem != nullptr)
            {
                cout << thisItem->data << " ";
                thisItem = thisItem->next;
            }
            cout << endl;
        }
    }
};


int main()
{
    auto start1 = high_resolution_clock::now();
    ArrayStack my_Array_Stack;
    my_Array_Stack.push(8);
    my_Array_Stack.push(10);
    my_Array_Stack.push(5);
    my_Array_Stack.push(11);
    my_Array_Stack.push(15);
    my_Array_Stack.push(23);
    my_Array_Stack.push(6);
    my_Array_Stack.push(18);
    my_Array_Stack.push(20);
    my_Array_Stack.push(17);
    my_Array_Stack.Display();
    for (size_t i = 0; i < 5; i++)
    {
        my_Array_Stack.pop();
    }
    my_Array_Stack.Display();
    my_Array_Stack.push(4);
    my_Array_Stack.push(30);
    my_Array_Stack.push(3);
    my_Array_Stack.push(1);
    my_Array_Stack.Display();

    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<chrono::nanoseconds>(end1 - start1);
    cout << "Array stack running time : " << duration1.count() << " ns" << endl;


    auto start = high_resolution_clock::now();

    LinkedListStack my_Stack;
    my_Stack.push(8);
    my_Stack.push(10);
    my_Stack.push(5);
    my_Stack.push(11);
    my_Stack.push(15);
    my_Stack.push(23);
    my_Stack.push(6);
    my_Stack.push(18);
    my_Stack.push(20);
    my_Stack.push(17);
    my_Stack.Display();
    for (size_t i = 0; i < 5; i++)
    {
        my_Stack.pop();
    }
    my_Stack.Display();
    my_Stack.push(4);
    my_Stack.push(30);
    my_Stack.push(3);
    my_Stack.push(1);
    my_Stack.Display();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<chrono::nanoseconds>(end - start);
    cout << "LinkedList stack running time : " << duration.count() << " ns" << endl;



}
