#include <cstdio>
#include <vector>
#include <queue>

std::vector<int> list[3030]; //인접 리스트
int v,e;//정점의 갯수, 간선의 갯수
bool visit[3030]; //visit 배열 

void dfs(int s)
{
	visit[s]=true;
	for (int i = 0; i < list[s].size(); i++)
    {
        if (!visit[list[s][i]]) dfs(list[s][i]);
    }
}

int main()
{
	int comp=0; //연결 요소의 갯수 
	int odd=0; //연결 구간의 갯수가 홀수개인 지점의 수 
	
	//입력 
	scanf("%d %d",&v,&e);
	for(int i=0;i<e;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		list[a].push_back(b);
		list[b].push_back(a);
	}
	
	for(int i=1;i<=v;i++)
	{
		if(!visit[i]) //연결 요소의 갯수
		{
			dfs(i);
			comp++;
		}
		
		//연결 구간의 갯수가 홀수개인 지점
		if(list[i].size()%2==1) odd++;
	}
	
	if(comp==1 && (odd==0 || odd==2)) printf("YES");
	else printf("NO");
	return 0;
}
