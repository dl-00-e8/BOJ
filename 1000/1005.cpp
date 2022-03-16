#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int t, n, k, w;
int build[1001]; // �ǹ� ���� ���
int indigree[1001]; // ��������
int result[1001]; // ��� ���
vector<int> graph[1001]; // ���� ����
int solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        memset(build, 0, sizeof(build));
        memset(indigree, 0, sizeof(indigree));
        memset(result, 0, sizeof(result));
        for(int i = 0; i < 1001; i++) {
            graph[i].clear();
        }

        cin >> n >> k;
        for(int i = 1; i < n + 1; i++) {
            cin >> build[i];
        }
        for(int i = 0; i < k; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            indigree[y]++;
        }
        cin >> w;

        cout << solve() << endl;
    }

    return 0;
}

int solve() {
    // first : ���� �������� �ð�, second : idx
    priority_queue<int, vector<int>, greater<int>> pq;

    // ���� ������ 0�� ������ pq�� ����
    for(int i = 1; i < n + 1; i++) {
        if(indigree[i] == 0) {
            pq.push(i);
            result[i] = build[i];
        }
    }

    // toplogy sort ����
    while(!pq.empty()) {
        int now = pq.top();
        pq.pop();

        for(auto visit : graph[now]) {
            result[visit] = max(result[visit], result[now] + build[visit]);
            
            indigree[visit]--;
            if(indigree[visit] == 0) {
                pq.push(visit);
            }
        }
    }

    return result[w];
}