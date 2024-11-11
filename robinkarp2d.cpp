#include<iostream>
using namespace std;
#include<string>
#include<math.h>
#include <vector>

int valueOf(char ch)
{
    return (ch-'0');
}
bool check_characters(string T, string P, int s)
{
    int n,m,i;
    n = T.length();
    m = P.length();
    for(i=0;i<m;i++)
    {
        if(P[i]!=T[s+i+1])
            return false;
    }
    return true;
}
void rabin_karp_matcher(string T, string P, int d, int q)
{
    int n, m, h, p, t0, i,s;
    n = T.length();
    m = P.length();
    h = (int)pow(d,m-1)%q;
    cout<<"h value is "<<h<<endl;
    p = 0;
    t0 = 0;
    for(i=0;i<m;i++)
    {
        p = (d*p + valueOf(P[i]))%q;
        t0 = (d*t0 + valueOf(T[i]))%q;
    }
    for(s=-1;s<n-m;s++)
    {
        cout<<p<<" "<<t0<<endl;
        if(p==t0)
        {
           if (check_characters(T,P,s))
                cout<<s+1<<endl;
        }
        if(s<n-m)
            t0 = (d*(t0-valueOf(T[s+1])*h)+valueOf(T[s+m+1]))%q;
    }
}
int main()
{
    string T, P;
    int d,q;
    cin>>T>>P;
    cin>>d>>q;
    rabin_karp_matcher(T,P,d,q);
}
int valueOf2D(char ch)
{
    return (ch - '0');
}

bool check_characters_2D(vector<vector<char>> &T, vector<vector<char>> &P, int row, int col)
{
    int m = P.size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (P[i][j] != T[row + i][col + j])
                return false;
        }
    }
    return true;
}

void rabin_karp_matcher_2D(vector<vector<char>> &T, vector<vector<char>> &P, int d, int q)
{
    int n = T.size();
    int m = P.size();
    int h = (int)pow(d, m - 1) % q;
    int p = 0;
    vector<vector<int>> t0(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            p = (d * p + valueOf2D(P[i][j])) % q;
            t0[i][j] = (d * t0[i][j] + valueOf2D(T[i][j])) % q;
        }
    }

    for (int row = 0; row <= n - m; row++)
    {
        for (int col = 0; col <= n - m; col++)
        {
            if (p == t0[row][col])
            {
                if (check_characters_2D(T, P, row, col))
                    cout << "Pattern found at (" << row << ", " << col << ")" << endl;
            }
            if (col < n - m)
            {
                for (int i = 0; i < m; i++)
                {
                    t0[row][col + 1] = (d * (t0[row][col + 1] - valueOf2D(T[row + i][col]) * h) + valueOf2D(T[row + i][col + m])) % q;
                }
            }
        }
        if (row < n - m)
        {
            for (int j = 0; j < m; j++)
            {
                t0[row + 1][j] = (d * (t0[row + 1][j] - valueOf2D(T[row][j]) * h) + valueOf2D(T[row + m][j])) % q;
            }
        }
    }
}

int main()
{
    int n, m, d, q;
    cin >> n >> m;
    vector<vector<char>> T(n, vector<char>(n));
    vector<vector<char>> P(m, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> T[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> P[i][j];
        }
    }

    cin >> d >> q;
    rabin_karp_matcher_2D(T, P, d, q);
}