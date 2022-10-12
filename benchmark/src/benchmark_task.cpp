#include <benchmark/benchmark.h>
#include <libTask.h>

/**
 * @file benchmark_task.cpp
 * @author Barry Robinson (barry.w.robinson64@gmail.com)
 * @brief Test harness for task application library
 * @version 0.1
 * @date 11/10/2020
 *
 * @copyright Copyright (c) 2021
 * @addtogroup benchmark
 * @{
 * @addtogroup main
 * @{
 *
 */static void BM_RunFullParser(benchmark::State &state) {
    for (auto _ : state) {
        Numbers::CmdParser parser("//[,][.]\n1,2.3,4,5.6,7,8,9,10");
        parser.add();
    }
}

static void BM_RunSimpleParser(benchmark::State &state) {
    for (auto _ : state) {
        Numbers::CmdParser parser("//,\n1,2,3,4,5,6,7,8,9,10");
        parser.add();
    }
}

// Register the function as a benchmark
BENCHMARK(BM_RunFullParser);
BENCHMARK(BM_RunSimpleParser);

// Run the benchmark
BENCHMARK_MAIN();

/**
 * @}
 * @}
 *
 */