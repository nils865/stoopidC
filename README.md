
# stoopidC

The stoopid programing language rewritten in C

---

## Roadmap

### Rewrite Roadmap

- [X] **Lexer** to divide Words into Categries
- [X] **Parser** for validating Grammar of Statements
- [ ] Implement System for **Variables**
- [ ] Implement a **Reverse Polish Notation** Calculator
- [ ] Universal **Calculator** for Numbers, Strings and Bools
- [ ] **Complete the Rewrite**
- [ ] Add a **simple creation tool** for **new keywords**
- [ ] Finally Merge with Main

### Future

- [ ] Add functionality of Python Stoopid
- [ ] Finish the language for 1.0 Build

---

## How to Use

You can use the interpreter by running the command `stoopid <filename>`

## Build Instructions

Requirements:

- G++
- make
- python3

`make compile` only compiles files that changed since the last compile

`make compile-all` compiles all files

`make run` runs a debug script

if there is an error please change the `python` variable in `makefile` to the command that runs python on your system, try changing it from `python3` to `python`

NOTE: mingw comes with make, its just named mingw32-make, so if you are using mingw just run `mingw32-make` instead of `make`

## Guide

### ⚠️ WARNING this Guide is outdated for this Version of the Branch, Proper Guide will follow before Merge with Main

| Keyword | Description | Syntax |
| ------- | ----------- | ------ |
| var | Defines a variable | `var : <name> = <value>` |
| out | Prints something to the output | `out : <value>` |
| goto | Sets the next line to be read by the Interpreter | `goto : <linenumber>` |
| sleep | Pauses the execution | `sleep : <ms>`
| end | Ends the programm | `end` |

### String

Strings can be combined with `+`

ints, bools and variables can also be combined with strings

### Math

Math equasions can be used anywhere

All standart operators can be used as well as `%` for modulo and `^` to get the power of something

Math equasions also support brackets

### Bools

Booleans are also completely implemented although they work different than in other languages

| Comparator | Description |
| ---------- | ----------- |
| `<<` | less than |
| `>>` | greater than |
| `<=` | less or equal |
| `>=` | greater or equal |
| `==` | equal |
| `!=` | not equal |
| `&&` | and |
| `\|\|` | or |
| `!` | not |

### Comments

Comments always need their own line and can be used by starting with `#`

Example: `# This is a comment`
