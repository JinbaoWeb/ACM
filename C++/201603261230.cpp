#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000 + 100;
int arr[MAX_N];
int main(){
	int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        sort(arr, arr + n);
        int _max = 1, temp = 1, k = 0;
        for(int i = 1; i < n; i++)
        {
            if(arr[i] == arr[i - 1])
            {
                temp++;
                if(i == n - 1)
                {
                    if(_max <= temp)
                    {
                        _max = temp;
                        k = i;
                    }
                }
            }
            else
            {
                if(_max <= temp)
                {
                    _max = temp;
                    k = i - 1;
                    if(i == n - 1)
                        k = i;
                }
                temp = 1;
            }
        }
        cout<<arr[k]<<endl;
    }
	return 0;
}