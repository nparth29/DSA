#include<iostream>
#include<string>
using namespace std;

int main(){
    string name;
    cout << "enter the string : ";
    getline(cin, name);
    int count = 0;
    for (int i = 0; name[i] != '\0';i++){
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u'){
            count++;
        }
    }
    cout << count;
}