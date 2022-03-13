#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int N, r, c;
int recursive(int seung, int x, int y, int value); // seung : �� ��, x : ���� x ��ǥ, y : ���� y ��ǥ, value : ���� ��ǥ�� ������ ��

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> r >> c;

    cout << recursive(N, 0, 0, 0) << endl;

    return 0;
}

int recursive(int seung, int x, int y, int value) {
    // �ش� �ڽ��� ���� �ȿ� ���� ���
    if(x <= r && r < x + 2 && y <= c && c < y + 2) {
        if(x == r) {
            if(y == c) {
                return value;
            }
            else if(y + 1 == c) {
                return value + 1;
            }
        }
        else if(x + 1== r) {
            if(y == c) {
                return value + 2;
            }
            else if(y + 1 == c) {
                return value + 3;
            }
        }
    }

    //divide & conquer �κ� �ۼ�
    int move = pow(2, seung - 1);
    if(x <= r && r < x + move && y <= c && c < y + move){
        return recursive(seung - 1, x, y, value);
    }
    else if(x + move <= r && r < x + (move * 2) && y <= c && c < y + move) {
        return recursive(seung - 1, x + move, y, value + (pow(4, seung - 1) * 2));
    }
    else if(x <= r && r < x + move && y + move <= c && c < y + (move * 2)) {
        return recursive(seung - 1, x, y + move, value + pow(4, seung - 1));
    }
    else if(x + move <= r && r < x + (move * 2) && y + move <= c && c < y + (move * 2)) {
        return recursive(seung - 1, x + move, y + move, value + (pow(4, seung - 1) * 3));
    }


    return 0;
}

/*
4�� 15�¿� ���� 2���� �迭�� �����ϴ� ���� �Ұ���
���� : 4^15 > 10��
memoization���� Ǯ �� �ִ°�?

r, c ��ǥ�� ����� �����ٴ� ���ε�
4�� ����� �������� ��, ��� �������� �̿��ؼ� ���Ѵ�.
*/