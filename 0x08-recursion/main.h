#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include <string.h>

int _putchar(char ch);
void _puts_recursion(char *s);
void _print_rev_recursion(char *s);
int _strlen_recursion(char *s);
int factorial(int n);
int _pow_recursion(int x, int y);
int _sqrt_recursion(int n);
int _sqrt_helper(int n, int start);
int is_prime_number(int n);
int prime_helper(int n, int i)
int is_palindrome(char *s);
int pali_helper(char *s, int start, int end);
int wildcmp(char *s1, char *s2);
int wildcmp_helper(char *s1, char *s2);

#endif
