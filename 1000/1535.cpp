#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n, condition;
int dp[21][101];
vector<int> lost;
vector<int> delight;
int solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    condition = 100;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        lost.push_back(input);
    }
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        delight.push_back(input);
    }

    cout << solve() << endl;

    return 0;
}

int solve() {
    int result = 0; // �ִ� ���
    
    memset(dp, 0, sizeof(dp)); // dp���̺� �ʱ�ȭ

    for(int i = 1; i < n + 1; i++) {
        for(int j = 0; j < 100; j++) {
            if(lost[i - 1] <= j) {
                if(delight[i - 1] + dp[i - 1][j - lost[i - 1]] > dp[i - 1][j]) {
                    dp[i][j] = dp[i - 1][j - lost[i - 1]] + delight[i - 1];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }

            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    result = *max_element(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(int));

    return result;
}

/*
���� : ü���� ���� -> ����� ����
�������� ü���� 0�̳� ������ �Ǳ� ������ �� ������� �� ������ �λ簡 ������.
*/