/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:30:34 by coder             #+#    #+#             */
/*   Updated: 2022/01/04 10:05:06 by radelwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/definitions.hpp"
#include "../inc/Phonebook.hpp"
#include "../inc/Contact.hpp"

void	search_contact(Phonebook *phonebook){
	std::string	index_str;
	int			index;
	Contact		*contact;

	phonebook->print_list();
	std::cout << "enter index for full information: ";
	std::getline(std::cin, index_str);
	if (index_str.length() == 1 && index_str[0] >= '0' && index_str[0] <= '7' && index_str[1] == '\0') {
		index = index_str[0] - '0';
		contact = phonebook->get_contact(index);
		if (contact)
			contact->print_all();
		else
			std::cout << "not a valid index\n";
	}
	else
		std::cout << "not a valid index\n";
}

void	add_contact(Phonebook *phonebook){
	Contact new_contact;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

	std::cout << "enter first name: ";
	std::getline(std::cin, first_name);
	std::cout << "enter last name: ";
	std::getline(std::cin, last_name);
	std::cout << "enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "enter phone number: ";
	std::getline(std::cin, phone_number);
	std::cout << "enter darkest secret: ";
	std::getline (std::cin, darkest_secret);
	new_contact = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
	phonebook->add(new_contact);
}

void	user_interaction(Phonebook *phonebook){
	std::string	input_str;

	std::cout << "you can use the commands ADD, SEARCH and EXIT to interact with the phonebook\n";
	while (true){
		std::cout << "what do you want to do? ";
		std::getline(std::cin, input_str);
		if (input_str == "ADD")
			add_contact(phonebook);
		if(input_str == "SEARCH")
			search_contact(phonebook);
		if (input_str == "EXIT")
			return ;
	}
}

int	main()
{
	Phonebook phonebook;

	user_interaction(&phonebook);
	return (EXIT_SUCCESS);
}