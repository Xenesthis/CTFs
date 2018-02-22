# EzReverse

**Category:** Reverse Engineering

**Description:**

> Take a look at executable. Objdump the executable and read some assembly!

**Solution:**

I used IDA pro to solved this challenge. You can find the dissasembled code [here](./pseudocode.c). 

The programme needs one argument to execute. If wrong argument is given, the programme will automatically delete itself. 

In the pseudocode, you can see that the argument should be a string of 5 characters and it's equal to `103 51 122 107 109`. Converting to ASCII, it becomes `g3zkm`.

Now we can get the flag
```sh
$ ./executable g3zkm
Now here is your flag: 10453125111114
```
