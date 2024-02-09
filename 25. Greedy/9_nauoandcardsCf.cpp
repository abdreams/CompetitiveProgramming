//A. Nauuo and Cards
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int min_operations(int n, vector<int>& a, vector<int>& b) {
    // Step 1: Find the index of each numbered card in the pile
    unordered_map<int, int> card_index;
    for (int i = 0; i < n; ++i) {
        card_index[b[i]] = i;
    }

    // Step 2: Find the maximum index of numbered cards in the pile
    int max_index = -1;
    for (const auto& entry : card_index) {
        max_index = max(max_index, entry.second);
    }

    // Step 3: Initialize the variable to keep track of operations
    int operations = 0;

    // Step 4: Iterate through Nauuo's initial cards
    for (int card : a) {
        // Step 4a: Check if the card is already in the correct position
        if (card_index[card] <= max_index) {
            continue;
        }

        // Step 4b: Calculate the number of operations needed
        operations += card_index[card] - max_index;

        // Step 4c: Update the maximum index
        max_index = card_index[card];
    }

    // Step 5: Output the total number of operations
    return operations;
}

int main() {
    // Input reading
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    // Output the result
    int result = min_operations(n, a, b);
    cout << result << endl;

    return 0;
}
