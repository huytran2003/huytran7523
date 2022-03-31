#include<bits/stdc++.h>
using namespace std;
int main()
{
    float a, b, c, denta=0, x1=0, x2=0;
    cin >> a >> b >> c;
    cout << fixed << setprecision(4);
    denta = b*b -4*a*c;
    if (denta>0){
        x1 = (-b +sqrt(denta))/(2*a);
        x2 = (-b -sqrt(denta))/(2*a);
        cout << x1 <<endl;
        cout << x2 <<endl;
    }
    else {
     if (denta==0){
         x1=x2= -b/(2*a);
         cout << x1 <<endl;
     }
    
    else {
        cout << "Vo nghiem" <<endl;
    }
    } 
return 0;
}
