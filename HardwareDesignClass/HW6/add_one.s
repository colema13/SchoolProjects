	.section .rodata
	@ reports data for num1, num2, num1_plus, and num2_plus
report_results:
	.ascii "%d + 1 = %d and %d + 1 = %d\012\000"
	.align 2

	.text
	.global main

main:
	@ set up stack frame for main
	push {fp,lr}
	add fp, sp, #4
	sub sp, sp, #16
	@ #-8 is num1
	@ #-12 is num2
	@ #-16 is num1_plus
	@ #-20 is num2_plus

	@ initialize #-8 as 4
	mov r3, #4
	str r3, [fp,#-8]

	@ initialize #-12 as 7
	mov r3, #7
	str r3, [fp,#-12]

	@ call add_one to num1 and store it in num1_plus
	ldr r0, [fp,#-8]
	bl add_one
	str r0, [fp,#-16]

	@ call add_one to num2 and store it in num1_plus
	ldr r0, [fp,#-12]
	bl add_one
	str r0, [fp,#-20]

	@ print results
	ldr r1, [fp,#-8]
	ldr r2, [fp,#-16]
	ldr r3, [fp,#-12]
	ldr r4, [fp,#-20]
	ldr r0, report_results_ptr

	bl printf

	@ return 0
	mov r0, #0
	@ tear down stack frame for main
	sub sp, fp, #4
	pop {fp, pc}

	.align 2
@adds one to select numbers	
add_one:
	@set up stack frame for add_one
	@x = [fp,#-8]
	push {fp, lr}
	add fp, sp, #4
	sub sp, sp, #4

	@store values
	str r0, [fp, #-8]

	@load x and add one
	ldr r0, [fp,#-8]
	add r0, r0, #1

	@tear down stack frame
	sub sp, fp, #4
	pop {fp, pc}
	
report_results_ptr:
	.word report_results
