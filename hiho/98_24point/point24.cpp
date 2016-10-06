#include <cstdio>
#include <vector>
#include <cmath>
using std::vector;

#define EPSILON 1e-6

int areSame(double a, double b) {
    return fabs(a - b) < EPSILON? 1: 0;
}

void swap(vector<int>&v, int i, int j) {
    int t = v[i];
    v[i] = v[j];
    v[j] = t;
}

inline double compute(double a, double b, int ops) {
    double res = 0;

    switch (ops) {
    case 0: res = a + b; break;
    case 1: res = a - b; break;
    case 2: res = a * b; break;
    case 3: if (!areSame(0, b)) res = a / b; break;
    case 4: res = b - a; break;
    case 5: if (!areSame(0, a)) res = b / a; break;
    }

    return res;
}

int calc1(vector<int> &v, vector<int> &ops) {
    double x = compute(compute(compute(v[0], v[1], ops[0]), v[2], ops[1]), v[3], ops[2]);

    return areSame(x, 24);
}

int calc2(vector<int> &v, vector<int> &ops) {
    double x = compute(compute(v[0], v[1], ops[0]), compute(v[2], v[3], ops[2]), ops[1]);

    return areSame(x, 24);
}

int permOps(vector<int> &v, vector<int> &ops, int curi) {
    if (curi == 3) {
        if (calc1(v, ops)) {
            return 1;
        }

        if (calc2(v, ops)) {
            return 1;
        }

        return 0;
    }

    for (int i=0; i<6;i++) {
        ops[curi] = i;
        if (permOps(v, ops, curi+1)) {
            return 1;
        }
    }

    return 0; 
}

int hasAnswer(vector<int> &v, int curi) {
    if (curi == 4) {
        vector<int> ops(6);
        return permOps(v, ops, 0);
    }

    for (int i=curi; i<4; i++) {
        swap(v, curi, i);

        if (hasAnswer(v, curi+1)) {
            return 1;
        }

        swap(v, curi, i);
    }

    return 0;
}

int main() {
    int n;
    vector<int> v(5);

    scanf("%d\n", &n);
    for (int i=0; i<n; i++) {
        scanf("%d %d %d %d\n", &v[0], &v[1], &v[2], &v[3]);

        if (hasAnswer(v, 0)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
    return 0;
}
