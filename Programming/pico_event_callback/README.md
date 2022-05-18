# Creating high performance library in assembly
This repo directory provides a simple example of creating a static library by writing the functions 
in assembly language. The example features an element-wise vector multiplication where the operation 
performance is measured as number of clock cycles.
The static library build repo is found under the name 'mkv_asm_lib'. The assembly code is 

```
.file	"dsp_cortex_m4.s"
.text
.syntax unified
.align  4

/* Element-wise vector multiplication of floating-point values */
.type   asm_vector_mult_float, %function
.globl  asm_vector_mult_float
asm_vector_mult_float:
.fnstart
float_vec_loop:
vldr 		s0, [r0]
add			r0, r0, #4
vldr 		s1, [r1]
add 		r1, r1, #4
vmul.f32    s1, s0, s1
vstr		s1, [r2]
add			r2, r2, #4
sub			r3, r3, #1
cmp			r3, #0
bne 		float_vec_loop
bx       	lr
.fnend

/* Element-wise vector multiplication of integers */
.type   asm_vector_mult_fixed, %function
.globl  asm_vector_mult_fixed
asm_vector_mult_fixed:
.fnstart
fixed_vec_loop:
ldr		    r4, [r0], #4
ldr		    r5, [r1], #4
mul			r6, r4, r5
str			r6, [r2], #4
sub			r3, r3, #1
cmp			r3, #0
bne 		fixed_vec_loop
bx       	lr
.fnend
```

The software project is developed in MCUXpresso IDE. 

https://www.caspiansystems.dk/