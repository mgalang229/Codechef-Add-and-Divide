#include <bits/stdc++.h>

using namespace std;

vector<int> GetPrimeFactors(int n) {
    vector<int> prime;
    while (n % 2 == 0) {
        prime.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            prime.push_back(i);
            n /= i;
        }
    }
    if (n > 2) {
        prime.push_back(n);
    }
    return prime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b;
        cin >> a >> b;
        // view the image in this repository for better understanding
        // (b ^ n) must be divisible by a for some n >= 1
        vector<int> factors = GetPrimeFactors(a);
        bool checker = true;
        for (int i = 0; i < (int) factors.size(); i++) {
            checker &= (b % factors[i] == 0);
        }
        cout << (checker ? "YES" : "NO") << '\n';
    }
    return 0;
}
