org 0100h

.data

num1 db ?
num2 db ?
sum db ?

.code 

main proc
    
    
    mov ah,1h
    int 21h  
    sub al,48
    
    mov num1,al
    
    mov ah,1h
    int 21h 
    
    sub al,48
    
    mov num2,al  
    
    mov al,num1
    mov bl,num2
    
    
    add al,bl  
    mov sum,al
    
    mov dl,al
    
    
     mov ah,02h 
     int 21h
      
     
     
     
     
     mov ah,4ch
     int 21h
     main endp  

end main 