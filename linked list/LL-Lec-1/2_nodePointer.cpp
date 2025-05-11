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
    cout << "Printing the nodes : " << endl;
    while(temp != NULL){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}


void insertAtEnd(Node* head,int val){
    Node *temp = head;
    Node *newNode = new Node(val);
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

int main(){
    Node* head = new Node(10); // head is a pointer to Node :head has address of this node(10)
    Node* second = new Node(20); // second is a pointer to Node :second has address of this node(20)
    Node* third = new Node(30); // third is a pointer to Node :third has address of this node(30)
    Node* tail = new Node(40); // tail is a pointer to Node :tail has address of this node(40)

    head->next = second; // head -> next contain address of second (*head).next = second
    second->next = third; // second -> next contain address of third (*second).next = third
    third->next = tail; // third -> next contain address of tail (*third).next = tail

    cout<<endl;

    cout<<"---- printing specific node value using head ----"<<endl;
    cout<<"head->val :"<<head->val<<endl; // 10
    cout<<"head->next->val :"<<head->next->val<<endl; // 20
    cout<<"head->next->next->val :"<<head->next->next->val<<endl; // 30
    cout<<"head->next->next->next->val :"<<head->next->next->next->val<<endl; // 40

    cout<<endl;

    cout<<"---- printing all value using ptr ----"<<endl;

    Node* ptr = head;  // ptr is a pointer to head
    while(ptr != NULL) {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }

    cout<<endl<<endl;

    cout<<"---- Changing the node values using pointers----"<<endl;
    head->val = 100;
    cout<<"head->val :"<<head->val<<endl; // 100
    head->next->val = 200;
    cout<<"head->next->val :"<<head->next->val<<endl; // 200
    head->next->next->val = 300;
    cout<<"head->next->next->val :"<<head->next->next->val<<endl; // 300
    head->next->next->next->val = 400;      
    cout<<"head->next->next->next->val :"<<head->next->next->next->val<<endl; // 400

    display(head);

    insertAtEnd(head, 500);
    display(head);
    return 0;
}