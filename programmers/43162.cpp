#include <bits/stdc++.h>

using namespace std;

int visited[201];
void dfs(int x);

void dfs(int x, vector<vector<int>> computers) {
    for(int i = 0; i < computers[x].size(); i++) {
        if(computers[x][i] && !visited[i]) {
            visited[i] = visited[x];
            dfs(i, computers);
        }
    }   
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 1;
    
    memset(visited, 0, sizeof(visited));
    
    //i�� ���� i�� ��� ���� ���� ����� 0���� ����
    for(int i = 0; i < n; i++) {
        computers[i][i] = 0;
    }
    
    // DFS ����
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            visited[i] = answer;
            dfs(i, computers);
            answer++;
        }
    }
    
    return answer - 1;
}