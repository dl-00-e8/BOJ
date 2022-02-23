#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define maxNum 100,000

int n, m;
vector<int> num;
vector<int> tree;
int init(int start, int end, int node);
int findMin(int start, int end, int node, int left, int right);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    tree.resize(4 * n);
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        num.push_back(input);
    }

    init(0, n -1, 1);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << findMin(0, n - 1, 1, a - 1, b - 1) << endl;
    }

    return 0;
}

// start : ���� idx, end : ������ idx
int init(int start, int end, int node) {
    if(start == end) {
        return tree[node] = num[start];
    }
    int mid = (start + end) / 2;
    
    // �� ���� �� �ּڰ��� �ش� ����� ���� ��
    return tree[node] = min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

// start : ���� idx, end : �� idx, left, right : �ּڰ��� ���ϴ� ����
int findMin(int start, int end, int node, int left, int right) {
    // ���� �ۿ� �ִ� ���
    if(left > end || right < start) return 1000000001;
    
    // ���� �ȿ� �ִ� ���
    if(left <= start && end <= right) return tree[node];
    
    // ������ �� �ɰ��� �ϴ� ���
    int mid = (start + end) / 2;
    return min(findMin(start, mid, node * 2, left, right), findMin(mid + 1, end, node * 2 + 1, left, right));
}