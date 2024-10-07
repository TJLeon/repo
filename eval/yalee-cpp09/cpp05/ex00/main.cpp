#include "Bureaucrat.hpp"

int main()
{
	string input;
	const char *tempstr;
	int grade;
	while (1)
	{
		cout << "Enter a grade: ";
		getline(cin, input);
		try
		{
			tempstr = input.c_str();
			grade = atoi(tempstr);
		}
		catch (exception &e)
		{
			cout << "input error" << endl;
			cout << e.what() << endl;
			continue;
		}
		break;
	}
	try
	{
		cout << "grade: " << grade << endl;
		Bureaucrat bureaucrat("Laian", grade);
		cout << "test" << endl;
		cout << bureaucrat;
	}
	catch (GradeTooHighException &e)
	{
		cout << "Grade too high" << endl;
	}
	catch (GradeTooLowException &e)
	{
		cout << "Grade too low" << endl;
	}
}