	.section .data
current_year:
	.word 0
birth_year:
	.word 0

	.section .rodata
current_year_p:
	.ascii "Enter the current year: \000"
	.align 2
birth_year_p:
	.ascii "Enter the year you were born: \000"
	.align 2

print_current_year:
	.ascii "The current year is %d.\012\000"
	.align 2

print_birthday:
	.ascii "This year I turn %d years old.\012\000"
	.align 2

print_both:
	.ascii "In %d, I will turn %d years old.\012\000"


input:
	.ascii "%d\000"
	.align 2

.text
.global main

main:
	push {fp, lr}
	add fp, sp, #4

	ldr r0, current_year_p_ptr
	bl printf

	ldr r1, =current_year
	ldr r0, input_ptr
	bl scanf
	
	ldr r0, birth_year_p_ptr
	bl printf

	ldr r1, =birth_year
	ldr r0, input_ptr
	bl scanf
	
	ldr r1, =current_year
	ldr r1, [r1]
	ldr r0, print_current_year_ptr
	bl printf
	
	ldr r2, =current_year
	ldr r2, [r2]
	ldr r3, =birth_year
	ldr r3, [r3]
	sub r1, r2, r3
	ldr r0, print_birthday_ptr
	bl printf

	ldr r3, =current_year
	ldr r3, [r3]
	ldr r4, =birth_year
	ldr r4, [r4]
	sub r2, r3, r4
	ldr r1, =current_year
	ldr r1, [r1]
	ldr r0, print_both_ptr
	bl printf

	mov r0, #0
	pop {fp,pc}

	.align 2

current_year_p_ptr:
	.word current_year_p
birth_year_p_ptr:
	.word birth_year_p
print_current_year_ptr:
	.word print_current_year
print_birthday_ptr:
	.word print_birthday
print_both_ptr:
	.word print_both
input_ptr:
	.word input
