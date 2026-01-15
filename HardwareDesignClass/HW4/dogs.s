@ Global Constants
	.section .rodata
	@ dogs_prompt: asks how many dogs the user has
dogs_prompt:
	.ascii "How many dogs do you have? \000"
	.align 2
	
	@ input: formatting string for getting user input
input:
	.ascii "%d\000"
	.align 2

	@ response: formatting string for the computer's response
response:
	.ascii "I have %d dogs.\012\000"
	.align 2
	
.text
.global main

	@ main function
	@ save registers fp and lr
main:	
	push {fp, lr}

	@ set up the stack frame, 1 local variable
	add fp, sp, #4
	sub sp, sp, #4

	@[fp, #-4] is an integer, num_dogs, storing the number of dogs
	
	@ print the question asking the user how many dogs they have
	ldr r0, dogs_prompt_ptr
	bl printf
	@ load the address of num_dogs in register r1
	sub r1, fp, #4
	@ load the address of the input formatting string in register r0
	ldr r0, input_ptr
	@ call scanf
	bl scanf


	@ load the value of the variable num_dogs int r0
	ldr r0, [fp, #-4]
	@ increment the value in r0 by 1
	add r0, r0, #1
	@ store the value in r0 to the variable of num_dogs
	str r0, [fp, #-4]
	@ setting up call to printf:
	@ load the value of num_dogs into register r1
	ldr r1, [fp, #-4]
	@ load the address of the string response in register r0
	ldr r0, response_ptr
	@ call printf
	bl printf
	@return 0
	mov r0, #0
	@move sp back to original position
	sub sp, fp, #4
	@restore fp and pc
	pop {fp, pc}

	.align 2
	


@ Pointers
	@ dogs_prompt_ptr: Pointer to the question that asks how many dogs the user has
dogs_prompt_ptr:
	.word dogs_prompt
	@ input_ptr: pointer to the formatting string for user input
input_ptr:
	.word input
	@ response_ptr: pointer to the formatting string response
response_ptr:
	.word response
