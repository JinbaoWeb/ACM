#include <iostream>
using namespace std;
char str[101];
int pos;
bool judge( char str[], int value )
{
 pos++;
 switch ( str[pos] )
 {
 case 'p': return value&1;
 case 'q': return (value>>1)&1;
 case 'r': return (value>>2)&1;
 case 's': return (value>>3)&1;
 case 't': return (value>>4)&1;
 case 'K': return judge(str,value)&judge(str,value);
 case 'A': return judge(str,value)|judge(str,value);
 case 'N': return !judge(str,value);
 case 'C': return (!judge(str,value))|judge(str,value);
 case 'E': return judge(str,value)==judge(str,value);
 default:;
 }
}
int main()
{
 bool mark;
 while ( cin >> str && str[0] != '0' )
 {
  mark = true;
  for ( int i = 0; i < 32; i++ )
  {
   pos = -1;
   if ( !judge(str,i) ) {
    mark = false; break;
   }
  }
  if ( mark ) cout << "tautology" << endl;
  else cout << "not" << endl;
 }
 return 0;
}