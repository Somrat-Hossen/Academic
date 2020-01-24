 
include 'emu8086.inc' 

  
org 0100h

.data
      
arr db 10 dup(?) 
sum db 0

.code 

main proc  
    
        mov ax,@data
        mov ds,ax
        lea si,arr
        
        mov cx,5
 
        for:
         
         mov ah,01h
         int 21h
         
         mov [si],al
         inc si
         loop for 
         
         printn
         
         mov cx,5
         lea si,arr 
         
         
         
         
         output:
         
         mov dl,[si] 
         xor al,al
         xor bl,bl
         
         mov al,dl 
         
         mul al
         
         sub al,48 
         add sum,al 
          
        
         
         mov ah,2h
         int 21h 
         printn
         inc si 
         
         loop output
      

         printn "Summation is :"
         
         mov ah,2h
         mov dl,sum
         int 21h
    
     
     main endp  

  end main  
ret