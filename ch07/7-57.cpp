#include <string>
#include <iostream>

class Account {
	friend std::ostream& print(std::ostream& os, Account& act);
public:
	Account(): Account ("Empty acct name", 0){}
	Account(const std::string &s, double cash=0.0): owner(s), amount(cash) {}

	void calculate() { amount += amount * interestRate; }
	static double rate() { return interestRate; }
	static void rate(double);

private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
	static constexpr int period = 30;
	double daily_tbl[period];
};

double Account::interestRate = initRate();
void Account::rate(double newRate) { interestRate = newRate; }
double Account::initRate() { return 0.05; }
constexpr int Account::period;

std::ostream& print(std::ostream& os, Account& act)
{
	os << act.owner << " has a balance of " << act.amount;
	return os;
}

int main()
{
	Account a1;
	Account a2("Stevens, Cat");
	Account a3("Ali Maharishi", 3540.56);
	std::string random_name = "Raleigh, Sir Walter";
	Account a4 = random_name;
	
	print(std::cout, a1) << std::endl;
	print(std::cout, a2) << std::endl;
	print(std::cout, a3) << std::endl;
	print(std::cout, a4) << std::endl;

	return 0;
}