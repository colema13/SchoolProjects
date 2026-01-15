	@global Constants
get_num:
	.ascii "Enter a number: \000"
	.align 2
input:
	.ascii "%d\000"
	.align 2
output:
	.ascii "The sum of your positive numbers is %d.\012\000"
	.align 2

	.text
	.global main

main:
	@set up stack frame
	@#-8: n
	@#-12: sum
	push {fp,lr}
	add fp, sp, #4
	sub sp, sp, #8

	@Set sum to 0
	mov r0, #0
	str r0, [fp, #-12]

loop_start:
	@add n to sum
	ldr r0, [fp, #-8]
	ldr r1, [fp, #-12]
	add r2, r0, r1

	str r2, [fp, #-12]



loop_test:	
	@Get n from user
	ldr r0, get_num_ptr
	bl printf

	ldr r0, input_ptr
	sub r1, fp, #8
	bl scanf

	@check loop condition if n > 0, repeat loop
	ldr r0, [fp, #-8]
	cmp r0, #0
	bgt loop_start

	@output the sum of your positive numbers
	ldr r0, output_ptr
	ldr r1, [fp, #-12]
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

	
