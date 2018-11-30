#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define INF 987654321
#define MAX_N 101
#define MAX_R 201

using namespace std;

int N, R;
int dist[MAX_N] = { 0 };
int base[MAX_N] = { 1, };

typedef struct NODE
{
	int end;
	int cost;
};
vector<NODE> position[MAX_R];

void dijkstra()
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, 1 });
 
	while (!pq.empty())
	{
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < position[now].size(); i++)
		{
			int new_cost = dist[now] + position[now][i].cost;
			int before_cost = dist[position[now][i].end];

			if (new_cost < before_cost)
			{
				base[position[now][i].end] = base[now] + 1;
				dist[position[now][i].end] = new_cost;
				pq.push({ -1 * new_cost, position[now][i].end });
			}
		}
	}
}

int main()
{
	cin >> N >> R;

	int from, to, basic, plus, time;

	for (int i = 0; i < R; i++)
	{
		scanf("%d %d %d %d %d", &from, &to, & basic, &plus, &time);

		if (time <= 10)
		{
			position[from].push_back(NODE{ to, basic });
		}
		else if (time > 10)
		{
			position[from].push_back(NODE{ to, basic + (time - 10) * plus });
		}
	}

	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
	}
	dist[1] = 0;

	dijkstra();
 
	if (dist[N] == 987654321) printf("It is not a great way.");
	else printf("%d %d", dist[N], base[N] + 1);

	return 0;
}
