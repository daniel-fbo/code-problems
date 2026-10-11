#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <math.h>

#ifdef LOCAL
#define dbg(fmt, ...) fprintf(stderr, "\033[32m[%d] " fmt "\033[0m\n", __LINE__, ##__VA_ARGS__)
#else
#define dbg(...)
#endif

typedef long long ll;
typedef unsigned long long ull;

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/* Leitura rápida de inteiros (inclusive negativos).
   Usa getchar (portável: o Codeforces roda em Windows, sem getchar_unlocked). */
static inline ll read_ll(void) {
    int c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    bool neg = false;
    if (c == '-') { neg = true; c = getchar(); }
    ll x = 0;
    for (; c >= '0' && c <= '9'; c = getchar()) x = x * 10 + (c - '0');
    return neg ? -x : x;
}

static inline int cmp_ll(const void *a, const void *b) {
    ll x = *(const ll *)a, y = *(const ll *)b;
    return (x > y) - (x < y);
}

void solve(void) {

}

int main(void) {
    int t = 1;
    t = (int)read_ll(); /* comente se o problema tiver um único caso */
    while (t--) solve();
    return 0;
}
