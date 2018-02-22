# Diff

**Category:** Forensics

**Description:**

> Sometimes, the differences matter. Especially between the files in this archive.
> Hint: This is a TAR archive file. You can extract the files inside this tar by navigating to the directory where you downloaded it and running tar xf file.tar! If you don't have tar on your personal computer, you could try doing it from the Shell server. Once you extract the files, try comparing the hex encodings of the files against the first file.

**Solution:**

We have 4 files.
```sh
$ ls
file  file2  file3  file4
```

The hint says we have to compare the hex encodings of the files against the first file. So we can use this command: 
```sh
cmp -l file file2 | gawk '{printf %08X %02X %02Xn, , strtonum(0), strtonum(0)}'
```

So we got the following. 

**file** and **file2**:
```
0000000A 00 65  e
0000007A 00 61  a
000000EB 00 73  s
00000115 00 79  y
00000116 00 63  c
00000117 00 74  t
00000127 00 66  f
00000188 00 7B  {
000001E8 00 64  d
000003A8 00 69  i
```

**file** and **file3**:
```
000000B3 00 66  f       
00000105 00 66  f       
000001F6 00 69  i
00000316 00 6E  n
00000317 00 69  i
000003C7 00 74  t
000003C8 00 6C  l
00001107 6C 79  y
00001108 61 5F  _
000011A7 00 61  a
000011A8 00 6E  n
000011A9 00 5F  _
```

**file** and **file4**:
```
000004E1 02 65  e
000004E2 00 7A  z
000004E5 02 5F  _
000004E6 00 70  p
000004E7 02 72  r
000004E8 00 6F  o
000004E9 02 62  b
000004EA 00 6C  l
000004EB 00 65  e
000004EC 00 6D  m
000004ED 00 21  !
000004EE 00 7D  }
```

After checking the decimal value of each caracter, we found the flag is:
```
easyctf{diffinitly_an_ez_problem!}
```
