#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> card;
vector<int> check;
bool binarySearch(int start, int end, int num);
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        card.push_back(input);
    }
    cin >> m;
    for(int i = 0; i < m; i++) {
        int input;
        cin >> input;
        check.push_back(input);
    }
    
    solve();

    return 0;
}

bool binarySearch(int start, int end, int num) {
    int mid = (start + end) / 2;

    // start���� end�� Ŀ���� ����
    if(start > end) {
        return false;
    }
    
    // ã�� ��ȣ�� ���� idx�� value���� ���� ��
    if(num < card[mid]) {
        return binarySearch(start, mid - 1, num);
    }
    // ã�� ��ȣ�� ������ ��
    else if(num == card[mid]) {
        return true;
    }
    // ã�� ��ȣ�� ���� idx�� value���� Ŭ ��
    else {
        return binarySearch(mid + 1, end, num);
    }
}

void solve() {
    sort(card.begin(), card.end(), less<int>());

    for(int i = 0; i < m; i++) {
        if(binarySearch(0, n -1, check[i])) {
            cout << 1 << " ";
        }
        else {
            cout << 0 << " ";
        }
    }
}