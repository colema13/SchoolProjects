	@global constants
	.section .rodata
get_num:
	.ascii "Enter a number: \000"
	.align 2

input:
	.ascii "%d\000"
	.align 2
output:
	.ascii "The sum of squares from 1 through %d is %d.\012\000"
	.align 2

	.text
	.global main

main:
	@Set up stack frame
	@#-8: i
	@#-12: n
	@#-16: sum

	push {fp,lr}
	add fp, sp, #4
	sub sp, sp, #12

	@set i to 1 and sum to 0
	mov r0, #1
	str r0, [fp, #-8]
	mov r0, #0
	str r0, [fp, #-16]

	@Get n from user
	ldr r0, get_num_ptr
	bl printf

	ldr r0, input_ptr
	sub r1, fp, #12
	bl scanf

	@ start of loop
loop_start:
	@ load values of i and sum
	ldr  r0, [fp, #-8]
	ldr  r1, [fp, #-16]
	@square i
	mul r2, r0, r0
	@ add i to sum
	add  r1, r2, r1
	str  r1, [fp, #-16]
	@ add 1 to i
	add  r0, r0, #1
	str  r0, [fp, #-8]
	
loop_test:
	@ check loop condition if i <= n, repeat loop
	ldr  r0, [fp, #-8]
	ldr r3, [fp, #-12]
	cmp  r0, r3
	ble  loop_start

	@After loop print sum
	ldr r0, output_ptr
	ldr r1, [fp, #-12]
	ldr r2, [fp, #-16]
	bl printf

	@return 0 and restore fp and pc
	mov r0, #0
	sub sp, fp, #4
	pop {fp, pc}

	.align 2

	@Pointers
get_num_ptr:
	.word get_num
input_ptr:
	.word input
output_ptr:
	.word output
