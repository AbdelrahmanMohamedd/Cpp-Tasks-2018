#include <iostream>
#include<cmath>

using namespace std;

int main()
{
    float Center_X , Center_Y , Radius , PointX , PointY  , distance;

    cout<<"Enter the Coordinates of the Center : " ;
    cin>>Center_X>>Center_Y;

    cout<<"Enter the Radius of the circle : " ;
    cin>>Radius;

    cout<<"Enter the Coordinates of the point : " ;
    cin>>PointX>>PointY;

    distance=sqrt(pow((PointX-Center_X),2)+ pow((PointY-Center_Y),2));

    if (distance<Radius){

        cout<<"This point lies inside the circle"<<endl;
    }
    if (distance>Radius){

        cout<<"This point lies outside the circle"<<endl;
    }
    if (distance==Radius){

        cout<<"This point lies on the circle"<<endl;
    }

    return 0;
}
