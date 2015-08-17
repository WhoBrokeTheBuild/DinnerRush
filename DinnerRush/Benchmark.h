#pragma once

#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <iostream>
#include <iomanip>
#include <chrono>

#define BENCH_START() \
auto benchmark_clock_start = std::chrono::high_resolution_clock::now();

#define BENCH_PRINT(FUNC_NAME) \
auto benchmark_clock_end = std::chrono::high_resolution_clock::now(); \
long long benchmark_diff_nano = std::chrono::duration_cast<std::chrono::nanoseconds>(benchmark_clock_end - benchmark_clock_start).count(); \
double benchmark_diff_millis = (benchmark_diff_nano / 1000000.0); \
std::cout << "Function: " << FUNC_NAME << " took " << std::setprecision(3) << benchmark_diff_millis << " millis" << std::endl;

#endif // BENCHMARK_H