/*
 * account.h
 *
 *  Created on: 17-May-2022
 *      Author: LearningSector
 */

#include<iostream>
#include<string>
#include<list>
#include<memory>
using namespace std;

#ifndef ACCOUNT_H_
#define ACCOUNT_H_

class contact
{
private:

		 	int accountId;
			string address;
			int code;
			string city;
			string state;
			string number;

public:
contact();
~contact();
contact(contact& cont);
friend std::ostream& operator<<( std::ostream& stream, unique_ptr<contact> D );
void askUser();
void addId(int id);
int getId();
string getAddress();
};

class account
{
private:
	struct accNode
	{
		int accID;
		string accName;
		float accBalance;
		accNode(int id, string name, float balance);
	};
	int ref_value;
	float ref_per;
	list<accNode*> acc;
	list<unique_ptr<contact>> accContact;
public:

    account();
	void addContact();
    void displayMenu();
	void printAccount(accNode* it);
	void addAccount(string name, float balance);
	accNode* findAccountById(int id);
	void displayAccount();
    void totalBalance();
	void addDeposit(accNode* deposit);
    bool matchedId(accNode* it);
    float sumBalance(int sum, accNode* it2);
    void removeAccount(int id);
	void withdrawBalance(accNode* withdraw);
	void calculateDividend(int per);
	accNode* findTransform(accNode* per);
	void findDividend(int val);
};


#endif /* ACCOUNT_H_ */
