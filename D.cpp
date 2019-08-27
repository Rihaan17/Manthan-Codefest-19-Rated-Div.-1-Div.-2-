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

#define INF 1<<29
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

/*int dx[] = {0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,-1,-1,-1,-1,-1,-1,-1,-1};
int dy[] = {0,0,1,1,1,-1,-1,-1,0,0,1,1,1,-1,-1,-1,0,0,1,1,1,-1,-1,-1};
int dz[] = {1,-1,0,1,-1,0,1,-1,1,-1,0,1,-1,0,1,-1,1,-1,0,1,-1,0,1,-1};*/

int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};

map<string,int>mp;
vector<int>graph[17777];
bool vis[17777], block[17777];
int cost[17777];

char calc(char c, int i)
{
        if(c=='a'&&i==-1) return 'z';
        if(c=='z'&&i==1) return 'a';
        return c+i;
}

void pre_relation()
{
        char a, b, c;
        string str = "abc";
        for(a='a';a<='z';a++)
        {
                str[0] = a;
                for(b='a';b<='z';b++)
                {
                        str[1] = b;
                        for(c='a';c<='z';c++)
                        {
                                str[2] = c;
                                string temp = str;
                                for(int i=0;i<6;i++) {
                                        temp[0] = calc(a, dx[i]);
                                        temp[1] = calc(b, dy[i]);
                                        temp[2] = calc(c, dz[i]);

                                        graph[mp[str]].push_back(mp[temp]);
                                }
                        }
                }
        }
}

void pre_map()
{
        int cnt=0;
        char a, b, c;
        string str = "abc";
        for(a='a';a<='z';a++)
        {
                str[0] = a;
                for(b='a';b<='z';b++)
                {
                        str[1] = b;
                        for(c='a';c<='z';c++)
                        {
                                str[2] = c;
                                mp[str] = cnt++;
                        }
                }
        }

        //cout<<cnt<<endl;
}

bool check(int s)
{
        if(vis[s]==false&&block[s]==false) return true;
        return false;
}

int bfs(int s, int d)
{
        if(s==d) {
                if(block[s] == false) return 0;
                return -1;
        }

        if(block[s]||block[d]) return -1;
        queue<int>q;
        cost[s] = 0;
        q.push(s);
        vis[s] = true;

        while(!q.empty())
        {
                int u = q.front();
                q.pop();

                for(int i = 0;i<graph[i].size();i++)
                {
                        int v= graph[u][i];
                        if(check(v))
                        {
                                vis[v] = true;
                                cost[v] = cost[u] + 1;
                                if(v==d) return cost[v];
                                q.push(v);
                        }
                }
        }

        return -1;
}

int main ()
{
        pre_map();
        pre_relation();
        int t, i, j, k, n, Case = 1;
        scanf("%d",&t);

        while(t--)
        {
                string sc, des;
                cin>>sc>>des;
                scanf("%d",&n);

                while(n--)
                {
                        string str1, str2, str3;
                        cin>>str1>>str2>>str3;
                        int l1 = str1.length(), l2 = str2.length(), l3 = str3.length();
                        string str = "abc";
                        for(i=0;i<l1;i++)
                        {
                                str.replace(0,1,1,str1[i]);
                                for(j=0;j<l2;j++)
                                {
                                        str.replace(1,1,1,str2[j]);//str.assign(str2,j,2);
                                        for(k=0;k<l3;k++)
                                        {
                                                str.replace(2,1,1,str3[k]);//str.assign(str3,k,3);
                                                block[mp[str]] = true;
                                        }
                                }
                        }
                }

                printf("Case %d: %d\n",Case++,bfs(mp[sc], mp[des]));

                for(i=0;i<17777;i++) {
                        vis[i] = false;
                        block[i] = false;
                }
        }

        return 0;
}

