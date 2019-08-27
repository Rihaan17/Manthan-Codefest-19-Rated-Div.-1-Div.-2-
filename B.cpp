/*
Author: Golam Rahman Tushar
........Aust Cse 27th batch.........
*/

//{ Template

//{ C-headers
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cfloat>
#include <cctype>
#include <cassert>
#include <ctime>
//}
//{ C++-headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>

using namespace std;
//}

//}
//{ Floating-points
#define EPS DBL_EPSILON
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2 * acos (0.0)
//}

#define INF (1<<29)
#define ll long long

template <typename T>
std::string to_string(T const& value) {
    stringstream sstr;
    sstr << value;
    return sstr.str();
}
//}

template <class T> T gcd(T a,T b){if(b==0) return a;else return gcd(b,a%b);}
template <class T> T lcm(T a,T b){return (a*b)/gcd(a,b);}
template <class T> T power( T a, T b){if(b==0) return 1; T x=a;for(T i=2;i<=b;i++) a=a*x;return a;}
template <class T> T BigMod(T a,T b,T c){if(a==0) return 0;if(b==0) return 1;if(b%2==0){T x=BigMod(a,b/2,c)%c;return (x*x)%c;}else return  ((a%c)*BigMod(a,b-1,c)%c)%c;}

int dp[107][107], arr[107];

int solve(int l, int r) {
    if(dp[l][r]!=99999) return dp[l][r];
    if(l>r) return dp[l][r] = 0;

    int ret = -99999, i, temp = 0;
    for(i=l;i<=r;i++) {
        temp += arr[i];
        ret = max(ret, temp-solve(i+1,r));
    }
    temp = 0;
    for(i=r;i>=l;i--) {
        temp += arr[i];
        ret = max(ret, temp-solve(l,i-1));
    }

    return dp[l][r] = ret;
}
int main ()
{
    //freopen("input.txt","r",stdin);
    int t, n, Case = 1, i, j;
    scanf("%d",&t);
    while(t--) {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&arr[i]);
        for(i=0;i<=n;i++) for(j=0;j<=n;j++) dp[i][j] = 99999;
        printf("Case %d: %d\n",Case++,solve(0,n-1));
    }
    return 0;
}
