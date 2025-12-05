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

int Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int Account::getTotalAmount( void ) {
    return _totalAmount;
}

int Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

int Account::checkAmount( void ) const {
    return _amount;
}

void Account::makeDeposit( int deposit ) 
{
    
}

bool Account::makeWithdrawal( int withdrawal ) 
{

}

void Account::displayAccountsInfos( void )
{

}

void Account::displayStatus( void ) const
{
    _displayTimestamp();
    std::cout << "index:"        << _accountIndex
              << ";amount:"      << _amount
              << ";deposits:"    << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals
              << std::endl;
}

void Account::_displayTimestamp( void )
{
    std::time_t time_in_seconds = std::time(NULL); 
    std::tm*    local_time_info = std::localtime(&time_in_seconds);

    char log_buffer[16];
    std::strftime(log_buffer, sizeof(log_buffer), "%Y%m%d_%H%M%S", local_time_info);
    std::cout << "[" << log_buffer << "] ";
}
