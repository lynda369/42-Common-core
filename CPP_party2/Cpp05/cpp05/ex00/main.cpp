#include "Bureaucrat.hpp"


int main()
{
  // HighRank test
  try
  {
    Bureaucrat bu("Ray", 0);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  Bureaucrat bu("Ray", 1);
  try
  {
    bu.incrementGrade();
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << bu << std::endl;

  // LowRank Test
  try
  {
    Bureaucrat bu("Row", 151);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  Bureaucrat ba("ba", 150);
  try
  {
    ba.decrementGrade();
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << ba << std::endl;

  // test copy operator ;
  ba = bu;
  std::cout << "After assigment: " << ba << std::endl;

  Bureaucrat copy(ba);
  std::cout << "copy of ba: " << copy << std::endl;
}