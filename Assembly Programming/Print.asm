ORG 0100H
.DATA
A DB ?  
B DB ?

.CODE
MAIN PROC
           
    MOV AX,@DATA
    MOV DS,AX 
    
    MOV AH,1
    INT 21H
    MOV A,AL
   
  ; ADD A,48
    
    MOV AH,2
    MOV DL,A
    INT 21H
    
    MOV AH,4CH
    INT 21H
     
    
  
MAIN ENDP
END MAIN
RET
    
