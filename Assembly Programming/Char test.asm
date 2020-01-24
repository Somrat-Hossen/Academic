ORG 0100h
MAIN PROC
    MOV AH, 1
    INT 21h 
    MOV BL, AL
        
    CMP BL, 97 
    JL UPR
    
    SUB BL, 32
    JMP SKP
    
    UPR: ADD BL, 32
    
    SKP:MOV AH, 2
        MOV DL, 0Ah
        INT 21h
        MOV DL, 0Dh
        INT 21h
        MOV DL, BL
        INT 21h
    
    MAIN ENDP
END MAIN 
RET