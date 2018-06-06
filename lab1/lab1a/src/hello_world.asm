; hello_world.asm
; Prints out 'Hello <NAME>!' to the console.
; Replace <NAME> with your name to see the program print out your name instead.

; Inputs:
;   None

; Outputs:
;   Hello <NAME>! printed to console

.ORIG x3000

MAIN
    LEA R0, HELLO_WORLD ; Load the address of HELLO_WORLD into R0
    PUTS		; Ouput string to console

DONE
    HALT		; Finish executing

; Data    
HELLO_WORLD .STRINGZ "Hello <NAME>!\n"

.END
