# Adder

**Category:** Reverse Engineering

**Description:**

> This program adds numbers. Find the flag! adder

**Solution:**

Let's try to run the program.
```
$ ./adder 
Enter three numbers!
1
2
3
nope.
```

This program adds three numbers and print the flag if the sum is equal to some number.

Let's see what the assembly says.
```
$ objdump -d -M intel adder > objdump.txt
```
In the main section: 
```
0000000000400b1e <main>:

  ...

  400b4a:       48 8d 45 f4             lea    rax,[rbp-0xc]
  400b4e:       48 89 c6                mov    rsi,rax
  400b51:       bf 80 20 60 00          mov    edi,0x602080
// Enter number 1
  400b56:       e8 f5 fc ff ff          call   400850 <_ZNSirsERi@plt>

  400b5b:       48 8d 55 f0             lea    rdx,[rbp-0x10]
  400b5f:       48 89 d6                mov    rsi,rdx
  400b62:       48 89 c7                mov    rdi,rax
// Enter number 2
  400b65:       e8 e6 fc ff ff          call   400850 <_ZNSirsERi@plt>

  400b6a:       48 8d 55 ec             lea    rdx,[rbp-0x14]
  400b6e:       48 89 d6                mov    rsi,rdx
  400b71:       48 89 c7                mov    rdi,rax
// Enter number 3
  400b74:       e8 d7 fc ff ff          call   400850 <_ZNSirsERi@plt>

  ...

// edx <- num1 + num2
  400b91:       8b 55 f4                mov    edx,DWORD PTR [rbp-0xc]
  400b94:       8b 45 f0                mov    eax,DWORD PTR [rbp-0x10]
  400b97:       01 c2                   add    edx,eax
// eax <- edx + num3
  400b99:       8b 45 ec                mov    eax,DWORD PTR [rbp-0x14]
  400b9c:       01 d0                   add    eax,edx
*
// if (eax != 0x539) jne 400bcc
  400b9e:       3d 39 05 00 00          cmp    eax,0x539
  400ba3:       75 27                   jne    400bcc <main+0xae>
  400ba5:       be e6 0c 40 00          mov    esi,0x400ce6
  400baa:       bf a0 21 60 00          mov    edi,0x6021a0
  400baf:       e8 7c fc ff ff          call   400830 <_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc@plt>
  400bb4:       48 8b 45 f8             mov    rax,QWORD PTR [rbp-0x8]
  400bb8:       48 89 c7                mov    rdi,rax
  400bbb:       e8 23 ff ff ff          call   400ae3 <_Z9print_ptrPc>
  400bc0:       bf ef 0c 40 00          mov    edi,0x400cef
*
// Print the flag
  400bc5:       e8 f6 fb ff ff          call   4007c0 <puts@plt>

  ...
```

So we have to enter three numbers whose sum is equal to `0x539`, `1337` in decimal.

The behavior of the program can be checked with `gdb`.

```
$ gdb ./adder
// Set some breakpoints
(gdb) b *0x400b9e
Breakpoint 1 at 0x400b9e
(gdb) b *0x400bc5
Breakpoint 2 at 0x400bc5
(gdb) run
Starting program: /home/.../adder 

Enter three numbers!
398 
400
539

// The program stops at breakpoint 1
Breakpoint 1, 0x0000000000400b9e in main ()

// Let's see some information about registry
// We can see that rax = 0x539, indeed 398+400+539 = 1337
(gdb) info registers
rax            0x539    1337
rbx            0x0      0
rcx            0x0      0
rdx            0x31e    798
rsi            0x615441 6378561
rdi            0x0      0

// We can use ni to execute the next instruction
(gdb) ni
0000000400ba3 in main ()
// and c to continue running until the next breakpoint
(gdb) c
Continuing.

Breakpoint 2, 0x0000000000400bc5 in main ()

// Show the current position
(gdb) bt
#0  0x0000000000400bc5 in main ()

// Show assembly instruction
(gdb) layout asm

// Finally, the flag is:
(gdb) c
Continuing.
easyctf{y0u_added_thr33_nums!}
```
