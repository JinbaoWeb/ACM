#include <iostream>
using namespace std;
void Permutations(char *a,const int k,const int m)
{
    //Generate all the permutations of a[k],...,a[m];
    int i;
    if (k==m)
    {
        //output permutations
        for (i=0;i<=m;i++)
            cout<<a[i]<<'\t';
        cout<<endl;
    }
    else
    {
        //a[k:m] has more than one permutation. Generate these recursively.
        for (i=k;i<=m;i++)
        {
            swap(a[k],a[i]);
            Permutations(a,k+1,m);
            swap(a[k],a[i]);
        }
    }
}
int main()
{
    char x[4];
    for (int i=0;i<4;i++)
        cin>>x[i];
    Permutations(x,0,3);
}
