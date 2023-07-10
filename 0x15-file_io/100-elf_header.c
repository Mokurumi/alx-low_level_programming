#include "main.h"

/**
 * print_error - Prints error message to stderr and exits with status code 98.
 * @message: The error message to be displayed.
 */
void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

/**
 * display_elf_header - Displays the information contained in the ELF header.
 * @header: Pointer to the ELF header structure.
 */
void display_elf_header(const Elf64_Ehdr *header)
{
	printf("Magic: %02x %02x %02x %02x\n",
			header->e_ident[EI_MAG0], header->e_ident[EI_MAG1],
			header->e_ident[EI_MAG2], header->e_ident[EI_MAG3]);
	printf("Class: %d\n", header->e_ident[EI_CLASS]);
	printf("Data: %d\n", header->e_ident[EI_DATA]);
	printf("Version: %d\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI: %d\n", header->e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", header->e_ident[EI_ABIVERSION]);
	printf("Type: %d\n", header->e_type);
	printf("Entry point address: %lx\n", header->e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
	Elf64_Ehdr header;
	int fd;
	ssize_t num_bytes;

	/* Validate command-line arguments */
	if (argc != 2)
	{
		print_error("Invalid number of arguments");
	}

	/* Open the ELF file */
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		print_error("Failed to open file");
	}

	/* Read the ELF header */
	num_bytes = read(fd, &header, sizeof(header));
	if (num_bytes == -1 || num_bytes < (ssize_t)sizeof(header))
	{
		print_error("Failed to read ELF header");
	}

	/* Check if the file is an ELF file */
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		print_error("Not an ELF file");
	}

	/* Display the ELF header information */
	display_elf_header(&header);

	/* Close the file */
	close(fd);

	return (0);
}
