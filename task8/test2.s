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
  mov $0, %edi

  add x(,%esi,4), %edx
  add $1, %esi
  add x(,%esi,4), %ecx
  add $1, %esi
  add x(,%esi,4), %ebx
  add $1, %esi
  add x(,%esi,4), %eax
  sub $3, %esi

  add y(,%esi,4), %edi
  cmp %edx, %edi
    ja L1
  sub %edi, %edx
  jmp L01

L01:
    neg edi
    add $0x7fffffff, %edi
    add %edi, %edx
    sub $1, %ecx

L1:
