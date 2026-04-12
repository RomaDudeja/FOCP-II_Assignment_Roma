#include <bits/stdc++.h>
using namespace std;

// Check if we can turn off all bulbs using <= m operations for given k
bool canTurnOff(string bulbs, int n, int m, int k) {
    int operations = 0;
    vector<int> turned(n, 0);  // track already turned off

    for (int i = 0; i < n; i++) {
        // if bulb is ON and not already turned off
        if (bulbs[i] == '1' && turned[i] == 0) {
            operations++;
            if (operations > m) return false;

            // turn off next k bulbs
            for (int j = i; j < min(n, i + k); j++) {
                turned[j] = 1;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    string bulbs;
    cin >> bulbs;

    int left = 1, right = n, ans = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canTurnOff(bulbs, n, m, mid)) {
            ans = mid;
            right = mid - 1; // try smaller k
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
