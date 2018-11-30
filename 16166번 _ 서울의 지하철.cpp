#include <vector>
#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

#define INF 98765432;

//Hoseon
int adj[11][11] = { 0, };
int floyd[11][11] = { 0, };

bool my_find(vector<int>& source, vector<int>& find) {
	for (int i = 0; i < source.size(); i++) {
		for (int j = 0; j < find.size(); j++) {
			if (source[i] == find[j]) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n;
	map< int, vector<int> > mp;

	scanf("%d", &n);
	
	vector<int> hasZero;
	
	for (int i = 0; i < n; i++) {
		int m;
		scanf("%d", &m);
		for (int j = 0; j < m; j++) {
			int station;
			scanf("%d", &station);
			if (station == 0) {
				hasZero.push_back(i + 1);
			}
			mp[i+1];
			mp[i+1].push_back(station);
		}
	}

	for (int st = 1; st <= mp.size(); st++) {
		if (mp[st].size() == 0) continue;

		for (int ar = 1; ar <= mp.size(); ar++) {
			if (my_find(mp[st], mp[ar]))
				adj[st][ar] = 1;
		}
	}

	for (int r = 0; r < 11; r++) {
		for (int c = 0; c < 11; c++) {
			if (adj[r][c] == 0) {
				adj[r][c] = INF;
			}
		}
	}

	for (int r = 0; r < 11; r++) {
		adj[r][r] = 0;
	}

	int dest;
	scanf("%d", &dest);
	vector<int> hasDest;

	for (int i = 0; i < mp.size(); i++) {
		for (int j = 0; j < mp[i].size(); j++) {
			if (mp[i][j] == dest) {
				hasDest.push_back(i);
				break;
			}
		}
	}

	for (int k = 0; k<11; k++)
		for (int i = 0; i<11; i++)
			for (int j = 0; j<11; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);


	int ret = INF;
	for (int st = 0; st < hasZero.size(); st++) {
		for (int de = 0; de < hasDest.size(); de++) {
			ret = min(ret, adj[hasZero[st]][hasDest[de]]);
		}
	}

	if (ret == 98765432) {
		printf("-1");
	}
	else {
		
		printf("%d", ret);
	}

		
	return 0;
}
