#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define MOD 1000000007

void solve()
{   
    
    int n;
    cin >> n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x; cin >> x;
        v.pb(x);
    }

    stack<int>s;
    vector<int>NGE_inx(n);

    for(int i=0;i<n;i++)
    {
        while(!s.empty() && v[i] > v[s.top()])
        {
            NGE_inx[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while(!s.empty())
    {
        NGE_inx[s.top()] = -1; // This elements do not have any NGE so we assign -1 to it.
        s.pop(); 
    }

    for (int i = 0; i < n; ++i)
    {
        cout << v[i] << " " << (NGE_inx[i] == -1? -1 : v[NGE_inx[i]]) << endl;    
    }
}
int main()
{
    fast
    int t = 1;
    //cin>>t;
    while(t--)
    {
        solve();
    }
}
