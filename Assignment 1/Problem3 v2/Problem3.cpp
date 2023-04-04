#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{ // plan tutorial for user
	string PlanA = " Plan A (Premium) :- \n 1- Call between 7:00AM and 5:00PM (Sunday to Thursday) is billed at a rate of 0.60 L.E/Min (call less than 15 mins) otherwise the rate would be 0.80 L.E/Min \n 2- Call before 7:00AM or after 5:00PM (Sunday through Thursday) is charged at a rate of 0.45 L.E/Min \n 3- Call on a Friday or Saturday is charged at a rate of 0.25 L.E/Min";
	string PlanB = " Plan B (Platinum) :- \n 1- Call between 7:00AM and 5:00PM, (Sunday to Wednesday), is billed at a rate of 0.60 L.E/Min (call lasts less than 30 Mins), otherwise the rate would be 0.80 L.E/Min  \n 2- Call before 7:00AM or after 5:00PM, Sunday through Wednesday, is charged at a rate of L.E. 0.45 per minute \n 3- Call on a Thursday, Friday or Saturday is charged at a rate of 0.25 L.E/Min";

	cout << "\n Welcome to Etisalat..." << endl;
	cout << " Etisalat provides thier customers with 2 plans A & B \n" << endl;
	cout << PlanB << endl << endl;
	cout << PlanA << endl << endl; //show plans
	/// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int plan;
	int Start_Hr, Start_Min, Start_Sec;
	int End_Hr, End_Min, End_Sec;
	int Diff_Hr, Diff_Min, Diff_Sec;
	string Day;
	int DateD, DateM;
/// -------------------------------------------------------------------------------------
	cout << " >>> So, Which plan would you like to deal by ? \n for Plan A enter > 1 \n for plan B enter > 2 " << endl;
	cin >> plan;    //  selecting plan A or B
	if (plan != 1 && plan != 2) {  //input validation
        cout << "ERROR! Invalid input, choose 1 or 2 only, Try again " << endl;
        cin >> plan;
            if ((plan != 1 && plan != 2)) {
                cout << "ERROR! Invalid input, you should enter 1 or 2 only ,So please Rerun the program and try again" << endl;
                return 0;
            }
	}
/// -------------------------------------------------------------------------------------
	cout << " Please enter the START time of the call in 24H format (hh mm ss) respectively..." << endl;
	cin >> Start_Hr >> Start_Min >> Start_Sec;
	/// Start Time validation
	if (Start_Hr < 0 || Start_Min < 0 || Start_Sec < 0  ) {
		cout << "ERROR! Time cant be negative!, Try again " << endl;
        cin >> Start_Hr >> Start_Min >> Start_Sec;
            if (Start_Hr < 0 || Start_Min < 0 || Start_Sec < 0  ) {
               cout << "ERROR! there is no time in negative!, please Rerun the program and try again" << endl;
               return 0;
            }
	}
	else if (Start_Hr > 23 || Start_Min > 59 || Start_Sec > 59) {
		cout << "ERROR! Max values are hh>23 mm>59 ss>59!, Try again" << endl;
        cin >> Start_Hr >> Start_Min >> Start_Sec;
            if (Start_Hr > 23 || Start_Min > 59 || Start_Sec > 59) {
                cout << "ERROR! Max values are hh>23 mm>59 ss>59!, please Rerun the program and try again" << endl;
                return 0;
            }
	}
/// -------------------------------------------------------------------------------------
	cout << " Please enter the END time of the call in 24H format (hh mm ss) respectively..." << endl;
	cin >> End_Hr >> End_Min >> End_Sec;
	/// End Time validation
	if ( End_Hr < 0 || End_Min < 0 || End_Sec < 0) {
        cout << "ERROR! there is no time in negative!,Try again" << endl;
        cin >> End_Hr >> End_Min >> End_Sec;
            if ( End_Hr < 0 || End_Min < 0 || End_Sec < 0) {
                cout << "ERROR! there is no time in negative!, please Rerun the program and try again" << endl;
                return 0;
            }
	}
	else if ( End_Hr > 23 || End_Min > 59 || End_Sec > 59) {
        cout << "ERROR! Max values are hh:23 mm:59 ss:59!, Try again" << endl;
            cin >> End_Hr >> End_Min >> End_Sec;
            if ( End_Hr > 23 || End_Min > 59 || End_Sec > 59)  {
                cout << "ERROR! Max values are hh:23 mm:59 ss:59!, please Rerun the program and try again" << endl;
                return 0;
            }
	}
/// -------------------------------------------------------------------------------------
	cout << " Please enter the DATE of the call (e.g: Thurs 22 4)..." << endl;
	cin >> Day;
	cin >> DateD >> DateM;
	// Date validation
	if (DateD < 0 || DateM < 0 || DateD > 31 || DateM > 12) {
		cout << "ERROR! Day Cant be more than 12 and Days is 31 as max, Aslo they can't be negative, Try again"<< endl;
        cin >> Day;
        cin >> DateD >> DateM;
		if (DateD < 0 || DateM < 0 || DateD > 31 || DateM > 12){
            cout << "ERROR! Day Cant be more than 12 and Days is 31 as max, Aslo they can't be negative ,So please Rerun the program and try again " << endl;
            return 0;
		}
	}
	else if (Day != "Sat" && Day != "Sun" && Day != "Mon" && Day != "Tues" && Day != "Wed" && Day != "Thurs" & Day != "Fri") {
        cin >> Day;
        cin >> DateD >> DateM;
		if  (Day != "Sat" && Day != "Sun" && Day != "Mon" && Day != "Tues" && Day != "Wed" && Day != "Thurs" & Day != "Fri"){
            cout << "ERROR! Check the shown format and make your the same as it is ,So please Rerun the program and try again" << endl;
            return 0;
		}
	}
	else {
		int Temp_Start_Sec = Start_Sec, Temp_Start_Min = Start_Min, Temp_Start_Hr = Start_Hr,
			Temp_End_Sec = End_Sec, Temp_End_Min = End_Min, Temp_End_Hr = End_Hr;

		if (Temp_End_Sec > Temp_Start_Sec) {
			--Temp_Start_Min;
			Temp_Start_Sec += 60;
		}

		int Diff_sec = Temp_Start_Sec - Temp_End_Sec;
		if (Temp_End_Min > Temp_Start_Min) {
			--Temp_Start_Hr;
			Temp_Start_Min += 60;
		}
		int Diff_min = Temp_Start_Min - Temp_End_Min;
		int Diff_hrs = Temp_Start_Hr - Temp_End_Hr;
		int Call_Duration = ((Diff_sec / 60) + Diff_min + (Diff_hrs * 60)) * -1;

        /// start must be BEFORE end
		if ((End_Hr * 3600 + End_Min * 60 + End_Sec) - (Start_Hr * 3600 + Start_Min * 60 + Start_Sec) < 0) {
			cout << "ERROR! its not logical to end a call before its start!!!, please Rerun the program and try again" << endl;
			return 0;
		}
		else {
			cout << " Call Information :- " << endl;
			cout << " Start Time >> " << Start_Hr << ":" << Start_Min << ":" << Start_Sec << endl;
			cout << " End Time >> " << End_Hr << ":" << End_Min << ":" << End_Sec << endl;
			cout << " Date >> " << Day << " " << DateD << "/" << DateM << endl;
			cout << " Call Duration in Minutes >> " << Call_Duration << " Minute " << endl; /// lw 0 sec hydene error fa momkn 23ml +1 3la al min OR lw 00 sec kda hyzwd d2e2a 3al fade
			double rate;

			switch (plan) {
			case 1: // cout << right << setw(50) << setfill(' ') << "  "<<endl;
				cout<< "\n Your plan is Premium (Plan A):-"<<endl; // plan view in tabular form with right alignment
                cout << "                                  " << "<<Call Time>> " << "                     "  << "<<Call Day>>" << "             "<< "<<Duration>>" << "             " << "<<Rate>>" << endl;
                cout << "                                  " << "7:00 am to 5:00 pm " << "                "  << "Sun-Thurs" << "                " << "<15 mins" << "                 " << "0.6" << endl;
                cout << "                                  " << "7:00 am to 5:00 pm " << "                "  << "Sun-Thurs" << "                " << ">=15 mins" << "                " << "0.8" << endl;
                cout << "                                  "  << "5:01 pm to 6:59 am " << "                " << "Sun-Thurs" << "                " << "OtherWise" << "                " << "0.45" << endl;
                cout << "                                  " << "OtherWise " << "                         " << "Fri-Sat" << "                  " << "OtherWise" << "                " << "0.25" << endl;

				if (Day == "Sun" || Day == "Mon" || Day == "Tues" || Day == "Wed" || Day == "Thurs") {
					if (Start_Hr >= 7 && Start_Hr <= 17) {
						if (Call_Duration < 15) {
							rate = Call_Duration * 0.6;
						}
						else {
							rate = Call_Duration * 0.8;
						}
					}
					else {
						rate = Call_Duration * 0.45;
					}
				}
				else if (Day == "Sat" || Day == "Fri") {
					rate = Call_Duration * 0.25;
				}
				cout << "Call rate = " << rate << " LE" << endl;
				break;
				/// ------------------------------------------------------------------------------
			case 2:
				cout << "\n Your plan Platinum (Plan B):-" << endl;   // plan view in tabular form with right alignment
                cout << "                                  " << "<<Call Time>> " << "                     "  << "<<Call Day>>" << "             "<< "<<Duration>>" << "             " << "<<Rate>>" << endl;
                cout << "                                  " << "7:00 am to 5:00 pm " << "                "  << "Sun-Wed" << "                " << "<30 mins" << "                 " << "0.6" << endl;
                cout << "                                  " << "7:00 am to 5:00 pm " << "                "  << "Sun-Wed" << "                " << ">=30 mins" << "                " << "0.8" << endl;
                cout << "                                  "  << "5:01 pm to 6:59 am " << "                " << "Sun-Wed" << "                " << "OtherWise" << "                " << "0.45" << endl;
                cout << "                                  " << "OtherWise " << "                         " << "Thurs-Fri-Sat" << "                  " << "OtherWise" << "                " << "0.25" << endl;

				if (Day == "Sun" || Day == "Mon" || Day == "Tues" || Day == "Wed") {
					if (Start_Hr >= 7 && Start_Hr <= 17) {
						if (Call_Duration < 30) {
							rate = Call_Duration * 0.6;
						}
						else {
							rate = Call_Duration * 0.8;
						}
					}
					else {
						rate = Call_Duration * 0.45;
					}
				}
				else if (Day == "Sat" || Day == "Fri" || Day == "Thurs") {
					rate = Call_Duration * 0.25;
				}
				cout << "Call rate = " << rate << " L.E" << endl;
				break;
			}
			return 0;
		}
	}
	return 0;
}
