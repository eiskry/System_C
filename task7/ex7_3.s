        .text
        .globl main
main:   mov $0,%esi #n
        mov $20,%edi    
        mov $0, %eax # fib(n)
        mov $0, %ebx # fib(n-1)
        mov $1, %ecx # fib(n-2)
        mov $0, %edx # temporary variable
        #fib(0)
        cmp $0, %edi
            je return       
        /* fib(1) */
        add $1, %esi
        mov %ecx, %eax
        cmp $1, %edi
            je return       
        /* fib(n) */
fib:    add $1,%esi
        mov %ebx, %ecx /* fib(n-1) -> fib(n-2) */
        mov %eax, %ebx /* fib(n) -> fib(n-1) */
        mov %ebx, %edx 
        add %ecx, %edx /* temp = fib(n-1)+fib(n-2) */
        mov %edx, %eax /* fib(n) =temp */
        cmp %edi, %esi 
	        je return
        jmp fib
return:
        call finish