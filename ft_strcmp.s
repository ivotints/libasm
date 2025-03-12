section .text
global ft_strcmp


ft_strcmp:                      ; rdi - s1, rsi - s2
    test rdi, rdi               ; NULL check
    jz .done
    test rsi, rsi
    jz .done

.loop:
    movzx eax, byte [rdi]       ; Load byte from s1 and zero extend it
    movzx edx, byte [rsi]       ; Load byte from s2 and zero extend it
    cmp al, dl
    jne .diff
    test al, al                 ; null terminator check
    jz .done 
    inc rdi
    inc rsi
    jmp .loop

.diff:
    sub eax, edx
    ret

.done:
    xor eax, eax           
    ret

















;                             ;ft_strcmp:          ; rdi - s1, rsi - s2
;                             ;    xor eax, eax
;                             ;    xor edx, edx
;                             ;    cld
;                             ;    test rdi, rdi
;                             ;    je .done
;                             ;    test rsi, rsi
;                             ;    je .done
;                             ;
;  this code is fast,         ;.loop:
;  but valgrind do not like   ;    cmpsb                       ; compare first char of both strings and increment them. in zero case ZF is set
;  it. 2nd version is also    ;    jne .diff
;  more clear than that       ;    test byte [rdi - 1], 0xFF   ; test if previouse byte is not zero
;                             ;    jz .done                    ; end of string
;                             ;    jmp .loop
;                             ;
;                             ;.diff:
;                             ;    movzx   eax, byte [rdi -1]  ; we write to 32 bit eax byte from first string that was different
;                             ;    movzx   edx, byte [rsi -1]  ; we write to 32 bit edx byte from second string that was different
;                             ;    sub eax, edx
;                             ;
;                             ;.done:
;                             ;    ret


