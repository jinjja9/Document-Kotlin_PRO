#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define foru(i,a,b) for(int i=a;i<=b;++i)
#define ford(i,b,a) for(int i=b;i>=a;--i)
#define ii pair<int,int>
#define ll long long
#define fi first
#define se second
#define fill(a,b) memset(a,b,sizeof(a))

const int TEST=100;

void gentest()
{
    ll a=1;
    ll b=1e18;
    int t=rnd.next(1,500);
    cout<<t<<"\n";
    for(int i=1; i<=t; i++)
    {
        ll k=rnd.next(a,b);
        cout<<k<<"\n";
    }
}

int main(int argc,char *argv[])
{
    registerGen(argc,argv,0);
    foru(i,1,TEST)
    {
        const char*c =("Test/"+to_string(i)+".in").c_str();
        FILE *f=freopen(c,"w",stdout);
        gentest();
        fclose(f);
    }
}
