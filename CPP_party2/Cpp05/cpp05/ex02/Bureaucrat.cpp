#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("BureaucrBureaucrat.cpp:2:10at::GradeTooHighException");
}

Bureaucrat::Bureaucrat(const std::string name, int grade):
	_name(name),
	_grade(grade)
{ 
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):
	_name(other._name),
	_grade(other._grade)
{ }

Bureaucrat::~Bureaucrat()
{ }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return (*this);
	_grade = other._grade;
	return (*this);
}

const std::string	&Bureaucrat::getName() const
{
	return (_name);
}

const int			&Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}
void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}
void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << *this << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << *this << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream& outs, const Bureaucrat &input)
{
	outs << input.getName() << ", bureaucrat grade: " << input.getGrade();
	return (outs);
}