/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 05:19:05 by discallow         #+#    #+#             */
/*   Updated: 2025/03/16 03:47:36 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

# include "Form.hpp"

class Form;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		~Bureaucrat();
		const std::string&	getName() const;
		int 		getGrade() const;
		void		decrement();
		void		increment();
		void		signForm(Form& f);
		class GradeTooHighException : std::exception {
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException : std::exception {
			public:
				const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj);

#endif

