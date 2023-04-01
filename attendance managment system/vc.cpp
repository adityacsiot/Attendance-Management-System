#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;

class student
{
    private:
        char name[20],branch[10];
        int semester,rollno;
    public:
        void input();
        void display();
};
void student::input()
{
    cout<<"enter name:-"<<endl;
    cin>>name;
    cout<<"enter the roll number:-"<<endl;
    cin>>rollno;
    cout<<"enter the branch:-"<<endl;
    cin>>branch;
    cout<<"enter semester:-"<<endl;
    cin>>semester;
}
void student::display()
{
    cout<<"name:-"<<name<<endl;
    cout<<"roll number:-"<<rollno<<endl;
    cout<<"branch:-"<<branch<<endl;
    cout<<"semester:-"<<semester<<endl;
}
void enter_value(int number,int lecture,int arr[25][32]){
    for(int i = 0; i < lecture; i++){
        cout<<"lecture:-"<<i+1<<endl;
        for(int j = 0; j < number; j++){
            cout<<"mark present or absent for present = 1 or absent = 0"<<endl;
            cin>>arr[i][j];
        }
    }
}
void calculate(int number,int lecture,int arr[25][32]){
    int sum = 0;
    for(int i = 0; i <lecture; i++){
        for(int j = 0; j < number; j++){
            sum = sum +arr[i][j];
        }
         int percent;
         percent = (sum*100)/lecture;
         if(percent < 75){
            cout<<"student index number "<<i<<"has  short attendance"<<endl;
        }
    }
}
void mainmenu();

int choice; 
bool cinfail; 
int confirmation; 
string username, password, password2;

void writetofile(string username){
    ofstream writefile;
    string file = username+".txt";
    writefile.open(file.c_str());
    writefile << password;
    writefile.close();
    mainmenu(); 
    }

void login(){
    cout << "You are being logged in!";}

void registerpassword(){
    cout << "Please enter the password:" << endl;
    cin >> password;
    cout << "Please renter your password:" << endl;
    cin >> password2;
    if (password == password2){
        cin.clear();
        cin.ignore(10000,'\n');
        writetofile(username);
        exit(1);
    }
    else;{
        cout << "Sorry invalid" << endl;
        registerpassword();
    }}


void registerme(){
    cout << "Please enter your username: " << endl;
    getline(cin, username);
    cout << "\nUsername -  \""<< username << "\"\nConfirm? \n\n[1] Yes\n[2] No" << endl;
    cin >> confirmation;
    if (confirmation == 1){
        registerpassword();
    }

    else; {
        cout << "Sorry invalid input, Please try again" << endl;
        cin.clear();
        cin.ignore(10000,'\n');
        registerme();
    }}


void exit(){
    exit(0);}

void mainmenu(){ cout << "Hello, Would you like to log in or register\n[1] Login\n[2] Register\n[3] Exit" <<endl; cin >> choice; do{
    cinfail = cin.fail();
    cin.clear();
    cin.ignore(10000,'\n');

    }while(cinfail == true);{
        switch(choice){
            case 1:
                login();
                break;

            case 2:
                registerme();
                break;

            case 3:
                exit();}}} 

int main(){
    int number,pressno,lecture,percentage;
    int arr[25][32];
    char name[10];
    float present, classattended;
   
    cout<<"press 1 for created you account "<<endl;
    cout<<"press 2 for attendance menagement"<<endl;
    cout<<"press 3 for student detail"<<endl;
    cout<<"press 4 for student attendance percentage"<<endl;
   
    cin>>pressno;
    switch(pressno){
        case 1 : mainmenu(); ;
        break;
        case 2 : cout<<"enter the number of student"<<endl;
                cin>>number;
                cout<<"enter the no of lecture"<<endl;
                cin>>lecture;
                 enter_value(number,lecture,arr);
                 calculate(number,lecture,arr);
        break;
        case 3 :cout<<"enter student details"<<endl;
                 student s;
                 s.input();
                 s.display();
        break;

        case 4 :
             cout << "number of days student present"<<endl;
             cin >> present;
             cout << "total number of days attendance"<<endl;
             cin >> classattended;
             percentage = (float)(present / classattended) * 100;
            cout << "you attendance is "<<percentage<<"%"<<endl;
            break;

        default : cout<<"enter valid number"<<endl;
        break;
    }
    return 0;
}