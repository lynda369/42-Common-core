#pragma once
#include <iostream>
class AForm;

class Bureaucrat
{
	public:
        Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
		Bureaucrat &operator=(const Bureaucrat &copy);

		const std::string	&getName() const;
		const int			&getGrade() const;

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(AForm &form);
        void	executeForm(AForm const & form) const;

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream& outs, const Bureaucrat &input);