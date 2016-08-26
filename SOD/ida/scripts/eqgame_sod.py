import idaapi
import idautils
import idc

def do_rename(line):
    splitted = line.split()
    strname = splitted[0]
    straddr = splitted[1].replace("\r", "").replace("\n", "")

    eaaddr = int(straddr, 16)
    idc.MakeCode(eaaddr)
    idc.MakeFunction(eaaddr)
    idc.MakeNameEx(int(straddr, 16), strname, idc.SN_NOWARN)

if __name__ == "__main__":
    file = open("eqgame_sod.txt", "r")
    for line in file:
        do_rename(line)
    file.close()