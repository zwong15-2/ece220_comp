;
; The code given to you here implements the histogram calculation that 
; we developed in class.  In programming lab, we will add code that
; prints a number in hexadecimal to the monitor.
;
; Your assignment for this program is to combine these two pieces of 
; code to print the histogram to the monitor.
;
; If you finish your program, 
;    ** commit a working version to your repository  **
;    ** (and make a note of the repository version)! **


	.ORIG	x3000		; starting address is x3000


;
; Count the occurrences of each letter (A to Z) in an ASCII string 
; terminated by a NUL character.  Lower case and upper case should 
; be counted together, and a count also kept of all non-alphabetic 
; characters (not counting the terminal NUL).
;
; The string starts at x4000.
;
; The resulting histogram (which will NOT be initialized in advance) 
; should be stored starting at x3F00, with the non-alphabetic count 
; at x3F00, and the count for each letter in x3F01 (A) through x3F1A (Z).
;
; table of register use in this part of the code
;    R0 holds a pointer to the histogram (x3F00)
;    R1 holds a pointer to the current position in the string
;       and as the loop count during histogram initialization
;    R2 holds the current character being counted
;       and is also used to point to the histogram entry
;    R3 holds the additive inverse of ASCII '@' (xFFC0)
;    R4 holds the difference between ASCII '@' and 'Z' (xFFE6)
;    R5 holds the difference between ASCII '@' and '`' (xFFE0)
;    R6 is used as a temporary register
;

	LD R0,HIST_ADDR      	; point R0 to the start of the histogram
	
	; fill the histogram with zeroes 
	AND R6,R6,#0		; put a zero into R6
	LD R1,NUM_BINS		; initialize loop count to 27
	ADD R2,R0,#0		; copy start of histogram into R2

	; loop to fill histogram starts here
HFLOOP	STR R6,R2,#0		; write a zero into histogram
	ADD R2,R2,#1		; point to next histogram entry
	ADD R1,R1,#-1		; decrement loop count
	BRp HFLOOP		; continue until loop count reaches zero

	; initialize R1, R3, R4, and R5 from memory
	LD R3,NEG_AT		; set R3 to additive inverse of ASCII '@'
	LD R4,AT_MIN_Z		; set R4 to difference between ASCII '@' and 'Z'
	LD R5,AT_MIN_BQ		; set R5 to difference between ASCII '@' and '`'
	LD R1,STR_START		; point R1 to start of string

	; the counting loop starts here
COUNTLOOP
	LDR R2,R1,#0		; read the next character from the string
	BRz PRINT_HIST		; found the end of the string

	ADD R2,R2,R3		; subtract '@' from the character
	BRp AT_LEAST_A		; branch if > '@', i.e., >= 'A'
NON_ALPHA
	LDR R6,R0,#0		; load the non-alpha count
	ADD R6,R6,#1		; add one to it
	STR R6,R0,#0		; store the new non-alpha count
	BRnzp GET_NEXT		; branch to end of conditional structure
AT_LEAST_A
	ADD R6,R2,R4		; compare with 'Z'
	BRp MORE_THAN_Z         ; branch if > 'Z'

; note that we no longer need the current character
; so we can reuse R2 for the pointer to the correct
; histogram entry for incrementing
ALPHA	ADD R2,R2,R0		; point to correct histogram entry
	LDR R6,R2,#0		; load the count
	ADD R6,R6,#1		; add one to it
	STR R6,R2,#0		; store the new count
	BRnzp GET_NEXT		; branch to end of conditional structure

; subtracting as below yields the original character minus '`'
MORE_THAN_Z
	ADD R2,R2,R5		; subtract '`' - '@' from the character
	BRnz NON_ALPHA		; if <= '`', i.e., < 'a', go increment non-alpha
	ADD R6,R2,R4		; compare with 'z'
	BRnz ALPHA		; if <= 'z', go increment alpha count
	BRnzp NON_ALPHA		; otherwise, go increment non-alpha

GET_NEXT
	ADD R1,R1,#1		; point to next character in string
	BRnzp COUNTLOOP		; go to start of counting loop



PRINT_HIST

; you will need to insert your code to print the histogram here

; do not forget to write a brief description of the approach/algorithm
; for your implementation, list registers used in this part of the code,
; and provide sufficient comments

;This code prints the desired histogram to the monitor.

;The code pulls initial ascii value for @ in memory and displays the next value

;by adding one to the value after each new line

;after doing this a space is added, and the hex number stored in the ascii 

;values bin is outputed using a subroutine made in Lab 1 part b.





;Registers:

;R0: Used to output characters to monitor

;R2: Counter



			AND R0, R0, #0		;initialization of registers

			AND R2, R2, #0

	

			LD R2, NUM_BINS		;Loads the number of bins in the counter (27)

		

NEXT_BIN	LD R0, FIRST_ASCII	;Load ascii character from associated bin into R0

			OUT					;output to monitor

		

			ADD R0, R0, #1		;shift ascii character to the next character in order

			ST R0, FIRST_ASCII	;store new value in memory space

			

			LD R0, SPACE		;load value for 'space' into R0

			OUT					;output to monitor



			BRnzp HEX			;move to hex subroutine to print number stored bin value to monitor

		

RETURN		LD R0, NEXT_LINE	;print a new line to monitor

			OUT

		

			ADD R2, R2, #-1     ;decrement the counter by 1

			BRp NEXT_BIN        ;Grab the next bin (if necessary)

			HALT











HEX

		; Prints out a hexadecimal number store in register R3 to the console. The hexadecimal number has to be converted to an appropriate ASCII character in order for the number to     be displayed correctly.



		; Inputs:

		;   R3: hexadecimal number



		; Outputs:

		;   [0 - F]{4} printed to console



		;Registers

		;R0: Used to output to moniter

		;R1: Shift counter

		;R2: Bitwise adder

		;R3: Storage for bin value

		;R4: Overall counter

				

				ST R2, COUNTER



				AND R0, R0, #0			;initialization of registers

				AND R1, R1, #0

				AND R2, R2, #0

				AND R4, R4, #0

	

				ADD R4, R4, #4			;set counter

				LDI R3, HIST_ADDR		;load histogram from memory address



	BACK		ADD R1, R1, #4			;Set shift counter

								

	LOOP		ADD R2, R2, R2			;Left shift R2

				ADD R3, R3, x0000		;Check if R3 is positive/negative

				BRzp	ZERO

				ADD R2, R2, #1			;Add 1 to R2 (if negative)

			

	ZERO		ADD R3, R3, R3			;left shift R3



				ADD R1, R1, #-1			;decrement counter

				BRnp LOOP				;loop 4 times



				ADD R0, R2, #-9			;Check if hex digit is letter or number

				BRnz NUM

				LD R0, ASCII_LET		;if letter, then add letter offset to R0

				BRnzp SKIP

	NUM			LD R0, ASCII_NUM		;if number, add number offset to R0

			

	SKIP		ADD R0, R2, R0 			;add 4-bits to offset



				OUT

				AND R2, R2, x0000		;reset bitwise and R0



				ADD R4, R4, #-1			;decrement overall counter

				BRz DONE				;end if R3 is zero



				AND R0, R0, x0000       ;reset R0

				BRnzp BACK



	DONE		LD R3, HIST_ADDR        ;Load histogram address into R3

				ADD R3, R3, #1          ;Add 1 to R3

				ST R3, HIST_ADDR        ;Store into R3

				LD R2, COUNTER          ;Load counter into R2

				BRnzp RETURN			; move back to other code section




; the data needed by the program
FIRST_ASCII .FILL x0040 ; holds the value of first ASCII character
COUNTER		.FILL x0000 ; holds the counter value
SPACE		.FILL x0020 ; holds the value for the 'space' character
NEXT_LINE	.FILL x000A ; holds the value for the 'newline' character
ASCII_LET	.FILL x0037 ; holds the offset for ASCII letters
ASCII_NUM	.FILL x0030 ; holds the offset for ASCII numbers
NUM_BINS	.FILL #27	; 27 loop iterations
NEG_AT		.FILL xFFC0	; the additive inverse of ASCII '@'
AT_MIN_Z	.FILL xFFE6	; the difference between ASCII '@' and 'Z'
AT_MIN_BQ	.FILL xFFE0	; the difference between ASCII '@' and '`'
HIST_ADDR	.FILL x3F00 ; histogram starting address
STR_START	.FILL x4000	; string starting address

; for testing, you can use the lines below to include the string in this
; program...
; STR_START	.FILL STRING	; string starting address
; STRING		.STRINGZ "This is a test of the counting frequency code.  AbCd...WxYz."



	; the directive below tells the assembler that the program is done
	; (so do not write any code below it!)

	.END
