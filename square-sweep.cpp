#include "everything.h"

#define TIME_SEC 0.5
#define NOTE_MAX 127.0
#define NOTE_INTERVAL 1

double square(double initial_frequency, long sample_index) {
    double sum = 0.0;

    long N = SAMPLE_RATE /(2 * initial_frequency);
    double t = sample_index / SAMPLE_RATE;

    for (int n = 1; n <= N; n+=2) {
        double phase = 2.0 * n * pi * t * initial_frequency;
        sum += sin(phase) / n;
    }
    return sum * 4 / pi;
}

int main() {

    for (long t = 0; t < TIME_SEC * SAMPLE_RATE; t++) {
        double sum = 0.0;
        for (float note = NOTE_MAX; note > 0; note-=NOTE_INTERVAL) {
            float freq = mtof(note);
            sum += square(freq, t);
        }
        mono(sum / NOTE_MAX);
    }

    return 0;
}