%macro swap 2
  mov rax, %1
  mov r12, %2
  mov %2, rax
  mov %1, r12
%endmacro

global _partition

; rdi: arr
; rsi: len
; rdx: pivot

_partition:

  ; rsi = len
  ; r8 = 0 : l
  ; r9 = 0 : e
  push rsi
  push rdi
  xor r8, r8
  mov r9, r8
  ; r10 = p
  dec rsi
  mov r10, rdx
  loop:
    ; while (e<r)
    cmp r9, rsi
    jg break

    cmp r10, [rdi+r9*8]
    je ince ; p == arr[e]
    jg swaple ; p > arr[e]
      ; else: p < arr[e]
    swap [rdi+r9*8], [rdi+rsi*8]
    dec rsi
    jmp loop
    ince:
      inc r9
      jmp loop
    swaple:
      swap [rdi+r8*8], [rdi+r9*8]
      inc r9
      inc r8
      jmp loop
  break:
    mov rax, rsi
    pop rdi
    pop rsi
    ret
