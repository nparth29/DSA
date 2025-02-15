#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int n) {
        int root = sqrt(n);
        return (root * root == n);
    }

    bool judgeSquareSum(int c) {
        int x = 0;
        int y = c;
        int i = 1; // i have took an extra variable to show the each ittriation 
        while (x <= y) {
            if (isPerfectSquare(x) && isPerfectSquare(y)) {
                return true;
            } 
            else if (!isPerfectSquare(y)) {
                y = (int)sqrt(y) * (int)sqrt(y);
                x = c - y;
            } 
            else {
                x = ((int)sqrt(x) + 1) * ((int)sqrt(x) + 1);
                y = c - x;
            }
            cout << "after the " << i << "'th itteration the value is :{" << x << " , " << y << "}"<<endl;
            i++;
        }

        return false;
    }
};

int main() {
    Solution solution;
    int c;
    
    cout << "Enter a number: ";
    cin >> c;
    
    if (solution.judgeSquareSum(c)) {
        cout << "True: There exist integers a and b such that a^2 + b^2 = " << c << endl;
    } else {
        cout << "False: No such integers exist for " << c << endl;
    }

    return 0;
}
