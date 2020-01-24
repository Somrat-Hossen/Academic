 
include 'emu8086.inc' 

  
org 0100h

.data
      
n db ?
str db 'The ASCII char are :','$'

.code 

main proc  
    
        mov ax,@data
        mov ds,ax
        
        
        
        lea dx,str
        mov ah,9h
        int 21
        
        
        
        mov cx,256 
        
        mov ah,2h
        mov dl,0
        
 
        start:
                
         int 21h
         inc dl
         loop start
     
      

     
    
     
     main endp  

  end main  
ret