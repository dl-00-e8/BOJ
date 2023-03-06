#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, k, up, down; // up: �ø��� ��ġ IDX, down: ������ ��ġ IDX
queue<int> robots; // robot���� IDX������ ����Ǿ� ����.
int belt[202];
bool visited[202];
void rotate();
bool canMove(int idx);
void move();
void upRobot();
bool check();
int solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visited, 0, sizeof(visited));

    // Input
    cin >> n >> k;
    for(int i = 1; i < 2 * n + 1; i++) {
        cin >> belt[i];
    }

    // Output
    cout << solve() << endl;

    return 0;
}

void rotate() {
    up--;
    down--;

    if(up == 0) {
        up = 2 * n;
    }

    if(down == 0) {
        down = 2 * n;
    }

    if(visited[down]) {
        while(true) {
            int now = robots.front();

            robots.pop();

            if(now != down) {
                robots.push(now);
            }
            else {
                break;
            }
        }
    }
    visited[down] = false;
}

bool canMove(int idx) {
    bool result = true;
    
    if(visited[idx]) {
        result = false;
    }

    if(belt[idx] <= 0) {
        result = false;
    }

    return result;
}

void move() {
    int qSize = robots.size();

    for(int i = 0; i < qSize; i++) {
        int now = robots.front();
        visited[now] = false;
        robots.pop();

        int next;
        if(now == 2 * n) {
            next = 1;
        }    
        else {
            next = now + 1;
        }
        if(canMove(next)) {
            belt[next]--;
            if(next != down) {
                visited[next] = true;
                robots.push(next);
            }   
        }
        else {
            visited[now] = true;
            robots.push(now);
        }
    }
}

void upRobot() {
    if(belt[up] > 0 && !visited[up]) {
        robots.push(up);
        belt[up]--;
        visited[up] = true;
    }
}

bool check() {
    int cnt = 0;
    
    for(int i = 1; i < 2 * n + 1; i++) {
        if(belt[i] == 0) {
            cnt++;
        }

        if(cnt >= k) {
            return false;
        }
    }

    return true;
}

int solve() {
    int answer = 0;

    up = 1;
    down = n;

    // ������� �ʴ´ٸ� ��� �ݺ�
    int num = 0;
    while(true) {
        // 1�ܰ�
        rotate();

        // 2�ܰ�
        move();

        // 3�ܰ�
        upRobot();

        // 4�ܰ�
        answer++;
        if(!check()) {
            break;
        }
    }

    return answer;
}