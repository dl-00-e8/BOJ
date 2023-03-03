#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int k, v, e;
bool check;
int visited[20001];
vector<int> graph[20001];
void dfs(int x, int num);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    while(k--) {
        cin >> v >> e;

        // Setting �ʱ�ȭ
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < e; i++) {
            int a, b;

            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        solve();
    }

    return 0;
}

void dfs(int x, int num) {
    visited[x] = num;

    for(int i = 0; i < graph[x].size(); i++) {
        if(visited[graph[x][i]] == num) {
            check = true;
            return ;
        }

        if(visited[graph[x][i]] == 0) {
            dfs(graph[x][i], num * -1);
        }
    }
}

void solve() {
    check = false;

    for(int i = 1; i < v + 1; i++) {
        if(visited[i] == 0) {
            dfs(i, 1);
        }

        if(check) {
            break;
        }
    }


    if(check) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}

/*
��ó + ���� ���۷���
- https://www.acmicpc.net/problem/1707
- https://gmlwjd9405.github.io/2018/08/23/algorithm-bipartite-graph.html
- https://hongjw1938.tistory.com/117  

�̺� �׷���(Bipartite Graph)
: ������ �������� ���� �ٸ� ������ ĥ�ؼ� ��� ������ �� ���� �����θ� ĥ�� �� �ִ� �׷���
-> �׷����� ��� ������ �� �׷����� ��������, ���� �ٸ� �׷��� ������ �������� ����Ǿ� �ִ� �׷���
-> �׷����� ��� ������ �� �׷����� ��������, ���� �׷쿡 ���� ���������� ���� �������� �ʵ��� �ϴ� �׷���
*/