#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

int main()
{
    double T_OutsideTemprture=0.0;
    double v_Velocity=0.0;
    double T_WindChill=0.0;

    ///T_WindChill= 13.12 + (0.6215*T_OutsideTemprture) - 11.37* pow(v_Velocity,0.16) + 0.3965 * pow(v,0.16);

    cout<<"please Enter the temprture in degrees Celsius : ";
    cin >>T_OutsideTemprture;
    cout<<"please Enter the wind speed in Kilometers : ";
    cin>>v_Velocity;

     if (v_Velocity >=4 && T_OutsideTemprture >= -50 && T_OutsideTemprture <= 5 ){
        T_WindChill= 13.12 + (0.6215*T_OutsideTemprture) - 11.37* pow(v_Velocity,0.16) + (0.3965*T_OutsideTemprture) * pow(v_Velocity,0.16);
        cout<<"The Wind Chill Temprture is : "<<setprecision(4)<<T_WindChill<<endl;
     }
     else {
        cout<<" Error! Try again one more time "<<endl;
        cout<<"please Enter the temprture in degrees Celsius : ";
        cin >>T_OutsideTemprture;
        cout<<"please Enter the wind speed in Kilometers : ";
        cin>>v_Velocity;
            if (v_Velocity >=4 && T_OutsideTemprture >= -50 && T_OutsideTemprture <= 5 ){
                T_WindChill= 13.12 + (0.6215*T_OutsideTemprture) - 11.37* pow(v_Velocity,0.16) + (0.3965*T_OutsideTemprture) * pow(v_Velocity,0.16);
                cout<<"The Wind Chill Temprture is : "<<setprecision(4)<<T_WindChill<<endl;
            }
            else {
                cout<<" Error! Please rerun the program and try again "<<endl;
                return 0;
            }
     }
}
