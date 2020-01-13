        .data
        a: .long 1,2,3,4,5,6,0
        i: .long 0
        sum: .long 0
        .text
        .globl main
main:   
L1:     mov i, %eax
        mov sum, %ebx
        cmp $0, a(,%eax,4)
            je L2
        add a(,%eax,4), %ebx
        add $1, %eax
        mov %eax, i
        mov %ebx, sum
            jmp L1
L2:     mov i, %eax
        mov sum, %ebx
        call finish