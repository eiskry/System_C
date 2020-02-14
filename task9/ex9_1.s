.text
.global main
L0:   #x=0
    mov $0, %eax
    leave
    ret
L1:   #x=1
    mov $1, %eax
    leave
    ret

fib:
    # 旧 ebp 待避
    push %ebp
    # 新 ebp セット
    mov %esp, %ebp
    # x=1
    cmp $1, %eax
        je L1
    # x = 0
    cmp $0, %eax
        je L0
    
    # xの待避
    push %eax
    # fib(x-1)
    sub $1, %eax
    call fib
    mov %eax, %ecx

    # xの復帰
    pop %eax
    
    #fib (x - 1) を待避
    push %ecx
    # fib (x - 2)
    sub $2, %eax
    call fib
    # %ecx の復帰
    pop %ecx

    add %ecx, %eax

    leave
    ret

main:
    mov $20, %eax
    call fib
    call finish
