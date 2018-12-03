#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>  

inline int w(int u, int v, int t) { return (u - v) * (u - v) + t; }

int main(void)
{
	int n;
	std::cin >> n;

	int rank[n], t[n], dp[n] = { 0, }, ind[n] = { 0, };
	std::vector<int> al[n];
	
	for (int i = 0; i < n; ++i)
		std::cin >> rank[i] >> t[i];
	//make a graph
	for(int u = 0;u < n;++u)
	{
		for (int v = 0; v < n; ++v)
		{
			//u->v
			if (rank[v] - rank[u] == 1)
			{
				ind[v] += 1;
				al[u].push_back(v);
			}
		}
	}
	//dp
	std::queue<int> q;
	for(int i = 0;i < n;++i)
		if(ind[i] == 0)
			q.push(i), dp[i] = t[i];
	int ans = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int v : al[u])
		{
			ind[v] -= 1; 
			dp[v] = std::max(dp[v], dp[u] + w(u, v, t[v]));
			ans = std::max(ans, dp[v]);
			if (ind[v] == 0)
				q.push(v);
		}
	}
	std::cout << ans;
	return 0;
}
