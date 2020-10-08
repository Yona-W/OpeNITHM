#include "RunningSum.h"
#include <stdlib.h>

RunningSum::RunningSum(int n) {
    _size = n;
    _ar = (int*) malloc(_size * sizeof(int));
    if (_ar == NULL) _size = 0;
    clear();
}

RunningSum::~RunningSum() {
    if (_ar != NULL) free(_ar);
}

void RunningSum::clear() {
    _cnt = 0;
    _idx = 0;
    _sum = 0.0;
    for (int i = 0; i< _size; i++) _ar[i] = 0;
}

void RunningSum::addValue(int f) {
    if (_ar == NULL) return;
    _sum -= _ar[_idx];
    _ar[_idx] = f;
    _sum += f;
    _idx++;
    if (_idx == _size) _idx = 0;
    if (_cnt < _size) _cnt++;
}
