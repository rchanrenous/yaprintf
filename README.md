# yaprintf: Yet Another Printf tester

## Introduction

`yaprintf` is a tester for the `ft_printf` project.

Tests compare both the printing and the return values of the `ft_printf` function to the original `printf` function.

`yaprintf` contains tests for the mandatory part.\
Most importantly, `yaprintf` contains thorough tests for the bonus part.\
Finally `yaprintf` can also test another feature of the `printf` function, the positional argument selection, which is non-required by the subject (neither in the mandatory and bonus parts).

## Tests

Clone the project at the root of the `ft_printf` project (where the `libfprintf.a` library should be built) and `cd` into `yaprintf`:
```
git clone git@github.com:rchanrenous/yaprintf.git
cd yaprintf
```

`make` will build the `ft_printf` project and test the mandatory part.\
`make bonus` will additionally test the bonus part.\
`make extra` will build the `ft_printf` project and test a non-required extra feature: positional argument selection, eg. `"%1$\*1$.\*d"` format strings (`man 3 printf`)