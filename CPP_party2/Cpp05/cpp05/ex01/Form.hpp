#pragma once 

#include "Bureaucrat.hpp"
#include <ostream>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		Form(void);
		Form(const std::string name, const int sign, const int execute);
		Form(const Form &copy);
		~Form(void);
		Form				&operator=(const Form &copy);
		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(const Bureaucrat &b);

	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, const Form &f);