#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<string> v;
    map<string, int> m;
    
    // map container insert
    for(int i = 0; i < clothes.size(); i++) {
        if(m.find(clothes[i][1]) != m.end()) {
           auto iter = m.find(clothes[i][1]);
            iter->second++;
        }
        else {
            m.insert({clothes[i][1], 1});
            v.push_back({clothes[i][1]});
        }
    }
    
    for(auto iter = m.begin(); iter != m.end(); iter++) {
        answer *= iter->second + 1;
    }
    
    return answer - 1;
}

// �� �ǻ� ���� ������ ���� ������ �� ����, ���� ���� �ִ�. ���� �� �ǻ� �������� �ǻ��� ���� ����� ���� �ǻ� ���� + 1.
// ��� �ǻ� ���� ������ �ǻ��� ���� ���� ���, �� �ǻ��� �ϳ��� ���� ���� ���� ��������� �Ѵ�.