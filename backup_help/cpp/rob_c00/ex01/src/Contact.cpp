/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:12:54 by coder             #+#    #+#             */
/*   Updated: 2021/12/11 20:35:33 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"
#include <iostream>
#include <iomanip>


Contact::Contact(std::string first_name, std::string last_name, std::string nickname, std::string phone_number, std::string darkest_secret) {
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

Contact::Contact(void){}

Contact::~Contact(void){}

std::string	trim_string(std::string str, unsigned long length){
	if (str.length() <= length)
		return (str);
	else
		return (str.substr(0, length - 1) + ".");
}

void	Contact::print_short_one_line(void){
	std::cout << std::setw(10) << std::right << trim_string(first_name, 10) << " | ";
	std::cout << std::setw(10) << std::right << trim_string(last_name, 10) << " | ";
	std::cout << std::setw(10) << std::right << trim_string(nickname, 10) << "\n";
}

void	Contact::print_all(void){
	std::cout << first_name << "\n";
	std::cout << last_name << "\n";
	std::cout << nickname << "\n";
	std::cout << phone_number << "\n";
	std::cout << darkest_secret << "\n";
}