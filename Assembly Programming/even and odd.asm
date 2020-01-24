org 0100h 



.data

  str db 'DUET am mursalin islam from duet','$' 
    str1 db 'Not found','$'
  first db ?
  snd db ? 
  
  cnt db 0
  
  
  .code
  main proc
    
    
    mov ax,@data
    mov ds,ax
    
    
    
   lea si,str
   
   
   for:
   
    mov al,[si] 
    cmp al,'$'
    je Exit  
    cmp al,32
    je Space
    
    cmp al,97
    jl Second 
    
    inc si
    loop for
    
    Space:
    inc si
    loop for
    
    
    
    Second: 
    
    mov bl,[si]
    mov first,bl 
    mov dl,first
   
    mov ah,02h
    int 21h
                 
    inc si  
    inc cnt
    
    second_case: 
    
    mov al,[si] 
    cmp al,'$'
    je Exit
    
    cmp al,32
    je Space2
    
    cmp al,97
    jl Store 
    
    inc si
    loop second_case
    
    Space2:
    inc si
    loop second_case
    
    
    Store: 
    inc cnt
    mov bl,[si]
    mov snd, bl
    inc si
    loop second_case
    
    
    
    Exit: 
    
    mov al,cnt
    cmp al,0
    je notfound
    cmp al,2
    jge print_second
    
    print_second:
     mov dl,snd
   
    mov ah,02h
    int 21h
    ret
    
    
    notfound:
    
    lea dx,str1
    
    mov ah,9h
    int 21h
    
    mov ah,4ch
    int 21h
    
    
    main endp
  
  end main 