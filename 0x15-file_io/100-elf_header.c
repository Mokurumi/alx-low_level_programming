#include "main.h"

/**
 * display_magic_n_class - Prints the magic and class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 */
void display_magic_n_class(unsigned char *e_ident)
{
	int i, j;

	printf("ELF Header:\n");

	for (i = 0; i < 4; i++)
	{
		if (e_ident[i] != 127 && e_ident[i] != 'E' &&
		    e_ident[i] != 'L' && e_ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}

	printf("  Magic:   ");
	for (j = 0; j < EI_NIDENT; j++)
	{
		printf("%02x", e_ident[j]);
		if (j == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}

	printf("  Class:                             ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
			break;
	}
}

/**
 * display_data_n_version - Prints the data and version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void display_data_n_version(unsigned char *e_ident)
{

	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
			break;
	}

	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * display_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void display_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}

	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * display_type_n_entry - Prints the type and entry point of an ELF header.
 * @e_type: The ELF type.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void display_type_n_entry(unsigned int e_type,
		unsigned char *e_ident, unsigned long int e_entry)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_type >>= 8;
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	printf("  Type:                              ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}

	printf("  Entry point address:               ");

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);
	else
		printf("%#lx\n", e_entry);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: 0 on success, 98 on failure.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd, r;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		if (close(fd) == -1)
			dprintf(STDERR_FILENO, "Error: Can't close file %d\n", fd);
		else
			dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(fd, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		if (close(fd) == -1)
			dprintf(STDERR_FILENO, "Error: Can't close file %d\n", fd);
		else
			dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	display_magic_n_class(header->e_ident);
	display_data_n_version(header->e_ident);
	display_osabi(header->e_ident);
	display_type_n_entry(header->e_type, header->e_ident, header->e_entry);

	free(header);
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close file %d\n", fd);
		exit(98);
	}
	return (0);
}
