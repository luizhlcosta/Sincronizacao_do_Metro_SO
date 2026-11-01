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

void station_init(station *station) {
	
	station->assentos_disponiveis = 0;
	station->embarques_pendentes = 0;
	station->passageiros_aguardando = 0;
	
	pthread_mutex_init(&station->mutex, NULL);
	pthread_cond_init(&station->cond_passageiros, NULL);
	pthread_cond_init(&station->cond_vagao, NULL);
}

