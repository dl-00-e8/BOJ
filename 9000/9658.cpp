#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int n;
int dp[1001][3];
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    cin >> n;

    if(n % 7 == 1 || n % 7 == 3) {
        cout << "CY" << endl;
    }
    else {
        cout << "SK" << endl;
    }

    return 0;
}

/*
���� �̷п� ���� ����
https://www.acmicpc.net/board/view/26161

�� 1��
-> ������ ��� �й� (�������� �ϹǷ�)

�� 2��
��� 1�� -> â�� �й�

�� 3��
��� 1�� -> â�� 1�� -> ��� �й�

�� 4��
��� 3�� -> â�� �й�

�� 5��
��� 4�� -> â�� �й�

�� 6��
��� 3�� -> â�� 1�� -> ��� 1�� -> â�� �й�

�� 7��
��� 4�� -> â�� 1�� -> ��� 1�� -> â�� �й�

�� 8��
��� 4�� -> â�� 3�� -> ��� �й�
��� 3�� -> â�� 4�� -> ��� �й�

7���� �������� ���� �뷡 �ݺ�
*/
