#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/statvfs.h>

const char* GREEN = "\033[1;32m";
const char* RED = "\033[1;31m";
const char* RESET = "\033[0m";

void printBanner() {
    // ANSI escape-коды для цвета
    

    // Логотип ASCII-арт
    const char* LOGO[] = {
        "\n\n\n",
        "      |\\      _,,,---,,_",
        "ZZZzz /,`.-'`'    -.  ;-;;,_",
        "     |,4-  ) )-,_. ,\\ (  `'-'",
        "    '---''(_/--'  `-'\\_)\033[1;31m meowk1r1 software\n\033[0m",
        "\033[33mMEOWRT"
    };

    // Вывод логотипа
    printf("%s", GREEN);
    for (int i = 0; i < 6; i++) {
        printf("%s\n", LOGO[i]);
    }
    printf("%s", GREEN);

}


void print_system_info() {
    // Get system uptime
    FILE *uptime_file = fopen("/proc/uptime", "r");
    if (uptime_file != NULL) {
        float uptime_seconds;
        fscanf(uptime_file, "%f", &uptime_seconds);
        fclose(uptime_file);
        printf("System Uptime: %.0f seconds\n", uptime_seconds);
    } else {
        printf("Unable to get system uptime.\n");
    }

    // Get memory info
    FILE *mem_info = fopen("/proc/meminfo", "r");
    if (mem_info != NULL) {
        char line[256];
        while (fgets(line, sizeof(line), mem_info)) {
            if (strstr(line, "MemTotal")) {
                printf("Total Memory: %s", line);
            } else if (strstr(line, "MemFree")) {
                printf("Free Memory: %s", line);
            }
        }
        fclose(mem_info);
    }

    // Get disk usage info
    struct statvfs fs_info;
    if (statvfs("/", &fs_info) == 0) {
        unsigned long long total_space = fs_info.f_blocks * fs_info.f_frsize;
        unsigned long long free_space = fs_info.f_bfree * fs_info.f_frsize;
        unsigned long long used_space = total_space - free_space;

        printf("Disk Usage: %llu / %llu bytes used\n", used_space, total_space);
        printf("Free Space: %llu bytes\n", free_space);
    }
}

void print_load_avg() {
    // Load average over 1, 5, and 15 minutes
    double loadavg[3];
    if (getloadavg(loadavg, 3) == -1) {
        perror("getloadavg");
    } else {
        printf("Load Average (1 min): %.2f\n", loadavg[0]);
        printf("Load Average (5 min): %.2f\n", loadavg[1]);
        printf("Load Average (15 min): %.2f\n", loadavg[2]);
    }
    printf("%s", RESET);}

int main() {
    // Print logo
    printBanner();

    // Print system information
    print_system_info();

    // Print load average
    print_load_avg();

    return 0;
}
