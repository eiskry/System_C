 .data
  .align 4
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
  add y(,%esi,4), %edx
  jc  L0
  jmp L00

L00:
  add $1, %esi
  add x(,%esi,4), %ecx
  add y(,%esi,4), %ecx
  jc  L1
  jmp L10

L10:
  add $1, %esi
  add x(,%esi,4), %ebx
  add y(,%esi,4), %ebx
  jc  L2
  jmp L20

L20:
  add $1, %esi
  add x(,%esi,4), %eax
  add y(,%esi,4), %eax
  call stop

L0:
	add $1, %ecx
  jmp L00

L1:
	add $1, %ebx
  jmp L10

L2:
	add $1, %eax
  jmp L20
© 2020 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
Pricing
API
Training
Blog
About
