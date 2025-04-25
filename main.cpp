#include<bits/stdc++.h>
using namespace std;int main(){string a,b;getline(cin,a);for(char c:a)if(isalpha(c))b+=tolower(c);int n=0,x=b.length();for(int i=0;i<x/2;i++)if(b[i]!=b[x-i-1])n=1;if(n==1)cout<<0;else cout<<1;cin>>n;vector<int>q(n);for(int i=0;i<n;i++)cin>>q[i];sort(q.begin(),q.end());for(int r:q)cout<<r;}
