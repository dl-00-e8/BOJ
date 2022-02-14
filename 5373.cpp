#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

int t, n;
char start[6][3][3]  = {
    {
        {'w', 'w', 'w'},
        {'w', 'w', 'w'},
        {'w', 'w', 'w'}
    },
    {
        {'y', 'y', 'y'},
        {'y', 'y', 'y'},
        {'y', 'y', 'y'}
    },
    {
        {'r', 'r', 'r'},
        {'r', 'r', 'r'},
        {'r', 'r', 'r'}
    },
    {
        {'o', 'o', 'o'},
        {'o', 'o', 'o'},
        {'o', 'o', 'o'}
    },
    {
        {'g', 'g', 'g'},
        {'g', 'g', 'g'},
        {'g', 'g', 'g'}
    },
    {
        {'b', 'b', 'b'},
        {'b', 'b', 'b'},
        {'b', 'b', 'b'}
    }
}; // ��, �Ʒ�, ��, ��, ����, ������ ���� ť�� ����
char cube[6][3][3];
char temp[6][3][3];
vector<string> moveDir;
void solve(string input); //ť�� ������
void topColor(); // ���� ���� ���

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        copy(&start[0][0][0], &start[0][0][0] + sizeof(start), &cube[0][0][0]);
        for(int j = 0; j < n; j++) {
            string input;
            cin >> input;
            solve(input);
        }
        topColor();
    }

    return 0;
}

void solve(string input) {
    // �����̴� �������� �ʿ��� temp ť�꿡 �� ����
    copy(&cube[0][0][0], &cube[0][0][0] + sizeof(cube), &temp[0][0][0]);

    if(input[0] == 'U') {
        // �Ϸ�
        if(input[1] == '+') {
            temp[0][0][0] = cube[0][2][0];
            temp[0][0][1] = cube[0][1][0];
            temp[0][0][2] = cube[0][0][0];
            temp[0][1][0] = cube[0][2][1];
            temp[0][1][1] = cube[0][1][1];
            temp[0][1][2] = cube[0][0][1];
            temp[0][2][0] = cube[0][2][2];
            temp[0][2][1] = cube[0][1][2];
            temp[0][2][2] = cube[0][0][2];
            temp[2][0][0] = cube[5][0][0];
            temp[2][0][1] = cube[5][0][1];
            temp[2][0][2] = cube[5][0][2];
            temp[3][0][0] = cube[4][0][0];
            temp[3][0][1] = cube[4][0][1];
            temp[3][0][2] = cube[4][0][2];
            temp[4][0][0] = cube[2][0][0];
            temp[4][0][1] = cube[2][0][1];
            temp[4][0][2] = cube[2][0][2];
            temp[5][0][0] = cube[3][0][0];
            temp[5][0][1] = cube[3][0][1];
            temp[5][0][2] = cube[3][0][2];
        }
        // �Ϸ�
        else if(input[1] == '-') {
            temp[0][0][0] = cube[0][0][2];
            temp[0][0][1] = cube[0][1][2];
            temp[0][0][2] = cube[0][2][2];
            temp[0][1][0] = cube[0][0][1];
            temp[0][1][1] = cube[0][1][1];
            temp[0][1][2] = cube[0][2][1];
            temp[0][2][0] = cube[0][0][0];
            temp[0][2][1] = cube[0][1][0];
            temp[0][2][2] = cube[0][2][0];
            temp[2][0][0] = cube[4][0][0];
            temp[2][0][1] = cube[4][0][1];
            temp[2][0][2] = cube[4][0][2];
            temp[3][0][0] = cube[5][0][0];
            temp[3][0][1] = cube[5][0][1];
            temp[3][0][2] = cube[5][0][2];
            temp[4][0][0] = cube[3][0][0];
            temp[4][0][1] = cube[3][0][1];
            temp[4][0][2] = cube[3][0][2];
            temp[5][0][0] = cube[2][0][0];
            temp[5][0][1] = cube[2][0][1];
            temp[5][0][2] = cube[2][0][2];
        }
    }
    else if(input[0] == 'D') {
        // �Ϸ�
        if(input[1] == '+') {
            temp[1][0][0] = cube[1][2][0];
            temp[1][0][1] = cube[1][1][0];
            temp[1][0][2] = cube[1][0][0];
            temp[1][1][0] = cube[1][2][1];
            temp[1][1][1] = cube[1][1][1];
            temp[1][1][2] = cube[1][0][1];
            temp[1][2][0] = cube[1][2][2];
            temp[1][2][1] = cube[1][1][2];
            temp[1][2][2] = cube[1][0][2];
            temp[2][2][0] = cube[4][2][0];
            temp[2][2][1] = cube[4][2][1];
            temp[2][2][2] = cube[4][2][2];
            temp[3][2][0] = cube[5][2][0];
            temp[3][2][1] = cube[5][2][1];
            temp[3][2][2] = cube[5][2][2];
            temp[4][2][0] = cube[3][2][0];
            temp[4][2][1] = cube[3][2][1];
            temp[4][2][2] = cube[3][2][2];
            temp[5][2][0] = cube[2][2][0];
            temp[5][2][1] = cube[2][2][1];
            temp[5][2][2] = cube[2][2][2];
        }
        // �Ϸ�
        else if(input[1] == '-') {
            temp[1][0][0] = cube[1][0][2];
            temp[1][0][1] = cube[1][1][2];
            temp[1][0][2] = cube[1][2][2];
            temp[1][1][0] = cube[1][0][1];
            temp[1][1][1] = cube[1][1][1];
            temp[1][1][2] = cube[1][2][1];
            temp[1][2][0] = cube[1][0][0];
            temp[1][2][1] = cube[1][1][0];
            temp[1][2][2] = cube[1][2][0];
            temp[2][2][0] = cube[5][2][0];
            temp[2][2][1] = cube[5][2][1];
            temp[2][2][2] = cube[5][2][2];
            temp[3][2][0] = cube[4][2][0];
            temp[3][2][1] = cube[4][2][1];
            temp[3][2][2] = cube[4][2][2];
            temp[4][2][0] = cube[2][2][0];
            temp[4][2][1] = cube[2][2][1];
            temp[4][2][2] = cube[2][2][2];
            temp[5][2][0] = cube[3][2][0];
            temp[5][2][1] = cube[3][2][1];
            temp[5][2][2] = cube[3][2][2];            
        }
    }
    else if(input[0] == 'F') {
        // �Ϸ�
        if(input[1] == '+') {
            temp[2][0][0] = cube[2][2][0];
            temp[2][0][1] = cube[2][1][0];
            temp[2][0][2] = cube[2][0][0];
            temp[2][1][0] = cube[2][2][1];
            temp[2][1][1] = cube[2][1][1];
            temp[2][1][2] = cube[2][0][1];
            temp[2][2][0] = cube[2][2][2];
            temp[2][2][1] = cube[2][1][2];
            temp[2][2][2] = cube[2][0][2];
            temp[0][2][0] = cube[4][2][2];
            temp[0][2][1] = cube[4][1][2];
            temp[0][2][2] = cube[4][0][2];
            temp[1][0][0] = cube[5][2][0];
            temp[1][0][1] = cube[5][1][0];
            temp[1][0][2] = cube[5][0][0];
            temp[4][0][2] = cube[1][0][0];
            temp[4][1][2] = cube[1][0][1];
            temp[4][2][2] = cube[1][0][2];
            temp[5][0][0] = cube[0][2][0];
            temp[5][1][0] = cube[0][2][1];
            temp[5][2][0] = cube[0][2][2];
        }
        // �Ϸ�
        else if(input[1] == '-') {
            temp[2][0][0] = cube[2][0][2];
            temp[2][0][1] = cube[2][1][2];
            temp[2][0][2] = cube[2][2][2];
            temp[2][1][0] = cube[2][0][1];
            temp[2][1][1] = cube[2][1][1];
            temp[2][1][2] = cube[2][2][1];
            temp[2][2][0] = cube[2][0][0];
            temp[2][2][1] = cube[2][1][0];
            temp[2][2][2] = cube[2][2][0];
            temp[0][2][0] = cube[5][0][0];
            temp[0][2][1] = cube[5][1][0];
            temp[0][2][2] = cube[5][2][0];
            temp[1][0][0] = cube[4][0][2];
            temp[1][0][1] = cube[4][1][2];
            temp[1][0][2] = cube[4][2][2];
            temp[4][0][2] = cube[0][2][2];
            temp[4][1][2] = cube[0][2][1];
            temp[4][2][2] = cube[0][2][0];
            temp[5][0][0] = cube[1][0][2];
            temp[5][1][0] = cube[1][0][1];
            temp[5][2][0] = cube[1][0][0];            
        }
    }
    else if(input[0] == 'B') {
        // �Ϸ�
        if(input[1] == '+') {
            temp[3][0][0] = cube[3][2][0];
            temp[3][0][1] = cube[3][1][0];
            temp[3][0][2] = cube[3][0][0];
            temp[3][1][0] = cube[3][2][1];
            temp[3][1][1] = cube[3][1][1];
            temp[3][1][2] = cube[3][0][1];
            temp[3][2][0] = cube[3][2][2];
            temp[3][2][1] = cube[3][1][2];
            temp[3][2][2] = cube[3][0][2];
            temp[0][0][0] = cube[5][0][2];
            temp[0][0][1] = cube[5][1][2];
            temp[0][0][2] = cube[5][2][2];
            temp[1][2][0] = cube[4][0][0];
            temp[1][2][1] = cube[4][1][0];
            temp[1][2][2] = cube[4][2][0];
            temp[4][0][0] = cube[0][0][2];
            temp[4][1][0] = cube[0][0][1];
            temp[4][2][0] = cube[0][0][0];
            temp[5][0][2] = cube[1][2][2];
            temp[5][1][2] = cube[1][2][1];
            temp[5][2][2] = cube[1][2][0];
        }
        // �Ϸ�
        else if(input[1] == '-') {
            temp[3][0][0] = cube[3][0][2];
            temp[3][0][1] = cube[3][1][2];
            temp[3][0][2] = cube[3][2][2];
            temp[3][1][0] = cube[3][0][1];
            temp[3][1][1] = cube[3][1][1];
            temp[3][1][2] = cube[3][2][1];
            temp[3][2][0] = cube[3][0][0];
            temp[3][2][1] = cube[3][1][0];
            temp[3][2][2] = cube[3][2][0];
            temp[0][0][0] = cube[4][2][0];
            temp[0][0][1] = cube[4][1][0];
            temp[0][0][2] = cube[4][0][0];
            temp[1][2][0] = cube[5][2][2];
            temp[1][2][1] = cube[5][1][2];
            temp[1][2][2] = cube[5][0][2];
            temp[4][0][0] = cube[1][2][0];
            temp[4][1][0] = cube[1][2][1];
            temp[4][2][0] = cube[1][2][2];
            temp[5][0][2] = cube[0][0][0];
            temp[5][1][2] = cube[0][0][1];
            temp[5][2][2] = cube[0][0][2];            
        }
    }
    else if(input[0] == 'L') {
        // �Ϸ�
        if(input[1] == '+') {
            temp[4][0][0] = cube[4][2][0];
            temp[4][0][1] = cube[4][1][0];
            temp[4][0][2] = cube[4][0][0];
            temp[4][1][0] = cube[4][2][1];
            temp[4][1][1] = cube[4][1][1];
            temp[4][1][2] = cube[4][0][1];
            temp[4][2][0] = cube[4][2][2];
            temp[4][2][1] = cube[4][1][2];
            temp[4][2][2] = cube[4][0][2];
            temp[0][0][0] = cube[3][2][2];
            temp[0][1][0] = cube[3][1][2];
            temp[0][2][0] = cube[3][0][2];
            temp[1][0][0] = cube[2][0][0];
            temp[1][1][0] = cube[2][1][0];
            temp[1][2][0] = cube[2][2][0];
            temp[2][0][0] = cube[0][0][0];
            temp[2][1][0] = cube[0][1][0];
            temp[2][2][0] = cube[0][2][0];
            temp[3][0][2] = cube[1][2][0];
            temp[3][1][2] = cube[1][1][0];
            temp[3][2][2] = cube[1][0][0];
        }
        // �Ϸ�
        else if(input[1] == '-') {
            temp[4][0][0] = cube[4][0][2];
            temp[4][0][1] = cube[4][1][2];
            temp[4][0][2] = cube[4][2][2];
            temp[4][1][0] = cube[4][0][1];
            temp[4][1][1] = cube[4][1][1];
            temp[4][1][2] = cube[4][2][1];
            temp[4][2][0] = cube[4][0][0];
            temp[4][2][1] = cube[4][1][0];
            temp[4][2][2] = cube[4][2][0];
            temp[0][0][0] = cube[2][0][0];
            temp[0][1][0] = cube[2][1][0];
            temp[0][2][0] = cube[2][2][0];
            temp[1][0][0] = cube[3][2][2];
            temp[1][1][0] = cube[3][1][2];
            temp[1][2][0] = cube[3][0][2];
            temp[2][0][0] = cube[1][0][0];
            temp[2][1][0] = cube[1][1][0];
            temp[2][2][0] = cube[1][2][0];
            temp[3][0][2] = cube[0][2][0];
            temp[3][1][2] = cube[0][1][0];
            temp[3][2][2] = cube[0][0][0];
        }
    }
    else if(input[0] == 'R') {
        // �Ϸ�
        if(input[1] == '+') {
            temp[5][0][0] = cube[5][2][0];
            temp[5][0][1] = cube[5][1][0];
            temp[5][0][2] = cube[5][0][0];
            temp[5][1][0] = cube[5][2][1];
            temp[5][1][1] = cube[5][1][1];
            temp[5][1][2] = cube[5][0][1];
            temp[5][2][0] = cube[5][2][2];
            temp[5][2][1] = cube[5][1][2];
            temp[5][2][2] = cube[5][0][2];
            temp[0][0][2] = cube[2][0][2];
            temp[0][1][2] = cube[2][1][2];
            temp[0][2][2] = cube[2][2][2];
            temp[1][0][2] = cube[3][2][0];
            temp[1][1][2] = cube[3][1][0];
            temp[1][2][2] = cube[3][0][0];
            temp[2][0][2] = cube[1][0][2];
            temp[2][1][2] = cube[1][1][2];
            temp[2][2][2] = cube[1][2][2];
            temp[3][0][0] = cube[0][2][2];
            temp[3][1][0] = cube[0][1][2];
            temp[3][2][0] = cube[0][0][2];
        }
        // �Ϸ�
        else if(input[1] == '-') {
            temp[5][0][0] = cube[5][0][2];
            temp[5][0][1] = cube[5][1][2];
            temp[5][0][2] = cube[5][2][2];
            temp[5][1][0] = cube[5][0][1];
            temp[5][1][1] = cube[5][1][1];
            temp[5][1][2] = cube[5][2][1];
            temp[5][2][0] = cube[5][0][0];
            temp[5][2][1] = cube[5][1][0];
            temp[5][2][2] = cube[5][2][0];
            temp[0][0][2] = cube[3][2][0];
            temp[0][1][2] = cube[3][1][0];
            temp[0][2][2] = cube[3][0][0];
            temp[1][0][2] = cube[2][0][2];
            temp[1][1][2] = cube[2][1][2];
            temp[1][2][2] = cube[2][2][2];
            temp[2][0][2] = cube[0][0][2];
            temp[2][1][2] = cube[0][1][2];
            temp[2][2][2] = cube[0][2][2];
            temp[3][0][0] = cube[1][2][2];
            temp[3][1][0] = cube[1][1][2];
            temp[3][2][0] = cube[1][0][2];
        }
    }

    // ������ ť�갡 temp�� ����Ǿ� �����Ƿ� �̸� �ٽ� cube�� ����
    copy(&temp[0][0][0], &temp[0][0][0] + sizeof(temp), &cube[0][0][0]);
}

void topColor() {
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j++) {
            cout << cube[0][i][j];
        }
        cout << endl;
    }
}