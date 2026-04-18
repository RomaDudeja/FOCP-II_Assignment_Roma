#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];

        map<int,int> freq;
        for (int x : a) freq[x]++;

        vector<int> odd;

        for (auto &p : freq) {
            if (p.second % 2 == 1) {
                odd.push_back(p.first);
            }
        }

        sort(odd.begin(), odd.end(), greater<int>());

        int alex = 0, bob = 0;

        for (int i = 0; i < odd.size(); i++) {
            if (i % 2 == 0) alex += odd[i];
            else bob += odd[i];
        }

        if (alex > bob) cout << "Alex\n";
        else if (bob > alex) cout << "Bob\n";
        else cout << "Tie\n";
    }

    return 0;
}
