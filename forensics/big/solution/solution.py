import pwn
import struct
import binascii

big = open("./big.png", "rb")
magic = big.read(8)

def read_chunk(stream):
    size = (stream.read(4))
    size = struct.unpack(">I", size)[0]
    type = stream.read(4)
    data = stream.read(size)
    crc = stream.read(4)
    crc = struct.unpack(">I", crc)[0]
    return [size, type, data, crc]

def read_chunks(stream):
    chunks = []
    try:
        while True:
            chunk = read_chunk(stream)
            chunks.append(chunk)
    except struct.error as e:
        return chunks

def chunk_to_bytes(chunk):
    bs = b""
    bs += struct.pack(">I", chunk[0])
    bs += chunk[1]
    bs += chunk[2]
    bs += struct.pack(">I", chunk[3])
    return bs

def check_crc(chunk):
    # use chunk and data
    bs = chunk[1] + chunk[2]
    return binascii.crc32(bs) == chunk[3]
chunks = read_chunks(big)
ihdr = chunks[0]
ihdr_legit = ihdr[2][8:]
def fix_chunk(ihdr, ihdr_legit):
    for i in range(5000):
        width = struct.pack(">I", i)
        for j in range(5000):
            height = struct.pack(">I", j)
            new_chunk = ihdr[:]
            new_chunk[2] = width + height + ihdr_legit
            if check_crc(new_chunk):
                return new_chunk

new_chunk = fix_chunk(ihdr, ihdr_legit)
big2 = open("./big.png","rb").read()
bs = chunk_to_bytes(new_chunk)
big2 = big2[:8] + bs + big2[8+len(bs):]
final = open("big2.png","wb")
final.write(big2)