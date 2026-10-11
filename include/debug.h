// debug.h — só é incluído localmente (compilado com -DLOCAL).
// Uso:  dbg(x);  dbg(n, v, mp);   → imprime no stderr, em verde, com a linha.
// Funciona com: números, strings, char, bool, pair, tuple, vector, set, map,
// array, deque, bitset, queue, stack, priority_queue e contêineres aninhados.
#pragma once
#include <bits/stdc++.h>

namespace cpdbg {

template <class T> void print(const T& x);
template <class A, class B> void print(const std::pair<A, B>& p);
template <class... Ts> void print(const std::tuple<Ts...>& t);
template <class T, class C> void print(std::queue<T, C> q);
template <class T, class C> void print(std::stack<T, C> s);
template <class T, class C, class Cmp> void print(std::priority_queue<T, C, Cmp> pq);
template <size_t N> void print(const std::bitset<N>& b);
inline void print(const std::string& s);
inline void print(const char* s);
inline void print(char c);
inline void print(bool b);

inline void print(const std::string& s) { std::cerr << '"' << s << '"'; }
inline void print(const char* s) { std::cerr << '"' << s << '"'; }
inline void print(char c) { std::cerr << '\'' << c << '\''; }
inline void print(bool b) { std::cerr << (b ? "true" : "false"); }
template <size_t N> void print(const std::bitset<N>& b) { std::cerr << b; }

template <class A, class B> void print(const std::pair<A, B>& p) {
    std::cerr << '(';
    print(p.first);
    std::cerr << ", ";
    print(p.second);
    std::cerr << ')';
}

template <class... Ts> void print(const std::tuple<Ts...>& t) {
    std::cerr << '(';
    std::apply([](const auto&... xs) {
        int i = 0;
        ((std::cerr << (i++ ? ", " : ""), print(xs)), ...);
    }, t);
    std::cerr << ')';
}

template <class T, class C> void print(std::queue<T, C> q) {
    std::cerr << "queue{";
    for (bool first = true; !q.empty(); q.pop(), first = false) {
        if (!first) std::cerr << ", ";
        print(q.front());
    }
    std::cerr << '}';
}

template <class T, class C> void print(std::stack<T, C> s) {
    std::cerr << "stack(topo→){";
    for (bool first = true; !s.empty(); s.pop(), first = false) {
        if (!first) std::cerr << ", ";
        print(s.top());
    }
    std::cerr << '}';
}

template <class T, class C, class Cmp> void print(std::priority_queue<T, C, Cmp> pq) {
    std::cerr << "pq{";
    for (bool first = true; !pq.empty(); pq.pop(), first = false) {
        if (!first) std::cerr << ", ";
        print(pq.top());
    }
    std::cerr << '}';
}

template <class T>
concept Streamable = requires(std::ostream& os, const T& x) { os << x; };
template <class T>
concept Iterable = requires(const T& x) { std::begin(x); std::end(x); };

template <class T> void print(const T& x) {
    if constexpr (Streamable<T>) {
        std::cerr << x;
    } else if constexpr (Iterable<T>) {
        std::cerr << '{';
        bool first = true;
        for (const auto& e : x) {
            if (!first) std::cerr << ", ";
            first = false;
            print(e);
        }
        std::cerr << '}';
    } else {
        std::cerr << "<?>";
    }
}

inline void print_all(const char* names) { (void)names; }

template <class T, class... Rest>
void print_all(const char* names, const T& x, const Rest&... rest) {
    // Separa os nomes na vírgula de nível zero (ignora vírgulas dentro de (), {}, <>, "")
    int depth = 0;
    bool in_str = false;
    const char* p = names;
    for (; *p; ++p) {
        char c = *p;
        if (c == '"' && (p == names || p[-1] != '\\')) in_str = !in_str;
        if (in_str) continue;
        if (c == '(' || c == '{' || c == '[' || c == '<') depth++;
        else if (c == ')' || c == '}' || c == ']' || c == '>') depth--;
        else if (c == ',' && depth == 0) break;
    }
    std::cerr << std::string_view(names, p - names) << " = ";
    print(x);
    if constexpr (sizeof...(rest) > 0) {
        std::cerr << " │ ";
        while (*p == ',' || *p == ' ') ++p;
        print_all(p, rest...);
    }
}

}  // namespace cpdbg

#define dbg(...)                                                        \
    do {                                                                \
        std::cerr << "\033[32m[" << __LINE__ << "] ";                   \
        cpdbg::print_all(#__VA_ARGS__, __VA_ARGS__);                    \
        std::cerr << "\033[0m" << std::endl;                            \
    } while (0)
