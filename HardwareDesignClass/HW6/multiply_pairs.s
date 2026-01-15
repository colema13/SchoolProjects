	@global Constants
	.section .rodata
return_data:
	.ascii "%d x %d = %d\012\000"
	.align 2

mul_two:
	@set up stack fram for mul_two
	@#-8 is x
	@#-12 is y
	push {fp, lr}
	add fp, sp, #4
	sub sp, sp, #8

	@store values
	str r0, [fp,#-8]
	str r1, [fp,#-12]

	@load x and y 
	ldr r0, [fp, #-8]
	ldr r1, [fp, #-12]

	@multiply x and y
	mul r0, r0, r1

	@tear down stack frame
	sub sp, fp, #4
	pop {fp, pc}

	.text
	.global main

	@ main
main:	
	@ set up stack frame for main
	@#-8 is a
	@#-12 is b
	@#-16 is c
	@#-20 is axb
	@#-24 is bxc
	@#-28 is cxa
	push {fp, lr}
	add fp, sp, #4
	sub sp, sp, #24
	
	@ initialize a to 4
	mov r3, #4
	str r3, [fp, #-8]
	
	@ initialize b to 9
	mov r3, #9
	str r3, [fp, #-12]
	
	@ initialize c to 7
	mov r3, #7
	str r3, [fp, #-16]
	
	@ call mul_two on a and b, and store the result to axb
	ldr r0, [fp, #-8]
	ldr r1, [fp, #-12]
	bl mul_two
	str r0, [fp, #-20]
	@ call mul_two on b and c, and store the result to bxc
	ldr r0, [fp, #-12]
	ldr r1, [fp, #-16]
	bl mul_two
	str r0, [fp, #-24]
	
	@ call mul_two on a and c, and store the result to axc
	ldr r0, [fp, #-16]
	ldr r1, [fp, #-8]
	bl mul_two
	str r0, [fp, #-28]

	@print axb
	ldr r0, return_data_ptr
	ldr r1, [fp, #-8]
	ldr r2, [fp, #-12]
	ldr r3, [fp, #-20]
	bl printf

	@print bxc
	ldr r0, return_data_ptr
	ldr r1, [fp, #-12]
	ldr r2, [fp, #-16]
	ldr r3, [fp, #-24]
	bl printf

	@print axc
	ldr r0, return_data_ptr
	ldr r1, [fp, #-16]
	ldr r2, [fp, #-8]
	ldr r3, [fp, #-28]
	bl printf
	
	@ return 0
	mov r0, #0
	
	@ tear down stack frame for main
	sub sp, fp, #4
	pop {fp, pc}

	.align 2

	@pointers
return_data_ptr:
	.word return_data
