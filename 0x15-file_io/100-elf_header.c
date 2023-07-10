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
 * get_data_encoding - Retrieves the string representation of the ELF data encoding.
 * @encoding: The value of the ELF data encoding.
 * Return: The string representation of the ELF data encoding.
 */
const char *get_data_encoding(unsigned char encoding)
{
	switch (encoding)
	{
		case ELFDATA2LSB:
			return "2's complement, little endian";
		case ELFDATA2MSB:
			return "2's complement, big endian";
		default:
			return ("Invalid");
	}
}

/**
 * get_osabi_name - Retrieves the string representation of the OS/ABI.
 * @osabi: The value of the OS/ABI.
 * Return: The string representation of the OS/ABI.
 */
const char *get_osabi_name(unsigned char osabi)
{
	switch (osabi)
	{
		case ELFOSABI_SYSV:
			return "UNIX - System V";
		case ELFOSABI_HPUX:
			return "HP-UX";
		case ELFOSABI_NETBSD:
			return "NetBSD";
		case ELFOSABI_LINUX:
			return "Linux";
		case ELFOSABI_SOLARIS:
			return "Solaris";
		case ELFOSABI_AIX:
			return "AIX";
		case ELFOSABI_IRIX:
			return "IRIX";
		case ELFOSABI_FREEBSD:
			return "FreeBSD";
		case ELFOSABI_TRU64:
			return "TRU64 UNIX";
		case ELFOSABI_ARM:
			return "ARM architecture";
		case ELFOSABI_STANDALONE:
			return "Standalone (embedded) application";
		default:
			return ("Unknown");
	}
}

/**
 * display_elf_header - Displays the information contained in the ELF header.
 * @header: Pointer to the ELF header structure.
 */
void display_elf_header(const Elf64_Ehdr *header)
{
	int i;

	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("Class: ");
	switch (header->e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("Invalid\n");
			break;
	}

	printf("Data: %s\n", get_data_encoding(header->e_ident[EI_DATA]));
	printf("Version: %d\n", header->e_ident[EI_VERSION]);
	printf("OS/ABI: %s\n", get_osabi_name(header->e_ident[EI_OSABI]));
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
