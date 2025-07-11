#include <iostream>
#include<vector>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Step 1: create the deep copy(usint dummy node) and initally random pointing at NULL
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* tempD = dummy;
        while(temp){
            Node* a = new Node(temp->val);
            tempD->next = a;
            temp = temp->next;
            tempD = tempD->next;
        }  // we have created deep copy 
        temp = head; // mantaining the temp pointer 
        Node* dublicate = dummy->next; // head of copied list 

        // step 2; alternately joing the both list with frst node is the head of main list 
        // a and b are to traversing and to joining 
        Node* a = head;  // point to the main list 
        Node* b = dublicate;  // point to the copied list 
        tempD = dummy;        // used to link the both list 
        while(b != NULL){
            tempD->next = a;
            a = a->next;
            tempD = tempD->next;

            tempD->next = b;
            b = b->next;
            tempD = tempD->next;
        }
        dummy = dummy->next; // dummy pointing to joined node head; 

        // step 2: here we join the rendom pointor of deep copy 
        // we will take t1 and t2 for travering, initally random of copied list pointing at NULL 
        Node* t1 = dummy; 
        Node* t2 = dummy;
        while(t1 != NULL){
            t2 = t1->next; // t2 always point at coppied list node while t1 on main list
            if(t1->random) t2->random = t1->random->next; // V imp; 
            t1 = t1->next->next;
        }

        // step 4 removing connection and seperting list  : 
        Node* x = new Node(-1);
        Node* tempX = x;
        Node* y = new Node(-1);
        Node* tempY = y;
        temp = dummy; // dummy pointing to the joinde list head
        while(temp){
            tempX->next = temp;
            temp = temp->next; 
            tempX = tempX->next;

            tempY->next = temp;
            temp = temp->next; 
            tempY = tempY->next;
        }
        tempX->next =NULL;
        tempY->next = NULL;

        return y->next;
    }
};

// Utility function to print the list (val + random)
void printList(Node* head) {
    Node* temp = head;
    while(temp) {
        cout << "Val: " << temp->val;
        if (temp->random)
            cout << ", Random: " << temp->random->val << endl;
        else
            cout << ", Random: NULL" << endl;
        temp = temp->next;
    }
    cout << "--------------------" << endl;
}

// Utility to build a list from array and random map
Node* buildList(vector<int> vals, vector<int> randomIndices) {
    vector<Node*> nodes;
    for (int val : vals) {
        nodes.push_back(new Node(val));
    }
    for (int i = 0; i < vals.size() - 1; i++) {
        nodes[i]->next = nodes[i + 1];
    }
    for (int i = 0; i < vals.size(); i++) {
        if (randomIndices[i] != -1)
            nodes[i]->random = nodes[randomIndices[i]];
    }
    return nodes[0];
}

int main() {
    // Create a list: 7 -> 13 -> 11 -> 10 -> 1
    // Random pointers: [null, 0, 4, 2, 0]
    vector<int> vals = {7, 13, 11, 10, 1};
    vector<int> randoms = {-1, 0, 4, 2, 0};

    Node* head = buildList(vals, randoms);
    cout << "Original List:\n";
    printList(head);

    Solution s;
    Node* copied = s.copyRandomList(head);

    cout << "Copied List:\n";
    printList(copied);

    return 0;
}
