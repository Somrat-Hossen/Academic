
include 'emu8086.inc' 

  
org 0100h

.data
      
n db ?

.code 

main proc  
    
     
     
      mov ah,1h
      int 21h 
      sub al,48
      mov n,al
      
      mov ah,2h
      mov dl,'*' 
      
      printn;newline
     
     
     mov bh,1
     
     loop1: 
     
       cmp bh,n   
     
       jg exit_loop1 ;if first loop is equal to n go to out of the loop area
        mov bl,1 ;else go to the loop2 and perform print *
     loop2:  
     
     cmp bl,n
     jg exit_loop2  ;if second loop is greater than n the we need to inc cnt for loop 1 .this is done in exit_loop2
     
     int 21h 
     inc bl
     jmp loop2
     
     
     
     
     exit_loop2: 
     inc bh
     printn
     jmp loop1
     
     
        
     exit_loop1: 

     
    
     
     main endp  

  end main  
ret