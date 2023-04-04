#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Funcs prototypes
double spentDays();
double DepartureTime();
double ArrivalTime();
double planeTicketsCost();
double CarRental();
double DrivenKMs();
double ParkingFees(double days);
double TaxiFees(double days);
double Confer_Seminar_Fees();
double Accommodation (double days);
double MealsCost(double days, double depart, double arrive);

int main()
{
    string firstName,lastName;
    double TripDays=0 ,DepTime=0 ,ArriTime=0 ;
    double PLANEcost=0,CARcost=0,KMScost=0,PARKINGcost=0,TAXIcost=0,CONFER_SEMINAR_cost=0,ACCOMDcost=0,MEALScost=0 , TOTALREJECTEDCOST=0;
    cout << "       ****************************************" << endl;
    cout << "       * Welcome to Travel Expense Calculator *" << endl;
    cout << "       ****************************************" << endl << endl;
    cout << " What is Employee first Name?: ";
    cin >> firstName ;
    cout << " What is Employee second Name?: ";
    cin>> lastName;
    cout <<endl<<" Enter the following information..."<<endl;
    TripDays = spentDays();
    cout << endl;
    DepTime = DepartureTime();
    cout << endl;
    ArriTime = ArrivalTime();
    cout << endl << endl;
    cout << "******************************************************************" << endl << endl;
    cout << endl << " Calculating Traveling cost..." << endl<< endl;
    PLANEcost = planeTicketsCost();
    cout << endl << endl;
    CARcost = CarRental();
    cout << endl << endl;
    KMScost= DrivenKMs();
    cout << endl << endl;
    cout << "******************************************************************" << endl << endl;
    cout << endl << " Calculating Fees..." << endl<< endl;
    PARKINGcost = ParkingFees(TripDays);
    cout << endl << endl;
    TAXIcost = TaxiFees(TripDays);
    cout << endl << endl;
    CONFER_SEMINAR_cost = Confer_Seminar_Fees();
    cout << endl << endl;
    ACCOMDcost= Accommodation(TripDays);
    cout << endl << endl;
    cout << "******************************************************************" << endl << endl;
    cout << endl << " Calculating Meals cost..." << endl << endl;
    MEALScost = MealsCost(TripDays,DepTime, ArriTime);
    cout << endl << endl;
    cout <<"######################################################################" << endl;
    cout <<" The Trip Duration in days >> "<< TripDays <<endl;
    cout <<" Employee depart at >> " << DepTime << endl;
    cout <<" Employee arrive at >> " << ArriTime << endl << endl;
    cout <<" >> Here is a list with extras that spent by the employee and they will be rejected :- "<< endl;
    cout <<" Plane tickets cost: " << PLANEcost<< endl;
    cout <<" Car Cost: " << CARcost<< endl;
    cout <<" Driving with own Car Cost: " << KMScost<< endl;
    cout <<" Parking Cost: " << PARKINGcost<< endl;
    cout <<" Taxi Cost: " << TAXIcost<< endl;
    cout <<" Conferences & Seminars ticket Costs: " << CONFER_SEMINAR_cost<< endl;
    cout <<" Accommodation Cost: "<< ACCOMDcost<< endl;
    cout <<" Meals Cost: " << MEALScost<< endl;

    TOTALREJECTEDCOST = PLANEcost+  CARcost+  KMScost+  PARKINGcost+  TAXIcost+  CONFER_SEMINAR_cost+ ACCOMDcost+ MEALScost;  // calc the rejected costs
    cout << "******************************************************************" << endl << endl;
    cout<<" The total expenses that were rejected for the employee = "<< TOTALREJECTEDCOST<<endl<<endl<<endl;
    cout << "******************************************************************" << endl << endl;
    return 0;
}
/// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double spentDays (){
    double spntDays=0;
    cout<<" How many days were spent in the trip?"<<endl;
    cin>>spntDays;
        while( spntDays < 1 ){
            cout << " Zero and negatives not acceptable, Please enter at least one day" << endl;
            cout << " How many days were spent in the trip?"<<endl;
            cin>>spntDays;
        }
    return spntDays;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double DepartureTime(){
    double departure;
	cout << " At what time did the employee depart on the first day of the trip ? "<<endl;
	cout << " Input should be in range (00.00 - 23.59) Ex: 9.30>>9:30am | 21.30>>9:30pm (24hr format)"<<endl;
	cin >> departure;
        while (departure < 0 || departure > 23.59 || departure - (int)departure > .59) { // what if he arrived at 00:23!
            cout << " Error,Please stick to the input format" << endl;
            cout << " At what time did the employee depart on the first day of the trip ? ";
            cout << " Input should be in range (00.00 - 23.59) Ex: 9.30>>9:30am | 21.30>>9:30pm (24hr format)"<<endl;
            cin >> departure;
        }
    return departure;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double ArrivalTime(){
    double arrival;
	cout << " At what time did the employee arrive back home on the last day of the trip?"<<endl;
    cout << " Input should be in range (00.00 - 23.59) 8.30>>8:30am | 21.30>>9:30pm (24hr format)"<<endl;
	cin >> arrival;
        while (arrival < 0 || arrival > 23.59 || arrival - (int)arrival > .59) {
            cout << " Error,Please stick to the input format" << endl;
            cout << " At what time did the employee arrive back home on the last day of the trip?"<<endl;
            cout << " Input should be in range (00.00 - 23.59) 8.30>>8:30am | 21.30>>9:30pm (24hr format)"<<endl;
            cin >> arrival;
        }
    return arrival;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double planeTicketsCost(){
    int ifplan=0;
    double pTicketsCost=0;
    cout<<" Did employee travel by plane?"<<endl;
    cout<<" If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
    cin>>ifplan;
    while (ifplan!=1 && ifplan!=0){
        cout<<" Only 1 or 0 are valid"<<endl;
        cout<<" Did employee travel by plane?"<<endl;
        cout<<" If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
        cin>>ifplan;
    }
    if (ifplan==1){
        cout<<" How much did the plane tickets cost?"<<endl;
        cin>>pTicketsCost;
        while (pTicketsCost < 0) {
            cout << " Error in your input, try again" << endl;
            cout << " How much was the flight? $";
            cin >> pTicketsCost;
        }
    }
    else{
        cout<<endl;
    }
    return pTicketsCost;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double CarRental(){
    int car = 0 ;
    double  carcost = 0;
    cout<<" For the Car..."<<endl;
    cout<<" Did employee rent a car? "<<endl;
    cout<<" If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
    cin>>car;
    while (car!=1 && car!=0){
            cout<<" Only 1 or 0 are valid"<<endl;
            cout<<" Did employee rent a car? "<<endl;
            cout<<" If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
            cin>>car;
        }
    if (car==1){
        cout<<" How did it cost?"<<endl;
        cin>>carcost;
        while(carcost<0){
            cout<<" Error, Negatives are not accepted"<<endl;
            cout<<" How did it cost?"<<endl;
            cin>>carcost;
        }
    }
    else{
        cout<<endl;
    }
    return carcost;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double DrivenKMs(){
    int ifdrove=0;
    double KMs = 0, DistanceCost = 0;
    cout<<" Did employee used his own car?"<<endl;
    cout<<" If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
    cin>>ifdrove;
    while (ifdrove!=0 && ifdrove!=1){
      cout<<" Only 1 or 0 are valid"<<endl;
      cout<<" Did employee used his own car?"<<endl;
      cout<<" If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
      cin>>ifdrove;
    }
    if(ifdrove==1){
        cout << " How many KMs were driven with his car? "<<endl;
        cin>>KMs;
        while (KMs<0){
            cout<<" Error, Negatives are not accepted"<<endl;
            cout<<" How many KMs were driven with his car? "<<endl;
            cin>>KMs;
        }
    }
    else{
        cout<<endl;
    }
    DistanceCost= KMs*0.775;
    return DistanceCost;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double ParkingFees(double days){
    int ifpfees = 0;
    double ParkFees = 0 ;
    double PfeesSupply= 0;
    cout << " Did the Employee pay any parking fees?! "<<endl;
    cout << " If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
    cin >> ifpfees;
     while (ifpfees!=0 && ifpfees!=1){
          cout << " Only 1 or 0 are valid"<<endl;
          cout << " Did the Employee pay any parking fees?! "<<endl;
          cout << " If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
          cin>>ifpfees;
        }
    if(ifpfees==1){
        cout << " How much was the fees? ";
        cin >> ParkFees;
        while(ParkFees < 0){
            cout << " Error, Negatives are not accepted"<<endl;
            cout << " How much was the fees? "<<endl;
            cin >> ParkFees;
        }
        PfeesSupply=days*25;  //allowed amount from company
        if(ParkFees > PfeesSupply){
            ParkFees = ParkFees -PfeesSupply;
            cout << " Employee paid from his own money : " << ParkFees << " for Parking fees"<<endl;
        }else if (ParkFees <= PfeesSupply) {
            cout << " Employess Paid " << ParkFees << " for Parking fees, and Company covered it !"<<endl;
            ParkFees=0;
        }
    }
    else{
        cout<<endl;
    }
    return ParkFees ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double TaxiFees(double days){
    int ifTfees=0 ;
    double TaxiFee=0 , TaxiFeeSupply=0 ;
    double TaxiTimesUsed=0;
    cout << " Were there any taxi fee's? "<<endl;
    cout << " If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
    cin >> ifTfees;
    while(ifTfees!=0 && ifTfees!=1){
        cout << " Only 1 or 0 are valid"<<endl;
        cout << " Were there any taxi fee's? Y/N: "<<endl;;
        cout << " If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
        cin >> ifTfees;
    }
    if(ifTfees==1){
        cout<<" How many days did you use Taxi?"<<endl;
        cin>>TaxiTimesUsed;
        while(TaxiTimesUsed<0 || TaxiTimesUsed > days ){
            cout<<" Error, Negatives are not accepted"<<endl;
            cout<<" Don't write number more than sepnt days in the trip"<<endl;
            cin >> TaxiTimesUsed;
        }
        cout << " How much was the taxi fees? ";
        cin >> TaxiFee;
        while(TaxiFee < 0){
            cout<<" Error, Negatives are not accepted"<<endl;
            cin >> TaxiFee;
        }
        TaxiFeeSupply=TaxiTimesUsed*100;
         if(TaxiFee > TaxiFeeSupply ){
           TaxiFee = TaxiFee - TaxiFeeSupply ;
           cout << " Employee paid" << TaxiFee << " for Taxi fees" << endl;
        }else if (TaxiFee <= TaxiFeeSupply) {
            cout << " Employess Paid " << TaxiFee << " for Taxi fees, and Company covered it !"<<endl;
            TaxiFee=0;
        }
    }
    else{
        cout<<endl;
    }
    return TaxiFee ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double Confer_Seminar_Fees(){
    int ifConSem=0;
    double EntryFees=0 ;
    cout<<" Did employee attend any conference or seminar ?"<<endl;
    cout << " If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
    cin >> ifConSem;
    while(ifConSem!=1 && ifConSem!=0){
        cout << " Only 1 or 0 are valid"<<endl;
        cout << " Did employee attend any conference or seminar ?"<<endl;
        cout << " If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
        cin >> ifConSem;
    }
    if(ifConSem==1){
        cout<<" How much was the fees ?"<<endl;
        cin>>EntryFees;
        while (EntryFees < 0){
            cout<<" Error, Negatives are not accepted"<<endl;
            cin >> EntryFees;
        }
    }
    else{
        cout<<endl;
    }
    return EntryFees ;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double Accommodation (double days){
    int ifAccomd=0;
    double AccommodPrice=0 ,AccommodPriceSupply=0 ;
    cout << " Were there any Accommodation expenses? "<<endl;
    cout << " If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
    cin >> ifAccomd;
    while(ifAccomd!=1 && ifAccomd!=0){
        cout << " Only 1 or 0 are valid"<<endl;
        cout << " Were there any Accommodation expenses?"<<endl;
        cout << " If YES enter 1 "<<endl<<"If NO enter 0 "<<endl;
        cin >> ifAccomd;
    }
    if(ifAccomd==1){
        cout << " How much were the expenses? ";
        cin >> AccommodPrice;
        while(AccommodPrice < 0){
            cout<<" Error, Negatives are not accepted"<<endl;
            cin >> AccommodPrice;
        }
        AccommodPriceSupply=days*500;
        if(AccommodPrice > AccommodPriceSupply ){
          AccommodPrice = AccommodPrice - AccommodPriceSupply ;
          cout << " Employee pays: " << AccommodPrice << " as Accommodation expenses" << endl;
        }
        else if(AccommodPrice <= AccommodPriceSupply){
            cout << " Employess Paid " << AccommodPrice << " as Accommodation expenses, and Company covered it !"<<endl;
            AccommodPrice=0;
        }
    }
    else{
        cout<<endl;
    }
    return AccommodPrice;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double MealsCost(double days, double depart, double arrive){
    double breaksfastPrice=0 , lunchPrice=0 , dinnerPrice=0 ; // user inputs
    double TotalbreaksfastPrices=0 , TotallunchPrices=0 , TotaldinnerPrices=0 ; //each meal total le kol l days
    double BreakfastSupp=0 , LunchSupp=0 , DinnerSupp=0;   // from the comp
    double MealsCosts=0; // to return it as a whole cost
    cout<<" Its Time to get Meals Costs..."<<endl<<endl;
    cout<<" How much was the Breakfast ?"<< endl;
    cin>>breaksfastPrice;
    while(breaksfastPrice<1){
        cout<<" Error, Zero & Negatives are not accepted"<<endl;
        cout<<" How much was the Breakfast ?"<< endl;
        cin>>breaksfastPrice;
    }
    cout<<" How much was the Lunch ?"<< endl;
    cin>>lunchPrice;
    while(lunchPrice<1){
        cout<<" Error, Zero & Negatives are not accepted"<<endl;
        cout<<" How much was the Lunch ?"<< endl;
        cin>>lunchPrice;
    }
    cout<<" How much was the Dinner ?"<< endl;
    cin>>dinnerPrice;
    while(dinnerPrice<1){
        cout<<" Error, Zero & Negatives are not accepted"<<endl;
        cout<<" How much was the Dinner ?"<< endl;
        cin>>dinnerPrice;
    }
    for (int i=1 ; i<=days ; i++){  // i >> days counter
        //// first day
        if (i==1 && depart==8.0){
            TotalbreaksfastPrices=TotalbreaksfastPrices+breaksfastPrice;
        }
        else if (i==1 && depart==12.0){
            TotallunchPrices=TotallunchPrices+lunchPrice;
        }
        else if (i==1 && depart==18.0){
            TotaldinnerPrices=TotaldinnerPrices+dinnerPrice;
        }
        ////// last day
        else if (i==days && arrive==9.0){
            TotalbreaksfastPrices=TotalbreaksfastPrices+breaksfastPrice;
        }
        else if (i==days && arrive==13.0){
            TotallunchPrices=TotallunchPrices+lunchPrice;
        }
        else if (i==days && arrive==19.0){
            TotaldinnerPrices=TotaldinnerPrices+dinnerPrice;
        }
        else {
            TotalbreaksfastPrices=TotalbreaksfastPrices+breaksfastPrice;
            TotallunchPrices=TotallunchPrices+lunchPrice;
            TotaldinnerPrices=TotaldinnerPrices+dinnerPrice;
        }
    }
    BreakfastSupp=days*40;
    LunchSupp=days*60;
    DinnerSupp=days*80;
    if (TotalbreaksfastPrices > BreakfastSupp){
        TotalbreaksfastPrices = TotalbreaksfastPrices-BreakfastSupp;
        cout << " Employee pays: " << TotalbreaksfastPrices << " for all breakfast meals in the trip" << endl;
    }
    else if( TotalbreaksfastPrices <= BreakfastSupp){
        cout << " Employess Paid " << TotalbreaksfastPrices << " as Breakfasts fees, and Company covered it !"<<endl;
        TotalbreaksfastPrices=0;
    }

    if(TotallunchPrices > LunchSupp){
        TotallunchPrices = TotallunchPrices-LunchSupp;
        cout << " Employee pays: " << TotallunchPrices << " for all Lunch meals in the trip" << endl;
    }
    else if( TotallunchPrices <= LunchSupp){
        cout << " Employess Paid " << TotallunchPrices << " as Lunches fees, and Company covered it !"<<endl;
        TotallunchPrices=0;
    }

    if(TotaldinnerPrices > DinnerSupp){
        TotaldinnerPrices=TotaldinnerPrices-DinnerSupp;
        cout << " Employee pays: " << TotaldinnerPrices << " for all Dinner meals in the trip" << endl;
    }
    else if( TotaldinnerPrices <= DinnerSupp){
        cout << " Employess Paid " << TotaldinnerPrices << " as Dinners fees, and Company covered it !"<<endl;
        TotaldinnerPrices=0;
    }

    MealsCosts= TotalbreaksfastPrices + TotallunchPrices + TotaldinnerPrices ;
    return MealsCosts;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

