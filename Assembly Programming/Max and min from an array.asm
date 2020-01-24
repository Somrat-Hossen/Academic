  
include 'emu8086.inc' 

  
org 0100h

.data
      
arr db 4,8,1,5,2
min db 10
max db 0 
mean db ?
 

.code 

main proc  
    
        mov ax,@data
        mov ds,ax
        mov si, offset arr   
        
        
        mov cx,5
        
 
        Maximum: 
        
         mov bl,max
         
         cmp [si],bl
         jg Swap 
         inc si
         loop Maximum 
          
         mov si,offset arr  
         mov cx,5
         jmp Minimum
         
         
         
         
         Swap:
         mov bl,[si]
         mov max,bl 
         inc si 
         loop Maximum   
         
         
         Minimum:
          mov bl,min
         
         cmp [si],bl
         jl Swap1 
         inc si
         loop Minimum
        
         jmp Average 
         
         
         
         Swap1:
         mov bl,[si]
         mov min,bl 
         inc si
         loop Minimum   
         
         
         
         Average: 
         
         xor ax,ax
         mov al,max 
         mov bl,min
         
         add al,bl 
         
         mov bl,2 
         
         div bl
         mov mean, al
         
        
    
     
     main endp  

  end main  
ret