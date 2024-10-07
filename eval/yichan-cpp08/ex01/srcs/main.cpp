# include "Span.hpp"

int main()
{
	//Normal test
	{
		Span test(5);
		test.addNumber(10);
		test.addNumber(17);
		test.addNumber(17);
		test.addNumber(14);
		test.addNumber(5);
		// test.addNumber(5);
		// test.showNumber();
		// test.shortestSpan();
		std::cout << "longestSpan" <<  test.longestSpan() << std::endl;
		std::cout << "shortestSpan" <<  test.shortestSpan() << std::endl;
	}
	//Volume full ( overflow )
	{
		try
		{
			Span test(5);
			test.addNumber(10);
			test.addNumber(17);
			test.addNumber(17);
			test.addNumber(14);
			test.addNumber(14);
			test.addNumber(14);
			test.addNumber(14);
			test.addNumber(5);
			test.showNumber();
			test.shortestSpan();
			std::cout << "longestSpan" <<  test.longestSpan() << std::endl;
			std::cout << "shortestSpan" <<  test.shortestSpan() << std::endl;
		}
		catch(const Span::numFullException &e)
		{
			std::cout << "Error:\t" << e.what() << std::endl;
		}
		catch(const Span::SpanNotFoundException &e)
		{
			std::cout << "Error:\t" << e.what() << std::endl;
		}
	}
	//Volume too low (less than 2; only one)
	{
		try
		{
			Span test(5);
			// test.addNumber(10);
			test.showNumber();
			test.shortestSpan();
			std::cout << "longestSpan" <<  test.longestSpan() << std::endl;
			std::cout << "shortestSpan" <<  test.shortestSpan() << std::endl;
		}
		catch(const Span::numFullException &e)
		{
			std::cout << "Error:\t" << e.what() << std::endl;
		}
		catch(const Span::SpanNotFoundException &e)
		{
			std::cout << "Error:\t" << e.what() << std::endl;
		}
	}

	// test.addNumber(6);
}

