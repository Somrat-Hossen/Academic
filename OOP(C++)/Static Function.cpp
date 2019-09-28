#include <iostream>
using namespace std;

class Account
{
    public:
    int balance;
     Account()
     {
        balance = 0;
    }
    static Account getAcc(Account a, Account b)
    {
        Account ac;
        ac.balance = a.balance+b.balance;
        return ac;
    }
};
int main(){
    Account a1;
    a1.balance = 50;
    Account a2;
    a2.balance = 60;
    Account b = Account::getAcc(a1,a2);
    cout << b.balance << endl;
}
