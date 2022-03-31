/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:26:09 by coder             #+#    #+#             */
/*   Updated: 2021/12/11 20:36:29 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class	Phonebook {
	private:
		Contact	contacts[8];
		int		number_of_contacts;
	
	public:
		Phonebook(void);
		~Phonebook(void);
		void print_list(void);
		void add(Contact contact);
		Contact	*get_contact(int index);
};

#endif