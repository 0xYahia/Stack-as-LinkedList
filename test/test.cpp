#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int _data)
    {
        data = _data;
        next = NULL;
    }
};

class Stack
{
private:
    Node *head, *top;
public:
    Stack()
    {
        head = top= NULL;
    }
    void push(int _data)
    {
         Node * node = new Node(_data);
         if(head == NULL)
         {
            head = top =node;
         }
         else
         {
            node->next = top;
            top = node;
         }
    }
    int pop()
    {
       Node * currnet = top;
       cout<<"the data delete is "<< currnet->data<<endl;
       Node * prev = top->next;
       top = prev;
       delete currnet;
    }
    void display()
    {
        Node * current = top;
        while(current!=NULL)
        {
            cout<<current->data<<endl;
            current = current->next;
        }
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<"display data in stack"<<endl;
    s.display();
    cout<<"-------------"<<endl;
    s.pop();
    s.pop();
    cout<<"display data after pop"<<endl;
    s.display();
    cout<<"-------------"<<endl;
    cout<<"display data after insert new data"<<endl;
    s.push(6);
    s.display();
    return 0;
}