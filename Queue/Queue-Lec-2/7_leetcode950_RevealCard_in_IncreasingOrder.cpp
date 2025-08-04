#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end()); // Step 1: Sort the deck in increasing order

        vector<int> ans(n); // This will store the final arrangement
        queue<int> q;

        // Step 2: Fill the queue with indexes from 0 to n-1
        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        // Step 3: Place the cards in their correct position
        for (int i = 0; i < n; i++) {
            int idx = q.front(); q.pop();       // Reveal index
            ans[idx] = deck[i];                 // Place the current card

            if (!q.empty()) {
                q.push(q.front()); q.pop();     // Move the next index to the bottom
            }
        }

        return ans;
    }
};

int main() {
    Solution obj;
    
    // Sample input
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};

    // Solve
    vector<int> result = obj.deckRevealedIncreasing(deck);

    // Output
    cout << "Revealed order in increasing sequence:\n";
    for (int card : result) {
        cout << card << " ";
    }
    cout << endl;

    return 0;
}
