/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:54:08 by discallow         #+#    #+#             */
/*   Updated: 2025/02/08 01:01:50 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
# include <iostream>
# include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_nbWithdrawals = 0;
	_nbDeposits = 0;
	_amount = initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:"
		<< _amount << ";" << "created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:"
		<< _amount << ";" << "closed" << std::endl;
}

int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp(void) {
	time_t	now = time(0);
	struct tm	*time_info = localtime(&now);
	std::cout << "[" << time_info->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << time_info->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << time_info->tm_mday;
	std::cout << "_" << std::setfill('0') << std::setw(2) << time_info->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << time_info->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << time_info->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";" << "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";" << "withdrawals:" << _totalNbWithdrawals
		<< std::endl;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";" << "withdrawals:" << _nbWithdrawals
		<< std::endl;
}

int	Account::checkAmount(void) const {
	return (_amount);
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
		<< ";" << "p_amount:" << _amount << ";" << "deposit:" << deposit << ";";
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << "amount" << _amount << ";" 
		<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex 
		<< ";" << "p_amount:" << _amount << ";" << "withdrawal:";
	if (withdrawal > _amount) {
		std::cout << "refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ";" << "amount:" << _amount << ";" 
		<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}