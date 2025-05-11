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

int main() {

    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);

    a.next = &b;
    b.next = &c;
    c.next = &d;

    cout<<"(*(a.next)).val : "<<(*(a.next)).val<<endl; // 20 (a.next is a pointer to b) so to print the b value we need to dereference it.
    //                              and valus is stored in val so we need to access it using dot operator.
    cout<<"(*(b.next)).val : "<<(*(b.next)).val<<endl; // 30

    // we can also print the value using arrow operator
    cout<<"a.next->val :"<<a.next->val<<endl; // 20
    cout<<"b.next->val :"<<b.next->val<<endl; // 30
    cout<<"c.next->val :"<<c.next->val<<endl; // 40

    cout<<endl;

    cout<<"---- Changing the node values using pointers----"<<endl;
    a.next->val = 100;
    cout<<"a.next->val :"<<a.next->val<<endl; // 100
    (*(b.next)).val = 200;


    cout<<endl;

    cout<<"---- printing all value using a ----"<<endl;
    cout<<"a.val :"<<a.val<<endl; // 10
    cout<<"a.next->val :"<<a.next->val<<endl; // 100
    cout<<"a.next->next->val :"<<a.next->next->val<<endl; // 200
    cout<<"a.next->next->next->val :"<<a.next->next->next->val<<endl; // 40

    cout << endl;

    cout << "-----  printing using temp -----"<<endl;
    Node temp = a; // temp and a are different node but same values (val and next)
                   // temp has differnt memory allocation than a

    while(true){
        cout << temp.val << " ";
        if(temp.next == NULL)break;
        temp = *(temp.next);
    }


    
}