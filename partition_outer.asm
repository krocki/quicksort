global _partition_all
extern _partition

; rdi: arr
; rsi: len
_partition_all:

  cmp rsi, 1
  jle skip

  push rdx

  mov rdx, [rdi]
  call _partition
  push rsi
  mov rsi, rax
  push rax
  call _partition_all
  pop rax
  pop rsi

  push rsi
  sub rsi, rax
  dec rsi
  push rdi
  lea rdi, [8+rdi+rax*8]
  mov rdx, [rdi]
  call _partition_all
  pop rdi
  pop rsi
  pop rdx

  skip:
  ret
