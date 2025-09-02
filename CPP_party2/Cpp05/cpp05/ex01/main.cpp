#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Form ah("LA CAF", 50, 100);
	std::cout << "----------------------------------" << std::endl;
	std::cout << ah << std::endl;
	std::cout << "----------------------------------" << std::endl;
	Bureaucrat phil("Phil", 60);
	std::cout << "----------------------------------" << std::endl;
	phil.signForm(ah);
	std::cout << "----------------------------------" << std::endl;
	Bureaucrat loz("Loz", 2);
	std::cout << "----------------------------------" << std::endl;
	loz.signForm(ah);
	std::cout << "----------------------------------" << std::endl;
	std::cout << ah << std::endl;
	std::cout << "----------------------------------" << std::endl;
	return(0);
}