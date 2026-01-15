	@global constants
	.section .rodata
	@question - asks for a number
question:
	.ascii "Enter a number: \000"
	.align 2

	@input - gets the answer
input:
	.ascii "%d\000"
	.align 2

	@mult_output - prints the sum
add_output:	
	.ascii "%d + %d = %d\012\000"
	.align 2

	@sub_output - prints the difference
sub_output:	
	.ascii "%d - %d = %d\012\000"
	.align 2

	.text
	.global main

	@sum function
sum:
	@set up stack frame for sum
	@x = [fp, #-8]
	@y = [fp, #-12]
	push {fp, lr}
	add fp, sp ,#4
	sub sp, sp, #8

	@store values
	str r0, [fp, #-8]
	str r1, [fp, #-12]

	@load x and y
	ldr r0, [fp, #-8]
	ldr r1, [fp, #-12]

	@add x and y
	add r0, r0, r1

	@tear down stack frame
	sub sp, fp, #4
	pop {fp, pc}

	@difference function
difference:
	@set up stack frame for difference
	@x is [fp, #-8]
	@y is [fp, #-12]
	push {fp, lr}
	add fp, sp, #4
	sub sp, sp, #8

	@store values
	str r0, [fp, #-8]
	str r1, [fp, #-12]

	@load values
	ldr r0, [fp, #-8]
	ldr r1, [fp, #-12]

	@subtract x and y
	sub r0, r0, r1

	@tear down stack frame
	sub sp, fp, #4
	pop {fp, pc}

	@main
main:
	@set up stack frame for main
	@a is [fp, #-8]
	@b is [fp, #-12]
	@a+b is [fp, #-16]
	@a-b is [fp, #-20]
	@b-a is [fp, #-24]
	push {fp, lr}
	add fp, sp, #4
	sub sp, sp, #20

	@get first number and store in a
	ldr r0, question_ptr
	bl printf

	sub r1, fp, #8
	ldr r0, input_ptr
	bl scanf

	@get second number and store in b
	ldr r0, question_ptr
	bl printf

	sub r1, fp, #12
	ldr r0, input_ptr
	bl scanf

	@call sum and store in #-16
	ldr r0, [fp, #-8]
	ldr r1, [fp, #-12]
	bl sum

	str r0, [fp, #-16]

	@call difference for a-b and store in #-20
	ldr r0, [fp, #-8]
	ldr r1, [fp, #-12]
	bl difference

	str r0, [fp, #-20]

	@call difference for b-a and store in #-24
	ldr r0, [fp, #-12]
	ldr r1, [fp, #-8]
	bl difference

	str r0, [fp, #-24]

	@output results
	@sum
	ldr r0, add_output_ptr
	ldr r1, [fp, #-8]
	ldr r2, [fp, #-12]
	ldr r3, [fp, #-16]
	bl printf

	@a-b
	ldr r0, sub_output_ptr
	ldr r1, [fp, #-8]
	ldr r2, [fp, #-12]
	ldr r3, [fp, #-20]
	bl printf

	@b-a
	ldr r0, sub_output_ptr
	ldr r1, [fp, #-12]
	ldr r2, [fp, #-8]
	ldr r3, [fp, #-24]
	bl printf

	@return 0
	mov r0, #0

	@tear down stack frame
	sub sp, fp, #4
	pop {fp, pc}

	.align 2

	@pointers
question_ptr:
	.word question
input_ptr:
	.word input
add_output_ptr:
	.word add_output
sub_output_ptr:
	.word sub_output
