#include<iostream>
using namespace std;

class Node {
    public:
        int val;
        Node* next;

        Node(int val) {
            this->val = val;
            next = NULL;
        }
};


void display(Node* head){
    Node* temp = head;
    if (temp == NULL) return;
    cout << temp->val << " ";
    display(temp->next);
}

void reverseDisplay(Node* head){
    Node *temp = head;
    if(temp == NULL)
        return;
    reverseDisplay(temp->next); // calling before printing the value
    cout << temp->val << " ";
}

int main(){
    Node* head = new Node(10); // head is a pointer to Node :head has address of this node(10)
    Node* second = new Node(20); // second is a pointer to Node :second has address of this node(20)
    Node* third = new Node(30); // third is a pointer to Node :third has address of this node(30)
    Node* tail = new Node(40); // tail is a pointer to Node :tail has address of this node(40)

    head->next = second; // head -> next contain address of second (*head).next = second
    second->next = third; // second -> next contain address of third (*second).next = third
    third->next = tail; // third -> next contain address of tail (*third).next = tail

    cout<<"Displaying the linked list using recursion : "<<endl;
    display(head);

    cout << endl;

    cout<<"Displaying the linked list in reverse order using recursion : "<<endl;
    reverseDisplay(head);

    return 0;
}