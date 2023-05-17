;
; EPITECH PROJECT, 2022
; assembleur
; File description:
; strtok.asm
;

; section .text
; global strtok
; strtok ;bStr is the string to be parsed, pStr is the token string
;     mov rdi, bStr ;move string to rdi
;     mov edi, OFFSET bRet ;move destination to edi
;     lea esi, bRet ;move destination to esi
;     xor ecx,ecx ;clear ecx
;     Back: ;clean-up loop
;         mov BYTE PTR [esi], 0 ;clear bRet[]
;         inc esi ;increment esi
;         inc ecx ;increment ecx
;         cmp ecx,80 ;size of bRet, in this case 80 bytes
;         jle Back ;this clean-up loop can definitely be optimized

;         xor eax,eax ;clear eax
;         xor ecx,ecx ;clear ecx

;     sloop1: ;string loop
;     mov al, [rdi] ;move string to al
;     cmp al,0 ;
;     je sloop1e ;jump if end of input string
;     cmp al,13 ;
;     je sloop1n ;jump if end of line - make eax==0 to know end of line for looping
;     cmp al,10 ;
;     je sloop1n ;jump just to be safe if only 0A is present so first set ret value to 0
;     jmp sloop1a ;jump to token loop

;     sloop1n: ;end of line
;     xor eax,eax ;this is untested, so to put StrTok() into a loop
;     jmp exitloop ;return with eax==0 when end of the line

;     sloop1a: ;token loop
;     ;xor ecx,ecx ;to strip everything out except the strings, makes one long concatenation
;     mov ebx, pStr ;move token to ebx

;     sloop1b: ;token loop
;     mov cl,[ebx] ;move token to cl
;     cmp al,cl ;compare string to token
;     je sloop1c ;found a matching token, so we need to keep moving in our string
;     cmp cl,0 ;check if end of token string
;     je sloop1d ;you have reached the end of the token string and found no match, add to bRet[]
;     inc ebx ;increment ebx
;     jmp sloop1b ;found no match or end, keep looking for a match until found or end

;     sloop1c: ;found a match
;     cmp ch,1 ;set 'flag' here to indicate starting position in string
;     je sloop1e ;if found the first token, then we are done
;     inc rdi ;increment rdi
;     jmp sloop1 ;keep looking for the first token

;     sloop1d: ;only call this if no matches above
;     mov ch,1 ;simple flag for checking if found the first token
;     inc rdi ;added just now
;     mov BYTE PTR [edi], al ;move string to bRet[]
;     inc edi ;increment edi
;     jmp sloop1 ;keep looking for the first token

;     sloop1e: ;end of string
;     mov BYTE PTR [edi], 0 ;null-terminate the string
;     mov eax,1 ;move success to eax
;     exitloop: ;exit loop
;     ret ;return

;     StrTok endp ;end of function
;     end ;end of file