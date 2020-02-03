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

  add $0x7fffffff, %eax
  add $3, %ebx
  neg ebx
  call finish
