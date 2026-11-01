#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct station {
    int assentos_disponiveis;
    int embarques_pendentes;
    int passageiros_aguardando;

    pthread_mutex_t mutex;
    pthread_cond_t cond_passageiros;
    pthread_cond_t cond_vagao;
} station;

