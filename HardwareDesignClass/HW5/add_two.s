@Global Constants
	.section .rodata
get_num1:
	.ascii "Enter a number: \000"
	.align 2
get_num2:
	.ascii "Enter another number: \000"
	.align 2
report_total:
	.ascii "%d + %d = %d\012\000"
	.align 2
input:
	.ascii "%d\000"
	.align 2

@add_two function - takes two variables and adds them
add_two:
@Setup stack frame for 2 local variables
	push {fp, lr}
	add fp, sp, #4
	sub sp, sp, #8

@Stores input values
	str r0, [fp, #-8]
	str r1, [fp, #-12]

@Loads input values and adds them
	ldr r0, [fp, #-8]
	ldr r1, [fp, #-12]
	add r0, r0, r1

@tears down stack
	sub sp, fp, #4
	pop {fp, pc}

	.text
	.global main

main:
@Setup Stack for three local variables
	push {fp, lr}
	add fp, sp, #4
	sub sp, sp, #12

@Ask for first number and store it
	ldr r0, get_num1_ptr
	bl printf

	sub r1, fp, #8
	ldr r0, input_ptr
	bl scanf

@Ask for second number and store it
	ldr r0, get_num2_ptr
	bl printf

	sub r1, fp, #12
	ldr r0, input_ptr
	bl scanf

@calls add_two function
	ldr r0, [fp, #-8]
	ldr r1, [fp, #-12]
	bl add_two

@store the output in #-16
	str r0, [fp, #-16]

@report the total
	ldr r0, report_total_ptr
	ldr r1, [fp, #-8]
	ldr r2, [fp, #-12]
	ldr r3, [fp, #-16]
	bl printf
	
@return 0 and tear down stack frame
	mov r0, #0
	sub sp, fp, #4
	pop {fp, pc}

@pointers
get_num1_ptr:
	.word get_num1
get_num2_ptr:
	.word get_num2
report_total_ptr:
	.word report_total
input_ptr:
	.word input
