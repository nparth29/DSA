#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(students[i]);
        }

        int i = 0;
        int count = 0;
        while (q.size() > 0 && count != q.size()) {
            if (q.front() == sandwiches[i]) {
                q.pop();
                i++;
                count = 0;
            } else {
                q.push(q.front());
                q.pop();
                count++;
            }
        }
        return q.size();
    }
};

int main() {
    Solution sol;

    // ✅ Test Case 1: All students can eat (Expected: 0)
    vector<int> students1 = {1, 1, 0, 0};
    vector<int> sandwiches1 = {0, 1, 0, 1};
    cout << "Test Case 1: ";
    cout << "Students who can't eat: " << sol.countStudents(students1, sandwiches1) << endl;

    // ❌ Test Case 2: Some students cannot eat (Expected: > 0)
    vector<int> students2 = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches2 = {1, 0, 0, 0, 1, 1};
    cout << "Test Case 2: ";
    cout << "Students who can't eat: " << sol.countStudents(students2, sandwiches2) << endl;

    return 0;
}
