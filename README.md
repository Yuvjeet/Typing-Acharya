# Typing Acharya

Simple CLI typing tutor (college first-year project).

Features
- Random paragraph generation from `WordBank.txt`.
- 60-second timed typing test using a background thread.
- Simple lesson viewer from the `lessons/` files.

Build

Compile with `g++` and pthread support:

```
g++ "Typing_Test.cpp" -o typing_test -pthread
```

Run

Place `WordBank.txt` and the `lessons/` folder in the same directory, then:

```
./typing_test
```

Notes
- The program is a simple educational project. It uses POSIX `termios` for single-character input and POSIX threads for the timer.
- No compiled binaries are included in the repository; use the compile command above to build locally.

Suggested improvements
- Add a small Makefile, add command-line options for test duration, and refactor UI for portability.

Enjoy!
