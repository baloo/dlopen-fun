# Dopen fun

Read code, what should `make; ./main` print? Why?





## Why
```
$ readelf -d hello.la 

Dynamic section at offset 0x2dd8 contains 27 entries:
  Tag        Type                         Name/Value
[...]
 0x0000000000000019 (INIT_ARRAY)         0x3dc0
 0x000000000000001b (INIT_ARRAYSZ)       16 (bytes)
[...]
```

```
$ gdb hello.la
(gdb) x/2x 0x3dc0
0x3dc0:	0x00001160	0x00000000
(gdb) x/2x 0x3dc8
0x3dc8:	0x000011bf	0x00000000
(gdb) disas 0x1160
Dump of assembler code for function frame_dummy:
   0x0000000000001160 <+0>:	push   %rbp
   0x0000000000001161 <+1>:	mov    %rsp,%rbp
   0x0000000000001164 <+4>:	pop    %rbp
   0x0000000000001165 <+5>:	jmpq   0x10d0 <register_tm_clones>
End of assembler dump.
(gdb) disas 0x11bf
Dump of assembler code for function _GLOBAL__sub_I_hello.cc:
   0x00000000000011bf <+0>:	push   %rbp
   0x00000000000011c0 <+1>:	mov    %rsp,%rbp
   0x00000000000011c3 <+4>:	mov    $0xffff,%esi
   0x00000000000011c8 <+9>:	mov    $0x1,%edi
   0x00000000000011cd <+14>:	callq  0x116a <_Z41__static_initialization_and_destruction_0ii>
   0x00000000000011d2 <+19>:	pop    %rbp
   0x00000000000011d3 <+20>:	retq   
End of assembler dump.
(gdb) disas _Z41__static_initialization_and_destruction_0ii
Dump of assembler code for function _Z41__static_initialization_and_destruction_0ii:
   0x000000000000116a <+0>:	push   %rbp
   0x000000000000116b <+1>:	mov    %rsp,%rbp
   0x000000000000116e <+4>:	sub    $0x10,%rsp
   0x0000000000001172 <+8>:	mov    %edi,-0x4(%rbp)
   0x0000000000001175 <+11>:	mov    %esi,-0x8(%rbp)
   0x0000000000001178 <+14>:	cmpl   $0x1,-0x4(%rbp)
   0x000000000000117c <+18>:	jne    0x11bc <_Z41__static_initialization_and_destruction_0ii+82>
   0x000000000000117e <+20>:	cmpl   $0xffff,-0x8(%rbp)
   0x0000000000001185 <+27>:	jne    0x11bc <_Z41__static_initialization_and_destruction_0ii+82>
   0x0000000000001187 <+29>:	lea    0x2ebb(%rip),%rdi        # 0x4049 <_ZStL8__ioinit>
   0x000000000000118e <+36>:	callq  0x1070 <_ZNSt8ios_base4InitC1Ev@plt>
   0x0000000000001193 <+41>:	lea    0x2ea6(%rip),%rdx        # 0x4040
   0x000000000000119a <+48>:	lea    0x2ea8(%rip),%rsi        # 0x4049 <_ZStL8__ioinit>
   0x00000000000011a1 <+55>:	mov    0x2e50(%rip),%rax        # 0x3ff8
   0x00000000000011a8 <+62>:	mov    %rax,%rdi
   0x00000000000011ab <+65>:	callq  0x1040 <__cxa_atexit@plt>
   0x00000000000011b0 <+70>:	lea    0x2e93(%rip),%rdi        # 0x404a <_ZL5hello>
   0x00000000000011b7 <+77>:	callq  0x1030 <_ZN10HelloWorldC1Ev@plt>
   0x00000000000011bc <+82>:	nop
   0x00000000000011bd <+83>:	leaveq 
   0x00000000000011be <+84>:	retq   
End of assembler dump.
```

Reference:

http://people.redhat.com/drepper/dsohowto.pdf

https://docs.oracle.com/cd/E23824_01/html/819-0690/chapter3-8.html
