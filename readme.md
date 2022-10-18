# Simple number parser

## Dependencies

1. [Google test](https://github.com/google/googletest) framework.
2. [Google benchmark](https://github.com/google/benchmark) framework

These can be installed in Linux by running sudo `sudo apt install libgtest-dev` and `sudo apt install libbenchmark-dev` respectively. On MacOS the commands are `brew install googletest` and `brew install google-benchmark`.

## Building the project

The project has been designed and tested on MacOS but should build and function correctly on Linux. If you are running Windows 10 or 11 please build this project in WSL2 using the latest Ubuntu distro.

```bash
$ git clone https://github.com/GCUGreyArea/Skywind-task.git
$ cd Skywind-task
$ make test benchmark project
$ ./build/task -n "//[.][,]\n1,2.3.4"
```

## Updating the project

If you already have the code

```bash
$ cd Skywind-task
$ git pull
$ make clean test benchmark project
$ ./build/task -n "//[.][,]\n1,2.3.4"
```

## Building and running unit tests and benchmarks

Unit tests and benchmarks are built in the standard build. Test are provided in the `test` directory and benchmarks in the `benchmark` directory. These can either be run from the command line or through the makefile.

```bash
$ ./test/build/test_task

OR

$ make test
```

```bash
$ ./benchmark/build/benchmark_task

OR

make benchmark
```

## Optional code documentation

Optional code documentation is also available through [Doxygen](https://doxygen.nl/manual/starting.html). Both `Doxygen` and `graphviz` need to be installed.

Doxygen can be [installed from source](https://doxygen.nl/manual/install.html) on either MacOS or Linux.

On Linux run `sudo apt-get install doxygen graphviz`
On MacOS run `brew install doxygen` and `brew install graphviz`


```bash
$ make docs
```

The resulting HTML pages will be available in `docs/output/html`

## BNF for valid input

```bash
Input                ::= <Start> <DelimiterList> <End> <NumberList>
Start                ::= '//'
DelimiterList        ::= <SimpleDelimiter> || <ComplexDelimiterList>
SimpleDelimiter      ::= [0-9A-Za-z\,\-\.\*\&\^\%\$\£\@\!\+]+
ComplexDelimiterList ::= '[' <SimpleDelimiter> ']' || '[' <SimpleDelimiter> ']' <ComplexDelimiterList>
End                  ::= '\n'
NumberList           ::= [0-9]+ || [0-9]+ <SimpleDelimiter> <NumberList>
```