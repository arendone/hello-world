/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 10:57:50 by coder             #+#    #+#             */
/*   Updated: 2022/01/03 16:24:12 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

std::string	create_timestamp(void) {
	std::string	timestamp;
	std::time_t	now;
	std::tm	*ltm;

	now = time(0);
	ltm = localtime(&now);
	timestamp = "[";
	timestamp += std::to_string(1900 + ltm->tm_year);
	if (ltm->tm_mon < 9)
		timestamp += std::to_string(0);
	timestamp += std::to_string(ltm->tm_mon + 1);
	if (ltm->tm_mday <= 9)
		timestamp += std::to_string(0);
	timestamp += std::to_string(ltm->tm_mday);
	timestamp += "_";
	if (ltm->tm_hour <= 9)
		timestamp += std::to_string(0);
	timestamp += std::to_string(ltm->tm_hour);
	if (ltm->tm_min <= 9)
		timestamp += std::to_string(0);
	timestamp += std::to_string(ltm->tm_min);
	if (ltm->tm_sec <= 9)
		timestamp += std::to_string(0);
	timestamp += std::to_string(ltm->tm_sec);
	timestamp += "]";
	return (timestamp);
}

int	Account::getNbAccounts(void) { return (Account::_nbAccounts); }

int	Account::getTotalAmount(void) { return (Account::_totalAmount); }

int	Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }

int	Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }

void	Account::displayAccountsInfos(void) {
	std::cout << create_timestamp() << " accounts:" << Account::getNbAccounts()
			<< ";total:" << Account::getTotalAmount() << ";deposits:"
			<< Account::getNbDeposits() << ";withdrawals:" << Account::getNbWithdrawals()
			<< "\n";
}

Account::Account (int initial_deposit) {
	Account::_accountIndex = _nbAccounts++;
	Account::_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	std::cout << create_timestamp() << " index:" << Account::_accountIndex << ";amount:"
			<< Account::_amount << ";created\n";
}

Account::~Account (void) {
	std::cout << create_timestamp() << " index:" << Account::_accountIndex << ";amount:"
			<< Account::_amount << ";closed\n";
}

void	Account::makeDeposit(int deposit) {
	int	p_amount;

	p_amount = Account::_amount;
	Account::_nbDeposits ++;
	Account::_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << create_timestamp() << " index:" << Account::_accountIndex << ";p_amount:"
			<< p_amount << ";deposit:" << deposit << ";amount:" << Account::_amount
			<< ";nb_deposits:" << Account::_nbDeposits << "\n";
}

bool	Account::makeWithdrawal(int withdrawal) {
	int	p_amount;

	p_amount = Account::_amount;
	if (withdrawal <= Account::_amount){
		Account::_amount -= withdrawal;
		Account::_nbWithdrawals ++ ;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals ++ ;
		std::cout << create_timestamp() << " index:" << Account::_accountIndex << ";p_amount:"
			<< p_amount << ";withdrawl:" << withdrawal << ";amount:" << Account::_amount
			<< ";nb_withdrawls:" << Account::_nbWithdrawals << "\n";
		return (true);
	}
	else{
		std::cout << create_timestamp() << " index:" << Account::_accountIndex << ";p_amount:"
			<< p_amount << ";withdrawl:refused\n";
		return (false);
	}
}

int	Account::checkAmount(void) const {
	return (Account::_amount);
}

void	Account::displayStatus(void) const {
	std::cout << create_timestamp() << " index:" << Account::_accountIndex << ";amount:"
			<< Account::_amount << ";deposits:" << Account::_nbDeposits << ";withdrawls:"
			<< Account::_nbWithdrawals << "\n";
}