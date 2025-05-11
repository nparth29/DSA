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

int countNodes(Node* head){
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

void display(Node* head){
    Node* temp = head;
    cout << "Printing the nodes : " << endl;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(10); // head is a pointer to Node :head has address of this node(10)
    Node* second = new Node(20); // second is a pointer to Node :second has address of this node(20)
    Node* third = new Node(30); // third is a pointer to Node :third has address of this node(30)
    Node* tail = new Node(40); // tail is a pointer to Node :tail has address of this node(40)

    head->next = second; // head -> next contain address of second (*head).next = second
    second->next = third; // second -> next contain address of third (*second).next = third
    third->next = tail; // third -> next contain address of tail (*third).next = tail

    display(head);

    int size = countNodes(head);
    cout << "Number of nodes in the linked list : " << size << endl;
    return 0;
}