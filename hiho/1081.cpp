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

int N, E, s, e;
struct Edge {
    int node;
    int weight;
    struct Edge *next;
};

struct Node {
    Edge *e;
};

struct Entity {
    int to;
    int sp;
};

struct compare  {  
    // 最小化堆
    bool operator()(const Entity &l, const Entity &r) {
        return l.sp> r.sp;
    }  
}; 

typedef priority_queue<Entity, vector<Entity>, compare > pq;  

Edge edges[10001];
Node nodes[1001];
int ei;

int visited[1001];

int main() {
    scanf("%d %d %d %d\n", &N, &E, &s, &e);
    int a, b, w;
    map<int, int> m;

    for (int i=0; i<E; i++) {
        scanf("%d %d %d\n", &a, &b, &w);

        if (b > a) {
            int tmp = a;
            a = b;
            b = tmp;
        }

        int num = a * 10000 + b;
        if (m.find(num) == m.end()) {
            m[num] = w;
        } else {
            if (w < m[num]) {
                m[num] = w;
            }
        }
    }

    Edge *tmp;
    for (auto it=m.begin(); it!=m.end(); it++) {
        int a = it->first / 10000;
        int b = it->first % 10000;
        int w = it->second;
            
        tmp = nodes[a].e;
        edges[ei].node = b;
        edges[ei].weight = w;
        edges[ei].next = tmp;
        nodes[a].e = &edges[ei];
        ei++;

        int t = a; a=b; b=t;
        tmp = nodes[a].e;
        edges[ei].node = b;
        edges[ei].weight = w;
        edges[ei].next = tmp;
        nodes[a].e = &edges[ei];
        ei++;
    }

    pq p;
    visited[s] = 1;
    tmp = nodes[s].e;
    while (tmp) {
        Entity et;
        et.to = tmp->node;
        et.sp = tmp->weight;
        p.push(et);
        tmp = tmp->next;
    }

    while (!p.empty()) {
        Entity et = p.top();
        p.pop();
        if (visited[et.to]) {
            continue;
        }

        visited[et.to] = 1;
        if (et.to == e) {
            cout << et.sp <<endl;
            break;
        }
        int cursp = et.sp;
        Edge *tmp = nodes[et.to].e;
        while (tmp) {
            Entity et;
            et.to = tmp->node;
            et.sp = cursp + tmp->weight;

            if (!visited[et.to]) {
                p.push(et);
            }
            tmp = tmp->next;
        }
    }

    return 0;
}
