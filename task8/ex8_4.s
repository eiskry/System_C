.data
x: .long 120, -100, 60, -200
y: .long 10, 50, -3, -25
z: .long 0, 0, 0, 0
.text
.global main
main:
        mov $0, %esi
.L1:    cmp $4, %esi
        je .L2
        mov x(,%esi,4), %eax
        cltd
        idivl y(,%esi,4)
        mov %eax, z(,%esi,4)
        inc %esi
        jmp .L1
.L2:    mov $0, %esi
        mov z(,%esi,4), %eax
        inc %esi
        mov z(,%esi,4), %ebx
        inc %esi
        mov z(,%esi,4), %ecx
        inc %esi
        mov z(,%esi,4), %edx
        call finish