#include <iostream>
#include <fstream>

int main(int argc, char **argv)
{
	std::ifstream	ifs;
	std::ofstream	ofs;
	std::string		str;
	std::string		s1;
	std::string		s2;

	if (argc != 4)
	{
		std::cout << "Error: Wrong arguments." << std::endl;
		return (1);
	}

	ifs.open(argv[1]);
	if (ifs.fail())
	{
		std::cout << "Error: File open fail." << std::endl;
		return (1);
	}
	ofs.open(std::string(argv[1]) + ".replace");
	if (ofs.fail())
	{
		std::cout << "Error: Replace file open fail." << std::endl;
		ifs.close();
		return (1);
	}

	s1 = std::string(argv[2]);
	s2 = std::string(argv[3]);
	while (std::getline(ifs, str))
	{
		std::string::size_type	pos = str.find(s1);

		while (pos != std::string::npos)
		{
			str.erase(pos, s1.length());
			str.insert(pos, s2);
			pos = str.find(s1, pos);
		}
		ofs << str;
		if (!ifs.eof())
			ofs << std::endl;
	}
	if (ifs.fail() && !ifs.eof())
	{
		std::cout << "Error: File read fail." << std::endl;
		ifs.close();
		ofs.close();
		return (1);
	}
	ifs.close();
	ofs.close();
	return (0);
}