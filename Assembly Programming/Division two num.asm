org 0100h

.data

num1 db ?
num2 db ?
res db ?
rem db ?  
str1 db 'Enter the first num:$' 
str2 db 'Enter the second num:$'
str3 db 'Result is :$'

.code 

main proc
    
         
     lea dx,str1  ; print messaage 
    mov ah,09h
    int 21h     
         
    mov ah,1h ;take input
    int 21h  
    sub al,48
    mov num1,al 
    
    mov ah,02h ;newline
    mov dl,0ah
    int 21h
    mov dl,0dh
    int 21h 
    
    lea dx,str2;print messaage 
    mov ah,09h
    int 21h   
    
    mov ah,1h   ; take input
    int 21h 
    sub al,48
    mov num2,al  
    
    mov ah,02h   ;newline
    mov dl,0ah
    int 21h
    mov dl,0dh
    int 21h
    
    
    lea dx,str3;print messaage 
    mov ah,09h
    int 21h
    
    xor ax, ax   
    
    mov al,num1
    mov bl,num2
    
    
    div bl  
    mov res,al 
    mov rem,ah
    
    
    mov dl,al
    
    
     mov ah,02h 
     int 21h
      
     
     
     
     
     mov ah,4ch
     int 21h
     main endp  

end main 