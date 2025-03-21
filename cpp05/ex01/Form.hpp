/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:55:39 by discallow         #+#    #+#             */
/*   Updated: 2025/03/17 19:16:00 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
	public:
		Form(void);
		Form(const std::string name, int gradeToSign, int gradeToExec);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw();
		};
		class FormAlreadySigned : public std::exception {
			public:
				const char* what() const throw();				
		};
		void			beSigned(Bureaucrat& b);
		std::string		getName(void) const;
		bool			getIsSigned(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExec(void) const;
};

std::ostream& operator<<(std::ostream &os, Form& form);

#endif