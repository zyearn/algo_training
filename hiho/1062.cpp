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

struct Node {
    string name;
    Node *next;
};

Node nodes[201];
int ci;

Node* find(Node *pa, Node *pb) {
    Node *pai = pa, *pbi = pb;

    while (pai != pbi) {
        pai = pai->next;
        pbi = pbi->next;

        if (!pai && !pbi) return NULL;
        if (!pai) pai = pb;
        if (!pbi) pbi = pa;
    }

    return pai;
}

int main() {
    int n, m;
    string f, s;
    map<string, Node*> mp;

    scanf("%d\n", &n);
    for (int i=0; i<n; i++) {
        cin >> f >> s;

        if (mp.find(f) == mp.end()) {
            mp[f] = &nodes[ci++];
            mp[f]->name = f;
        }

        if (mp.find(s) == mp.end()) {
            mp[s] = &nodes[ci++];
            mp[s]->name = s;
        }
        
        Node *pf = mp[f];
        Node *ps = mp[s];
        ps->next = pf;
    }

    scanf("%d\n", &m);
    string a, b;
    for (int i=0; i<m; i++) {
        cin >> a >> b;
        Node *pa = mp[a];
        Node *pb = mp[b];
        if (!pa || !pb) {
            if (a != b) cout << "-1" << endl;
            else cout << a << endl;

            continue;
        }

        Node *res = find(pa, pb);
        if (res) {
            cout << res->name << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
