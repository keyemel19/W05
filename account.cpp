#include<iostream>
#include<string>
#include<stdexcept>
#include"account.h"
#include <functional>
#include <algorithm>
#include<bits/stdc++.h>
#include <list>
#include<memory>


contact::contact()
{
accountId=-1;
address="";
code=0;
city="";
state="";
number="";
}
contact::contact(contact& cont)
{
cont.accountId=this->accountId;
cont.address=this->address;
cont.code=this->code;
cont.city=this->city;
cont.state=this->state;
cont.number=this->number;
}
void contact::addId(int id)
{
accountId=id;
}
contact::~contact()
{

}
void contact::askUser()
{
cin.ignore(1,'\n');
cout<<"Enter Address: "<<"\n";
std::getline(cin, address);
cout<<"Enter City: ";
std::getline(cin, city);
cout<<"Enter State: ";
std::getline(cin, state);
cout<<"Enter Zip Code: ";
cin>>code;
cin.ignore(1,'\n');
cout<<"Enter Phone Number: ";
std::getline(cin, number);
}
int contact::getId()
{
	return accountId;
}
std::ostream& operator<<( std::ostream& stream, unique_ptr<contact> D )
{
	stream<<"++ Contact Information: "<<"Address: "<<D->address<<" city: "<<D->city<<" state: "<<D->state<<" zip: "<<D->code
			<<" phone: "<<D->number<<"\n";
	return stream;
}

string contact::getAddress()
{
return address;
}





account::account()
{
 ref_value=-1;
 ref_per=-1;
}

void account::addContact()
{
auto cont=unique_ptr<contact>(new contact);
int id;
cout<<"Enter the ID of the account to find: ";
cin>>id;
  	   if(findAccountById(id)==NULL)
  	   {
           cout<<"Account Not Found!"<<"\n";
           return;
  	   }
printAccount(findAccountById(id));
cont->addId(id);
cont->askUser();
accContact.push_back(move(cont));
cout<<"Added Succesfully."<<"\n";
return;
}

account::accNode::accNode(int id, string name, float balance)
{
accID=id;
accName=name;
accBalance=balance;
}
void account::displayMenu()
{
 cout<<"Account Menu:"<<"\n";
 cout<<"0. Quit Program"<<"\n";
 cout<<"1. Display Account Information"<<"\n";
 cout<<"2. Add a deposit to an account"<<"\n";
 cout<<"3. Withdraw from an account"<<"\n";
 cout<<"4. Add new account"<<"\n";
 cout<<"5. Find account by ID"<<"\n";
 cout<<"6. Remove account"<<"\n";
 cout<<"7. Show total balance for all accounts"<<"\n";
 cout<<"8. Add a dividend to all accounts"<<"\n";
 cout<<"9. Add contact information to an account"<<"\n";
 cout<<"Your choice: ";
}

void account::addAccount(string name, float balance)
{
	int id=acc.size();
	while(true)
	{
		if(findAccountById(id)==NULL)
		{
			break;
		}
     id++;
	}
accNode* tempAcc=new accNode(id, name, balance);
acc.push_back(tempAcc);
cout<<"Your Account ID: "<<id;
}
void account::printAccount(accNode* it)
{
	cout<<"Account ID: "<<(it)->accID<<" Name: "<<(it)->accName<<" Balance: "<<(it)->accBalance<<"\n";
	for(auto it1=accContact.begin();it1!=accContact.end();++it1)
	{
         if((*it1)->getId()==it->accID)
        	 {
        	 cout<<move(*it1);
        	 }
	}
}

void account::displayAccount()
{
	list<account::accNode*>::iterator it;
	if(acc.size()==0)
	{
		cout<<"No Account Found"<<"\n";
		return;
	}
	for_each(acc.begin(),acc.end(),std::bind1st(std::mem_fun(&account::printAccount),this));

}
account::accNode* account::findAccountById(int id)
{
	list<account::accNode*>::iterator it;
	for(it=acc.begin();it!=acc.end();++it)
		if((*it)->accID==id)
			{
			return (*it);
			}
	return NULL;
}
bool account::matchedId(accNode* it)
{
if(it->accID==ref_value)
{
	cout<<"In Account destructor (name is "<<it->accName<<")"<<"\n";
	return true;
}
return false;
}

void account::removeAccount(int id)
{
	ref_value=id;
acc.remove_if(std::bind1st(std::mem_fun(&account::matchedId),this));
for(auto it=accContact.begin();it!=accContact.end();++it)
{
  if((*it)->getId()==id)
  {
	  cout<<"\n\nIn Contact destructor (address is "<<(*it)->getAddress()<<")"<<"\n";
	accContact.erase(it);
			return ;
  }
}
}
float account::sumBalance(int sum, accNode* it2)
{
 return sum+it2->accBalance;
}
void account::totalBalance()
{
float sum=0;
auto f=bind(&account::sumBalance,this, std::placeholders::_1, std::placeholders::_2);
cout<<"Total Balance: "<<accumulate(acc.begin(), acc.end(), sum, f)<<"\n";

}
void account::addDeposit(accNode* deposit)
{
float addBalance;
cout<<"Found account: "<<" Account ID: "<<deposit->accID<<" Name: "<<deposit->accName<<" Balance: "<<deposit->accBalance<<"\n";
cout<<"Amount to deposit: ";
cin>>addBalance;
deposit->accBalance=deposit->accBalance+addBalance;
cout<<"New Balance: "<<" Account ID: "<<deposit->accID<<" Name: "<<deposit->accName<<" Balance: "<<deposit->accBalance<<"\n";
}

void account::withdrawBalance(accNode* withdraw)
{
float balance;
cout<<"Found account: "<<" Account ID: "<<withdraw->accID<<" Name: "<<withdraw->accName<<" Balance: "<<withdraw->accBalance<<"\n";
cout<<"Amount to deposit: ";
cin>>balance;
if (withdraw->accBalance-balance>0)
{
	withdraw->accBalance=withdraw->accBalance-balance;
}
else
{
	withdraw->accBalance=0;
}

cout<<"New Balance: "<<" Account ID: "<<withdraw->accID<<" Name: "<<withdraw->accName<<" Balance: "<<withdraw->accBalance<<"\n";
}
account::accNode* account::findTransform(accNode* per)
{
		per->accBalance=per->accBalance+((per->accBalance*ref_per)/100);
  return per;
}
void account::findDividend(int per)
{
ref_per=per;
transform(acc.begin(), acc.end(),acc.begin(),std::bind1st(std::mem_fun(&account::findTransform),this));
cout<<"Dividend Added Successfully."<<"\n";
}

