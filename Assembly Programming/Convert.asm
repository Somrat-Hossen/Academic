
ORG 0100H
.DATA 

 C DW ?
 . CODE

 MAIN PROC 
    
    MOV AX,1000
    SUB AX,32
              
     MOV BX,5
     MUL BX
     MOV BX,9
     DIV BX
     ADD AX,1
     MOV C, AX  
     
     MAIN ENDP
     END MAIN
     RET
    