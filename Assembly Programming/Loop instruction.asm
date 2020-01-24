 INCLUDE 'EMU8086.INC'
  
  org 0100h

.data
      
tmp db ?

.code 

main proc  
    
     
     mov cx,5   
     mov ax,0
     
     
     
     
     start:
     cmp ax,cx
     je Last
           
     printn "Hello World" 
     inc ax
     jne start;jmp is not equal
        
    
         
     last:
     
     main endp  

  end main  
ret