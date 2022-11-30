#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int frontIdx = 0;
    
    // ����
    sort(people.begin(), people.end(), less<int>());
    
    // ����Ʈ Ǯ��
    for(int i = people.size() - 1; i >= 0; i--) {
        if(i == frontIdx) {
            answer++;
        }
        else if(i > frontIdx) {
            if(people[i] + people[frontIdx] <= limit) {
                answer++;
                frontIdx++;
            }
            else {
                answer++;
            }
        }
    }
    
    return answer;
}