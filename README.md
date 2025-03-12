Register   Caller-Saved   Special Use 
           (Volatile)  
rax         ✅ Yes       Return value (functions return results in rax)
rbx         ❌ No        Preserved across function calls
rcx         ✅ Yes       4th function argument (Linux ABI)
rdx         ✅ Yes       3rd function argument
rsi         ✅ Yes       2nd function argument
rdi         ✅ Yes       1st function argument
rsp         ❌ No        Stack pointer (must be maintained properly)
rbp         ❌ No        Base pointer (optional, often used for stack frames)
r8          ✅ Yes       5th function argument
r9          ✅ Yes       6th function argument
r10         ✅ Yes       Caller-saved, used for syscall number
r11         ✅ Yes       Caller-saved, used for syscall flags
r12         ❌ No        Preserved across function calls
r13         ❌ No        Preserved across function calls
r14         ❌ No        Preserved across function calls
r15         ❌ No        Preserved across function calls

            ✅ - contain trash
            ❌ - safe before use