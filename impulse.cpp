#include "everything.h"

#define INIT_FREQUENCY 1000.0
#define TIME_SEC 2

double impulse(double initial_frequency, long sample_index) {
    double sum = 0.0;

    long N = SAMPLE_RATE /(2 * initial_frequency);
    double t = sample_index / SAMPLE_RATE;

    for (int n = 1; n <= N; n++) {
        double phase = 2.0 * n * pi * t * initial_frequency;
        sum += sin(phase);
    }
    return sum;
}

int main() {

    for (long t = 0; t < TIME_SEC * SAMPLE_RATE; t++) {
        mono(impulse(INIT_FREQUENCY, t));
    }

    return 0;
}