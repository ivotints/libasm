section .text
global ft_strdup
extern malloc
extern __errno_location
extern ft_strlen

ft_strdup:              ;  char *strdup(const char *s);
    




























    test rdi, rdi       ; if NULL, ZF is set
    jz .bad_address

    call ft_strlen      ; to get size of string
    inc rax             

    push rdi            ; to safe rdi - pointer on what to copy
    mov rdi, rax
    sub rsp, 8           ; Align stack before calling malloc
    call malloc wrt ..plt
    add rsp, 8           ; Restore stack alignment

    test rax, rax       ; if malloc returned null
    jz .malloc_fail
    mov rcx, rax
    pop rdi
    push rax

.loop:    

    mov al, [rdi]
    mov [rcx], al
    test al, al         ; if ZF then end of loop
    jz .done
    inc rdi
    inc rcx 
    jmp .loop

.bad_address:
    call __errno_location wrt ..plt
    mov qword [rax], 14            ; errno code of bad address. Not standard behavor, but better then original one in my opinion

.malloc_fail:
    xor rax, rax
    ret 

.done:
    pop rax
    ret
