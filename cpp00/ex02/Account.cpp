#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _amount = initial_deposit;

    _accountIndex = _nbAccounts;
    _nbAccounts++;
    _totalAmount += initial_deposit;

    // Loglama: [TIMESTAMP] index:X;amount:Y;created
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"
              << _amount  << ";created"    << std::endl;
}

Account::~Account()
{
    _nbAccounts--;
    _totalAmount -= _amount;

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:"
              << _amount  << ";closed"     << std::endl;
}
