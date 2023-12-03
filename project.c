#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void parse_accelerometer_data(uint8_t *packet_data, int packet_length) {
    int index = 0;

    if (packet_length < 33) {
        printf("Packet length is too short!\n");
        return;
    }

    printf("TEMA: ");
    for (int i = 0; i < 3; i++) {
        printf("%02X ", packet_data[index++]);
    }
    printf("\n");

    // Skipping over reserved data
    index += 2;

    printf("Manufacturer ID: ");
    for (int i = 0; i < 2; i++) {
        printf("%02X ", packet_data[index++]);
    }
    printf("\n");

    printf("Manufacturer data: ");
    for (int i = 0; i < 18; i++) {
        printf("%02X ", packet_data[index++]);
    }
    printf("\n");

    // Beacon Type (should be 0x06 for Beacon)
    printf("Beacon Type: %02X\n", packet_data[index++]);

    // UUID data length
    uint8_t uuid_data_length = packet_data[index++];
    printf("UUID data length: %d\n", uuid_data_length);

    printf("UUID data: ");
    for (int i = 0; i < uuid_data_length; i++) {
        printf("%02X ", packet_data[index++]);
    }
    printf("\n");

    printf("Major: ");
    for (int i = 0; i < 2; i++) {
        printf("%02X ", packet_data[index++]);
    }
    printf("\n");

    printf("Minor: ");
    for (int i = 0; i < 2; i++) {
        printf("%02X ", packet_data[index++]);
    }
    printf("\n");

    // RSSI at 1m
    printf("RSSI at 1m: %02X\n", packet_data[index++]);
}

int main() {
    // Example packet data
    uint8_t packet_data[] = {0x02, 0x01, 0x06, 0x03, 0x03, 0xE1, 0xFF, 0x12, 0x16, 0xE1, 0xFF, 0xA1, 0x03, 0x64, 0x00, 0x00, 0xFF, 0x80, 0x01, 0x3B, 0x00, 0x90, 0x78, 0x56, 0x34, 0x12, 0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0x03, 0xE8};
    int packet_length = sizeof(packet_data) / sizeof(packet_data[0]);

    parse_accelerometer_data(packet_data, packet_length);

    return 0;
}