#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    float phi_r, phi_p, phi_y;
    phi_r = 45;
    phi_y = 45;
    float r11 = cos(phi_r) * cos(phi_p);
    float r21 = sin(phi_r) * cos(phi_p);
    float r31 = -sin(phi_p);
    float r32 = cos(phi_p)*sin(phi_y);
    float r33 = cos(phi_p) * cos(phi_y);

    float pitch = atan2(-r31, sqrtf(r32*r32 + r33*r33));
    float roll = atan2(r21/cos(phi_p), r11/cos(phi_p));
    float yaw = atan2(r32/cos(phi_p), r33/cos(phi_p));
    printf("Roll: %f\n", roll);
    printf("Pitch: %f\n", pitch);
    printf("Yaw: %f\n", yaw);

    return EXIT_SUCCESS; }
