.data
x: .long 0x3456cdef # 2+1+2+2+2+3+3+4 = 19 = 0x13 
.text 
.global main
main:
    mov $0, %eax
    mov $0, %ebx
    movl x, %ecx
L0:
    cmp $32, %ebx
      je  L2
    add $1, %ebx
    shr $1, %ecx
      jc  L1
      jmp L0
L1:
    add $1, %eax
      jmp L0
L2:
    call finish
