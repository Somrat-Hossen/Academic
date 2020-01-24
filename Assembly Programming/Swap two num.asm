  org 0100h

.data
      
tmp db ?

.code 

main proc
           
           
     mov al,55
     mov bl,49
     
     xchg al,bl
     
     
      mov ah,02h
      mov dl,al
      int 21h
       
       
      MOV AH,2h                    ; return carriage 
      MOV DL, 0DH
      INT 21H

      MOV DL, 0AH                  ; line feed
      INT 21H
    
      
      mov ah,02h
      mov dl,bl
      int 21h
         
     
     
     main endp  

  end main  
ret