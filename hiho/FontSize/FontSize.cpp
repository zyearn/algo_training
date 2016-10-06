#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int tasks;
    int N, P, W, H;
    int a[1001];
    int l, h, s;

    scanf("%d\n", &tasks);


    for (int i=0; i<tasks; i++) {
        scanf("%d %d %d %d\n", &N, &P, &W, &H);
        
        for (int j=0; j<N; j++) {
            scanf("%d\n", &a[j]);
        }

        l = 1;
        h = min(W, H);
        int suc;

        while (l <= h) {
            s = l + (h - l) / 2;
            int ws = W/s;
            int sum = 0;
            for (int k=0; k<N; k++) {
                sum += (a[k] + ws - 1) / ws;
            }

            if (sum <= P * (H/s)) {
                l = s+1;
            } else {
                h = s-1;
            }
        }

        printf("%d\n", l-1);
    }

    return 0;
}
