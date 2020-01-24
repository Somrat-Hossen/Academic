org 0100h

.data
n db ? 
str db 'Give the input: ','$' 
str1 db  'Given output : ','$'


.code

  main proc
    
   mov ax,@data
   mov ds,ax
   
   
   call input 
   
   mov ah,2h
   mov dl,0ah
   int 21h
   
   mov dl,0dh
   int 21h
    
    lea dx,str1
        
        mov ah,9h
        int 21h
        
        
        mov ah,2h
        int 21h
        
        
       main endp 
  ret
    
    
   
    
  input proc
        lea dx,str
        
        mov ah,9h
        int 21h
        
        
        mov ah,1h
        int 21h
        sub al,48
        
        mov n,al
        
        ret
        input endp
    
    
    
  end main