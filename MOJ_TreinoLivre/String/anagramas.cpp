#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    vector <char> string1, string2;
    char c;

    while (cin.get(c) && c != '\n') {
        if (c == ',' || c == '.' || c== ' ') continue;
        string1.push_back(c);
    }

    while ((c = cin.get()) != EOF && c != '\n') {
        if (c == ',' || c == '.' || c== ' ') continue;
        string2.push_back(c);
    }
    sort(string1.begin(), string1.end() );
    sort(string2.begin(), string2.end() );

    cout << (string1 == string2 ? "S" : "N") << '\n';

    return 0;
}
