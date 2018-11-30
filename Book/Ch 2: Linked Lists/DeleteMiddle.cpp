/*
 Problem:
  Implement an algorithm to delete a node in the middle (i.e., any node but the first
  and last node, not necessarily the exact middle) of a singly linked list, given only
  access to that node.

 Implementation:
  Copy the data from the next node into the node of choice, then delete that node.

 Time Complexity: O(1)
 Space Complexity: O(1)
 */

#include <iostream>

using namespace std;
struct Node
{
    Node* next;
    int data;
};

void delete_node(Node* n)
{
    Node* to_delete = n->next;

    n->data = to_delete->data;
    n->next = to_delete->next;

    delete to_delete;
}

void print_list(Node* head)
{
    while (head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data << endl;
}

int main(int argc, char** argv)
{
    Node* n1 = new Node;
    n1->data = 1;
    Node* n2 = new Node;
    n2->data = 2;
    Node* n3 = new Node;
    n3->data = 3;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    print_list(n1);

    delete_node(n2);

    print_list(n1);

    return 0;
}
