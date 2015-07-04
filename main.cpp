
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <cmath>
#include <chrono>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

const int BANKNOTE = 50;
const int MIN_DEPOSIT = 100;
const int MAX_WITHDRAWAL = 2000;
const int MIN_BALANCE = 2000;
const int MAX_BALANCE = 10000;
const int BUFSIZE = 200;

int balance[10];
int rand(void);

int depositd(int a, int b)
{
	int r;
	r = a + b;
	return r;
}

int withdraww(int a, int b)
{
	int r;
	r = a - b;
	return r;
}

void signature()
{
	cout << endl;
	time_t t = time(0); //obtain the current time_t value
	tm now = *localtime(&t); //convert it to tm
	char tmdescr[BUFSIZE] = { 0 };
	const char fmt[] = "%A, %d %B %Y";
	if (strftime(tmdescr, sizeof(tmdescr) - 1, fmt, &now)>0)
		cout << "            -------------Nurul Fazilah     571114     " << tmdescr << "----------------" << endl << endl;
	else
		cerr << " strftime failed. Errno code: " << errno << endl;
}

int main()
{
	signature();
	srand((unsigned)time(NULL));
	balance[0] = rand() % (MAX_BALANCE-1999) + MIN_BALANCE;
	cout << endl << "  Current Account Balance : " << balance[0] << endl << endl;  //number between 2000 and 10000

	int newbalance[10];
	int amount[10];
	amount[0] = BANKNOTE;

	int no_of_bills[10];
	int i = 0;
	int z;

	char answer = 'Y';
	char transaction[10];

	while (i<10 && answer == 'Y')
	{

			cout << endl<<endl <<endl << "  Enter D for Deposit Or W for Withdrawal and press <Enter>: ";
			cin >> transaction[i];

			/********************************************
			** Here's the extra bit for the transaction**
			*********************************************/
			switch (transaction[i])
			{
				case 'D':
				{   
					cout <<endl<< "  Enter the amount to deposit (MIN 100) : ";
					cin >> amount[i];

					if (amount[i] >= MIN_DEPOSIT && amount[i] % BANKNOTE == 0)
					{
						newbalance[i] = depositd(balance[i], amount[i]);
						no_of_bills[i] = amount[i] / BANKNOTE;
						cout << endl <<"  50 Dollar bills required for this transaction is " << no_of_bills[i] << endl;
						cout << endl <<"  My new balance is " << newbalance[i];
						balance[i+1] = newbalance[i];
						i++;	
					}
					else 
					{ 
						cout <<endl << "  You are not allowed to deposit less than 100 and only 50-dollar bills are allowed " << endl; 
					}
				break;
				}
				
				case 'W':
				{   
					cout <<endl << "  Enter the amount to withdraw (MAX 2000) : ";
					cin >> amount[i];
					if (amount[i] <= MAX_WITHDRAWAL && amount[i] % BANKNOTE == 0)
					{
						newbalance[i] = withdraww(balance[i], amount[i]);
						no_of_bills[i] = amount[i] / BANKNOTE;
						cout << endl << "  50 Dollar bills given for this transaction is " << no_of_bills[i] << endl;
						cout << endl << "  My new balance is " << newbalance[i];
						balance[i+1] = newbalance[i];
						i++;
					}
					else 
					{ 
						cout <<endl<< "  You are not allowed to withdraw more than 2000 and only 50-dollar bills are allowed " << endl; 
					}
				break;
				}
			
				default:
					cout << endl<<endl<< "  Invalid input. Please enter D for deposit or W for withdrawal.";
				break;
			}

			cout << endl<< endl << "  Do you wanna make another transaction? (Y/N) ";
			cin >> answer;
		}
	cout <<endl<<endl<< "   Initial Balance----------Transaction Code (D or W)----------Amount To Deposit/Withdraw----------Number Of Banknotes----------Final Balance"<<endl<<endl;
	for (z = 0; z < i; z++)
	{
			cout << "        " << balance[z] << "\t\t|\t\t" << transaction[z] << "\t\t   |\t\t  " << amount[z] << "           \t|\t    " << no_of_bills[z] << "\t\t   |    \t" << newbalance[z] << endl;
	}
	//holds output window open in visual studio
	cin.clear();
	cin.ignore();
	cin.get();

	return 0;
}




