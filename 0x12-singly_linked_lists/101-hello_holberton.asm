global _start

section .data
    hello: db 'Hello, Holberton', 0
    format: db '%s', 10, 0

section .text
_start:
    ; Set up the stack pointer
    mov rsp, rbp
    sub rsp, 16

    ; Push the format string onto the stack
    mov rdi, format
    xor rsi, rsi
    mov rax, 0
    call printf

    ; Push the hello string onto the stack
    mov rdi, hello
    xor rsi, rsi
    mov rax, 0
    call printf

    ; Exit the program
    xor rdi, rdi
    mov rax, 60
    syscall

