#include <iostream>
#include <cmath>
using namespace std;

int binom(int n, int k) {
    if (n < k) {
        return 0;
    } else if (k == 0 || k == n){
        return 1;
    }else {
        return binom(n-1, k) + binom(n-1, k-1);
    }
}

int coefficient(int n, int k) {
    int m = floor(n/10);
    int sum = 0;
    for (int i = 0; i <= m; i++) {
        sum += pow(-1, i)*binom(n - 10*i + k - 1, k -1)*binom(k, i);
    }
    return sum;
}

int solution_count(int k) {
    int sum = 0;
    for (int n = 3; n <= 9*k; n+= 3) {
        sum += coefficient(n, k);
    }
    return sum;
}

int main() {
    int k;
    cout << "Enter k: ";
    cin >> k;
    int solution = solution_count(k) - solution_count(k-1);
    cout << solution;
}