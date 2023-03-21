#include <bits/stdc++.h>

using namespace std;

#define endl "\n"

string input;
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;

    solve();

    return 0;
}

void solve() {
    stack<char> operators;

    for(int i = 0; i < input.size(); i++) {
        char now = input[i];

        if(now == '+' || now == '-') {
            // ��Ģ������ ���
            while(!operators.empty() && operators.top() != '(') {
                cout << operators.top();
                operators.pop();
            }
            operators.push(now);
        }
        else if(now == '*' || now == '/') {
            while(!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {
                cout << operators.top();
                operators.pop();
            }
            operators.push(now);
        }
        else if(now == '(') {
            // ��ȣ�� ���
            operators.push(now);
        }
        else if(now ==  ')') {
            while(!operators.empty() && operators.top() != '(') {
                cout << operators.top();
                operators.pop();
            }
            operators.pop(); // ( pop�ϱ�
        }
        else {
            // ������ ���
            cout << now;
        }
    }

    while(!operators.empty()) {
        cout << operators.top();
        operators.pop();
    }

}