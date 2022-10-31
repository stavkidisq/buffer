#include <stdio.h>
#include <stdlib.h>

const int BUFF_SIZE = 32000;
const int BUFF_COUNT = 32000 / sizeof(unsigned short int);

void fill_buff(unsigned short int*);
void write_file(const char*, unsigned short int*);
FILE* open_file(const char*, const char*);

unsigned short int* init_buff();

/*
    Имя программы: buffer.
    Назначение программы: заполнение буффера полосатым кодом, запись буффера в файл.
    Автор: Рабцевич Александр.
    Дата создания: 31.10.22.
*/
int main()
{
    unsigned short int* buff = init_buff();

    fill_buff(buff);
    write_file("bin-file.bin", buff);

    free(buff);

    printf("The program has been successfully completed!");

    return 0;
}

void fill_buff(unsigned short int* buff)
{
    buff[0] = 0;

    for(int i = 1; i < BUFF_COUNT; i++)
    {
        buff[i] = 52;
    }
}

void write_file(const char* filename, unsigned short int* buff)
{
    FILE* fstream = open_file(filename, "wb");

    printf("Writing to file...\n");

    for(int i = 0; i < BUFF_COUNT; i++)
    {
        fwrite(&buff[i], sizeof(unsigned short int), 1, fstream);
    }

    fclose(fstream);
}

FILE* open_file(const char* filename, const char* mode)
{
    FILE* fstream = NULL;

    printf("Opening file...\n");

    if((fstream = fopen(filename, mode)) == NULL)
    {
        printf("No such file.\n");
        exit(EXIT_FAILURE);
    }

    return fstream;
}

unsigned short int* init_buff()
{
    printf("Buffer initialization...\n");

    unsigned short int* buff = (unsigned short int*)malloc(BUFF_SIZE);

    if(buff == NULL)
    {
        printf("Failed to allocate, aborting...\n");
        exit(EXIT_FAILURE);
    }

    return buff;
}
