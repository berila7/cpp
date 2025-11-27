#include <iostream>
#include <fstream>
#include <cstdlib>

void	search_replace(const std::string& file, const std::string& s1, const std::string& s2)
{
	std::ifstream infile;
	std::ofstream outfile;
	(void)s1;
	(void)s2;

	infile.open(file.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: opening file" << std::endl;
		std::exit(1);
	}

	std::string outname = file + ".replace";
	outfile.open(outname.c_str());

	if(!outfile.is_open())
	{
		std::cerr << "Error: creating output file" << std::endl;
		std::exit(1);
	}
	std::string line;

	while (std::getline(infile, line))
	{
		std::string result = "";
		size_t pos = 0;

		size_t found = line.find(s1, pos);
		if (found != std::string::npos)
		{
			result += s2;
			pos = found + s1.length();
			outfile << result << std::endl;
			std::cout << pos << std::endl;
		}
		else
		{
			outfile << line << std::endl;
			pos += line.length();
		}
	}
	infile.close();
	outfile.close();
}

int main(int ac, char *av[])
{
	(void)ac;
	(void)av;
	if (ac == 4)
	{
		search_replace(av[1], av[2], av[3]);
	}
	else
	{
		std::cout << "Invalid args" << std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}