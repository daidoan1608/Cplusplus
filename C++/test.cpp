#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int sum=0;
    for(int i=0;i<100;i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (i=j)
            {
                for (int k = 0; k < 100; k++)
                {
                    sum= sum+1;
                }
                
            }
            
        }
        
    }
    cout<<sum;
    return 0;   
}
