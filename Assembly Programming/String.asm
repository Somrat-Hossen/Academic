 ORG 0100h
MAIN PROC
    MOV AH,1
    INT 21h
    MOV BL, AL
    
    MOV CL,5  ; use for counter 
    
    CMP BL,97 ; check uppercase 
    JL TOLOWER
    
    SUB BL,31 ; Convert lower case to upper case
    JMP OUTPUT
    
    
    TOLOWER: ADD BL,33 ; Convert upper case to lower case
    
    OUTPUT:
     CMP AL,65
     JE AR:
     CMP AL, 97
     JE AR:
     SUB BL,26
        
    AR: MOV AH,2
       MOV DL,0DH
       INT 21h
       MOV DL,0AH
       INT 21h 
       
    LOOP1:       
       MOV DL,BL
       INT 21h
       
       INC BL   ; Data increase 1
       DEC CL   ; decrease counter 1
       JNZ LOOP1  
       
    SUB BL,6
    MOV CL,5     ; use for counter 
    
    
    ; Reverse Order
     CMP BL,65
     JE AB:
     CMP BL, 97
     JE AB:
     CMP BL,64
     JE AB1:
     CMP BL, 96
     JE AB1:
     JMP LEVEL
        
    AB: 
       ADD BL,25
       JMP LEVEL  
       
    AB1: 
       ADD BL,25
    
    LEVEL: 
       MOV AH,2
       MOV DL,0DH
       INT 21h
       MOV DL,0AH
       INT 21h 
       
    LOOP2:       
       MOV DL,BL
       INT 21h
       
       DEC BL   ; Data increase 1
       DEC CL   ; decrease counter 1
       JNZ LOOP2 
    
       
       MAIN ENDP
END MAIN
RET