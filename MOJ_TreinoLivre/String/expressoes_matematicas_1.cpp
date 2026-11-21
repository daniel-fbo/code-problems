#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    stack <int> pilha;
    bool perfeito = true;
    int c;

    while ((c = cin.get()) != EOF && c != '\n')
    {
        if (c == 40 || c == 91 || c == 123) pilha.push(c);
        if (c == 41 || c == 93 || c == 125)
        {
            if (pilha.empty())
            {
                perfeito = false;
                break;
            }
            int topo = pilha.top();
            pilha.pop();

            if ((c == 41 && topo != 40) || (c == 93 && topo != 91) || (c == 125 && topo != 123))
            {
                perfeito = false;
                break;
            }
        }
    }
    if (!pilha.empty()) perfeito = false;

    cout << (perfeito ? "sim" : "nao") << '\n';
    return 0;
}
