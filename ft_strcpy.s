section .text
global ft_strcpy

ft_strcpy:                  ; rdi - dest, rsi - src
    test rdi, rdi
    jz .null_case
    test rsi, rsi
    jz .null_case

    mov rcx, rdi            ; to safe original pointer on dest
    cld                     ; to set direction of pointers forvard. (automaticly increment pointer after read)

.loop:
    lodsb                   ; to read rsi (src, second argument) first letter and send it to al - lower 8 bit of rax.
    stosb                   ; to set on first position of rdi (dest, first argument) al, which stores letter which was readed with lodsb
    test al, al             ; to check if al is zero. If yes ZF is set to 1
    jnz .loop               ; jump if not zero to loop to repeat.
    mov rax, rcx
    ret

.null_case
    xor rax, rax
    ret
