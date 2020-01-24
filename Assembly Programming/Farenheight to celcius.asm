org 0100h

.data

celcius dw ?
farenheight dw 1000

.code 

main proc
    
         
     mov ax,farenheight
     
     sub ax,32
     
     mov bx,5
     
     mul bx  ;ax=ax*bx
     
     mov bx,9
     
     div bx  ;ax=ax/bx
     
     add ax,1
   
    
   mov celcius,ax
    
    
     mov ah,02h 
     int 21h
      
     
     
     
     
     mov ah,4ch
     int 21h
     main endp  

end main 