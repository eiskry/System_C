.data
vendor_id: .string “wwwwxxxxyyyyzzzz"
.text
.globl main
main:
push %ebp
mov %esp, %ebp
mov$0, %eax
cpuid
mov $vendor_id, %esi
movl %ebx, 0(%esi) # first 4 letters
movl %edx, 4(%esi) # next 4 letters
movl %ecx, 8(%esi) # last 4 letters
movl $0x0000000a, 12(%esi) # “¥n¥0¥0¥0”
push %esi
call printf
pop %eax
leave
ret