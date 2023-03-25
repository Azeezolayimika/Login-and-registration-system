/*  C++ Program for Username and Password Registration System  */

#include<iostream>
#include<fstream>
using namespace std;

struct mail
{
    char fname[50];             // First Name
    char lname[50];             // Last Name
    char dept[50];				// Department
    char mnum[50];				//Matric Number
    char pd[50];				//Password
    void reg(int);
} obj[10];

void mail::reg(int k)
{
    int i=k;
    cout<<"\nEnter First Name :: ";
    cin>>fname;
    
    cout<<"\nEnter Last Name :: ";
    cin>>lname;
    
    cout<<"\nEnter Department :: ";
    cin>>dept;
    
    cout<<"\nEnter Matric Number :: ";
    cin>>mnum;
    
    cout<<"\nEnter password :: ";
    cin>>pd;

    ofstream filout;
//    filout.open("C:\\Users\\acer\\Documents\\registration.txt",ios::app|ios::binary);
    filout.open("registration.txt",ios::app|ios::binary);
    if(!filout)
    {
        cout<<"\nCannot open file\n";
    }
    else
    {
        cout<<"\n";
        filout.write((char *)&obj[i],sizeof(mail));
        filout.close();
    }

    cout<<"\n...........You are now registered.......... \n\n";

}   // end of sign up or register func

int main()
{
    int t;
    cout<<"\nEnter Registration Details for User 1 :: \n";
    obj[0].reg(0);
//    cout<<"\nEnter Registration Details for User 2 :: \n";
//    obj[1].reg(1);
//    cout<<"\nEnter Registration Details for User 3 :: \n";
//    obj[2].reg(2);

    mail obj2;

    ifstream filein;
    filein.open("registration.txt",ios::in|ios::binary);
    if(!filein)
    {
        cout<<"\nUnable to open file to read\n";
    }
    else
    {
        cout<<"\nRegistered Details of All Users :: \n";
        filein.read((char *)&obj2,sizeof(obj2));
        while(filein)
        {
            cout<<"\nLast Name :: "<<obj2.lname
			<<"\nFirst Name :: "<<obj2.fname
			<<"\nDepartment :: "<<obj2.dept
			<<"\nMatric Number :: "<<obj2.mnum
			<<"\nPassword :: "<<obj2.pd
			<<"\n";
            filein.read((char *)&obj2,sizeof(obj2));
        }
            //filein.close();
    }
        return 0;
}
