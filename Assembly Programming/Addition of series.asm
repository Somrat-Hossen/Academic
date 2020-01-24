
include 'emu8086.inc' 

  
org 0100h

.data
      
n db ?
sum dw 0  
i dw 1

.code 

main proc  
    
     
     
      mov ah,1h
      int 21h 
      sub al,48
      mov n,al
      
      
      
      mov cl,n
      
      mov bx,1
     
     
     
     
     start: 
     xor ax,ax
     
      mov ax,i
     
     mul ax
     
     add sum,ax
     inc i
     loop start;
        
     printn 
     
     
     output:
     printn "The sum is: " 
     
    
         
     mov dx,sum 
     sub dx,48

     
     mov ah,02h
     int 21h 
     
     main endp  

  end main  
ret