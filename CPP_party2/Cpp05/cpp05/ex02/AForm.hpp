#pragma once 

#include "Bureaucrat.hpp"
#include <ostream>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		AForm(void);
		AForm(const std::string name, const int sign, const int execute);
		AForm(const AForm &copy);
		~AForm(void);
		AForm				&operator=(const AForm &copy);
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

std::ostream	&operator<<(std::ostream &o, const AForm &f);