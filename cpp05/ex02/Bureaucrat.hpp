/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: discallow <discallow@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 05:19:05 by discallow         #+#    #+#             */
/*   Updated: 2025/03/18 00:22:23 by discallow        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include <fstream>
# include <cstdlib>
# include <ctime>

# include "AForm.hpp"

# ifndef RED
#  define RED	"\033[31m"
# endif
# ifndef GREEN
#  define GREEN	"\033[32m"
# endif
# ifndef BLUE
#  define BLUE	"\033[34m"
# endif
# ifndef WHITE
#  define WHITE	"\033[37m"
# endif
# ifndef BLACK
#  define BLACK	"\033[30m"
# endif
# ifndef YELLOW
#  define YELLOW	"\033[33m"
# endif
# ifndef CYAN
#  define CYAN	"\033[36m"
# endif
# ifndef GRAY
#  define GRAY	"\033[90m"
# endif
# ifndef RESET
#  define RESET	"\033[0m"
# endif

class AForm;

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();
		const std::string&	getName() const;
		int 		getGrade() const;
		void		decrement();
		void		increment();
		void		signForm(AForm& f);
		void		executeForm(AForm const& form);
		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat &obj);

#endif

