section .text
global ft_strcmp

ft_strcmp:          ; rdi - s1, rsi - s2
    xor eax, eax
    xor edx, edx
    cld
    test rdi, rdi
    je .done
    test rsi, rsi
    je .done

.loop:
    cmpsb                       ; compare first char of both strings and increment them. in zero case ZF is set
    jne .diff
    test byte [rdi - 1], 0xFF   ; test if previouse byte is not zero
    jz .done                    ; end of string
    jmp .loop

.diff:
    movzx   eax, byte [rdi -1]  ; we write to 32 bit eax byte from first string that was different
    movzx   edx, byte [rsi -1]  ; we write to 32 bit edx byte from second string that was different
    sub eax, edx

.done:
    ret
