/********************************************************************************
 * 45 --> E ~~~~~~ 4c --> L ~~~~~~ 46 --> F
 * 
 *             hypothetical layout
 *             +-----------------+
         +----| ELF File Header |----+
         |    +-----------------+    |
         v                           v
 +-----------------+      +-----------------+
 | Program Headers |      | Section Headers |
 +-----------------+      +-----------------+
      ||                               ||
      ||                               ||
      ||                               ||
      ||   +------------------------+  ||
      +--> | Contents (Byte Stream) |<--+
           +------------------------+
 
 
 * ///////////////////////////////////////////////////////////////////////////////
 * 
 * Class:           64 bit architecture
 * Data:            Least Significant Bit (LSB or little endian)
 * ABI:             application binary interface 
 * Type:            this is REL, others are DYN (shared object file) or EXEC
 * 
    $ hexdump -C -n 64 /bin/ps
    00000000  7f 45 4c 46 02 01 01 00  00 00 00 00 00 00 00 00  |.ELF............|
    00000010  02 00 3e 00 01 00 00 00  a8 2b 40 00 00 00 00 00  |..>......+@.....|
    00000020  40 00 00 00 00 00 00 00  30 65 01 00 00 00 00 00  |@.......0e......|
    00000030  00 00 00 00 40 00 38 00  09 00 40 00 1c 00 1b 00  |....@.8...@.....|
 * 
 * ///////////////////////////////////////////////////////////////////////////////
 * 
 *
 * Section Headers: post gcc linkage 
 *      .interp                         holding pathname of interpreter 
 *      .gnu.hash                       dynamic hash table
 *      .dynsym                         imported/exported symbol table
 *      .dynstr                         dynamic names table
 *      .init, .plt, .fini              code sections
 *      .text                           code
 *      .rela.text, .rela               relocation tables
 *      .data, .bss, .rodata            data sections
 *      .got, .dynamic, .plt            dynamic binaries 
 *      .comment                        extra, misc.
 *      .symtab                         symbol tables
 *      .shstrtab                       section string tables (name of each section)
 *      .strtab                         string tables
 * 
 * Jumps: readelf -r hello (patching offset for printf at 000000600ff8)
 * 
        Relocation section '.rela.dyn' at offset 0x380 contains 1 entries:
        Offset          Info           Type           Sym. Value    Sym. Name + Addend
        000000600ff8  000300000006 R_X86_64_GLOB_DAT 0000000000000000 __gmon_start__ + 0

        Relocation section '.rela.plt' at offset 0x398 contains 3 entries:
        Offset          Info           Type           Sym. Value    Sym. Name + Addend
        000000601018  000100000007 R_X86_64_JUMP_SLO 0000000000000000 printf + 0
        000000601020  000200000007 R_X86_64_JUMP_SLO 0000000000000000 __libc_start_main + 0
        000000601028  000300000007 R_X86_64_JUMP_SLO 0000000000000000 __gmon_start__ + 0
 * 
 * 
 * 
 * References: 
 * - https://linux-audit.com/elf-binaries-on-linux-understanding-and-analysis/
 * - http://fluxius.handgrep.se/2011/10/20/the-art-of-elf-analysises-and-exploitations/
 * - http://www.cs.stevens.edu/~jschauma/810/elf.html
 * 
/********************************************************************************/
 
#include<stdio.h>

int testGlobal = 1; 

int main(void)
{
    printf("Hello World \n");
    printf("%d", testGlobal);

}

