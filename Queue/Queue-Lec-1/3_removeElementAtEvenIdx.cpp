// remove all the elements present at even position in queue. consider 0 based indexing 

#include<iostream>
#include<queue>

using namespace std;

void display(queue<int>& q){
    int size = q.size();
    for (int i = 0; i < size;i++){
        cout<<q.front()<<" ";
        int x = q.front();
        q.pop();

        q.push(x);
    }
    cout << endl;
}



void remove(queue<int> &q){
    int n = q.size();
    for (int i = 0; i < n; i++){
        if( i%2 !=0){
            int x = q.front();
            q.push(x);
        }
            q.pop();
    }
}

int main(){
    queue<int> q;

    q.push(10);  // idx: 0 
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    display(q);
    remove(q);
    display(q);
}