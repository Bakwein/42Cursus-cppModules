#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void){return _nbAccounts;}
int Account::getTotalAmount(void){return _totalAmount;}
int Account::getNbDeposits(void){return _totalNbDeposits;}
int Account::getNbWithdrawals(void){return _totalNbWithdrawals;}

