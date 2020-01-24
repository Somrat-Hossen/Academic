org 0100h

.data

num1 db ?
num2 db ?
res db ?

.code 

main proc
    
    
    mov ah,1h
    int 21h  
    sub al,48
    mov num1,al 
    
    mov ah,02h
    mov dl,0ah
    int 21h
    mov dl,0dh
    int 21h
    
    mov ah,1h
    int 21h 
    sub al,48
    mov num2,al  
    
    mov ah,02h
    mov dl,0ah
    int 21h
    mov dl,0dh
    int 21h
    
    mov al,num1
    mov bl,num2
    
    
    mul bl  
    mov res,al
    
    mov dl,al
    
    
     mov ah,02h 
     int 21h
      
     
     
     
     
     mov ah,4ch
     int 21h
     main endp  

end main 