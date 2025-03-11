section .text
global ft_write
extern __errno_location

                	                    ; ssize_t ft_write(int fd, const void *buf, size_t count);
ft_write:                   
    mov rax, 1                          ; set rax to 1 what means syscall 1 - write. (better do it with xor, inc)
                                        ; in rdi we already have fd
                                        ; in rsi we already have buf
                                        ; in rdx we already have message len
    syscall                             ; invoke system call 1 - write
    test rax, rax                       ; if return value was negative - error: SF (sign flag) is set
    jns .done                           ; jump if not sign to done

    neg rax                             ; to get positive error code. -16 -> 16
    mov rdi, rax                        ; now we need to safe rax somewhere. push rdx or use rdi    
    call __errno_location wrt ..plt     ; it will set rax to point on errno. in rax now pointer to errno
                                        ; plt is procedure linkage table. (to find adress of __errno_location in C lib) . We need plt because in compile time compiler do not know adress of that function
                                        ; wrt is WithRespectTo.
    mov [rax], rdi                      ; set error in errno
    mov rax, -1                         ; default value in case of error
    
.done:
    ret
