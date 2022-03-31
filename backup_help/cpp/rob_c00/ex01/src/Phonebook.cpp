/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:12:51 by coder             #+#    #+#             */
/*   Updated: 2021/12/11 20:35:38 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Phonebook.hpp"

Phonebook::Phonebook(void){
	number_of_contacts = 0;
}

Phonebook::~Phonebook(void){
	std::cout << "Phonebook gets deleted\n";
}

void	Phonebook::add(Contact new_contact){
	if (number_of_contacts < 8){
		contacts[number_of_contacts] = new_contact;
		number_of_contacts++;
	}
	else{
		for (int i = 0; i < 7; i++)
			contacts[i] = contacts[i + 1];
		contacts[7] = new_contact;
	}
}

void	Phonebook::print_list(void){
	for (int i = 0; i < number_of_contacts; i++){
		std::cout << std::setw(10) << std::right << i << " | ";
		contacts[i].print_short_one_line();
	}
}

Contact	*Phonebook::get_contact(int index){
	if (index >= 0 && index < number_of_contacts)
		return (&contacts[index]);
	else
		return (NULL);
}
