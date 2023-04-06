
# a1CalcFunctions

A hub of my own personal functions for solving Algebra problems to be used on repetitive IXLs that I don't want to do myself

## Compiling
```g++ main.cpp include/quadratic.cpp -o a1CalcFunctions -l ncurses```

**If you have errors like this:**
- "symbol(s) not found for architecture"

Try this command: ```g++ main.cpp include/quadratic.cpp -o a1CalcFunctions -I/include/path/to/ncurses -L/lib/path/to/ncurses -lncurses```

**For example, your paths may be like this for macOS on x86_64 using homebrew:**
- -I/usr/local/Cellar/ncurses/6.4/include
- -L/usr/local/Cellar/ncurses/6.4/lib
