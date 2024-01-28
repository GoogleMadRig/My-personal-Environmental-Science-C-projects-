//
//  main.cpp
//  Converting with the ideal gas law
//
//  Created by David Heiblum on 10/8/23.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace  std;
double Calculating_Pressure(double Volume,double moles, double R, double Temp);
double Calculating_Volume(double Pressure,double moles, double R, double Temp);
double Calculating_Moles(double Pressure, double Volume,double R, double Temp);
double Calculating_Temperature(double Pressure, double Volume,double moles, double R);
int main(int argc, const char * argv[]) {
    // insert code here...
    double R=0.08206;
    cout<<"Do you need to deal with the ideal gas law equation but don't want to bother with doing tghe actual calculations themselves? Well, you come to the right place. To get started, let's figure what values for gas pressure,volume,moles and Temperature gthat you already know/given.\n";
    cout<<"Don't worry about entering the R value by either keyboard input or file input userr. It is "<<R<<"L·atm/K·mol.\n";
    char PressureInput;
    cout<<"Do you want to enter gas pressure via keyboard input(k) or file input(f).\n";
    cin>>PressureInput;
   
    double Pressure=0.00;
    if (PressureInput == 'K' || PressureInput == 'k')
    {
        cout<<"Please enter your gas pessure in atmospheres.\n";
        cin>>Pressure;
        cout<<"The gas pressure that you entered is "<<Pressure<<" atms.\n";
    }
    else if (PressureInput== 'F'|| PressureInput=='f')
    {
        string file_name;
        cin>> file_name;
        ifstream in_stream;
         in_stream.open(file_name);
          if (in_stream.fail())
          {
              cout << "Input file opening process failed.\n";
              exit(1);
          }
              while(!in_stream.eof())
              {
                  in_stream>> Pressure;
                  cout <<"The gas pressure that is recieved from input file is "<<Pressure<<" atms.\n";
              }
        in_stream.close();
    }
    else
    {
        cout<<"Invalid user input.\n";
        exit(1);
    }
   
    char VolumeInput;
    cout<<"Do you want to enter your volume in liters via keyboard(k) or file input(f).\n";
    cin>>VolumeInput;
    double Volume=0.00;
    if (VolumeInput=='K'||VolumeInput=='k')
    {
        cout<<"Please enter your gas volume in liters.\n";
        cin>>Volume;
        cout<<"The gas volume that you entered is "<<Volume<<" liters(L).\n";
    }
    else if (VolumeInput== 'F'|| VolumeInput=='f')
    {
        string file_name;
        cin>> file_name;
        ifstream in_stream;
         in_stream.open(file_name);
          if (in_stream.fail())
          {
              cout << "Input file opening process failed.\n";
              exit(1);
          }
              while(!in_stream.eof())
              {
                  in_stream >>Volume;
                  cout <<"The gas volume that is recieved from input file is "<<Volume<<" liters(L).\n";
              }
        in_stream.close();
    }
    else
    {
        cout<<"Invalid user input.\n";
        exit(1);
    }
    char molesInput;
    double moles=0.00;
    cout<<"Do you want to enter your gas amount via keyboard(K) or file input(F).\n";
    cin>>molesInput;
    if (molesInput=='K'||molesInput=='k')
    {
      
        cout<<"Please enter your gas amount in moles.\n";
        cin>>moles;
        cout<<"The gas amount that you entered is "<<moles<<" moles.\n";
    }
else if (molesInput == 'F'|| molesInput=='f')
{
    string file_name;
    cin>> file_name;
    ifstream in_stream;
    in_stream.open(file_name);
    if (in_stream.fail())
    {
        cout << "Input file opening process failed.\n";
        exit(1);
    }
    double moles=0.00;
    while(!in_stream.eof())
    {
        in_stream >>moles;
        cout <<"The gas amount that is recieved from input file is "<<moles<<" moles.\n";
    }
    in_stream.close();
}
else{
    cout<<"Invalid user input.\n";
    exit(1);
}
          
        char TempInput;
        cout<<"Do you want to enter your gas temperature via keyboard(K) or file input(F).\n";
        cin>> TempInput;
    double Temp=0.00;
    if (TempInput=='K'||TempInput=='k')
    {
        cout<<"Please enter your gas temperature in Kelvins(K).\n";
        cin>>Temp;
        cout<<"The gas temperature that you entered is "<<Temp<<" Kelvins(K).\n";
    }
   else if (TempInput== 'F'||TempInput== 'f')
    {
        string file_name;
        cin>> file_name;
        ifstream in_stream;
        in_stream.open(file_name);
        if (in_stream.fail())
        {
            cout << "Input file opening process failed.\n";
            exit(1);
        }
        while(!in_stream.eof())
        {
            in_stream >>Temp;
            cout <<"The gas temperature that is recieved from input file is "<<Temp<<" Kelvins(K).\n";
        }
        in_stream.close();
    }
    else
    {
        cout<<"Invalid option. Exiting now.\n";
        exit(1);
    }
        int user_choice=0;
        cout<<"With the ideal gas law, what do you ned to calculate? 1 for Pressure(atms), 2 for Volume(Liters), 3 for moles and 4 for temperature(Kelvins).\n";
        cin>>user_choice;
        cout<<"You choose "<<user_choice<<endl;
    switch (user_choice) {
        case 1:
           Pressure=Calculating_Pressure(Volume,moles,R,Temp);
            cout<<"Your calculated gas presure is "<<Pressure<<" atms.\n";
            char user_write_option;
            cout<<"Do you want to write this result to a file on disk? Yes(Y)or No(N).\n";
            cin>>user_write_option;
            if (user_write_option == 'Y' || user_write_option == 'y') {
                string file_name;
                cout << "What do you want to call the output file?\n";
                cin >> file_name;
                ofstream out_stream;
                out_stream.open(file_name);
                if (out_stream.fail()) {
                    cout << "Output file opening process failed.\n";
                    exit(1);
                }
                out_stream << "Your calculated gas pressure is " << Pressure << " atm.\n";
                out_stream.close();
            } else if (user_write_option == 'N' || user_write_option == 'n') {
                cout << "Oh ok. Exiting now.\n";
            } else {
                exit(1);
            }
                break;
            case 2:
            Volume=Calculating_Volume(Pressure, moles, R, Temp);
            cout<<"Your calculated gas volume is "<<Volume<<" liters(L).\n";
            cout<<"Do you want to write this result to a file on disk? Yes(Y)or No(N).\n";
            cin>>user_write_option;
            if (user_write_option == 'Y' || user_write_option == 'y') {
                string file_name;
                cout << "What do you want to call the output file?\n";
                cin >> file_name;
                ofstream out_stream;
                out_stream.open(file_name);
                if (out_stream.fail()) {
                    cout << "Output file opening process failed.\n";
                    exit(1);
                }
                out_stream<<"Your calculated gas volume is "<<Volume<<" liters(L).\n";
                out_stream.close();
            } else if (user_write_option == 'N' || user_write_option == 'n') {
                cout << "Oh ok. Exiting now.\n";
            } else {
                exit(1);
            }
                break;
            case 3:
            moles=Calculating_Moles(Pressure,Volume,R,Temp);
            cout<<"Your calculated gas amount is "<<moles<<" moles.\n";
            cout<<"Do you want to write this result to a file on disk? Yes(Y)or No(N).\n";
            cin>>user_write_option;
            if (user_write_option == 'Y' || user_write_option == 'y') {
                string file_name;
                cout << "What do you want to call the output file?\n";
                cin >> file_name;
                ofstream out_stream;
                out_stream.open(file_name);
                if (out_stream.fail()) {
                    cout << "Output file opening process failed.\n";
                    exit(1);
                }
                out_stream<<"Your calculated gas amount is "<<moles<<" moles.\n";
                out_stream.close();
            } else if (user_write_option == 'N' || user_write_option == 'n') {
                cout << "Oh ok. Exiting now.\n";
            } else {
                exit(1);
            }
            case 4:
            Temp=Calculating_Temperature( Pressure, Volume, moles, R);
            cout<<"Your calculated gas temperature is "<<Temp<<" Kelvins(K).\n";
            cout<<"Do you want to write this result to a file on disk? Yes(Y)or No(N).\n";
            cin>>user_write_option;
            if (user_write_option == 'Y' || user_write_option == 'y') {
                string file_name;
                cout << "What do you want to call the output file?\n";
                cin >> file_name;
                ofstream out_stream;
                out_stream.open(file_name);
                if (out_stream.fail()) {
                    cout << "Output file opening process failed.\n";
                    exit(1);
                }
                out_stream<<"Your calculated gas temperature is "<<Temp<<" Kelvins(K).\n";
                out_stream.close();
            } else if (user_write_option == 'N' || user_write_option == 'n') {
                cout << "Oh ok. Exiting now.\n";
            } else {
                exit(1);
            }
            default:
                cout<<"Invalid option. Exiting now.\n";
                exit(1);
                break;
            }
    return 0;
    };
double Calculating_Pressure(double Volume,double moles, double R, double Temp)
{
   double Pressure=0.00;
    Pressure=moles*R*Temp/Volume;
    return Pressure;
}
double Calculating_Volume(double Pressure,double moles, double R, double Temp)
{
   double Volume=0.00;
    Volume=moles*R*Temp/Pressure;
    return Volume;
}
double Calculating_Moles(double Pressure, double Volume, double R, double Temp)
{
    double moles=0.00;
    moles=(Pressure*Volume)/(R*Temp);
    return moles;
}
double Calculating_Temperature(double Pressure, double Volume,double moles, double R)
{
 double Temp=0.00;
    Temp=(Pressure*Volume)/(moles*R);
    return Temp;
}
