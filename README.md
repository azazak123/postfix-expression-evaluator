# Postfix expression evaluator

Using postfix notation, infix expression `(2 + 3) * 10` can be written as `23 + 10 *`

This program can evaluate such expressions, and do some additional operations.

## Operation list

- Evaluation
- Saving into a specified file
- Reading from a specified file
- Clearing evaluator memory
- Showing evaluator memory
- Evaluation using the last numbers in memory

## Build

To build using CMake:

```shell
mkdir build
cd build
cmake ..
make
```

Or using Nix:

```shell
nix build
```
