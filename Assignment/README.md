# math
## performs bitwise arithmetic on two signed integers

### Author
John McAvoy

### Last Updated
10 Sep 2018

### Files
* [math.h](./math.h)
* [math.c](./math.c)
* [test_cli.c](./test_cli.c)

### Building
Execute the build script to compile the cli testbench
`$ ./build.sh`

### Running the cli testbench
After building, run
`$ ./bin/math`

The cli takes three args: `lhs integer`, `operator character`, and `rhs integer` and runs the [math::math()](./math.c) function.

#### Usage
```
math [<lhs>:integer] [<op>:operator] [<rhs>:integer]
        integers:
                binary:  ex: 0b1, 0b10, 0b1101, ...
                decimal: ex: 1, 7, -99, ...
                hex:     ex: 0x1, 0x1f, 0xfffffa4f, ...
        operators:
                +, -, *, /, %, <, >, &, |, ^, ~
```
#### Examples
* Decimal integers
```
$ bin/math 1 + 2
    Dec:    1          + 2          = 3
    Hex:    0x1        + 0x2        = 0x3
```

* Also works with binary and hex integers too
```
$ bin/math 0xf3 '<' 0b1001
    Dec:    243        < 9          = 124416
    Hex:    0xf3       < 0x9        = 0x1e600
```
