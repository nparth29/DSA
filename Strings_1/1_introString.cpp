#include<iostream>
using namespace std;

int main(){
    char str1[] = {'a', 'b', 'c', 'd', 'e','f'};

    for (int i = 0; str1[i] !='\0';i++){
        cout << str1[i] << " ";
    }
    cout << endl
         << str1;

    // char str2[] = "abcde";
    // for (int i = 0; i < 5;i++){
    //     cout << str2[i] << " ";
    // }
    char str3[] = {'a', 'b', '\0', 'd', 'e','f'};
    cout <<endl<< str3;
}