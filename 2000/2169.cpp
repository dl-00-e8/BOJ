#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF -100000001

int n, m;
int dx[] = {1, 0, 0}; // �������� �̵� �Ұ�
int dy[] = {0, -1, 1}; // �������� �̵� �Ұ�
int graph[1001][1001];
bool visited[1001][1001];
int dp[1001][1001][3];
int dfs(int x, int y, int dir);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    fill(&dp[0][0][0], &dp[0][0][0] + sizeof(dp) / sizeof(int), INF);

    cin >> n >> m;
    for(int i = 1; i < n + 1; i++) {
        for(int j = 1; j < m + 1; j++) {
            cin >> graph[i][j];
        }
    }

    cout << dfs(1, 1, 0) << endl;

    return 0;
}

int dfs(int x, int y, int dir) {
    if(x == n && y == m) {
        return dp[x][y][dir] = graph[x][y];
    }

    if(dp[x][y][dir] != INF) {
        return dp[x][y][dir];
    }

    visited[x][y] = true;
    
    int tempMax = INF;
    for(int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 1 || nx > n || ny < 1 || ny > m) {
            continue;
        }

        if(!visited[nx][ny]) {
            tempMax = max(tempMax, dfs(nx, ny, i));
        }
    }

    visited[x][y] = false;

    return dp[x][y][dir] = graph[x][y] + tempMax;
}


/* 
�������� ��� ����Ʈ
1. dp�迭�� dp[1001][1001][3];���� �����Ͽ� 3���⿡ ���� ����ó���� �����ؾ� ��.
�׷���, dp[1001][1001]�� �ذ��ϰ��� �Ͽ���.

2. �ᱹ DFS�� ���� ���� dp�迭�� dp[n][m][?]���� ���۵Ǵ� ����.
DFS + DP�� ��Ȯ�� �۵� ������ ���� ���ص��� �������� ����.
DP������ ���� �Ƿ� ����
*/