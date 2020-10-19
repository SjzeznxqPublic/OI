#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,l,len;

ll poww(ll a, ll b) {
     int ans = 1, base = a;
     while (b != 0) {
         if (b & 1 != 0)
        {
              ans *= base;
        }
              base *= base;
              b >>= 1;
     }
     return ans;
 }

ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll ret=exgcd(b,a%b,y,x);
    y-=a/b*x;
    return ret;
}

ll getInv(int a,int mod) 
{
    ll x,y;
    ll d=exgcd(a,mod,x,y);
    return d==1?(x%mod+mod)%mod:-1;
}

int main()
{
    //freopen("card.in","r",stdin);
   // freopen("card.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&l);
    n++;
    ll ans=getInv(2,n);
    ans=poww(2,m);
    printf("%lld",ans);
   // fclose(stdin);
  //  fclose(stdout);
    return 0;
}