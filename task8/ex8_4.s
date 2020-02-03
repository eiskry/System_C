.data
x: .long 120, -100, 60, -200
y: .long 10, 50, -3, -25
z: .long 0, 0, 0, 0
.text
.global main
main:
  mov $0, %eax #q
  mov $0, %edx #r

  mov $0, %ebx
  mov $0, %ecx

  mov $0, %esi #step

  mov $0, %edi #hinan


  add x(,%esi,4), %eax
  add y(,%esi,4), %ebx

  idiv ebx

  # mov src1, %eax
