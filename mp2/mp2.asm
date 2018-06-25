; mp2.asm
; Implement a stack calculator that can do the following operations:
; ADD, SUBTRACT, MULTIPLY, DIVIDE

;Description: This program evaluates a postfix expression, calculates its value in hex, stores it in R5, and outputs the hex value to console.
;the program works in the following way: in the main routine, a value is inputed to monitor. The code checks for "=" and "space." If "=" is detected, the program checks 
;if there is only one value in the stack; if there is, that value is outputted and stored in R5. After these two characters are checked, the program jumps to the 
;EVALUATE subroutine and checks if the character is an operate and then an operand. If neither, the program outputs "Invalid Expression." If its an operate, two values
;are popped from memory, stored in R3 and R4, then they are sent to an arithmetic subroutine (different one depending on operant inputted) and the result is pushed into
;memory.

; Inputs:
;   Console - postfix expression

; Outputs:
;   Console - [0 - F]{4}, evaluation of postfix expression
;   Register R5 - [0 - F]{4}, evaluation of postfix expression

;Registers used
;R0 -- Store console inputs and output characters onto screen
;R1 -- Temporary storage for loading character values from memory
.ORIG x3000
	
MAIN

			IN		;Get input value from console

			LD R1, EQUAL_VAL		;determine if input is equal 
			NOT R1, R1
			ADD R1, R1, #1
			ADD R1, R1, R0
			BRz ONE_VAL

			LD R1, SPACE			;check if input is a 'space'
			NOT R1, R1
			ADD R1, R1, #1
			ADD R1, R1, R0
			BRz MAIN				;if space, move back to beginning

			JSR EVALUATE            ;parse through data to determine input
			BRnzp MAIN


;Evaluate Subroutine
;DESCRIPTION: Evalaute calls upon pop, push, add, subtract, multiply
;and divide subroutines depending on if the input is an operator or operand.
;Inputs: R0 - Input Value
;Outputs:R0 - Evaluated input value

EVALUATE

		    LD R1, ASCII_MULT		;Check if input is a "*"
			JSR NEGATE
			
			ADD R1, R0, R1			;If it is, send to multiply subroutine
			BRnp CHECK_DIV
			JSR TWO_POP             
			JSR MUL

CHECK_DIV	LD R1, ASCII_DIV		;Check if input is a "/"
			JSR NEGATE
			
			ADD R1, R0, R1          ;If it is, send to divison subroutine
			BRnp CHECK_PLUS
			JSR TWO_POP
			JSR DIV

CHECK_PLUS	LD R1, ASCII_PLUS		;Check if input is a "+"
			JSR NEGATE
			
			ADD R1, R0, R1          ;If it is, send to addition subroutine
			BRnp CHECK_MIN
			JSR TWO_POP
			JSR PLUS

CHECK_MIN	LD R1, ASCII_MINUS		;Check if input is a "-"
			JSR NEGATE
			
			ADD R1, R0, R1          ;If it is, send to subtract subroutine
			BRnp CHECK_NUM
			JSR TWO_POP
			JSR MIN

CHECK_NUM	LD R1, ASCII_ZERO		;load ascii zero value into R1 and negate it
			JSR NEGATE

			ADD R1, R0, R1			;check if input is above ascii zero value, if not then it is an invalid expression
			BRn INVALID		

			LD R1, ASCII_NINE		;load ascii nine into R0 and negate it
			JSR NEGATE

			ADD R1, R0, R1
			BRp INVALID

			LD R1, ASCII_ZERO		;Convert ASCII value to its HEX number
			JSR NEGATE

			ADD R0, R1, R0

	        JSR PUSH
			
			LD R7, MAIN_ADDR        ;Return back to MAIN
			RET


;DATA
MAIN_ADDR	.FILL x3000			
ASCII_MULT	.FILL x002A
ASCII_DIV	.FILL x002F
ASCII_PLUS	.FILL x002B
ASCII_MINUS	.FILL x002D
ASCII_ZERO	.FILL x0030			
ASCII_NINE	.FILL x0039
EQUAL_VAL	.FILL x003D
SPACE		.FILL x0020





NEGATE
;negates character in R1
;Inputs: R1 - Input Value
;Outputs: R1 - Negated Input Value

NOT R1, R1
ADD R1, R1, #1
RET




DONE
    HALT



TWO_POP
;POPs two top values of stack into R3 and R4
;in addition, checks for underflow in stack
;Inputs: no inputs needed
;Outputs: R4 and R3 contain top characters in stack

ST R7, JUMP_STORE		;load R7 into memory to accommodate for other jumps in subroutine

AND R3, R3, #0			;initialize R3 and R4
AND R4, R4, #0

JSR POP					;POP character into R4 and check for underflow
ADD R4, R4, R0
BRz INVALID

JSR POP					;POP character into R3 and check for underflow
ADD R3, R3, R0
BRz INVALID

LD R7, JUMP_STORE		;Load jump address back into R7
RET


JUMP_STORE	.FILL x0000



ONE_VAL
;Description: Checks if there is one value left in stack after equal sign is detected and stores answer into R3 if this is the case, otherwsise sent to INVALID
;Inputs: No inputs necessary
;Outputs: R3 - Popped Character 

			JSR POP				;pop character from stack
			AND R3, R3, #0
			ADD R3, R0, R3

			JSR POP				;pop next character from stack
			ADD R5, R5, #0		;check if the character is zero
			BRnz INVALID		;if not zero, move to section that prints "invalid expression"

			ADD R3, R3, #0		
			BRnzp PRINT_HEX


INVALID
;Description: prints "invalid expression" to monitor
;Inputs: No inputs necessary
;Outputs: R0 has "Invalid Expression"

LEA R0, INVALID_STRING        ;Contains starting address of strin
PUTS                          ;Outputs to monitor
ADD R0, R0, #0
BRnzp DONE

INVALID_STRING	.STRINGZ "Invalid Expression"



; PRINT_HEX
;   Description: prints out the value in R5 to the console
;   Inputs: R5 - value in register to be printed out
;   Outputs: Value printed to the console

PRINT_HEX

;Registers
		;R0 -- Used to output to moniter
		;R1 -- shift counter
		;R2 -- Bitwise adder
		;R4 -- overall counter
		;R3 -- storage for hex value
				
				ST R1, TEMP_ST1
				ST R2, TEMP_ST2
				ST R4, TEMP_ST3

				AND R0, R0, #0			;initialize registers
				AND R1, R1, #0
				AND R2, R2, #0
				AND R4, R4, #0

				AND R5, R5, #0			;store value in R3 into R5 to fit MP criteria
				ADD R5, R3, R5
	
				ADD R4, R4, #4			;set counter

	BACK		ADD R1, R1, #4			;Set shift counter
								
	LOOP		ADD R2, R2, R2			;Left shift R2
				ADD R3, R3, x0000		;Check if R3 is positive/negative
				BRzp	ZERO
				ADD R2, R2, #1			
			
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
				BRz STOP				;end if R3 is zero

				AND R0, R0, x0000
				BRnzp BACK

STOP			LD R1, TEMP_ST1
				LD R2, TEMP_ST2
				LD R4, TEMP_ST3
				BRnzp DONE				; Go to HALT 

;histogram printing storage
ASCII_LET	.FILL x0037
ASCII_NUM	.FILL x0030

;Temporary Storage
TEMP_ST1	.FILL x0000
TEMP_ST2	.FILL x0000
TEMP_ST3	.FILL x0000


; PLUS
;   Description: adds two numbers (R0 = R3 + R4) then pushes into stack
;   Inputs: R3 - addend
;	        R4 - addend
;   Outputs: R0 - sum
PLUS	

ADD R0, R3, R4			;add values
JSR PUSH                ;push to stack
ADD R0, R0, #0			;
LD R7, MAIN_ADDR        ;Return to MAIN
RET
			

	
; MIN
;   Description: subtracts two numbers (R0 = R3 - R4) then pushes into stack
;   Inputs: R3 - minuend
;	        R4 - subtrahend
;   Outputs: R0 - difference
MIN	

NOT R4, R4				;Make R4's two's complement
ADD R4, R4, #1
ADD R0, R3, R4			;R3 - R4 -> R0
JSR PUSH				;push to stack

LD R7, MAIN_ADDR        ;Return to MAIN
RET

	
; MUL
;   Description: multiplies two numbers (R0 = R3 * R4) then pushes into stack
;   Inputs: R3 - factor
;	        R4 - factor
;   Outputs: R0 - product
MUL				
		ADD R4, R4, #-1		;initially reduce R4 by one to compensate
			
LOOP2	ADD R0, R3, R0		;R1 <- R3 + R1
		ADD R4, R4, #-1		;reduce R4 by 1
		BRp LOOP2		;stop adding when R4 is 0
		
JSR PUSH			;Push to stack
LD R7, MAIN_ADDR    ;Return to MAIN
RET

; DIV
;   Description: divides two numbers (R0 = R3 / R4) then pushes into stack
;   Inputs: R3 - numerator
;	    R4 - denominator
;   Outputs: R0 - quotient
DIV			
		NOT R4, R4			;convert R4 to twos complement
		ADD R4, R4, #1
		AND R0, R0, #0		;initialize R0

SUBTR	ADD R0, R0, #1		;keep adding to R0
		ADD R3, R4, R3		;R4 - R3
		BRp SUBTR 

		JSR PUSH			;push to stack
		LD R7, MAIN_ADDR    ;Return to MAIN
		RET
	
; PUSH
;   Description: Pushes a charcter unto the stack
;   Inputs: R0 - character to push unto the stack
;   Outputs: R5 - 0 (success) or 1 (failure/overflow)
;   Registers: R3 - stores STACK_END
;	       R4 - stores STACK_TOP
PUSH	
	ST R3, PUSH_SaveR3	;save R3
	ST R4, PUSH_SaveR4	;save R4
	AND R5, R5, #0		;
	LD R3, STACK_END	;Load stack end
	LD R4, STACk_TOP	;Load stack pointer
	ADD R3, R3, #-1		;
	NOT R3, R3		    ;Negate R3
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz OVERFLOW		;stack is full
	STR R0, R4, #0		;no overflow, store value in the stack
	ADD R4, R4, #-1		;move top of the stack
	ST R4, STACK_TOP	;store top of stack pointer
	BRnzp DONE_PUSH		;
OVERFLOW
	ADD R5, R5, #1		;
DONE_PUSH
	LD R3, PUSH_SaveR3	;Restore registers
	LD R4, PUSH_SaveR4	;
	RET


PUSH_SaveR3	.BLKW #1	;
PUSH_SaveR4	.BLKW #1	;


; POP
;   Description: Pops a character off the stack
;   Inputs: 
;   Outputs: R5 - 0 (success) or 1 (failure/underflow)
;	     R0 - character popped off the stack
;   Registers: R3 - stores STACK_END
;	       R4 - stores STACK_TOP

POP	
	ST R3, POP_SaveR3	;save R3
	ST R4, POP_SaveR4	;save R3
	AND R5, R5, #0		;clear R5
	LD R3, STACK_START	;Load stack start
	LD R4, STACK_TOP	;load stack pointer
	NOT R3, R3		    ;Negate R3
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;Check if there is underflow
	BRz UNDERFLOW		;
	ADD R4, R4, #1		;Pop character, if no error detected
	LDR R0, R4, #0		;
	ST R4, STACK_TOP	;Update stack pointer
	BRnzp DONE_POP		;
UNDERFLOW
	ADD R5, R5, #1		;
DONE_POP
	LD R3, POP_SaveR3	;Restore registers
	LD R4, POP_SaveR4	;
	RET


POP_SaveR3	.BLKW #1	;
POP_SaveR4	.BLKW #1	;
STACK_END	.FILL x3FF0	;
STACK_START	.FILL x4000	;
STACK_TOP	.FILL x4000	;


.END
