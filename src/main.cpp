/*
** EPITECH PROJECT, 2018
** arcade
** File description:
** Main file.
*/

#include <iostream>
#include "Arcade.hpp"

int error_handling(int ac , char **av)
{
	Elf64_Ehdr *elf;
	void *data;
	FILE *file  = fopen(av[1], "rb");

	if (ac > 2)
		throw Error("too many argument");
	else if (file) {
		fread(&elf, 1, sizeof(elf), file);
		if (elf->e_ident[EI_MAG0] != 0x7f
			|| elf->e_ident[EI_MAG1] != 'E'
			|| elf->e_ident[EI_MAG2] != 'L'
			|| elf->e_ident[EI_MAG3] != 'F')
				throw Error("is not an ELF file");
		fclose(file);
	} else {
		std::cout << "ok" << std::endl
	}
	
}

int Arcade::run(int ac , char **av)
{
	try {
		error_handling(ac, av)
	} catch(const arc::Error& e) {
		std::cerr << "Error : "  << e.what() << std::endl;
		return arc::FAILURE;
	}
	return (0)
}

int main(int ac, char **av)
{
	Arcade app;

	return app.run(ac, av);	
}