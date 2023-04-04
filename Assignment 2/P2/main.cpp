#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

void LetsVote();
void Voting(string v1,string v2,string v3);
void NormalElection(string v1,string v2,string v3);
void NewElection(string v1,string v2,string v3);
void WhoIsWinner(string cand1, string cand2, string cand3, int MaxC, int MaxP );

    string cand1,cand2,cand3;
    int NUMofVoters;
    int Vcount1=0 , Vcount2=0 , Vcount3=0;
    int Vpoints1=0 , Vpoints2=0 , Vpoints3=0;

int main(){
    cout <<" ************************************************ " <<endl;
    cout <<" * # Welcome to the Developed Election System # * "<<endl;
    cout <<" ************************************************ " <<endl<<endl;
    cout <<" Enter 3 Names of 3 Candidates Respectively... "<<endl;
    restart1:
    cout <<" 1st Candidate Name: " ;
    cin >> cand1;
    cout <<" 2nd Candidate Name: "  ;
    cin >> cand2;
    cout <<" 3rd Candidate Name: "  ;
    cin >> cand3;
        if ( cand1==cand2 || cand2==cand3 || cand3==cand1 ){
                cout << " Please input Different candidate names (without repetitions!)" <<endl;
               goto restart1;
                }
    cout <<endl<<" How Many Voters in this Elections ?!"<<endl<<" Number of voters: ";
    cin >> NUMofVoters;
        while (NUMofVoters<1){
            cout <<endl<<" How Many Voters in this Elections ?!"<<endl<<" Number of voters: ";
            cout << " Zero and Negative numbers are not accepted!, please enter positive number (x>1) " <<endl;
            cin >> NUMofVoters;
        }
        string vote1,vote2,vote3;
        LetsVote();
        for (int i=1 ; i<=NUMofVoters ; i++){
            cout <<" Elector Number >> ( " << i <<" ), It is your turn... "<<endl;
            Voting(vote1,vote2,vote3);
        }
        int MxCount = max(Vcount1,max(Vcount2,Vcount3));
        int MxPoint = max(Vpoints1,max(Vpoints2,Vpoints3));
        WhoIsWinner(cand1,cand2,cand3, MxCount, MxPoint);
}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LetsVote(){
    cout <<" \n Each voter must vote 1 time by entering the Candidates names in order of his preference  " <<endl;
    cout <<" ***************************************************************************************" <<endl <<endl;
    }
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Voting(string v1,string v2,string v3){
    restart2:
    cout <<" 1st preferences: ";
    cin >> v1;
    cout <<" 2nd preferences: ";
    cin >> v2;
    cout <<" 3rd preferences: ";
    cin >> v3;
        if ( v1==v2 || v2==v3 || v3==v1 ){
            cout << " Please input the names without repetitions!" <<endl;
            goto restart2;
            }
        else if (  (v1!=cand1 && v1!=cand2 && v1!=cand3) || (v2!=cand1 && v2!=cand2 && v2!=cand3) || (v3!=cand1 && v3!=cand2 && v3!=cand3) ){
            cout << " Please Choose right names of the  candidates that we made election for them! "<<endl;
           goto restart2;
        }
        cout << " Thanks for your voting, wait for the results at the end " << endl << endl;
        NormalElection(v1,v2,v3);
        NewElection(v1,v2,v3);
}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void NormalElection(string v1,string v2,string v3){
        if      (v1==cand1) Vcount1++;
        else if (v1==cand2) Vcount2++;
        else if (v1==cand3) Vcount3++;
}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void NewElection(string v1,string v2,string v3){
        if (v1==cand1 && v2==cand2 && v3==cand3 ) {
            Vpoints1+=3;
            Vpoints2+=2;
            Vpoints3+=1;
        }
        else if (v1==cand1 && v2==cand3 && v3==cand2 ) {
            Vpoints1+=3;
            Vpoints3+=2;
            Vpoints2+=1;
        }
        else if (v1==cand2 && v2==cand3 && v3==cand1 ) {
            Vpoints2+=3;
            Vpoints3+=2;
            Vpoints1+=1;
        }
        else if (v1==cand2 && v2==cand1 && v3==cand3) {
            Vpoints2+=3;
            Vpoints1+=2;
            Vpoints3+=1;
        }
        else if (v1==cand3 && v2==cand2 && v3==cand1 ) {
            Vpoints3+=3;
            Vpoints2+=2;
            Vpoints1+=1;
        }
        else if (v1==cand3 && v2==cand1 && v3==cand2 ) {
            Vpoints3+=3;
            Vpoints1+=2;
            Vpoints2+=1;
        }
}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void WhoIsWinner(string cand1, string cand2, string cand3 , int MaxC, int MaxP){
        int MaxCount = MaxC;
        int MaxPoint = MaxP;
        cout << " ************************************************************************"<<endl<<endl;
        cout <<" Votes for each candidate:- " <<endl;
        cout <<" Candidate "<<cand1<<" Got "<< Vcount1 <<" Votes " <<endl;
        cout <<" Candidate "<<cand2<<" Got "<< Vcount2 <<" Votes " <<endl;
        cout <<" Candidate "<<cand3<<" Got "<< Vcount3 <<" Votes " <<endl;
        if (MaxCount == Vcount1) {
            cout<<endl<<" According to the NORMAL Election system, The winner is "<< cand1 <<" as he got "<<Vcount1<<" votes "<<endl<<endl;
        }
        if (MaxCount == Vcount2) {
            cout<<endl<<" According to the NORMAL Election system, The winner is "<< cand2 <<" as he got "<<Vcount2<<" votes "<<endl<<endl;
        }
        if (MaxCount == Vcount3) {
            cout<<endl<<" According to the NORMAL Election system, The winner is "<< cand3 <<" as he got "<<Vcount3<<" votes "<<endl<<endl;
        }
        if (Vcount1 == Vcount2 || Vcount2 == Vcount3 || Vcount3==Vcount1){
            cout<<" Tied in the elections, Please Conduct a run-off election "<<endl<<endl<<endl;
        }
    //////////////////////////////////////////////////////////////
        cout <<" Points for each candidate:- " <<endl;
        cout <<" Candidate "<<cand1<<" Got "<< Vpoints1 <<" Votes " <<endl;
        cout <<" Candidate "<<cand2<<" Got "<< Vpoints2 <<" Votes " <<endl;
        cout <<" Candidate "<<cand3<<" Got "<< Vpoints3 <<" Votes " <<endl;

        if (MaxPoint == Vpoints1) {
            cout<<endl<<" According to the NEW Election system, The winner is "<< cand1 <<" as he got "<<Vpoints1<<" point "<<endl;
        }
        if (MaxPoint == Vpoints2) {
            cout<<endl<<" According to the NEW Election system, The winner is "<< cand2 <<" as he got "<<Vpoints2<<" point "<<endl;
        }
        if (MaxPoint == Vpoints3) {
            cout<<endl<<" According to the NEW Election system, The winner is "<< cand3 <<" as he got "<<Vpoints3<<" point "<<endl;
        }
        if (Vpoints1 == Vpoints2 && Vpoints2 == Vpoints3 && Vpoints3==Vpoints1){
            cout<<" Tied in the elections, Please  Conduct a run-off election "<<endl<<endl<<endl;
        }
}
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

