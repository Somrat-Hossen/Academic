 
include 'emu8086.inc' 

  
org 0100h

.data
      
arr db 1,2,3,4,5,6,7,8,9

.code 

main proc  
    
        mov ax,@data
        mov ds,ax
        lea si,arr
        
        mov cx,9
 
        for:
          
         mov dl,[si] 
         add dl,48 
         
         mov ah,2h     
         int 21h
         
         add si,1
         loop for
     
      

     
    
     
     main endp  

  end main  
ret