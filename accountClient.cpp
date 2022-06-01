#include<iostream>
#include<string>
#include<list>
#include"account.h"
using namespace std;
int main()
{
account acc;
while(true)
{
int choice=-1;
   acc.displayMenu();
   cin>>choice;
   if(choice==0)
   {
	   break;
   }
   else if (choice==1)
   {
    acc.displayAccount();
   }
   else if(choice==2)
   {
	   int id;
	   cout<<"Enter the ID of the account to find: ";
	   cin>>id;
	   if(acc.findAccountById(id)==NULL)
	   {
         cout<<"Account Not Found!"<<"\n";
	   }
	   else
	   {
         acc.addDeposit(acc.findAccountById(id));
	   }
   }
   else if(choice==3)
   {
	       int id;
	   	   cout<<"Enter the ID of the account to find: ";
	   	   cin>>id;

	   	   if(acc.findAccountById(id)==NULL)
	   	   {
	            cout<<"Account Not Found!"<<"\n";
	   	   }
	   	   else
	   	   {

	            acc.withdrawBalance(acc.findAccountById(id));
	   	   }
   }
   else if(choice==4)
   {
	 string name;
	 int balance;
     cout<<"Enter the name: ";
     cin.ignore(1,'\n');
     getline(cin, name);
     cout<<"Enter the balance: ";
     cin>>balance;
     acc.addAccount(name, balance);
     cout<<"\n";
   }
   else if(choice==5)
   {
	   int id;
	   	   	   cout<<"Enter the ID of the account to find: ";
	   	   	   cin>>id;

	   	   	   if(acc.findAccountById(id)==NULL)
	   	   	   {
	   	            cout<<"Account Not Found!"<<"\n";
	   	   	   }
	   	   	   else
	   	   	   {
	   	   		cout<<"Found account: ";
	   	            acc.printAccount(acc.findAccountById(id));
	   	   	   }
   }
   else if(choice==6)
   {
	   int id;
	   	   	   	   cout<<"Enter the ID of the account to find: ";
	   	   	   	   cin>>id;

	   	   	   	   if(acc.findAccountById(id)==NULL)
	   	   	   	   {
	   	   	            cout<<"Account Not Found!"<<"\n";
	   	   	   	   }
	   	   	   	   else
	   	   	   	   {
	   	   	            acc.removeAccount(id);
	   	   	   	   }
   }
   else if(choice==7)
   {
	acc.totalBalance();
   }
   else if(choice==8)
   {
	   float per;
	   cout<<"Enter Dividend: ";
	   cin>>per;
	   acc.findDividend(per);
   }
   else if(choice==9)
   {
   acc.addContact();
   }

}
}



