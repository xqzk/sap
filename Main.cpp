#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

class Int64Stack
{
public:
	void push(int64_t value)
	{
		this->stack.push_back(value);
	}	

	int64_t pop()
	{
		if (this->stack.size() == 0)
		{
			std::cerr << "ERROR : Stack underflow" << std::endl;
			std::exit(1);
		}

		int64_t popped = this->stack[this->stack.size() - 1];

		this->stack.pop_back();

		return popped;
	}

	uint64_t size()
	{
		return this->stack.size();
	}

	void dup()
	{
		this->stack.push_back(stack[stack.size() - 1]);
	}

	void say()
	{
		std::cout << "STACK" << std::endl;

		for (int64_t &value : this->stack)
			std::cout << "\t" << value << std::endl;
	}

private:
	std::vector<int64_t> stack;
};

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "USAGE : sap [file]" << std::endl;
		return 1;
	}

	Int64Stack stack;
	std::ifstream file(argv[1]);

	if (!file.is_open())
	{
		std::cerr << "ERROR : File could not be opened!" << std::endl;
		return 1;
	}

	while (file.good())
	{
		char c;
		std::string buffer;

		while (file.good() && file.get(c) && !std::isspace(c))
		{
			buffer += c;
		}

		if (buffer == "+")
		{
			int64_t y = stack.pop();
			int64_t x = stack.pop();

			stack.push(x + y);
		}
		else if (buffer == "-")
		{
			int64_t y = stack.pop();
			int64_t x = stack.pop();

			stack.push(x - y);
		}
		else if (buffer == "*")
		{
			int64_t y = stack.pop();
			int64_t x = stack.pop();

			stack.push(x * y);
		}
		else if (buffer == "/")
		{
			int64_t y = stack.pop();
			int64_t x = stack.pop();

			stack.push(x / y);
		}
		else if (buffer == "s-dup")
		{
			stack.dup();
		}
		else if (buffer == "s-say")
		{
			stack.say();
		}
		else
		{
			try
			{ 
				stack.push(std::stoi(buffer));
			}
			catch (std::invalid_argument &e)
			{
				std::cerr << "ERROR : Unknown keyword" << std::endl;
				file.close();

				return 1;
			}
		}
	}

	file.close();

	return 0;
}