/*input
6 5
0 4
0 1 
1 2
2 3
5 4

*/
#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define endl "\n"


typedef long long ll;
typedef long double ld;

ll vis[100000]={0};

void dfs(vector<ll > a[], ll s)
{
	cout<< s<< " ";
	vis[s]=1;
	 for(int i = 0;i < a[s].size();++i)    {
         if(vis[a[s][i]] == 0)
             dfs(a ,a[s][i]);
        }
     
}

int main()
{
	fast;
	ll n;
	cin >> n;
	vector<ll > t[n];
	ll q; 
	cin >> q;
	while(q--)
	{
		ll a, b; 
		cin >>a >> b;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	for( ll i= 0 ;i< n ;i++)
	{
		if(vis[i] == false)
		{
			dfs(t, i);
		}
	}
	return 0;

}
