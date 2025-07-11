#include<iostream>
using namespace std;

class Node {
public:
    int val;

    Node *next;  
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

Node *createList1(){
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);


    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;

    return head;
}


void display( Node* head){
    Node *temp = head;
    while(temp != NULL){
        cout << temp->val <<"->";
        temp = temp->next;
    }
    cout << "NULL"<<endl;
}

int length(Node* head){
    Node *temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}



int main(){
    // Node *head1 = createList1();
    Node *head1 = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);


    head1->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    cout << "The first list is : ";
    display(head1);

    Node *temp = head1;

    for (int i = 1; i < 3;i++){
        cout << temp->val<<endl;
        temp = temp->next;
        cout << temp->val<<endl;
    }
}