#include<iostream>
using namespace std;

void hanoi(int n, char a, char b, char c){
    if(n == 0)
        return;
    hanoi(n - 1, a, c, b);  // Move n-1 disks from A to B using C
    cout << a << " -> " << c << endl; // Move nth disk from A to C
    hanoi(n - 1, b, a, c);  // Move n-1 disks from B to C using A
}

int main(){
    int n;
    cout << "Enter the number of discs : ";
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
}
