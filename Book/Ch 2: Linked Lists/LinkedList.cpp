// Singly LinkedList

#include<iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

class LinkedList{

    node *head;
public:
    LinkedList(){
        head = NULL;
    }

    //Insert in beginning
    void insert(int d){
        node *tmp = new node;
        tmp->data = d;
        tmp->next = NULL;

        if(head == NULL){
            head = tmp;
        }
        else{
            tmp->next = head;
            head = tmp;
        }
    }

    // Print
    void display(){
        node *tmp = head;
        while(tmp!=NULL){
            cout << tmp->data << " -> ";
            tmp = tmp->next;
        }
        cout<< "NULL";
    }


};

int main(){
    LinkedList l1;
    l1.insert(12);
    l1.insert(100);
    l1.insert(200);
    l1.display();

    return 0;
}
