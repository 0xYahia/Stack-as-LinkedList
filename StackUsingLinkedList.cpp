#include<iostream>
using namespace std;


class node
{
  public:
    int data;
    node *prev;
    node(int _data){
    data = _data;
    prev = NULL;
    }
};

class Stack{
  node *front, *top;
  public:
    Stack(){
      front = top = NULL;
    };
    void push(int _data){
      node *temp = new node(_data);
      if(front == NULL) {
        front = top = temp;
      } else {
        temp->prev = top;
        top = temp;
      }
    };
    int pop(){
      node *prev = top;
      if(front == NULL){
        return 0;
      }else{
        node *current = top->prev;
        top = current;
        delete prev;
      }
    };

    void display(){
      node *current = top;
      while (current != NULL)
      {
        cout<<current->data<<" ";
        current = current->prev;
      }
      cout<<endl;
    }
};



int main(){
  Stack stk;

  stk.push(10);
  stk.push(20);
  stk.push(30);
  stk.push(40);

  stk.display(); 
  stk.pop();
  stk.display(); 

  return 0;
}


