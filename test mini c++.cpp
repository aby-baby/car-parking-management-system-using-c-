#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;
class car
{
public:
     int d=0,p;
    char a[100],b[100],c[100];
    float time;
     void input()
    {
        cout<<"\t-------CAN PARK 10 CARS IN THE GARRAGE--------\n";
        cout<<"\tPlease enter the details to park the car!\n";
        d++;
        cout<<"\n\tEnter the name of driver:";
        cin>>a;
        cout<<"\n\tEnter the car number (*without space):";
        cin>>b;
        cout<<"\n\tEnter the no of hours of stay : ";
        cin>>time;
        cout<<"\n\tEnter the parking number:";
        cin>>p;
        if(d<10)
        {
            cout<<"\n\tYour car has been parked! \n\n";
            cout<<"\t-----pay Rs."<<time*10<<" before leaving parking lot!!-----";
        }
        else
        {
            cout<<"parking slot is full!!\n";
        }
    }
    void output()
    {

        cout<<"\n\n-------------------------------------";
        cout<<"\nThe Car No        :"<<b;
        cout<<"\nThe parking NO    :"<<p;
        cout<<"\nThe Driver Name   :"<<a;
        cout<<"\nThe Hours Of Stay :"<<time;
        cout<<"\nAmount to be paid :"<<time*10;
        cout<<"\n-------------------------------------";
    }
     void calculate()
    {

        cout<<"Total rate of parking the car is:";
        cout<<time*10<<"\n";
    }

}u;

main()
{
    int g,l,i;
    char a[100];
    char c,p;
	for(i=1;i<=100;++i)
{
system("color 0a");
system("cls");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tCAR PARKING RESERVATION SYSTEM";
system("color 0b");
cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tLOADING "<<i<<"%";
}
     system("cls");
    do
    {
        system("color 0a");
        cout<<"\n\n\t\t\t\t\t       \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
        cout<<"\n\t\t\t\t\t        CAR PARKING RESERVATION SYSTEM ";
        cout<<"\n\n\t\t\t\t\t       \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n";
        int f;
        string r;
        cout<<"\n\nENTER THE ADMIN USERNAME:";
        cin>>r;
        cout<<"\nENTER THE PASSWORD:";
        cin>>f;
        if(r=="admin" &&f==1234)
        {

            do
            {
                system("CLS");
                int choice;
                cout << "\n\n\t\t\t\t\t\t\t ====== CAR PARKING RESERVATION SYSTEM ======";
                cout <<"\n\n                                          ";
                cout<<"\t\t\t===CHOOSE A MENU FROM THE LIST===\n\n";
                cout<<" \n================================================================";
                cout << "\n 1. Arrival of a Car                                           |";
                cout << "\n 2. Total no of cars Arrived                                   |";
                cout << "\n 3. Total parking charges of all cars with details             |";
                cout << "\n 4. Departure of the car                                       |";
                cout<<  "\n 5. Exit                                                       |";
                cout<<" \n================================================================";
                cout << "\n\n";
                cout << " Select Your Choice ::";
                cin>>choice;
               switch(choice)
                {
                case 1:
                {
                    fstream myfile("car1.txt",ios::out|ios::app);
                    u.input();
                    myfile.write((char*)&u,sizeof(u));
                    myfile.close();
                    break;
                }


                case 2:
                {
                    system("CLS");
                    cout << "\n\n\t\t\t\t\t=== View the Records in the Parking Database ===";
                    cout << "\n";
                    fstream myfile("car1.txt",ios::in);
                    int d=1;
                    while (myfile.read((char *)&u,sizeof (u)))
                    {
                        cout << "\n";
                        cout<<"\n\nThe Car position in parking slot : "<<d;
                        d++;
                        u.output();
                        cout<<"\n\n";

                        cout<<endl;
                    }
                    myfile.close();
                    break;
                }
                case 3:
                {
                    system("CLS");
                    ifstream myfile("car1.txt",ios::out|ios::app);
                    int d=1;
                    cout<<"\n\t\t\t\tThe rate of parking car with details is:\n\n";
                    while(myfile.read((char *)&u,sizeof (u)))
                    {
                        cout<<"\n\nThe Car position in parking slot : "<<d<<"\n\n";
                        cout<<"----------------------------------------\n";
                        d++;
                        u.calculate();
                        u.output();
                        cout<<"\n---------------------------------------\n";
                        system("PAUSE");

                    }
                    myfile.close();
                    break;
                }
                case 4:
              {



                    int f=0;
                    system("CLS");
                    int n;

                    cout<<"\n\n\t\tEnter the car parking  number to departure the car : ";
                    cin>>n;
                    fstream inFile;
                    inFile.open("car1.txt",ios::in);
                    fstream outFile;
                    outFile.open("temp.txt", ios::out | ios::app);
                    while(inFile.read((char*)&u, sizeof(u)))
                    {
                        if(u.p!=n)
                        {
                            outFile.write((char*)&u, sizeof(u));
                        }
                        else if(u.p==n)
                        {
                            f++;
                            cout<<"\n\n\t\t Parking Record Deleted succesfully";
                        }
                    }

                    if(f==0)
                    {
                        cout<<"\n\t------>INVALID ENTRY OR CAR HAS BEEN DEPARTURE EARLY<---------";
                    }


                    inFile.close();
                    outFile.close();

                    remove("car1.txt");
                    rename("temp.txt", "car1.txt");
                    break;
                }


                case 5:
                {
                    break;
                }
                default:
                {
                    cout<<"INVALID CHOICE";
                }
                }
                cout<<"\n\n press any key to continue or 6 to exit:";
                cin>>p;

            }
            while(p!='6');
        }
        else
        {
            cout<<"\nINVALID USERNAME OR PASSWORD\n\n";
        }
        cout<<"\n \nPRESS 4 TO RETRY OR PRESS ANY KEY TO EXIT FROM PROGRAM:";
        cin>>l;
        system("CLS");

    }while(l==4);
}
