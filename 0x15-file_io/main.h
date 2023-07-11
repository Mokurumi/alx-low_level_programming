#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include <elf.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

/* elf functions */
void display_magic_n_class(unsigned char *e_ident);
void display_data_n_version(unsigned char *e_ident);
void display_osabi(unsigned char *e_ident);
void display_type_n_entry(unsigned int e_type, unsigned char *e_ident, unsigned long int e_entry);

#endif
