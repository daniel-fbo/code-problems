#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string s(N,' ');
    for (int i = 0; i < N/2; i++) {
        cin >> s[i];
    }

    char temp;
    if (N % 2 == 1) cin >> temp;
    for (int i = (N+1)/2; i < N; i++) {
        cin >> temp;
        if (temp != s[N-i-1]) {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';
    return 0;
}