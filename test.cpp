#include <cstdio>
#include <cstdlib>
#include <cstring>

struct trieNode {
    trieNode *t[26];
    int isEnd;
    int times;
};

int main() {
    int n, m;
    char strbuf[20];
    trieNode *root = (trieNode *)malloc(sizeof(trieNode));
    trieNode *tmp;
    int index;
    int size;

    memset(root, 0, sizeof(trieNode));
    scanf("%d\n", &n);
    for (int i=0; i<n; i++) {
        fgets(strbuf, 20, stdin);
        tmp = root;
        size = strlen(strbuf)-1;

        for (int j=0; j<size; j++) {
            index = strbuf[j] - 'a';
            if (!tmp->t[index]) {
                tmp->t[index] = (trieNode *)malloc(sizeof(trieNode));
                memset(tmp->t[index], 0, sizeof(trieNode));
            }
            
            tmp->times++;
            tmp = tmp->t[index];
        }
        tmp->times++;
        tmp->isEnd = 1;
    }

    scanf("%d\n", &m);
    int found;
    for (int i=0; i<m; i++) {
        fgets(strbuf, 20, stdin);
        tmp = root;
        size = strlen(strbuf)-1;
        found = 0;

        for (int j=0; j<size; j++) {
            index = strbuf[j] - 'a';
            if (!tmp->t[index]) {
                printf("0\n");
                found = 1;
                break;
            }
            tmp = tmp->t[index];
        }

        if (!found) {
            printf("%d\n", tmp->times);
        }
    }

}
