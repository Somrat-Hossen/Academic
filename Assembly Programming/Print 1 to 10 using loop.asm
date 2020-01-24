
include 'emu8086.inc' 

  
org 0100h

.data
      
n db ?
sum db 0

.code 

main proc  
    
     
     
      mov ah,1h
      int 21h 
      sub al,48
      mov n,al
      
      
      
      mov bl,1
     
     
     
     start:
     
     cmp bl,n
     
     jg output
     
     add sum,bl
     inc bl
     jmp start;
        
     printn 
     
     
     output:
     printn "The sum is: "
         
     mov dl,sum 

     
     mov ah,02h
     int 21h 
     
     main endp  

  end main  
ret