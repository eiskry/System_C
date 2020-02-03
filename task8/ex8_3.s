.data
x: .long 0x754f5900, 0x758f6640, 0x6d20645c, 0x000a2167 
y: .long 0xfedcba98, 0x76543210, 0x9abcdef0, 0x00045678 
.text
.global main
main:
    mov $0, %edx
    mov $0, %ecx
    mov $0, %ebx
    mov $0, %eax
    mov $0, %esi

    add x(,%esi,4), %edx
    sub y(,%esi,4), %edx
      js  L0  # negative
      jmp L00
L00:
    add $1, %esi
    add x(,%esi,4), %ecx
    sub y(,%esi,4), %ecx
      js  L1 # negative
      jmp L10
L10:
    add $1, %esi
    add x(,%esi,4), %ebx
    sub y(,%esi,4), %ebx
      js  L2
      jmp L20
L20:
    add $1, %esi
    add x(,%esi,4), %eax
    sub y(,%esi,4), %eax
    call finish
L0:
    add $0xffffffff, %edx
    sub $1, %ecx
      jmp L00
L1:
    add $0xffffffff, %ecx
    sub $1, %ebx
      jmp L10
L2:
    add $0xffffffff, %ebx
    sub $1, %eax
      jmp L20
