  include 'emu8086.inc'
 
 org 0100h 
 
 
 .data
 n dw 5
 i db 2 
 cnt db 0
 
 .code  
 
     
     main proc 
        
        mov ax,@data
        mov ds,ax
        
    
    
   ; mov ah,1h
    ;int 21h
    
    xor cx,cx
    
   ; mov n,al
    
    mov cx,n
    
    sub cx,2
    
    ;mov al,n
    mov bx,2
    
    xor ax,ax
     mov ax,n
     
    for:
      
     
     div bx
     
     cmp ah,0
     je Nonprime
     
     inc bx
     loop for
     
     printn "prime"
     ret
     
     
     
     Nonprime:
     
     printn "Nonprime"
     ret
     
   
    
    
       
 
 
  main endp
  
  end main 
  
  ret