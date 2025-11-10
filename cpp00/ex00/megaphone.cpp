#include <iostream>

char	*toupper(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = std::toupper(str[i]);
		i++;
	}
	return (str);
}

int main(int ac, char *av[])
{
	int i;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (i = 1; i < ac; i++)
			std::cout << toupper(av[i]);
		if (i == ac)
			std::cout << std::endl;
	}
	return (0);
} 