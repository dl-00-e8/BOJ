#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int t, a, b;
vector<string> answer;
int calc(char c, int num); // DSLR ���� �Լ�
void solve(int a, int b); // TC�� ������ �Լ�

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> a >> b;
        solve(a, b);
    }

    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}

int calc(char c, int num) {
    if(c == 'D') {
        num *= 2;

        if(num > 9999) {
            num %= 10000;
        }
    }
    else if(c == 'S') {
        if(num == 0) {
            num = 9999;
        }
        else {
            num -= 1;
        }
    }
    else if(c == 'L') {
        int temp = num;

        num = (temp / 1000) + ((temp % 1000) * 10);
    }
    else if(c == 'R') {
        int temp = num;

        num = (temp / 10) + ((temp % 10) * 1000);
    }

    return num;
}

void solve(int a, int b) {
    int tempNum;
    string result = "";
    queue<pair<int, string>> q;
    char dir[] = {'D', 'S', 'L', 'R'};
    bool visited[10001];
    
    memset(visited, 0, sizeof(visited));

    q.push({a, ""});
    visited[a] = true;

    while(!q.empty()) {
        int nowNum = q.front().first;
        string nowString = q.front().second;
        q.pop();

        if(nowNum == b) {
            answer.push_back(nowString);
            break;
        }

        for(int i = 0; i < 4; i++) {
            tempNum = calc(dir[i], nowNum);

            if(!visited[tempNum]) {
                visited[tempNum] = true;
                q.push({tempNum, nowString + dir[i]});
            }
            
        }
    }

    // cout << result << endl;
}

/*
�ð� �ʰ��� �߻��ϴ� ���� : string ����
string���縦 ������ �ݺ����� �ʵ��� 
C++���� string �� += ������ O(K)�̴�.
C++���� string �� + ������ O(N+K)�̴�.

s = s + "A"; --> O(N^2)�� �ð����⵵�� ����

���� �������� �ٽ��� string ���簡 �ð����⵵�� ���� ��ƸԴ´ٴ� ���ε�,
�̸� �ٸ� ������ �����ؼ� �ٽ� �Ѱ��ִ� ������ �ƴ�
�ٷ� �Ѱ��ִ� ������ ���ؼ� �ð����⵵�� �ּ�ȭ�Ͽ��� ��
*/