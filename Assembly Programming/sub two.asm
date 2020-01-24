 org 0100h
 
 
 .data
 
 A db ?
 B db ?
 res db ?
 
 
.code
 main proc
    
    
    mov ah,1h  ;first input
    int 21h
    sub al,48
    mov A,al   
    
    
    mov ah,2h  ;newline 
    mov dl,0ah
    int 21h
    mov dl,0dh   ;carrage return 
    int 21h
           
           
   
    mov ah,1h  ;second input
    int 21h
    sub al,48
    mov B,al
             
             
    mov ah,2h    ;newline 
    mov dl,0ah
    int 21h
    mov dl,0dh
    int 21h         
    
    
    mov al,A  ;Taking into reg
    mov bl,B
    
    sub al,bl   ;operation
    mov dl,  al  ;for output print
    mov res,dl   ;store in res 
   
   
   mov ah,02h    ;print the res
   int 21h
   
   
   
   
   mov ah,4ch       ;return 0
   int 21h
   main endp
 
 
 end main 
          
   