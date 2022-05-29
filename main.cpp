#include <iostream>
#include <vector>
#include <string>

using namespace std;

int pow2(int n)
{
    if(n==0)
        return 1;
    return 2*pow2(n-1);
}



int main()
{
    string s;
    s="CGUAAUUACGGCAUUAGCAU";

    int result=0;
    const int n=20;

    for(int i=0; i<pow2(n); i++)
    {
        vector<int> v;
        int ii=i;
        for(int j=0; j<n; j++)
        {
            v.push_back(ii%2);
            ii/=2;
        }

        bool ok=true;
        int countt=0;
        for(int j=0; j<n; j++)
        {
            if(v[j]==0)
                countt++;
            if(v[j]==1)
                countt--;
            if(countt<0)
                ok=false;
        }

        if(countt!=0)
            continue;

        if(!ok)
            continue;

        vector<int> pool;
        for(int j=0; j<n; j++)
        {
            if(v[j]==0)
            {
                countt++;
                v.push_back(j);
            }
            if(v[j]==1)
            {
                countt--;
                int kek=v[v.size()-1];
                v.pop_back();
                bool ok2=false;

                if(s[kek]=='U'&&s[j]=='A')
                    ok2=true;
                if(s[kek]=='A'&&s[j]=='U')
                    ok2=true;
                if(s[kek]=='C'&&s[j]=='G')
                    ok2=true;
                if(s[kek]=='G'&&s[j]=='C')
                    ok2=true;

                if(!ok2)
                    ok=false;
            }
        }

        if(!ok)
            continue;

        for(int j=0;j<n;j++){
            if(v[j]==0)
                cout<<"(";
            if(v[j]==1)
                cout<<")";
        }
        cout<<endl;
        result++;

    }

    cout<<result<<endl;


    return 0;
}
