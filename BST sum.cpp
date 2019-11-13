/*input
5
10 5 15 11 15
30
*/

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define endl "\n"
#define sp " " 
#define all(v) v.begin(),v.end()
#define makepr(a,b) make_pair(a, b)
#define loop(i,k,n) for(ll i=k;i<n;i++)
#define rlop(i,n,k) for(ll i=n-1;i>=k;i--)
#define lop(i ,a) for(auto i : a)
#define vecl vector<ll>
#define vecprl vector<pair<ll, ll> > v;
#define mpll map<ll, ll>
#define mpsl map<string, ll>
#define setl set<ll>
#define mod(a,b) a%b

typedef long long ll;
typedef long double ld;

struct node
{
	ll val;
	node * right;
	node * left;
	
};



struct node* insert(ll a,struct node* root)
{
	if(root== NULL)
	{
		struct node* x = (struct node*)malloc(sizeof(struct node));
		x->val = a;
		x->left= NULL;
		x->right = NULL;
		return x;
	}
	if(a < root->val)
	{
		root->left = insert(a, root->left);
	}
	else
	{
		root->right = insert(a,root->right);
	}
	return root;
}


mpll mp;

void dfs(struct node* root)
{
	if(root != NULL)
	{
		mp[root->val]++;
		dfs(root->left);
		dfs(root->right);
	}
	
}

int main()
{
	fast;
	ll n;
	cin >> n;
	vecl v;
	loop(i ,0,n)
	{
		ll a;
		cin >> a;
		v.pb(a);
	}
	ll k =0;
	cin >> k;
	struct node *root=NULL;
	lop(i, v)
	{
		if(i == v[0])
		{
			
			root = insert(i, root);
		}
		else
			insert(i,root);
	}
	dfs(root);
	lop(i, mp)
	{
		ll need = k - i.first;
		if(mp[need] >= 1 && i.second !=0)
		{
			cout<<"found"<<endl;
			return 0;
		}
	}
	cout<<"404"<<endl;
	return 0;
}
