// Cairo University
// Faculty of Computers and Information
// under supervision: Dr. Abdelhady Nabih
// Program Name: Maclaurin Expansions Application/Calculator.
// Date: 10/06/2018
// Author: Abdelrahman Mohamed Ahmed Mahmoud Hemeid
// ID: 20170148 , Group : G6
////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
int main()
{
    int operation ;
    cout << "Enter the Number of the Operatrion: " << endl;
    cout << "1- Count sin(x) " << endl;
    cout << "2- Count cos(x) " << endl;
    cout << "3- Count e to power x " << endl;
    cout << "4- Count ln(x) " << endl;
    cout << "5- Count tan^-1(x)  " << endl;
    cin >> operation ;
    switch (operation)
    {
    case 1 :
    {

        long double x, power ;
        cout << " enter the value of x : " ;
        cin >> x ;
        while (x > 360)
        {
            x-=360;
        }
        while (x < 0)
        {
            x+=360;
        }
        string sign ;
        if (x>90 && x<180)
        {
            x=180-x ;
            sign = "" ;
        }
        else if (x>=180 && x<270)
        {
            x-=180 ;
            sign = "-" ;
        }
        else if (x>=270 && x<=360)
        {
            x=360-x ;
            sign = "-" ;
        }
        x=(3.14*x)/180 ;
        power = x ;
        long double sum = 0 ;
        unsigned long long factorial = 1 ;
        for (int i=1 ; i < 60 ; ++i)
        {
            factorial=factorial*i ;
            if (i%2 == 0)
            {
                x*=-1 ;
            }
            else if (i%4 == 0)
            {
                x*=-1 ;
            }
            else if (i%2 != 0)
            {
                sum += x/factorial ;
            }
            x*=power ;

        }
        if (sum==0)
            cout << " the result is : " << sum << endl ;
        else
            cout << " the result is : " << sign << sum << endl ;

        main();

    }

    case 2 :
    {

        long double x, power ;
        cout << " enter the value of x : " ;
        cin >> x ;
        while (x > 360)
        {
            x-=360;
        }
        while (x < 0)
        {
            x+=360;
        }
        string sign ;
        if (x>90 && x<=180)
        {
            x=180-x ;
            sign = "-" ;
        }
        else if (x>180 && x<=270)
        {
            x-=180 ;
            sign = "-" ;
        }
        else if (x>270 && x<=360)
        {
            x=360-x ;
            sign = "" ;
        }
        x=(3.14*x)/180 ;
        power = x ;
        long double sum = 1 ;
        unsigned long long factorial = 1 ;
        for (int i=1 ; i < 60 ; ++i)
        {
            factorial=factorial*i ;
            if (i%4 == 0)
            {
                x*=-1 ;
                sum += x/factorial ;
            }
            else if (i%2 == 0)
            {
                x*=-1 ;
                sum += x/factorial ;
            }
            x*=power ;

        }
        if (sum==0)
            cout << " the result is : " << sum << endl ;
        else
            cout << " the result is : " << sign << sum << endl ;

        main();
    }


    case 3 :
        {
        long double x ;
        cout << " enter the value of x : " ;
        cin >> x ;
        long double sum = 1 ;
        long double factorial = 1 ;
        for (int i=0 ; i <= 700000 ; i++)
        {
            factorial *= x /(i+1);
            sum += factorial ;
        }


        cout << " the result is : " << fixed << sum << endl ;

        main();

        }
    case 4 :
        {
        long double x ;
        cout << " enter the value of x : " ;
        cin >> x ;
        long double factorial = x , sum = x ;
        for (int i=1 ; i <= 50000 ; i++)
        {
            factorial *= (x/(i+1)) ;
            sum -= factorial ;
            factorial *= (i+1) ;
        }
        cout << " the result is : " << fixed << sum << endl ;

        main();
        }
    case 5 :
        {
            long double  x, total,initial;// initial element in series

            cout<<" enter the value of x : ";
            cin>> x ;
            initial= x ;
            total=x ;
            for(int i=0; i<=500000; i++)
            {
                initial*=(((-1)*(x*x)*(2*i+1))/(2*i+3));//The ratio between every Consecutive elements
                total+=initial;//sum of series
            }
            total*=180.0/(22.0/7.0); // convert Angle from radian to degree
            while (total>360)
            {
                total = total - 360 ;
            }
            while(x< 0)
            {
                total = total + 360 ;
            }
            cout<<fixed <<total<<endl;

            main() ;
        }
    }
    return 0;
}
