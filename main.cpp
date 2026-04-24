// Problem 102 - Arbitrary base fixed-width string addition
#include <bits/stdc++.h>
using namespace std;

static inline int val_of(char c){
    if(c >= '0' && c <= '9') return c - '0';
    if(c >= 'A' && c <= 'Z') return c - 'A' + 10;
    if(c >= 'a' && c <= 'z') return c - 'a' + 10;
    return 0;
}

static inline char char_of(int v){
    if(v < 10) return char('0' + v);
    return char('A' + (v - 10));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long m, n; int B;
    if(!(cin >> m >> n >> B)) return 0;
    string s1, s2;
    if(!(cin >> s1)) return 0;
    if(!(cin >> s2)) return 0;

    const size_t L1 = s1.size();
    const size_t L2 = s2.size();
    const size_t W = max(L1, L2);

    string res(W, '0');
    int carry = 0;
    for(size_t i = 0; i < W; ++i){
        int a = 0, b = 0;
        if(i < L1) a = val_of(s1[L1 - 1 - i]);
        if(i < L2) b = val_of(s2[L2 - 1 - i]);
        int sum = a + b + carry;
        int digit = sum % B;
        carry = sum / B;
        res[W - 1 - i] = char_of(digit);
    }

    cout << res << "\n";
    return 0;
}
