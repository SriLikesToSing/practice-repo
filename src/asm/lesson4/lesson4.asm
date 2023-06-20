;subroutines
; what are subroutines?
	
;	  - they are better than jmp instruction because it automatically returns to address after executing
;	  	- behaves like a function

;	  - what is the difference between jmp and call?
;	  	- jmp just jumps directly to the memory address you tell it to 
;		- call stores the return value of the current address onto the stack to come back to it
;			after the call is executed


SECTION .data
msg db 'Hello, brave new world!', 0Ah ; this is the extra bit after 

SECTION .text
global _start

_start: 
	
	mov eax, msg
	call strlen

	mov edx, eax
	mov ecx, msg
	mov ebx, 1
	mov eax, 4
	int 80h

	; returns before continuing again to strlen: 
	mov ebx, 0
	mov eax, 1
	int 80h

;one continugous execution once it's called
strlen:
	push ebx
	mov ebx, eax

nextchar:
	cmp byte[eax], 0
	jz finished
	inc eax
	jmp nextchar

finished:
	sub eax, ebx
	pop ebx
	ret
	






























