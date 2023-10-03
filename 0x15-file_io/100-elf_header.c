#include "elf.h"

/**
 * main - program to validate input file as an ELF
 * then print some of the ELF Header information.
 * @ac: amount of arguments being passed at execution
 * @args: array of string with the arguments passed at execution
 *
 * Return: 0 is succesfull, 98 on error
 */
int main(int ac, char **args)
{
	int fd, idx = 0;
	size_t size = sizeof(char) * (MAGS);
	char *magic = malloc(size);

	for (idx = 0; idx < MAGS; idx++)
		magic[idx] = 0;
	if (ac != 2)
	{
		free(magic);
		perror("Usage : elf_header elf_filename\n");
		exit(98);
	}
	fd = open(args[1], O_RDONLY);
	if (fd == -1)
	{
		free(magic);
		perror("Failed to open\n");
		exit(98);
	}
	read(fd, magic, size - 1);
	if (!isElf(magic))
	{
		free(magic);
		perror("File is NOT is not in format ELF!!\n");
		close(fd);
		exit(98);
	}

	prntHeader(magic);
	free(magic);
	close(fd);

	return (0);
}

/**
 * isElf - checks if the file opened is an ELF executable
 * @m: string with the first 16 bytes of the file
 *
 * Return: 1 if file is an ELF executable, if not
 */
int isElf(char *m)
{
	return (m[0] == 0x7f && m[1] == 'E' && m[2] == 'L' && m[3] == 'F');
}
/**
 * prntHeader - Prints and calls all functions
 * for the ELF header output
 * @m: array with the first 64 bytes of the file
 */
void prntHeader(char *m)
{
	printf("ELF Header:\n");
	prntMagic(m);
	prntClass(m);
	prntData(m);
	prntVersion(m);
	prntOS_ABI(m);
	prntABI_Vers(m);
	prntType(m);
	prntEntryPoint(m);
}
/**
 * prntMagic - prints the Magic numbers
 * @m: string with the first 16 bytes of the file
 */
void prntMagic(char *m)
{
	int i;

	printf("  Magic:  ");
	for (i = 0; i < 16; i++)
		printf(" %.02x", m[i]);

	printf("\n");
}
/**
 * prntClass - takes care of printing the ELF file Class
 * @m: string with the first 16 bytes of the file
 */
void prntClass(char *m)
{
	printf("  Class:                             ");

	switch (m[4])
	{
		case ELFCLASSNONE:
			printf("Invalid Class\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
	}
}

/**
 * prntData - takes care of printing the ELF file Data type
 * @m: string with the first 16 bytes of the file
 */
void prntData(char *m)
{
	printf("  Data:                              ");

	switch (m[5])
	{
		case ELFDATANONE:
			printf("Unknown data format");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
	}
}

/**
 * prntVersion- takes care of printing the version
 * @m: string with the first 16 bytes of the file
 */
void prntVersion(char *m)
{
	printf("  Version:                           ");

	switch (m[6])
	{
		case EV_NONE:
			printf("Invalid version\n");
			break;
		case EV_CURRENT:
			printf("1 (current)\n");
	}
}
/**
 * prntOS_ABI - takes care of printing the OS/ABI
 * @m: string with the first 16 bytes of the file
 */
void prntOS_ABI(char *m)
{
	printf("  OS/ABI:                            ");

	switch (m[7])
	{
		/*case ELFOSABI_NONE:*/
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
			printf("UNIX -Solaris\n");
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64 UNIX\n");
			break;
		case ELFOSABI_ARM:
			printf("UNIX - ARM architecture\n");
			break;
		default:
			printf("<unknown: %.02x>\n", m[7]);
	}
}
/**
 * prntABI_Vers - takes cae of printing the ABI Version
 * @m: string wiht the first 16 bytes of the file
 */
void prntABI_Vers(char *m)
{
	printf("  ABI Version:                       ");
	printf("%d\n", m[8]);
}
/**
 * prntType - prints the Type of ELF file
 * @m: string with thw first 16 bytes of the file
 */
void prntType(char *m)
{
	printf("  Type:                              ");
	switch (m[16])
	{
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("NONE (Unknown file)\n");
	}

/*	printf("<<%d>> <%d>\n", m[16], ET_DYNi); */
}
/**
 * prntEntryPoint - prints the Entry Point Adress
 * @m: string wiht the first 16 bytes of the file
 */
void prntEntryPoint(char *m)
{
	printf("  Entry point address:               ");
	printf("0x%02x%02x%02x\n", m[26], m[25], (m[24] >= 0 ? m[24] : m[24] * -1));
}
