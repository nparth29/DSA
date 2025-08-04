// reverse using two extra stack 
#include<iostream>
#include<stack>
using namespace std;

int main(){
        stack<int> st;
        stack<int> gt;
        stack<int> rt;

        // Push elements
        st.push(10);
        st.push(20);
        st.push(30);
        st.push(40);
        st.push(50);
        st.push(60);
        cout << st.top() << endl;
        while (st.size() > 0){
            gt.push(st.top());
            st.pop();
        }
        cout << gt.top()<<endl;
        while(gt.size() > 0){
            rt.push(gt.top());
            gt.pop();
        }

        cout << rt.top() << endl;

        while(rt.size() > 0){
            st.push(rt.top());
            rt.pop();
        }

        cout <<"top element of st: "<< st.top() << " and size is : " << st.size();
}