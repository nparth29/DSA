#include<iostream>
using namespace std;

class Node{    // user define data type
public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        next = NULL;
    }
};


class LinkedList{       // LinkedList class to implement a singly linked list ( user defined data structure )
    public:
        Node *head;
        Node *tail;
        int size;
        LinkedList(){
            head = tail = NULL;
            size = 0;
        }

        void insertAtTail(int val){
            Node* newnode = new Node(val);
            if(head == NULL){
                head = tail = newnode;
            }else{
                tail->next = newnode;
                tail = newnode;
            }
            size++;
        }

        void insertAtHead(int val){
            Node *newnode = new Node(val);
            if(head == NULL){
                head = tail = newnode;
            }else{
                newnode->next = head;
                head = newnode; 
            }
            size++;
        }

        void insertAtIdx(int idx, int val){
            if(idx < 0 || idx > size)
                cout << "invalid index";
            else if(idx == 0)
                insertAtHead(val);
            else if(idx == size)
                insertAtTail(val);
            else{
                Node *temp = head;
                for (int i = 0; i < idx - 1;i++){
                    temp = temp->next;
                }
                Node* newnode = new Node(val);
                newnode->next = temp->next;
                temp->next = newnode;
                size++;
            }
        }

        int getIdx(int idx){
            if(idx < 0 || idx >= size){
                cout << "invalid index";
                return -1;
            }
            else if(idx ==0)
                return head->val;
            else if(idx == size -1)
                return tail->val;
            else{
                Node *temp = head;
                for (int i = 1; i <= idx;i++){
                    temp = temp->next;
                }
                return temp->val;
            }
        }

        void deleteAtHead(){
            if(head == NULL){
                cout << "List is empty";
            }
            else if (head == tail){
                delete head;
                head=tail=NULL;
                size--;
            }else{
                Node *temp = head;
                head = head->next;
                delete temp;
                size--;
            }
        }

        void deleteAtTail(){
            if(head == NULL){
                cout << "list is empty";
            } else if(head == tail){
                delete head;
                head = tail = NULL;
                size--;
            }else{
                Node *temp = head;
                while(temp->next != tail){
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                tail->next = NULL;
                size--;
            }
        }

        void deleteAtIdx(int idx){
            if(idx<0 || idx >= size){
                cout << "invalid index";
            }else if(idx == 0){
                deleteAtHead();
            }else if(idx == size - 1){
                deleteAtTail();
            }else{
                Node *temp = head;
                for (int i = 1; i < idx;i++){  // loop should be run idx-1 times to reach the node before the one to be deleted
                    temp = temp->next;
                }
                temp->next = temp->next->next;
                size--;
            }
        }

        void display(){
            Node *temp = head;
            while(temp != NULL){
                cout << temp->val << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main(){
    LinkedList ll;         //{ }
    ll.insertAtTail(10);   //{ 10 }
    ll.display();
    ll.insertAtTail(20);    //{ 10 ->20 }
    ll.display();
    ll.insertAtTail(30);    //{10 -> 20 -> 30 }
    ll.display();
    ll.insertAtTail(40);    //{ 10 -> 20 -> 30 -> 40 }
    ll.display();
    ll.insertAtHead(5);     //{ 5 -> 10 -> 20 -> 30 -> 40 -> NULL }
    ll.display();
    ll.insertAtIdx(3, 15);  //{ 5 -> 10 -> 20 -> 15 -> 30 -> 40 -> NULL }
    ll.display();
    ll.insertAtIdx(0, 1);   //{ 1 -> 5 -> 10 -> 20 -> 15 -> 30 -> 40 -> NULL }
    ll.display();
    ll.insertAtIdx(7, 50);  //{ 1 -> 5 -> 10 -> 20 -> 15 -> 30 -> 40 -> 50 -> NULL }
    ll.display();
    ll.insertAtIdx(7, 88);  //{ 1 -> 5 -> 10 -> 20 -> 15 -> 30 -> 40 -> 88 -> 50 -> NULL }
    ll.display();
    int val = ll.getIdx(3);
    cout << "Value at index 3 : " << val << endl;   // 20
    ll.deleteAtHead();      //{ 5 -> 10 -> 20 -> 15 -> 30 -> 40 -> 88 -> 50 -> NULL }
    ll.display();
    ll.deleteAtTail();      //{ 5 -> 10 -> 20 -> 15 -> 30 -> 40 -> 88 -> NULL }
    ll.display();
    ll.deleteAtIdx(3);      //{ 5 -> 10 -> 20 -> 30 -> 40 -> 88 -> NULL }
    ll.display();

    return 0;
}