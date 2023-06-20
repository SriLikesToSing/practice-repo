;external include files

;when do you choose to push registers onto the stack?
	; for the functions file it was prbably because this program might have had used those registers 
		; for something else entirely

;the reason it prints something out 2 times is because variables are stored contiguously in memory. 
;this means that you need to put 0h or a null terminating byte for a zero flag to be set to deliniate strings

%include 'functions.asm'

SECTION .data
msg1 db 'Hello, brave new world!' , 0Ah, 0h
msg2 db 'This is how we recycle in NASM.', 0Ah, 0h

SECTION .text
global _start

_start:

	mov eax, msg1
	call sprint

	mov eax, msg2
	call sprint


	call quit



























































