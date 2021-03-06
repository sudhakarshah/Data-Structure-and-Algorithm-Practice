//https://vjudge.net/contest/212260#problem/D
#include <iostream>
using namespace std;
#include <queue>     
#include <vector>  
#include <cmath>   
#include <limits.h>
#include <bitset>
#include <algorithm>
#include <string>
typedef long long ll;
int link[2001];
int size[2001];

struct e
{
	int a;
	int b;
	ll w;

};
bool compare(const e& a , const e& b) {
	return (a.w<b.w);
}
 
int find(int x)
{
	while (x!=link[x])
		x=link[x];
	return x;
}

int same(int a,int b)
{
	return (find(a)==find(b));
}

void unite(int a, int b)
{
	a=find(a);
	b=find(b);

	if (size[a]<size[b])
	{
		int temp=b;
		b=a;
		a=temp;
	}

	size[a]+=size[b];
	link[b]=link[a];
		
}



int main()
{
	int n,m;
	cin>>n>>m;
	vector<e> edges;
	while (m--)
	{
		int a,b;

		long long w;
		cin>>a>>b>>w;
		e edge;
		edge.a=a;
		edge.b=b;
		edge.w=w;
		edges.push_back(edge);

	}

	sort(edges.begin(),edges.end(),compare);

	for (int i = 1; i <= n; i++) link[i] = i;
	for (int i = 1; i <= n; i++) size[i] = 1;

	int c=0;
	
	while (!edges.empty() && c<n)
	{
		e t= edges.front();
		edges.erase(edges.begin());

		if (!same(t.a,t.b))
		{
			if(c==n-2)
			{
				cout<<t.w<<endl;
			}
			
			unite(t.a,t.b);
			c++;
		}
	}

	






}