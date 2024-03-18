# CLAB

## Compiled vs Interpreted Languages

* Compiled programming languages take high-level source code and translates this code to machine code, which allows portability across different platforms as long as a compiler specific to the target platforms are used

* Interpreted languages execute source code line by line, which allows for rapid development of programs

## Compiler AND Interpreter: A Soapbox
 
*CLAB* is inspired by the popular MATLAB program (short for "Matrix Laboratory"), heavily used in the science and engineering industries. MATLAB is a fully self-contained program, including a command line interpreter, source code editor, and runtime environment. The key drawback of using MATLAB, however, is that any target computer intended to run MATLAB code/files must have the MATLAB program installed, as it is this environment that interprets and executes MATLAB source code.

Compiled languages, such as C++, bypasses this dependency by directly translating source code to machine code, and the target computer executes this machine code. The executable file can be created and shared to as many machines as necessary, assuming the executable was compiled to the compatible platform (for example, you might download an .exe file from the web to run on your Windows machine, which works because you and the author have the same underlying computer architecture... and Microsoft goes through a lot of pain to keep Windows backwards compatible). Different target platforms (Windows, Linux, macOS, etc.) require a specific compiler for each platform, as the machine code will have different conventions/libraries for the different platforms. This allows for a modular approach, such that the same source code can be compiled to different target platforms, as long as system library standards are adhered to. 

The drawback to this is that development of the source code requires compilation and execution of the entire program every time. This is not a problem for many beginner programs with maybe a few hundred lines of code, but very quickly can become cumbersome when you find a typo after compiling a large codebase, and need to take time to recompile and test your fixes. Debuggers inject hooks into the final executable that allow for inspection of the code execution at runtime, but at the end of the day, the program must be compiled every time, and if you make a change, there is nothing you can do but recompile again.

So... what? Well, simply put, I find this annoying. Coming from MATLAB and learning C++, this was the biggest painpoint for me. Let's say I write a lengthy algorithm, and I'm getting output that doesn't make sense. Naturally, I would debug it by setting a breakpoint and stepping through the code. Ok, I found *something* that doesn't look quite right. So, I go ahead and fix it. I recompile, and... still broken. Doing this over and over again, with no way to quickly test my ammended statements in real-time before recompiling was just a headache that interpreted languages don't have -- I could have a program paused and just run a quick statement for a sanity check in the interpreter, and tweak it as many times as I need to in order to get the right set of statements. No recompiles.

So I thought something like that should exist for those of us not used to building compiled programs or are just starting out with C++, and try to strip away as much of the unnecessarily development headaches that come with writing it.

The goal of *CLAB* (short for "C++ Laboratory") is to marry the strengths of the MATLAB environment and the strengths of using C++ for its speed and portability, and to minimize the drawbacks of each. 

The key strength of C++ that this program intends to adopt is the ability to compile to a portable executable that is independent of the *CLAB* environment. When you build a program that you write in C++, you get a true binary executable just like if you had built it using a more mainstream compiler (in fact, *CLAB* uses mainstream compilers under the hood). If you build it on Windows, you're getting a Windows executable. If you target your build for Arduino, you're getting an Arduino executable, etc.

The key strength of MATLAB that this program intends to adopt is the ease of use during development and debugging of programs, such as the execution of individual C++ statements, and the ability to inspect, manipulate, and modify data during debugging at runtime, all from within the GUI application. It still has to be *valid* C++ syntax, but if you write `int dummy = 0; dummy += 5;` in the interpreter, you will see `dummy` in your workspace variables, with the value of `5`. If you write `std::cout << "Hi Mom!";` your terminal will display "Hi Mom!". The whole goal here is to remove as many barriers to entry for people to play with C++, and hopefully in turn *get better* at using C++.

## Dependencies

This application requires wxWidgets to build. You can find install and build instructions here: https://wiki.wxwidgets.org/Compiling_and_getting_started

If you are not familiar, the magic of wxWidgets is that it uses your system's built-in graphics APIs. So, building wxWidgets and the app locally will give you a *native* GUI. It is a C++ wrapper for native system APIs, so your code will be mostly portable (edge cases might not be supported). You can clone this repo, and as long as you have wxWidgets installed and your build system setup to point to the locally built libraries, it will give you a native GUI window.