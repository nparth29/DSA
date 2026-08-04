#include<iostream>
using namespace std;

class Vector{
public:
    int size;
    int capacity;
    int* arr; 
    Vector(){
        size = 0;
        capacity = 1;
        arr = new int(1);
    }

    void add(int ele){
        if(size == capacity){
            capacity *=2; 
            int* arr2 = new int(capacity);
            // now we have to copy the previous array elem in new array
            for(int i = 0; i<size;i++){
                arr2[i] = arr[i];
            }
            arr = arr2; // most imp, 
        }
        // if size != capacity -> simply put the elem in arr and increase the size
        arr[size] = ele; // Note: here we are putting elem in original array not new one
        size++;
    }
    void print(){
        for(int i = 0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int get(int idx){
        if(size == 0){
            cout<<"vector is empty";
            return -1;
        }
        if(idx >= size){
            cout<<"Invalid index";
            return -1;
        } 
        return arr[idx];
    }
    void remove(){
        if(size == 0){
            cout<<"vector is empty";
        }
        else{
            size --;
        }
    }
};

int main(){
    Vector v;
    v.add(10);
    cout<<v.size<<" "<<v.capacity<<endl;
    v.add(28);
    cout<<v.size<<" "<<v.capacity<<endl;
    v.add(9);
    cout<<v.size<<" "<<v.capacity<<endl;
    v.add(18);
    cout<<v.size<<" "<<v.capacity<<endl;
    v.add(11);
    cout<<v.size<<" "<<v.capacity<<endl;

    v.print();
    cout<<v.get(10)<<endl;
    cout<<v.get(3)<<endl;
    v.remove();
    v.print();
}
