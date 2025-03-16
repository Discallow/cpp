/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 02:55:39 by discallow         #+#    #+#             */
/*   Updated: 2025/03/16 03:30:26 by discallow        ###   ########.fr       */
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
		~Form();
		class GradeTooHighException : std::exception {
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : std::exception {
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