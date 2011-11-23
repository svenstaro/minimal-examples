#include <QTime>
#include <QVector>

#include <cstdint>
#include <list>
#include <vector>

#define COUNT 10000000

int main(int argc, char** argv) {
    qDebug("Benchmark payload: %d MB", ((COUNT/1000)/1000) * 8);

    QTime clock;
    clock.start();

    // Standard C array on heap
    clock.restart();
    uint64_t* c_array = new uint64_t[COUNT];
    for(uint64_t i = 0; i < COUNT; ++i)
        c_array[i] = 5;

    uint64_t c_array_sum = 0;
    for(uint64_t i = 0; i < COUNT; ++i)
        c_array_sum += c_array[i];

    qDebug("c_array_sum: %lu, time: %d ms", c_array_sum, clock.elapsed());


    // Standard vector
    clock.restart();
    std::vector<uint64_t> vector(COUNT);
    for(uint64_t i = 0; i < COUNT; ++i)
        vector[i] = 5;

    uint64_t vector_sum = 0;
    for(uint64_t i = 0; i < COUNT; ++i)
        vector_sum += vector[i];

    qDebug("vector_sum: %lu, time: %d ms", vector_sum, clock.elapsed());


    // Standard vector with iterator access
    clock.restart();
    std::vector<uint64_t> vector_it(COUNT);
    for(auto it = vector_it.begin(); it != vector_it.end(); ++it)
        *it = 5;

    uint64_t vector_it_sum = 0;
    for(auto it = vector_it.begin(); it != vector_it.end(); ++it)
        vector_it_sum += *it;

    qDebug("vector_it_sum: %lu, time: %d ms", vector_it_sum, clock.elapsed());


    // List standard vector
    clock.restart();
    std::list<uint64_t> list(COUNT);
    for(auto it = list.begin(); it != list.end(); ++it)
        *it = 5;

    uint64_t list_sum = 0;
    for(auto it = list.begin(); it != list.end(); ++it)
        list_sum += *it;

    qDebug("list_sum: %lu, time: %d ms", list_sum, clock.elapsed());


    // QVector vector
    clock.restart();
    QVector<uint64_t> qvector(COUNT);
    for(uint64_t i = 0; i < COUNT; ++i)
        qvector[i] = 5;

    uint64_t qvector_sum = 0;
    for(uint64_t i = 0; i < COUNT; ++i)
        qvector_sum += qvector[i];

    qDebug("qvector_sum: %lu, time: %d ms", qvector_sum, clock.elapsed());

    return 0;
}
