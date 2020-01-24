  org 0100h
 
 
 .data
 
Message db 'Start with Assembly language:','$'
 
 
.code
 main proc
    
    
     
      MOV AX,@DATA ;   ; initialize the data segment
      MOV DS,AX    ;
  
      ; load effective address of the string  
      LEA DX,Message  
  
     ;output the string 
     ;loaded in dx  
     MOV AH,09H 
     INT 21H  
     
             
             
    mov ah,2h    ;newline 
    mov dl,0ah
    int 21h
    mov dl,0dh
    int 21h         
     
   
   
   mov ah,4ch       ;return 0
   int 21h
   main endp
 
 
 end main 
          
   