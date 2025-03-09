section .text
global ft_strlen            ; Export the function name

ft_strlen:
    xor rax, rax            ; Set rax to 0; rax = rax (xor) rax
    
    test rdi, rdi           ; Performs a bitwise AND between rdi (register that holds a first argument) and itself. If result is 0 (0 && 0) -> ZF (zero flag) is set. If rdi is non-zero (1 && 1 -> 1) nothing happens.
    jz .done                ; If ZF (zero flag) is set (meaning rdi (first argument) is zero), jump to .done

.loop:
    cmp byte [rdi + rax], 0 ; cmp is substraction whithout storing the result. ZF (zero flag) is set if result of substaction is zero. jz and je are same
    je .done                ; js (jump if equal) is same as jz (jump if zero).
    inc rax                 ; increment our counter/return value
    jmp .loop               ; repeat

.done:
    ret                     ; Return length in rax