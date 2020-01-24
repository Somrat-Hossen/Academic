   org 0100h
   
   .data  
   str1 db 'Positive','$'
   str2 db 'Nagative','$'
   
   .code
   
   main proc
             
    mov ax,@data
    mov ds,ax         
             
    mov ah,01h
    int 21h   
    
    mov ah,02h
    mov dl,0ah
    int 21h
    
    mov dl,0dh
    int 21h
    
    
    cmp al,0
    
    jl Negative 
    
    lea dx, str1
    mov ah,09h
    int 21h  
    
    mov ah,4ch
    int 21h
    
    Negative:
    
    lea dx, str2
    mov ah,09h
    int 21h
    
    
    
  main endp
   
   end main
   
 ret  