
#include "sync_car.h"

void station_init(station *station) {
    station->assentos_disponiveis = 0;
    station->embarques_pendentes = 0;
    station->passageiros_aguardando = 0;

    pthread_mutex_init(&station->mutex, NULL);
    pthread_cond_init(&station->cond_passageiros, NULL);
    pthread_cond_init(&station->cond_vagao, NULL);
}

void station_wait_for_car(struct station *station) {
    pthread_mutex_lock(&station->mutex);

    station->passageiros_aguardando++;

    while (station->assentos_disponiveis == 0) {
        pthread_cond_wait(&station->cond_passageiros, &station->mutex);
    }

    station->passageiros_aguardando--;
    station->assentos_disponiveis--;
    station->embarques_pendentes++;

    pthread_cond_signal(&station->cond_vagao);

    pthread_mutex_unlock(&station->mutex);
}

void station_on_board(station *station) {
    pthread_mutex_lock(&station->mutex);

    station->embarques_pendentes--;

    pthread_cond_signal(&station->cond_vagao);

    pthread_mutex_unlock(&station->mutex);
}

void station_load_car(station *station, int count) {
    pthread_mutex_lock(&station->mutex);

    station->assentos_disponiveis = count;

    pthread_cond_broadcast(&station->cond_passageiros);

    while (!(station->embarques_pendentes == 0 &&
             (station->assentos_disponiveis == 0 ||
              station->passageiros_aguardando == 0))) {
        pthread_cond_wait(&station->cond_vagao, &station->mutex);
    }

    station->assentos_disponiveis = 0;

    pthread_mutex_unlock(&station->mutex);
}
