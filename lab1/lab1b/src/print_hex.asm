; print_hex.asm
; Prints out a hexadecimal number store in register R3 to the console. The hexadecimal number has to be converted to an appropriate ASCII character in order for the number to be displayed correctly.

; Inputs:
;   R3 - hexadecimal number

; Outputs:
;   [0 - F]{4} printed to console

.ORIG x3000

MAIN

; INSERT CODE HERE!

DONE
    HALT

; Data
ASCII_NUM .FILL x0030
ASCII_LET .FILL x0041

.END
