org 0100h

.data
      
tmp db ?

.code 

main proc
           
           
      mov ah,1h
      int 21h 
       mov bl,al  
      
      MOV AH,2h                    ; return carriage 
      MOV DL, 0DH
      INT 21H

      MOV DL, 0AH                  ; line feed
      INT 21H
      
               
     
      
      cmp bl,97
      jge toupper 
      
      add bl,32 
      mov tmp,bl
      
      mov ah,02h
      mov dl,bl
      int 21h
      
      ret
      
      
      
      
      
      
      toupper:
         
         sub bl,32
         mov tmp,bl
         mov ah,02h
         mov dl,bl
         int 21h 
     
     
     
     
     main endp  

  end main  
ret