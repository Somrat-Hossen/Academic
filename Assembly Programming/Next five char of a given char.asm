 org 0100h
 
 .data
 char db ?
 
 .code  
 
     
     main proc
        
        mov ax,@data
        mov ds,ax
        
        mov cx,5
        
        
        mov ah,1h
        int 21h
        
        
        
        cmp al,97
        jge Toupper 
        cmp al, 97
        jl Tolower
        ret
        
        
        
        
        
        
        Tolower:
        
          add al,32
        
          inc al
         
         
         for1: 
         
         
            cmp al,123 
            jge Limit:
            mov dl,al
            
            mov ah,2h
            int 21h
            
            inc al 
            
            
           loop for1 
           ret
           
           Limit:
           
            mov al,97 
            jmp for1  
           
        ret
        
        
        
        
        Toupper: 
         sub al,32
        
          inc al
         
         
         for:
           
            cmp al,91
            jge Limit1
            mov dl,al
            
            mov ah,2h
            int 21h
            
            inc al
            
           loop for
           ret
           
           
           limit1:
           mov al,65
           loop for
         
 
 
  main endp
  
  end main 
  
  ret