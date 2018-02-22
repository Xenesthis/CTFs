int __cdecl main(int argc, const char **argv, const char **envp)
{
  int result; // eax
  int v4; // [rsp+10h] [rbp-20h]
  int v5; // [rsp+14h] [rbp-1Ch]
  int v6; // [rsp+18h] [rbp-18h]
  int v7; // [rsp+1Ch] [rbp-14h]
  int v8; // [rsp+20h] [rbp-10h]
  const char *v9; // [rsp+28h] [rbp-8h]

  signal(2, sigintHandler);
  target = (char *)*argv;
  if ( argc != 2 )
    return 2;
  v9 = argv[1];
  v4 = 1;
  v5 = 2;
  v6 = 3;
  v7 = 4;
  v8 = 5;
  v4 = *v9 + 1;
  v5 = v9[1] + 2;
  v6 = v9[2] + 3;
  v7 = v9[3] + 4;
  v8 = v9[4] + 5;
  if ( v7 != 111 || v6 != 125 || v4 != v8 - 10 || v5 != 53 || v8 != v7 + 3 )
  {
    sleep(2u);
    remove(*argv);
    puts("successfully deleted!");
    result = 2;
  }
  else
  {
    printf("Now here is your flag: ", sigintHandler, argv);
    print_5(&v4);
    result = 1;
  }
  return result;
}
