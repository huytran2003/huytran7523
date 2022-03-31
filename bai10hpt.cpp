#include<iostream>
#include <iomanip>
using namespace std;
main()
{
    int T;
    float a1, b1, c1, a2, b2, c2;
    float D, Dx, Dy, x, y;
    cin>>T;
    if ((T>=1)&&(T<=10))
    {
        while (T!=0)
        {
            cin >> a1>> b1>> c1>>a2 >> b2>> c2;
            D = a1 * b2 - a2 * b1;
            Dx = c1 * b2 - c2 * b1;
            Dy = a1 * c2 - a2 * c1;
            if (D == 0) 
            {
                if (Dx + Dy == 0)
                    cout << "Many solutions"<<endl;
                else
                    cout << "No solution"<<endl;
            }
            else 
            {
                x = Dx / D;
                y = Dy / D;
                cout<<setprecision(6)<<fixed<<x<<" ";
                cout<<setprecision(6)<<fixed<<y<<endl;
            }
        T-=1;
        }
    }
}
