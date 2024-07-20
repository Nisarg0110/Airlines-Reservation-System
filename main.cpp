#include<iostream>
#include<filesystem>
#include<iomanip>
#include<fstream>


using namespace std;


void mainmenu();
bool oki=false;

class CustomerDetails{

    public:
        static string name,gender;
        string address;
        int age;
        int phoneno;
        static int cid;
        char ok[100];

        void info(){
            cout<<"\nENTER THE CUSTOMER ID : ";
            cin>>cid;
            cout<<"\nENTER THE NAME : ";
            cin>>name;
            cout<<"\nENTER THE AGE : ";
            cin>>age;
            cout<<"\nENTER THE GENDER : ";
            cin>>gender;
            cout<<"\nENTER THE ADDRESS : ";
            cin>>address;

            cout<<"\nYOUR DETAILS ARE STORED : ";
        }
};


int CustomerDetails::cid;
string CustomerDetails::name;
string CustomerDetails::gender;


class FlightRegisaction{

    public:
        static int choice;
        int ichoice;
        int ret;
        static double x;

        void flightbooking(){
            string flights[2]={"CANADA","USA"};

            cout<<"\n__________WELCOME TO THE AIRLINES __________\n"<<endl<<endl;
            for(int i=0;i<2;i++){
                cout<<(i+1)<<". FLIGHT TO : "<<flights[i]<<endl;
            }

            cout<<"PLEASE ENTER THE NUMBER OF FLIGHT TO BOOK"<<endl;
            cin>>choice;


            switch (choice)
            {
            case 1:
                cout<<"\t__________WELCOME TO CANADIAN AIRLINES__________\n"<<endl;

                cout<<"FOLLOWING ARE THE FLIGHTS : "<<endl;

                cout<<"1-> CANADA-99 "<<endl;
                cout<<"21-7-2024 8:00AM PRICE:30000\n"<<endl;
                
                cout<<"2-> CANADA-400 "<<endl;
                cout<<"21-7-2024 8:00AM PRICE:40000\n"<<endl;

                cout<<"PLEASE ENTER THE NUMBER OF FLIGHT : "<<endl;
                cin>>ichoice;
                if(ichoice==1){
                    x=30000;
                    cout<<"\nYOUR FLIGHT IS BOOKED "<<endl;
                }
                else if(ichoice==2){
                    x=40000;
                    cout<<"\nYOUR FLIGHT IS BOOKED "<<endl;
                }
                else{
                    cout<<"\nINVLID INPUT"<<endl;
                    flightbooking();
                }
                cout<<"\t\t PRESS ANY KEY TO GO BACK TO MAIN MENU    \t|"<<endl;
                cin>>ret;
                mainmenu();
                break;
            
            case 2:
                cout<<"\t__________WELCOME TO USA AIRLINES__________\n"<<endl;

                cout<<"FOLLOWING ARE THE FLIGHTS : "<<endl;

                cout<<"1-> USA-99 "<<endl;
                cout<<"21-7-2024 8:00AM PRICE:30000\n"<<endl;
                
                cout<<"2-> USA-400 "<<endl;
                cout<<"21-7-2024 8:00AM PRICE:40000\n"<<endl;

                cout<<"PLEASE ENTER THE NUMBER OF FLIGHT : "<<endl;
                cin>>ichoice;
                if(ichoice==1){
                    x=30000;
                    cout<<"\nYOUR FLIGHT IS BOOKED "<<endl;
                }
                else if(ichoice==2){
                    x=40000;
                    cout<<"\nYOUR FLIGHT IS BOOKED "<<endl;
                }
                else{
                    cout<<"\nINVLID INPUT"<<endl;
                    flightbooking();
                }

                cout<<"\t\t PRESS ANY KEY TO GO BACK TO MAIN MENU    \t|"<<endl;
                cin>>ret;
                mainmenu();
                break;

            
            default:
                cout<<"\t__________INVALID INPUT__________"<<endl;
                mainmenu();
                break;
            }
        }


};


double FlightRegisaction::x;
int FlightRegisaction::choice;

class Ticket:public CustomerDetails,FlightRegisaction
{

    public:
        void bill(){
            string ok="";
            ofstream outf("data.txt");
            {
                outf<<"__________ABC AIRLINES__________"<<endl;
                outf<<"___________TICKET_______________\n"<<endl;
                outf<<"________________________________\n\n"<<endl;



                outf<<"CUSTOMER ID : "<<CustomerDetails::cid<<endl;
                outf<<"CUSTOMER NAME : "<<CustomerDetails::name<<endl;
                outf<<"CUSTOMER GENDER : "<<CustomerDetails::gender<<endl;
                outf<<"__________DESCRIPTION__________: "<<endl<<endl;


                if(FlightRegisaction::choice==1){
                    ok="CANADA";
                }
                else if(FlightRegisaction::choice==2){
                    ok="USA";
                }

                outf<<"DESTINATION :"<<ok<<endl;
                outf<<"FLIGHT COST :"<<FlightRegisaction::x<<endl;
            }
            outf.close();

        }
        void displaybillinfo(){
            ifstream ifs("data.txt");
            {
                if(!ifs){
                    cout<<"\t__________FILE ERROR__________"<<endl;
                }
                while(!ifs.eof()){
                    ifs.getline(ok,100);
                    cout<<ok<<endl;
                }
            }
            ifs.close();
        }
};



class Management{

    public:
        Management(){
            mainmenu();
        }
};


void mainmenu(){
    int choice;
    int ret;

    if(oki){
        return;
    }

    cout << "\n"
         << "\t|---------------------------------------------|\n"
         << "\t|                  ABC AIRLINES               |\n"
         << "\t|---------------------------------------------|\n"
         << "\t|                  MAIN MENU                  |\n"
         << "\t|---------------------------------------------|\n"
         << "\t|                                             |\n"
         << "\t|   PRESS 1 TO ADD CUSTOMER DETAILS           |\n"
         << "\t|   PRESS 2 FOR FLIGHT REGISTRATION           |\n"
         << "\t|   PRESS 3 FOR TICKET AND CHARGES            |\n"
         << "\t|   PRESS 4 TO EXIT                           |\n"
         << "\t|                                             |\n"
         << "\t|---------------------------------------------|\n";


    cout<<"\nENTER THE CHOICE : ";
    cin>>choice;

    CustomerDetails d;
    FlightRegisaction fr;
    Ticket t;

    if(choice==4){
        cout<<"\t__________THANK YOU__________\n"<<endl;
        oki=true;
        return;
    }

    switch (choice)
    {
    case 1:
        cout<<"\t__________ENTER YOUR DETAILS__________"<<endl;
        d.info();
        cout<<"\t\t PRESS ANY KEY TO GO BACK TO MAIN MENU    \t"<<endl;
        cin>>ret;
        mainmenu();
        break;
    
    case 2:
        cout<<"\t__________BOOK A FLIGHT__________"<<endl;
        fr.flightbooking();
        // mainmenu();
        break;
    
    case 3:
        cout<<"\t__________GET YOUR TICKET DETAILS__________"<<endl;
        t.bill();
        cout<<"\t\t PRESS 1 TO SEE YOUR TICKET    \t|"<<endl;
        cin>>ret;
        if(ret==1){
            t.displaybillinfo();
            cout<<"\t\t PRESS ANY KEY TO GO TO MAIN MENU    \t|"<<endl;
            cin>>ret;
            mainmenu();
        }
        else{
            mainmenu();
        }
        mainmenu();
        break;
    
    case 4:
        cout<<"\t__________THANK YOU__________\n"<<endl;
        // exit(0);
        break;
    
    default:
        cout<<"\t__________INVALID INPUT__________"<<endl;
        mainmenu();
        break;
    }

    next:
        oki=true;
        return;
}


int main(){
    Management Man;
    return 0;
}