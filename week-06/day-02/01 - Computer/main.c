#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
};

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    Notebook Dell;
    Dell.cpu_speed_GHz = 3;
    Dell.ram_size_GB = 16;
    Dell.bits = 64;

    struct Computer pc;
    pc.cpu_speed_GHz = 3.5;
    pc.ram_size_GB = 8;
    pc.bits = 64;

    printf("The PC has a %.1f GHz of CPU speed, Ram size of %d, and has %d bits.\n", pc.cpu_speed_GHz,pc.ram_size_GB,pc.bits);
    printf("The Dell notebook has a %.1f GHz of CPU speed, Ram size of %d, and has %d bits.\n", Dell.cpu_speed_GHz,Dell.ram_size_GB,Dell.bits);

    return 0;
}