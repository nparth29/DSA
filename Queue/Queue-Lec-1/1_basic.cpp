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

int main(){
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // cout<<q.front()<<endl;
    // q.pop();
    // cout << q.front()<<endl;
    // cout<<q.back();
    display(q);

}