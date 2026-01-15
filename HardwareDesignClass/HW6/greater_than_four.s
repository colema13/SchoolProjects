	@global constants
	.section .rodata
	@question - asks for number
question:
	.ascii "Enter a number: \000"
	.align 2
input:
	.ascii "%d\000"
	.align 2
output:
	.ascii "This number is greater than 4.\012\000"
	.align

	.text
	.global main

	@main
main:
	@set up stack frame for main
	@x is [fp, #-8]
	push {fp, lr}
	add fp, sp, #4
	sub sp, sp, #4

	@prompt user for number and store in #-8
	ldr r0, question_ptr
	bl printf

	sub r1, fp, #8
	ldr r0, input_ptr
	bl scanf

	@if number isn't greater than 4, go to endif
	ldr r0, [fp, #-8]
	cmp r0, #4
	ble endif

	ldr r0, output_ptr
	bl printf

endif:
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
output_ptr:
	.word output
