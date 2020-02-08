global self_modify
section .text

self_modify:
self_modify_main:
    imul rdi, (self_modify_1 - self_modify_0)
    mov rcx, self_modify_empty
    add QWORD [rcx+1], rdi; modify self_modify_empty command
self_modify_empty:
    call self_modify_0
self_modify_end:
    sub QWORD [rcx+1], rdi
    ret
self_modify_0:
    mov rax, 0
    ret
self_modify_1:
    mov rax, 1
    ret
self_modify_2:
    mov rax, 2
    ret
self_modify_3:
    mov rax, 3
    ret
self_modify_4:
    mov rax, 4
    ret
self_modify_5:
    mov rax, 5
    ret
self_modify_6:
    mov rax, 6
    ret
self_modify_7:
    mov rax, 7
    ret
self_modify_8:
    mov rax, 8
    ret
self_modify_9:
    mov rax, 9
    ret

self_modify_10:
    mov rax, 10
    ret
self_modify_11:
    mov rax, 11
    ret
self_modify_12:
    mov rax, 12
    ret
self_modify_13:
    mov rax, 13
    ret
self_modify_14:
    mov rax, 14
    ret
self_modify_15:
    mov rax, 15
    ret
self_modify_16:
    mov rax, 16
    ret
self_modify_17:
    mov rax, 17
    ret
self_modify_18:
    mov rax, 18
    ret
self_modify_19:
    mov rax, 19
    ret

self_modify_20:
    mov rax, 20
    ret
self_modify_21:
    mov rax, 21
    ret
self_modify_22:
    mov rax, 22
    ret
self_modify_23:
    mov rax, 23
    ret
self_modify_24:
    mov rax, 24
    ret
self_modify_25:
    mov rax, 25
    ret
self_modify_26:
    mov rax, 26
    ret
self_modify_27:
    mov rax, 27
    ret
self_modify_28:
    mov rax, 28
    ret
self_modify_29:
    mov rax, 29
    ret

self_modify_30:
    mov rax, 30
    ret
self_modify_31:
    mov rax, 31
    ret
self_modify_32:
    mov rax, 32
    ret
self_modify_33:
    mov rax, 33
    ret
self_modify_34:
    mov rax, 34
    ret
self_modify_35:
    mov rax, 35
    ret
self_modify_36:
    mov rax, 36
    ret
self_modify_37:
    mov rax, 37
    ret
self_modify_38:
    mov rax, 38
    ret
self_modify_39:
    mov rax, 39
    ret