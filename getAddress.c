#include <stdio.h>
#include <elf.h>

int main(int argc, char **argv)
{
    FILE *file; 
    Elf32_Ehdr hdr; 
    
    if (argc < 2)
    {
        printf("uage: %s [FILE]/n", argv[0]);
        return -1;
    }
    
    if ((file = fopen(argv[1], "r")) == NULL) 
    {
        perror("error");
        return -1;
    }
    
    fread(&hdr, sizeof(Elf32_Ehdr), 1, file);
    fclose(file); 
    
    if ((hdr.e_ident[EI_MAG0] != ELFMAG0) 
    || (hdr.e_ident[EI_MAG1] != ELFMAG1) 
    || (hdr.e_ident[EI_MAG2] != ELFMAG2) 
    || (hdr.e_ident[EI_MAG3] != ELFMAG3)) 
    {
        printf("Error: Not a valid ELF file.\n");
        return -1;
    }
    
    printf("Entry Address (e_entry): 0x%.8x\n", hdr.e_entry);
    
    return 0;
}