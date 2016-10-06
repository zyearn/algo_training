class Solution {
public:
    struct Node {
        int val;
        int i, j;
    };

    struct compare  {  
        // 最小化堆
        bool operator()(const Node& l, const Node& r) {
            return l.val > r.val;  
        }  
    }; 

    typedef priority_queue<Node, vector<Node>, compare > pq;  

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = n?matrix[0].size():0;

        if (n == 0 || m == 0) {
            return -1;
        }

        bool **isVt = new bool*[n];
        for (int i=0; i<n; i++) {
            isVt[i] = new bool[m];
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                isVt[i][j] = false;
            }
        }

        pq p;
        Node top;
        top.i = top.j = 0;
        top.val = matrix[0][0];
        p.push(top);
        isVt[0][0] = true;

        Node tmp;
        while (k-- > 0 && !p.empty()) {
            top = p.top();
            p.pop();

            if (top.i + 1 < n && !isVt[top.i+1][top.j]) {
                isVt[top.i+1][top.j] = true;
                tmp.val = matrix[top.i+1][top.j];
                tmp.i = top.i+1;
                tmp.j = top.j;
                p.push(tmp);
            }

            if (top.j + 1 < m && !isVt[top.i][top.j+1]) {
                isVt[top.i][top.j+1] = true;
                tmp.val = matrix[top.i][top.j+1];
                tmp.i = top.i;
                tmp.j = top.j+1;
                p.push(tmp);
            }
        }

        return top.val;
    }
};
