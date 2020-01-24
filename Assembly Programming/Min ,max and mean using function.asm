org 0100h

.data
n db ? 
str db 'Largest is : ','$' 
str1 db  'Smallest : ','$' 
str2 db  'Mean : ','$'  
min db 100
max db 0
avg db ?

arr db 10 dup(?)



.code

  main proc
    
   mov ax,@data
   mov ds,ax 
   
   lea si,arr
   lea di,arr
   
    mov ah,1h
    int 21h
    sub al,48
    mov n,al
    
    
    mov cl,n
    
    
    for:
    
    mov ah,1h
    int 21h
    sub al,48 
    
    mov [si],al
    
    inc si
    loop for
   

   
   
   call Minumum  
   call Mamimum
   
   call Mean
   
   
        
        
  main endp      
  ret
    
    
   
    
  Minumum proc
        lea si,arr
        
             mov cl,n  
             
        Start: 
        mov al,min
        cmp [si],al
        jl swap
        
        inc si
        loop Start
        
        ret 
        
        swap:
        
        mov bl,[si]
        mov min,bl
        inc si
        loop Start
            
    ret
    Minumum endp 
  
  
     Mamimum proc
        lea si,arr
        
         mov cl,n  
             
        Start1: 
        mov al,max
        cmp [si],al
        jg swap1
        
        inc si
        loop Start1
        
        ret 
        
        swap1:
        
        mov bl,[si]
        mov max,bl
        inc si
        loop Start1
        
    ret
    Mamimum endp
                 
                 
    Mean proc
        
        xor al,al  
        xor ax,ax
        
        mov al,min
        add al,max
        
        mov bl,2
        
        div bl
        
        mov avg,al
        
    ret 
    Mean endp              
    
    
    
  end main