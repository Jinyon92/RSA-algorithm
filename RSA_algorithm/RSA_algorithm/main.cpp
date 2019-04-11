#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int gcd(int a, int b)
{
    while(b!=0)
    {
        int temp = a%b;
        a = b;
        b = temp;
    }
    return a;
}

int main()
{
    int p,q,n;
    cout<<"임의의 소수 p,q를 입력하시오:";
    cin>>p>>q;
    n = (p-1)*(q-1);
    int e = 2;
    for(int i=2; i<=n; i++)
    {
        if(gcd(i,n) == 1) //가장 처음으로 나온 서로소를 e로 저장
        {
            e = i;
            break;
        }
    }
    
    bool arr[10001]; //2~10000까지의 소수 d 후보찾기
    for(int i=0; i<10001; i++)
    {
        arr[i] = true;
    }
    int j;
    
    for(int i=2; i<10001; i++)
    {
        if(arr[i])
        {
            if(pow(i,2) > 10001)
            {
                break;
            }
            else
            {
                for(j = pow(i,2); j<10001;)
                {
                    arr[j] = false;
                    j = j+i;
                }
            }
        }
    }
    
    vector<int> d_candidate;
    
    for(int i=2; i<10001; i++)
    {
        if(arr[i])
        {
            d_candidate.push_back(i);
        }
    }
    int d = 0;
    for(auto di : d_candidate)
    {
        if((e*di) % n == 1)
        {
            d = di;
            break;
        }
    }
    
    if(d == 0)
    {
        cout<<"d값이 1~10000범위를 초과하여 찾을 수 없습니다.";
        return 0;
    }
    
    long long m,c;
    cout<<"암호 메세지 숫자를 입력하시오:";
    cin>>m;
    long long temp = pow(m,e);
    c = temp % (p*q);
    cout<<"암호화된 숫자는:"<<c<<"\n";
    
    temp = pow(c,d);
    m = temp % (p*q);
    cout<<"복호화된 메세지 숫자:"<<m;
    return 0;
}
