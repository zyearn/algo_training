#include <map>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

#define mpr make_pair
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <double, double> pdd;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <double> vd;
typedef vector <string> vs;
typedef map <string, int> mpsi;
typedef map <double, int> mpdi;
typedef map <int, int> mpii;

struct compare  {  
    // 最小化堆
    bool operator()(const int& l, const int& r) {
        return l > r;  
    }  
}; 

typedef priority_queue<int, vector<int>, compare > pq;  

double pi = acos(0.0) * 2.0;
long double eps = 1e-10;

inline bool isAlpha(char a) {
    return a >= 'A' && a<= 'Z';
}

inline bool isZero(double x) {
    if (x < eps && x > -eps) {
        return true;
    }

    return false;
}

template <class T> inline T abs1(T a) {return a < 0 ? -a : a;}

template <class T> inline T max1(T a, T b) { return b < a ? a : b; }
template <class T> inline T max1(T a, T b, T c) { return max1(max1(a, b), c); }
template <class T> inline T max1(T a, T b, T c, T d) { return max1(max1(a, b, c), d); }
template <class T> inline T max1(T a, T b, T c, T d, T e) { return max1(max1(a, b, c, d), e); }
template <class T> inline T min1(T a, T b) { return a < b ? a : b; }
template <class T> inline T min1(T a, T b, T c) { return min1(min1(a, b), c); }
template <class T> inline T min1(T a, T b, T c, T d) { return min1(min1(a, b, c), d); }
template <class T> inline T min1(T a, T b, T c, T d, T e) { return min1(min1(a, b, c, d), e); }

long long pow(long long n, long long m, long long mod = 0){
	if(m < 0) return 0;
	long long ans = 1 % mod;
	long long k = n;

	while(m){
		if(m & 1) {
			ans *= k;
			if(mod) ans %= mod;
		}
		k *= k;
		if(mod) k %= mod;
		m >>= 1;
	}

	return ans;
}

/**
 * 
 * read int: scanf("%d\n", &t);
 * read str: fgets(buf, sizeof(buf), stdin);
 * 迭代器用auto
 * printf("%lld", t)
 *
 */

class UF {
    private:
        int *f;
        int *rank;
        int len;
    public:
        UF(int n) {
            f = new int[n];
            rank = new int[n];
            len = n;

            for (int i=0; i<n; i++) {
                f[i] = i;
                rank[i] = 0;
            }
        }

        ~UF() {
            delete []f;
            delete []rank;
        }

        int Find(int x) {
            if (x < 0 || x >= len) {
                return -1;
            }

            if (x != f[x]) {
                return f[x] = Find(f[x]);
            } else {
                return x;
            }
        }

        void Union(int a, int b) {
            int roota = Find(a);
            int rootb = Find(b);
            if (roota == rootb) return;

            if (rank[roota] < rank[rootb]) f[roota] = rootb;
            else if (rank[roota] > rank[rootb]) f[rootb] = roota;
            else {
                f[rootb] = roota;
                rank[roota]++;
            }
        }

        bool Connected(int a, int b) {
            return Find(a) == Find(b);
        }
};

int t, n;

int main() {
    scanf("%d\n", &t);
    string n1, n2;
    map<string, int> nameton;
    int gi = 0;
    UF uf(200000);

    for (int i=0; i<t; i++) {
        cin >> n >> n1 >> n2;
        if (nameton.find(n1) == nameton.end()) {
            nameton.insert(pair<string, int>(n1, gi));
            gi++;
        }

        if (nameton.find(n2) == nameton.end()) {
            nameton.insert(pair<string, int>(n2, gi));
            gi++;
        }

        if (n == 0) {
            uf.Union(nameton[n1], nameton[n2]);
        } else {
            if (uf.Connected(nameton[n1], nameton[n2])) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
            
        }
    }

    return 0;
}
