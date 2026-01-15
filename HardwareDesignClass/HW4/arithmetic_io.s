	@ Global Constants
	.section .rodata
	@num1_prompt: asks for num1
num1_prompt:
	.ascii "What is the first number? \000"
	.align 2

	@num2_prompt: asks for num2
num2_prompt:
	.ascii "What is the second number? \000"
	.align 2

	@ add_ans: gives the numbers added
add_ans:
	.ascii "%d + %d = %d\012\000"
	.align 2

	@ sub_ans: gives the numbers subtracted
sub_ans:
	.ascii "%d - %d = %d\012\000"
	.align 2

	@ mut_ans: gives the numbers multiplied
mult_ans:
	.ascii "%d x %d = %d\012\000"
	.align 2

	@ input: formatting string for getting user input
input:
	.ascii "%d\000"
	.align 2

	.text
	.global main
	@main function
main:
	@save registers fp and lr
	push {fp, lr}
	
	@ set up the stack frame, 2 local variables
	add fp, sp, #4
	sub sp, sp, #8

	@ [fp, #-8] is an int, num1, storing the first number
	@ [fp, #-12] is an int, num2, storing the second number

	@ prompt user for first number
	ldr r0, num1_prompt_ptr
	bl printf

	@ get the first input
	sub r1, fp, #8
	ldr r0, input_ptr
	bl scanf

	@ prompt user for second number
	ldr r0, num2_prompt_ptr
	bl printf

	@get the second input
	sub r1, fp, #12
	ldr r0, input_ptr
	bl scanf

	@print outputs
	ldr r1, [fp, #-8]
	ldr r2, [fp, #-12]
	add r3, r1, r2
	ldr r0, add_ans_ptr
	bl printf

	ldr r1, [fp, #-8]
	ldr r2, [fp, #-12]
	sub r3, r1, r2
	ldr r0, sub_ans_ptr
	bl printf

	ldr r1, [fp, #-8]
	ldr r2, [fp, #-12]
	mul r3, r1, r2
	ldr r0, mult_ans_ptr
	bl printf

	@ return 0
	mov r0, #0

	@ move sp back or original position
	sub sp, fp, #4
	@ restore fp and pc
	pop {fp, pc}

	.align 2


	@pointers
num1_prompt_ptr:
	.word num1_prompt

num2_prompt_ptr:
	.word num2_prompt
add_ans_ptr:
	.word add_ans
sub_ans_ptr:
	.word sub_ans
mult_ans_ptr:
	.word mult_ans
input_ptr:
	.word input
