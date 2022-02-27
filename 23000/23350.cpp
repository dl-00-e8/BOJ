#include <bits/stdc++.h>

using namespace std;

int n, m, maxRank;
int rankCnt[101];
queue<pair<int, int>> q;
void solve();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	
	maxRank = 0;
	while(n--) {
		int p, w;
		cin >> p >> w;
		q.push({p, w});
		rankCnt[p]++;
		maxRank = max(maxRank, p);
	}
	
	solve();
	
	return 0;
}

void solve() {
	int move;
	int result = 0;
	pair<int, int> now;
	stack<pair<int, int>> space;
	stack<pair<int, int>> temp;

	while(!q.empty()) {
		now = q.front();
		q.pop();
		
		// cout << "now : " << now.first << ", " << now.second << endl;
		
		if(maxRank == now.first) {
			if(space.empty()) {
				space.push(now);
				result += now.second;
				// cout << "���� ���� �̵� : " << now.second << endl;
			}
			else {
				// ���� �����ߴ� ���� ������ ������ �Űܳ��� �ٽ� �����ؾ� �ϴ� ��쿡 ���� ����
				move = 0;
				while(true) {
					if(space.empty()) {
						space.push(now);
						move += now.second;
						// cout << "����� ���� ���� : " << now.second << endl;
						break;
					}
					else {
						if(space.top().first == now.first) {
							if(space.top().second < now.second) {
								// cout << "���� ���̷� ������ ���� �̵� : " << space.top().second << endl;
								temp.push(space.top());
								move += space.top().second;
								space.pop();								
							}
							else if(space.top().second >= now.second) {
								// cout << "���� ���� : " << now.second << endl;
								space.push(now);
								move += now.second;
								break;
							}
						}
						else if(space.top().first > now.first) {
							// cout << "�켱���� ���̷� �ٷ� ���� ���� : " << now.second << endl;
							space.push(now);
							move += now.second;
							break;
						}
					}
				}	
				while(!temp.empty()) {
					// cout << "������ �������� ���� ���� ����ġ : " << temp.top().second << endl;
					space.push(temp.top());
					move += temp.top().second;
					temp.pop();
				}
				
				result += move;
				// cout << "��� : " << result << endl;
			}
			
			rankCnt[maxRank]--;
			if(rankCnt[maxRank] == 0) {
				maxRank--;
			}
		}
		else {
			q.push(now);
			result += now.second;
			// cout << "�ڷ� �̷�� : " << now.second << endl;
		}
	}
	
	cout << result << endl;
}