#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define INF 987654321

int n;
vector<pair<int, int>> node;
double calc (int x1, int y1, int x2, int y2);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        
        cin >> x >> y;
        node.push_back({x, y});
    }

    solve();

    return 0;
}

double calc (int x1, int y1, int x2, int y2) {
    return sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
}

void solve() {
    int answer = 0;
    double result = INF;

    for(int i = 0; i < n; i++) {
        double dist = 0;

        for(int j = 0; j < n; j++) {
            if(i == j) {
                continue;
            }

            dist = max(dist, calc(node[i].first, node[i].second, node[j].first, node[j].second));
        }

        if(result > dist) {
            result = dist;
            answer = i;
        }
    }


    cout << node[answer].first << " " << node[answer].second << endl;
}

/*
���ǽü� ���� ���� ��� �����ϴٴ� ���� ����ؾ� �Ѵ�.
�׷��� ������, O(N^2)�� �ذᰡ��
������ �ִ� N�� 10^
*/