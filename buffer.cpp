#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 5

// Defini��o da estrutura BoundedBuffer
typedef struct {
    const char* buffer[BUFFER_SIZE];
    int count; // n�mero de itens no buffer
    int in;    // aponta para pr�xima posi��o livre
    int out;   // aponta pr�xima posi��o cheia
} BoundedBuffer;

// M�todo para inserir um item no buffer
void insert(BoundedBuffer* bb, const char* item) {
    while (bb->count == BUFFER_SIZE); // n�o faz nada, pois n�o h� nenhum buffer livre - buffer cheio
    bb->buffer[bb->in] = item;
    printf("Inseriu o objeto %s na posi��o %d do buffer\n", bb->buffer[bb->in], bb->in);
    ++bb->count; // acrescenta um item ao buffer
    bb->in = (bb->in + 1) % BUFFER_SIZE;
}

// M�todo para remover um item do buffer
const char* removeItem(BoundedBuffer* bb) {
    const char* item;
    while (bb->count == 0); // n�o faz nada, pois n�o h� nada para consumir - buffer vazio
    item = bb->buffer[bb->out];
    printf("Removeu o objeto %s na posi��o %d do buffer\n", bb->buffer[bb->out], bb->out);
    --bb->count; // remove um item do buffer
    bb->out = (bb->out + 1) % BUFFER_SIZE;
    return item;
}

// Fun��o principal
int main() {
    BoundedBuffer log;
    log.count = 0; // buffer inicialmente est� vazio
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

    // N�o � necess�rio liberar a mem�ria para literais de string constantes

    return 0;
}

