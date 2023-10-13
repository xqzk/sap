#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

class Sap
{
public:
	Sap() {}
	~Sap() {}
private:
	std::vector<int64_t> int_stack;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "USAGE\n\tsap [file]" << std::endl;
		return 1;
	}

	return 0;
}
