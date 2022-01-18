#include <bits/stdc++.h>

using namespace std;

int p, v, rv, n, r; 
struct node {
	string name;
    int ri, vote, total;
    double rate, prop_rate, p1, p2, p3, p2_rate, p3_rate;
    bool prop_able;
};
vector<node> party;
bool compare1(const pair<int, double> &a, const pair<int, double> &b); // �Ҽ��� �������� ����
bool compare2(const node &a, const node &b); // ��ü �Ǽ� �� �������� ����
void zero(); // ��ǥ��, ��ʵ�ǥ�� ���
void first(); // 1�ܰ�
void second(); // 2�ܰ�
void third(); // 3�ܰ�
void solve(); // Output ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> p >> v;
	rv = v;
	for(int i = 0; i < p; i++) {
		node temp;
		cin >> temp.name >> temp.ri >> temp.vote;
		party.push_back(temp);
		rv -= temp.vote;
	}
	rv = v - rv; //��ȿǥ
	
	zero();
	first();
	second();
	third();
	solve();
	
	return 0;
}

bool compare1(const pair<int, double> &a, const pair<int, double> &b) {
	return a.second > b.second;
}

bool compare2(const node &a, const node &b) {
	if(a.total == b.total) {
		return a.name < b.name;
	}
	else {
		return a.total > b.total;
	}
}

void zero() {
	// ��ǥ�� ��� + ��ʴ�ǥ�Ǽ� ���� �� �ִ��� ��� + ��ʵ�ǥ���� ��ȿ ��ǥ �� ���
	for(int i = 0; i < p; i++) {
		party[i].rate = (1.0 * party[i].vote) / rv;
		//party[i].rate = round(party[i].rate * 10000) / 10000;
		
		if(party[i].ri >= 5 || party[i].rate >= 0.03) {
			party[i].prop_able = true;
		}
		else {
			party[i].prop_able = false;
			rv -= party[i].vote;
		}
	}
	
	// ��ʵ�ǥ�� ���
	for(int i = 0; i < p; i++) {
		if(party[i].prop_able) {
			party[i].prop_rate = (1.0 * party[i].vote) / rv;
			//party[i].prop_rate = round(party[i].prop_rate * 10000) / 10000;
		}
	}
}

void first() {
	n = 300;
	r = 253;
	// 1�ܰ� ���� R ���
	for(int i = 0; i < p; i++) {
		if(party[i].prop_able) {
			r -= party[i].ri;
		}
	}
	
	// 30���� ���� �� ���纰 ��������Ǽ��� ����
	for(int i = 0; i < p; i++) {
		if(party[i].prop_able) {
			party[i].p1 = ((n -r) * (1.0 * party[i].prop_rate) - party[i].ri) / 2;
			if(party[i].p1 < 1) {
				party[i].p1 = 0;
			}
			else {
				party[i].p1 = round(party[i].p1);
			}
		}
	}
	
}

void second() {
	int sum = 0; // ���纰 ��������Ǽ��� �հ� ���ϴ� ����
	int nSum = 0; // ���ٺ� ��������Ǽ����� 30���� �ǵ��� �ϴ� ����
	vector<pair<int, double>> v;
	
	// ���� ��� �Ǽ� �� �� ���ϱ�
	for(int i = 0; i < p; i++) {
		if(party[i].prop_able) {
			sum += party[i].p1;
		}
	}
	
	if(sum == 30) {
		for(int i = 0; i < p; i++ ) {
			party[i].p2 = party[i].p1;
		}
		return;
	}
	else if(sum < 30) {
		// 2-1�ܰ� ����
		for(int i = 0; i < p; i++) {
			if(party[i].prop_able) {
				party[i].p2_rate = party[i].p1 + (30 - sum) * (1.0 * party[i].prop_rate);
				party[i].p2 = floor(party[i].p2_rate);
				party[i].p2_rate -= party[i].p2;
				
				nSum += party[i].p2;
				v.push_back({i, party[i].p2_rate});
			}
		}
		
		sort(v.begin(), v.end(), compare1);
		for(int i = 0; i < v.size(); i++) {
			if(nSum >= 30) {
				break;
			}
			party[v[i].first].p2++;
			nSum++;
		}
	}
	else if(sum > 30) {
		// 2-2�ܰ� ����
		for(int i = 0; i < p; i++) {
			if(party[i].prop_able) {
				party[i].p2_rate = 30 * (1.0 * party[i].p1) / sum;
				party[i].p2 = floor(party[i].p2_rate);
				party[i].p2_rate -= party[i].p2;
				
				nSum += party[i].p2;
				v.push_back({i, party[i].p2_rate});
			}
		}
		
		sort(v.begin(), v.end(), compare1);
		for(int i = 0; i < v.size(); i++) {
			if(nSum >= 30) {
				break;
			}
			party[v[i].first].p2++;
			nSum++;
		}
	}
}

void third() {
	int sum = 0;
	vector<pair<int, double>> v;
	
	for(int i = 0; i < p; i++) {
		if(party[i].prop_able) {
			party[i].p3_rate = 17 * (1.0 * party[i].prop_rate);
			party[i].p3 = floor(party[i].p3_rate);
			party[i].p3_rate -= party[i].p3;
			
			sum += party[i].p3;
			v.push_back({i, party[i].p3_rate});
		}
	}
	
	sort(v.begin(), v.end(), compare1);
	for(int i = 0; i < v.size(); i++) {
		if(sum >= 17) {
			break;
		}
		party[v[i].first].p3++;
		sum++;
	}
}

void solve() {
	for(int i = 0; i < p; i++) {
		if(party[i].prop_able) {
			party[i].total = party[i].ri + party[i].p2 + party[i].p3;
		}
		else {
			party[i].total = party[i].ri;
		}
	}
	
	sort(party.begin(), party.end(), compare2);
	for(int i = 0; i < p; i++) {
		cout << party[i].name << " " << party[i].total << endl;
	}
}