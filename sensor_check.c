#include <stdio.h>    // printf
#include <stdbool.h>  // bool, true, false (nice for readability)

// Simulated sensor reading (e.g., temperature in °C)
int read_sensor(void) { return 73; }

// Decide if the reading is OK, WARN, or FAIL using if/else
const char* classify_if(int x) {
    // OK: 0..69, WARN: 70..84, FAIL: 85+
    if (x <= 69) return "OK";
    else if (x <= 84) return "WARN";
    else return "FAIL";
}

// The same classification using switch on bucketized value
const char* classify_switch(int x) {
    int bucket = (x < 0) ? 0 : x;    // clamp negative to 0
    bucket /= 5;                     // 0..13 for 0..69; 14..16 for 70..84; 17+ for 85+
    switch (bucket) {
        case 0:  case 1:  case 2:  case 3:
        case 4:  case 5:  case 6:  case 7:
        case 8:  case 9:  case 10: case 11:
        case 12: case 13:
            return "OK";
        case 14: case 15: case 16:
            return "WARN";
        default:
            return "FAIL";
    }
}

int main(void) {
    int v = read_sensor();
    printf("Reading: %d => if/else: %s, switch: %s\n",
           v, classify_if(v), classify_switch(v));
    return 0;
}
