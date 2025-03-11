#include "Comb.h"

long long fact(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

long long A(int n, int k) {
    return fact(n) / fact(n - k);
}

long long _A(int n, int k) {
    return pow(n, k);
}

long long C(int n, int k) {
    return fact(n) / (fact(k) * fact(n - k));
}

long long _C(int n, int k) {
    return C(n + k - 1, k);
}

bool GenPerm(vi& A) {
    int n = A.size();
    int i = n - 2;
    while (i >= 0 && A[i] >= A[i + 1]) i--;
    if (i < 0) return 0;
    if (i >= 0) {
        int j = n - 1;
        while (A[j] <= A[i]) j--;
        swap(A[i], A[j]);
    }
    reverse(A.begin() + i + 1, A.end());
    return 1;
}

bool GenComb(vi& A, int n, int k) {
    int i = k - 1;
    while (i >= 0 && A[i] == n - k + i + 1) i--;
    if (i<0) return 0;
    if (i >= 0) {
        A[i]++;
        for (int j = i + 1; j < k; ++j)
            A[j] = A[j - 1] + 1;
    }
    return 1;
}
