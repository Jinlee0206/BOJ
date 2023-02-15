#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool prime(ll a)
{
    if(a < 2) return false;
    
    for(int i = 2; i <= sqrt(a); i++)
    {
        if(a%i == 0) return false;
    }
    return true;
}

string convert_num(int n, int k)
{
    string ret = "";
    
    while(n)
    {
        ret += to_string(n%k);
        n /= k;
    }
    
    return string(ret.rbegin(), ret.rend());
}

int get_answer(string num)
{
    string tmp = "";
    int res = 0;
    
    for(int i = 0; i<num.length(); i++)
    {
        if(num[i] == '0' && !tmp.empty())
        {
            ll n = stoll(tmp);
            if(prime(n)) res++;
            tmp = "";
        }
        else tmp += num[i];
    }
    
    if(!tmp.empty())
    {
        ll n = stoll(tmp);
        if(prime(n)) res++;
    }
    
    return res;
}

int solution(int n, int k) {
    int answer = 0;
    
    string num = convert_num(n,k);
    
    return get_answer(num);
}