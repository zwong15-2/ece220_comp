; print_hex.asm
; Prints out a hexadecimal number store in register R3 to the console. The hexadecimal number has to be converted to an appropriate ASCII character in order for the number to be displayed correctly.

; Inputs:
;   R3 - hexadecimal number

; Outputs:
;   [0 - F]{4} printed to console

.ORIG x3000

MAIN

; INSERT CODE HERE!
				AND R0, R0, #0
				AND R5, R5, #0	
				AND R1, R1, #0
				AND R4, R4, #0
				AND R2, R2, #0

				LD R3, HEX
				
				ADD R2, R2, #4
LOOP2			ADD R2, R2, #0			
				BRnz DONE
	
				ADD R1, R1, #4			
LOOP1			ADD R5, R5, R5			
				ADD R1, R1, #0
				BRnz DIGIT_CHECK
				ADD R3, R3, #0
				BRzp L_SHIFT
				ADD R5, R5, #1

L_SHIFT			ADD R3, R3, R3
				ADD R1, R1, #-1
				BRnzp LOOP1
				
						
DIGIT_CHECK		ADD R4, R5, #0
				ADD R4, R4, #-9
				BRnz NUMBER
				LD R0, ASCII_LET
				ADD R0, R5, R0
				BRnzp #2
NUMBER			LD R0, ASCII_NUM
				ADD R0, R5, R0 
				OUT

				AND R5, R5, #0
				AND R4, R4, #0
				AND R0, R0, #0
				ADD R2, R2, #-1
				BRnzp LOOP2
DONE
   				HALT

; Data
ASCII_NUM .FILL x0030
ASCII_LET .FILL x0041
HEX		  .FILL x0123

.END
