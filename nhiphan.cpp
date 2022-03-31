#include <iostream>
using namespace std;
int main()
{
    long dec,rem,i=1,sum=0;
    cin>>dec;
    do
    {
        rem=dec%2;
        sum=sum + (i*rem);
        dec=dec/2;
        i=i*10;
    }while(dec>0);
    cout<<sum<<endl;
    cin.get();
    cin.get();
 
    return 0;
}
