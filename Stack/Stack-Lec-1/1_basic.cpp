#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<int> st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    stack<int> temp;
    cout << "Original Stack:" << endl;
    while(st.size() > 0){
        cout << st.top()<<" ";
        temp.push(st.top());
        st.pop();
    }
    cout << endl;
    // puting element back from temp 
    while(temp.size() > 0){
        st.push(temp.top());
        temp.pop();
    }
    cout <<"top element of st: "<< st.top() << " and size is : " << st.size();
}