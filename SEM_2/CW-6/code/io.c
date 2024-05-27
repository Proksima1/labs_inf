#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "headers/io.h"
#include "headers/pc.h"

int get_type_input(char HELP_TEXT[], FILE *in)
{
    printf("%s", HELP_TEXT);
    int type = 0;
    fscanf(in, "%d", &type);
    while (type > 4)
    {
        printf("%s", HELP_TEXT);
        fscanf(in, "%d", &type);
    }
    return type;
}

void deleteLastSpace(char data[MAX_NAME_LENGTH])
{
    if (data[strlen(data) - 1] == '\n')
    {
        data[strlen(data) - 1] = '\0';
    }
}

char *getDiskType(int num)
{
    switch (num)
    {
    case 0:
        return "SCSI";
    case 1:
        return "IDE";
    case 2:
        return "ATA";
    case 3:
        return "SATA";
    default:
        return "Unknowd disk type";
    }
}

char *getVideoType(int num)
{
    switch (num)
    {
    case 0:
        return "INTEGRATED";
    case 1:
        return "EXTERNAL";
    case 2:
        return "AGP";
    case 3:
        return "PCI";
    default:
        return "Unknown video controller type";
    }
}

int pc_read_txt(PersonalComputer *pc, FILE *in)
{
    printf("Owner surname: ");
    do
    {
        fgets(pc->owner_surname, sizeof(char) * MAX_NAME_LENGTH, in);
    } while (strcmp(pc->owner_surname, "\n") == 0);
    deleteLastSpace(pc->owner_surname);
    printf("Processor count: ");
    fscanf(in, "%d", &pc->processor_count);
    while (pc->processor_count > 2)
    {
        printf("Amount of processors cannot be greater than 2\n");
        printf("Processor count: ");
        fscanf(in, "%d", &pc->processor_count);
    }
    for (int i = 0; i < pc->processor_count; ++i)
    {
        Processor *pr = (Processor *)malloc(sizeof(Processor));
        printf("Processor type: ");
        do
        {
            fgets(pr->type, sizeof(char) * MAX_NAME_LENGTH, in);
        } while (strcmp(pr->type, "\n") == 0);
        deleteLastSpace(pr->type);
        pc->processors[i] = pr;
    }
    printf("RAM capacity(in GB): ");
    fscanf(in, "%d", &pc->ram_size);
    int video_type = get_type_input(VIDEO_HELP_TEXT, in);
    pc->video_controller_type = video_type - 1;
    printf("Video memory(in GB): ");
    fscanf(in, "%d", &pc->video_memory_size);
    printf("Drives count: ");
    fscanf(in, "%d", &pc->disks_count);
    while (pc->disks_count > MAX_DRIVES)
    {
        printf("Amount of disks cannot be greater than %d", MAX_DRIVES);
        fscanf(in, "%d", &pc->disks_count);
    }
    for (int i = 0; i < pc->disks_count; ++i)
    {
        HardDrive *dr = (HardDrive *)malloc(sizeof(HardDrive));
        int drive_type = get_type_input(DRIVE_HELP_TEXT, in);
        dr->disk_controller_type = drive_type - 1;
        printf("Drive capacity(in GB): ");
        fscanf(in, "%d", &dr->capacity);
        pc->drives[i] = dr;
    }
    printf("External devices count: ");
    fscanf(in, "%d", &pc->external_device_count);
    for (int i = 0; i < pc->external_device_count; ++i)
    {
        ExternalDevice *ex = (ExternalDevice *)malloc(sizeof(ExternalDevice));
        printf("External device #%d type: ", i + 1);
        do
        {
            fgets(ex->type, sizeof(char) * MAX_NAME_LENGTH, in);
        } while (strcmp(ex->type, "\n") == 0);
        deleteLastSpace(ex->type);
        pc->external_devices[i] = ex;
    }
    printf("OS: ");
    do
    {
        fgets(pc->os, sizeof(char) * MAX_NAME_LENGTH, in);
    } while (strcmp(pc->os, "\n") == 0);
    deleteLastSpace(pc->os);
    return !feof(in);
}

int pc_read_bin(PersonalComputer *pc, FILE *in)
{
    fread(pc->owner_surname, sizeof(char), MAX_NAME_LENGTH, in);
    fread(&(pc->processor_count), sizeof(int), 1, in);
    int count = pc->processor_count;
    for (int i = 0; i < count; ++i)
    {
        Processor *pr = (Processor *)malloc(sizeof(Processor));
        fread(pr->type, sizeof(char), MAX_NAME_LENGTH, in);
        pc->processors[i] = pr;
        //        free(pr);
    }
    fread(&(pc->ram_size), sizeof(int), 1, in);
    fread(&(pc->video_controller_type), sizeof(int), 1, in);
    fread(&(pc->video_memory_size), sizeof(int), 1, in);
    fread(&(pc->disks_count), sizeof(int), 1, in);
    count = pc->disks_count;
    for (int i = 0; i < count; ++i)
    {
        HardDrive *dr = (HardDrive *)malloc(sizeof(HardDrive));
        fread(&dr->capacity, sizeof(int), 1, in);
        fread(&dr->disk_controller_type, sizeof(int), 1, in);
        pc->drives[i] = dr;
        //        free(dr);
    }
    fread(&(pc->external_device_count), sizeof(int), 1, in);
    count = pc->external_device_count;
    for (int i = 0; i < count; ++i)
    {
        ExternalDevice *ex = (ExternalDevice *)malloc(sizeof(ExternalDevice));
        fread(ex->type, sizeof(char), MAX_NAME_LENGTH, in);
        pc->external_devices[i] = ex;
        //        free(ex);
    }
    fread(pc->os, sizeof(char), MAX_NAME_LENGTH, in);
    return !feof(in);
}

void pc_write_bin(PersonalComputer *pc, FILE *out)
{
    // fwrite(pc->owner_surname, sizeof(char), MAX_NAME_LENGTH, out);
    // fwrite(&(pc->processor_count), sizeof(int), 1, out);
    // for (int i = 0; i < pc->processor_count; ++i)
    // {
    //     Processor *pr = pc->processors[i];
    //     fwrite(pr->type, sizeof(char), MAX_NAME_LENGTH, out);
    // }
    // fwrite(&(pc->ram_size), sizeof(int), 1, out);
    // fwrite(&(pc->video_controller_type), sizeof(int), 1, out);
    // fwrite(&(pc->video_memory_size), sizeof(int), 1, out);
    // fwrite(&(pc->disks_count), sizeof(int), 1, out);

    // for (int i = 0; i < pc->disks_count; ++i)
    // {
    //     HardDrive *drive = pc->drives[i];
    //     fwrite(&(drive->capacity), sizeof(int), 1, out);
    //     fwrite(&(drive->disk_controller_type), sizeof(int), 1, out);
    // }
    // fwrite(&(pc->external_device_count), sizeof(int), 1, out);
    // for (int i = 0; i < pc->external_device_count; ++i)
    // {
    //     fwrite(pc->external_devices[i]->type, sizeof(char), MAX_NAME_LENGTH, out);
    // }
    // fwrite(pc->os, sizeof(char), MAX_NAME_LENGTH, out);
}

void pc_print(PersonalComputer *pc)
{
    printf("Owner surname: %s\n", pc->owner_surname);
    printf("Processor count: %d\n", pc->processor_count);
    for (int i = 0; i < pc->processor_count; ++i)
    {
        printf("Processor #%d type: %s\n", i + 1, pc->processors[i]->type);
    }
    printf("RAM capacity: %d\n", pc->ram_size);
    printf("Video controller type: %s\n", getVideoType(pc->video_controller_type));
    printf("Video memory capacity: %d\n", pc->video_memory_size);
    printf("Drives count: %d\n", pc->disks_count);
    for (int i = 0; i < pc->disks_count; ++i)
    {
        printf("Disk #%d:\n", i + 1);
        printf("Disk capacity: %d\n", pc->drives[i]->capacity);
        printf("Disk controller type: %s\n", getDiskType(pc->drives[i]->disk_controller_type));
    }
    printf("External devices count: %d\n", pc->external_device_count);
    for (int i = 0; i < pc->external_device_count; ++i)
    {
        printf("External device #%d: %s\n", i + 1, pc->external_devices[i]->type);
    }
    printf("OS: %s\n", pc->os);
}

void pc_free(PersonalComputer *pc)
{
    for (int i = 0; i < pc->processor_count; ++i)
    {
        free(pc->processors[i]);
        pc->processors[i] = NULL;
    }
    for (int i = 0; i < pc->disks_count; ++i)
    {
        free(pc->drives[i]);
        pc->drives[i] = NULL;
    }
    for (int i = 0; i < pc->external_device_count; ++i)
    {
        free(pc->external_devices[i]);
        pc->external_devices[i] = NULL;
    }
    for (int i = 0; i < MAX_NAME_LENGTH; ++i)
    {
        pc->owner_surname[i] = '\0';
    }
    for (int i = 0; i < MAX_NAME_LENGTH; ++i)
    {
        pc->os[i] = '\0';
    }
    //    pc = (PersonalComputer *) malloc(sizeof(PersonalComputer));
}