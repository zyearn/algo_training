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

int t, n;
string s;
string words[] = {"A", "B", "C"};

int work(string s) {
    int c = 0;
    int size = s.size();
    if (size == 0) return 0;

    while (1) {
        string news;
        bool isFirst = true;
        for (int i=1; i<s.size(); i++) {
            if (s[i] != s[i-1]) {
                if (isFirst) {
                    news.push_back(s[i-1]);
                } else {
                    isFirst = true;
                }
            } else {
                isFirst = false;
            }
        }

        if (isFirst && s.size() > 0) {
            news.push_back(s[s.size()-1]);
        }
        //cout << "news = " << news << endl;

        if (news.size() == s.size()) {
            break;
        }

        s = news;
    } 

    return size - s.size();
}

int main() {
    scanf("%d\n", &t);
    string ss;

    for (int i=0; i<t; i++) {
        cin >> s;
        int size = s.size();
        int curMax = 0;

        for (int j=0; j<3; j++) {
            for (int k=0; k<=size; k++) {
                ss = s;
                ss.insert(k, words[j]);
                int w = work(ss);
                //cout << "ready to work " << ss << " :" << w << endl;
                
                curMax = max(curMax, w);
            }
        }

        printf("%d\n", curMax);
    }

    return 0;
}
