#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, r, d, X, Y;
double result = 0;
vector<pair<int, int>> tower;
vector<int> reach; // ���� ������ Ÿ������ idx value
vector<int> notReach; // �������� ���ϴ� Ÿ������ idx value
int visited[51];
double dist(int x1, int y1, int x2, int y2);
void bfs(int idx);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r >> d >> X >> Y;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tower.push_back({x, y});

        // ���� �Ÿ� �ȿ� �ִ��� ����
        if(dist(x, y, X, Y) <= r) {
            result += d;
            reach.push_back(i);
        }
        else {
            notReach.push_back(i);
        }
    }

    solve();

    return 0;
}

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y2 - y1), 2));
}

void bfs(int idx) {
    queue<int> q;

    q.push(idx);
    visited[idx] = 0;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int i = 0; i < n; i++) {
            // �ڱ� �ڽ��� dest�� �Ǵ� ��� ����
            if(now == i) {
                continue;
            }

            // ���� �ش� Ÿ���� �Ÿ��� �����Ÿ� �̳��̸鼭, �̹� �湮���� ���� �����
            if(dist(tower[now].first, tower[now].second, tower[i].first, tower[i].second) <= r && !visited[i]) {
                q.push(i);
                visited[i] = visited[now] + 1;
            }
        }
    }
}

void solve() {
    // ž���� ���� ���ϴ� ������ ���� BFS ����
    for(int i = 0; i < notReach.size(); i++) {
        memset(visited, 0, sizeof(visited));
        
        bfs(notReach[i]);

        int minCnt = 987654321;
        for(int j = 0; j < reach.size(); j++) {
            if(visited[reach[j]] != 0) {
                minCnt = min(visited[reach[j]], minCnt);
            }
        }    

        result += (double)d / pow(2, minCnt);
    }

    cout << fixed;
    cout.precision(2);
    cout << result << endl;
}