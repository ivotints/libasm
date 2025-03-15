section .text
global ft_read
extern __errno_location

ft_read:                    ; ssize_t read(int fd, void *buf, size_t count);
    xor rax, rax            ; set 0. 0 is a read syscall
    test rsi, rsi           ; in case of NULL ZF is set
    jz .bad_address

    syscall
    test rax, rax           ; if result is negative SF is set.
    jns .done

    neg rax
    mov rdi, rax
    sub rsp, 8
    call __errno_location wrt ..plt
    add rsp, 8
    mov [rax], edi
    xor rax, rax
    dec rax 
    
.done:
    ret

.bad_address:
    sub rsp, 8
    call __errno_location wrt ..plt
    add rsp, 8
    mov qword [rax], 14
    xor rax, rax
    dec rax 
    ret