#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <cmath>

using namespace std;

pair<int, int> solve(int length, const vector<int>& mixed_grids) {
    int k = length - 2;
    unordered_map<int, int> counts;
    unordered_set<int> mixed_grids_set;

    for (int num : mixed_grids) {
        counts[num]++;
        mixed_grids_set.insert(num);
    }

    for (int a = 1; a <= sqrt(k); ++a) {
        if (k % a == 0) {
            int b = k / a;
            if (mixed_grids_set.count(a) && mixed_grids_set.count(b)) {
                if (a == b && counts[a] < 2) {
                    continue;
                }
                return {a, b};
            }
        }
    }
    return {-1, -1};
}

int main() {
    int count;
    cin >> count;

    for (int i = 0; i < count; ++i) {
        int length;
        cin >> length;
        vector<int> mixed_grids(length);
        for (int j = 0; j < length; ++j) {
            cin >> mixed_grids[j];
        }
        pair<int, int> result = solve(length, mixed_grids);
        if (result.first != -1) {
            cout << result.first << " " << result.second << endl;
        }
    }

    return 0;
}
