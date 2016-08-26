import sys, os, struct, operator, zlib

def decodeString(name, length):
    hash = bytearray([0x95, 0x3A, 0xC5, 0x2A, 0x95, 0x7A, 0x95, 0x6A])

    result = list(name)

    for x in xrange(length):
        value = 0
        value ^= hash[x % 8]
        result[x] = str(value)

    result = ''.join(result)

    return result

print 'EverQuest WLD Read'

file = open('trakanon_obj.wld', 'rb')

fileMagicNumber, = struct.unpack('i', file.read(4))
print 'File Magic Number:', hex(fileMagicNumber)
if (fileMagicNumber != 0x54503D02):
    print 'File Magic Number is incorrect!'

fileVersion, = struct.unpack('i', file.read(4))
print 'File Version:', hex(fileVersion)
if (fileVersion == 0x00015500):
    print 'File Version is old format.'
elif (fileVersion == 0x1000C800):
    print 'File Version is new format.'

fileFragmentCount, = struct.unpack('i', file.read(4))
print 'File Fragment Count:', fileFragmentCount

fileUnknown1, = struct.unpack('i', file.read(4))
print 'File Unknown 1:', fileUnknown1

fileUnknown2, = struct.unpack('i', file.read(4))
print 'File Unknown 2:', fileUnknown2

fileStringHashSize, = struct.unpack('i', file.read(4))
print 'File String Hash Size:', fileStringHashSize

fileUnknown4, = struct.unpack('i', file.read(4))
print 'File Unknown 4:', fileUnknown4

fileString, = struct.unpack('%s', file.read(fileStringHashSize))
tempp = decodeString(fileString, fileStringHashSize)
print 'tempp:', tempp

file.close()
