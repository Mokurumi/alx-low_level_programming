section .data
	hello: db 'Hello, Holberton', 10, 0
	format: db '%s', 0

section .text
	global _start
	extern printf

_start:
	; Set up the stack pointer
	mov rsp, rbp
	sub rsp, 16

	; Push the hello string onto the stack
	mov rdi, format
	mov rsi, hello
	mov rax, 0
	call printf

	; Exit the program
	xor rdi, rdi
	mov rax, 60
	syscall
