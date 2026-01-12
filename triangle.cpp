#include "everything.h"

#define INIT_FREQUENCY 440.0
#define TIME_SEC 2

double triangle(double initial_frequency, long sample_index) {
    double sum = 0.0;

    long N = SAMPLE_RATE /(2 * initial_frequency);
    double t = sample_index / SAMPLE_RATE;

    for (int n = 1; n <= N; n+=2) {
        double phase = 2.0 * n * pi * t * initial_frequency;

        double factor = -1.0;
        if (((n - 1) / 2) % 2 == 0) {
            factor = 1.0;
        }

        sum += sin(phase) * factor / n / n;
    }
    return sum * 8 / pi / pi;
}

int main() {

    for (long t = 0; t < TIME_SEC * SAMPLE_RATE; t++) {
        mono(triangle(INIT_FREQUENCY, t));
    }

    return 0;
}