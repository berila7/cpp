#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

int	read_file(const std::string& file, std::string& result)
{
	std::ifstream		infile;
	std::stringstream	buffer;

	infile.open(file.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: opening file" << std::endl;
		return (1);
	}
	buffer << infile.rdbuf();
	result = buffer.str();
	infile.close();
	return (0);
}

int	search_replace(const std::string& file, const std::string& s1, const std::string& s2)
{
	std::ofstream	outfile;
	size_t			pos = 0;
	size_t			found;
	std::string		result = "";
	std::string		outname = file + ".replace";

	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}
	if (read_file(file, result))
		return (1);
	outfile.open(outname.c_str());
	if(!outfile.is_open())
	{
		std::cerr << "Error: creating output file" << std::endl;
		return (1);
	}
	while ((found = result.find(s1, pos)) != std::string::npos)
	{
		outfile << result.substr(pos, found - pos);
		outfile << s2;
		pos = found + s1.length();
	}
	outfile << result.substr(pos);
	outfile.close();
	return (0);
}

int main(int ac, char *av[])
{
	if (ac == 4)
	{
		if (search_replace(av[1], av[2], av[3]))
			return (EXIT_FAILURE);
	}
	else
	{
		std::cout << "Invalid args" << std::endl;
		return (EXIT_FAILURE);
	}
	return (0);
}