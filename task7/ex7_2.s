        .text
        .globl main
main:   mov $0 ,%eax #loop count
        mov $0 ,%edx #add result
    L1:  cmp $10, %eax
        je L2
        add $1,%eax
        add %eax, %edx
        jmp L1
    L2: call finish
        