; parent_stack.asm
; Determine whether a string containing only parentheses and a newline
; character is balanced or not

; Inputs:
;   Console - string with parantheses and newline character

; Outputs:
;   Console - input string echoed back
;   Register R6 - 1 (balanced) or -1 (unbalanced)

.ORIG x3000

MAIN

; INSERT CODE HERE!
			AND R1, R1, #0 ;Initialzation
			AND R2, R2, #0
			AND R3, R3, #0
			AND R4, R4, #0
			AND R5, R5, #0
			AND R6, R6, #0

AGAIN		LD R1, SPACE
			LD R2, NEG_OPEN
			LD R3, NEG_CLOSE
			NOT R1, R1
			ADD R1, R1, #1
		

			GETC
			ADD R1, R0, R1
			BRz AGAIN
			ADD R2, R0, R2
			BRz CHECK1
			ADD R3, R0, R3
			BRz CHECK2
			JSR IS_BALANCED2
			ADD R4, R4, #0
			BRzp #1
			ADD R6, R6, #-2
			BRnzp DONE

CHECK1      JSR PUSH
			ADD R5, R5, #0
			BRp FAIL
			BRnz PRINT

CHECK2	    JSR IS_BALANCED
			ADD R5, R5, #0
			BRp FAIL
			ADD R6, R6, #0
			BRz FAIL			

PRINT		OUT
			AND R1, R1, #0
			AND R2, R2, #0
			AND R3, R3, #0
			AND R4, R4, #0
            BRnzp AGAIN

FAIL        ADD R6, R6, #-1			

ERROR		OUT
DONE		HALT_MAIN
			
			HALT
		
; Data
CHECK_BASE  .FILL x-3FFF
JUMP        .FILL x0000
SPACE	    .FILL x0020
NEW_LINE    .FILL x000A
CHAR_RETURN .FILL x000D

; IS_BALANCED
;   Description: checks if a string is balanced or not
;   Inputs: R0 - input character to push/pop
;   Outputs: R6 - integer indicating balanceness

	
; INSERT CODE HERE!

IS_BALANCED 
				
				ST R7, JUMP
				JSR POP
				ADD R5, R5, #0
				BRp NON_MATCH
				NOT R6, R6
				ADD R6, R6, #1
				ADD R6, R0, R6
				BRnz NON_MATCH
				BRp DONE2



IS_BALANCED2    ST R7, JUMP
				LD R4, CHECK_BASE
				LD R3, STACK_TOP
				ADD R4, R4, #-1
				ADD R4, R3, R4
				BRnp NON_MATCH2
				ADD R6, R6, #0
				BRnzp #3
NON_MATCH		AND R6, R6, #0
				
	

NON_MATCH2		ADD R6, R6, #0
				
DONE2			LD R7, JUMP			
				RET
				
			

; Data
NEG_OPEN .FILL xFFD8
NEG_CLOSE .FILL xFFD7

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
	LD R3, STACK_END	;
	LD R4, STACk_TOP	;
	ADD R3, R3, #-1		;
	NOT R3, R3		    ;
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
	LD R3, PUSH_SaveR3	;
	LD R4, PUSH_SaveR4	;
	RET


PUSH_SaveR3	.BLKW #1	;
PUSH_SaveR4	.BLKW #1	;


; POP
;   Description: Pops a character off the stack
;   Inputs: 
;   Outputs: R5 - 0 (success) or 1 (failure/underflow)
;	     R6 - character popped off the stack
;   Registers: R3 - stores STACK_END
;	       R4 - stores STACK_TOP
POP	
	ST R3, POP_SaveR3	;save R3
	ST R4, POP_SaveR4	;save R3
	AND R5, R5, #0		;clear R5
	LD R3, STACK_START	;
	LD R4, STACK_TOP	;
	NOT R3, R3		    ;
	ADD R3, R3, #1		;
	ADD R3, R3, R4		;
	BRz UNDERFLOW		;
	ADD R4, R4, #1		;
	LDR R6, R4, #0		;
	ST R4, STACK_TOP	;
	BRnzp DONE_POP		;
UNDERFLOW
	ADD R5, R5, #1		;
DONE_POP
	LD R3, POP_SaveR3	;
	LD R4, POP_SaveR4	;
	RET

POP_SaveR3	.BLKW #1	;
POP_SaveR4	.BLKW #1	;
STACK_END	.FILL x3FF0	;
STACK_START	.FILL x4000	;
STACK_TOP	.FILL x4000	;

.END
