#include "Bureaucrat.hpp"

int main()
{
	string input;
	string name;
	string form_name;
	int form_grade;
	const char *tempstr;
	int grade;
	while (1)
	{
		cout << "Enter a name (bureaucrat): ";
		getline(cin, input);
		try
		{
			tempstr = input.c_str();
			name = tempstr;
		}
		catch (exception &e)
		{
			cout << "input error (grade)" << endl;
			cout << e.what() << endl;
			continue;
		}
		cout << "Enter a grade (bureaucrat): ";
		getline(cin, input);
		try
		{
			tempstr = input.c_str();
			grade = atoi(tempstr);
		}
		catch (exception &e)
		{
			cout << "input error (grade)" << endl;
			cout << e.what() << endl;
			continue;
		}
		cout << "Enter a name (form): ";
		getline(cin, input);
		try
		{
			tempstr = input.c_str();
			form_name = tempstr;
		}
		catch (exception &e)
		{
			cout << "input error (grade)" << endl;
			cout << e.what() << endl;
			continue;
		}
		cout << "Enter a grade (form) : ";
		getline(cin, input);
		try
		{
			tempstr = input.c_str();
			form_grade = atoi(tempstr);
		}
		catch (exception &e)
		{
			cout << "input error (grade)" << endl;
			cout << e.what() << endl;
			continue;
		}

		break;
	}
	try
	{
	cout << "---------check bureaucrat-----------" << endl;
	Bureaucrat bureaucrat(name, grade);
	cout << bureaucrat;
	cout << "---------check form-----------------" << endl;
	Form form(form_name, form_grade, form_grade);
	cout << form;
	cout << "---------try sign--------------------" << endl;
	bureaucrat.signForm(form);
	cout << "----------after sign-----------------" << endl;
	cout << form;
	}
	catch (exception &e)
	{
		cout << "\n-----------------------------\n" << "error! "<< e.what() << endl;
	}
}