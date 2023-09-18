#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 5

// Definição da estrutura BoundedBuffer
typedef struct {
    const char* buffer[BUFFER_SIZE];
    int count; // número de itens no buffer
    int in;    // aponta para próxima posição livre
    int out;   // aponta próxima posição cheia
} BoundedBuffer;

// Método para inserir um item no buffer
void insert(BoundedBuffer* bb, const char* item) {
    while (bb->count == BUFFER_SIZE); // não faz nada, pois não há nenhum buffer livre - buffer cheio
    bb->buffer[bb->in] = item;
    printf("Inseriu o objeto %s na posição %d do buffer\n", bb->buffer[bb->in], bb->in);
    ++bb->count; // acrescenta um item ao buffer
    bb->in = (bb->in + 1) % BUFFER_SIZE;
}

// Método para remover um item do buffer
const char* removeItem(BoundedBuffer* bb) {
    const char* item;
    while (bb->count == 0); // não faz nada, pois não há nada para consumir - buffer vazio
    item = bb->buffer[bb->out];
    printf("Removeu o objeto %s na posição %d do buffer\n", bb->buffer[bb->out], bb->out);
    --bb->count; // remove um item do buffer
    bb->out = (bb->out + 1) % BUFFER_SIZE;
    return item;
}

// Função principal
int main() {
    BoundedBuffer log;
    log.count = 0; // buffer inicialmente está vazio
    log.in = 0;
    log.out = 0;

    insert(&log, "Teste0");
    insert(&log, "Teste1");
    insert(&log, "Teste2");
    insert(&log, "Teste3");
    insert(&log, "Teste4");

    const char* t = removeItem(&log);
    const char* t1 = removeItem(&log);
    const char* t2 = removeItem(&log);
    const char* t3 = removeItem(&log);
    const char* t4 = removeItem(&log);

    // Não é necessário liberar a memória para literais de string constantes

    return 0;
}

