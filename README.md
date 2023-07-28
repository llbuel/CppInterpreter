# CLAB

## Compiled vs Interpreted Languages

* Compiled programming languages take high-level source code and translates this code to machine code, which allows portability across different platforms as long as a compiler specific to the target platforms are used

* Interpreted languages execute source code line by line, which allows for rapid development of programs

## Compiler AND Interpreter?!
 
CLAB is inspired by the popular MATLAB program, heavily used in the science and engineering industries. MATLAB is a fully self-contained program, including a command line interpreter, source code editor, and runtime environment. The key drawback of using MATLAB, however, is that any target computer intended to run MATLAB code/files must have the MATLAB program installed, as it is this environment that interprets and executes MATLAB source code.

Compiled languages, such as C++, bypasses this dependency by directly translating source code to machine code, and the target computer executes this machine code. The executable file can be created and shared to as many machines as necessary, assuming the executable was compiled to the compatible platform. Different target platforms (Windows, Linux, macOS, etc.) require a specialized compiler for each platform, as the machine code will have different conventions for the different platforms. This allows for a modular approach, such that the same source code can be compiled to different target platforms. The drawback to this is in development of the source code requires compilation and execution of the entire program every time. Debuggers inject hooks into the final executable that allow for inspection of the code execution at runtime, but at the end of the day, the program must be compiled every time.

The goal of CLAB (short for "C++ Laboratory") is to marry the strengths of the MATLAB environment and the strengths of using C++ as a compiled language, and to minimize the drawbacks of each. 

The key strength of C++ that this program intends to adopt is the ability to compile to a portable executable that is independent of the CLAB environment.

The key strenght of MATLAB that this program intends to adopt is the ease of use during development and debugging of programs, such as the execution of individual C++ statements, and the ability to inspect, manipulate, and modify data during debugging at runtime, all from within the GUI application.

## Writing Compilers and Interpreters

The architecture and design of this program is derived from the Pascal interpreter implemented in Java as developed by Ronald Mak in his book "Writing Compilers and Interpreters". The program was converted from Java to C++, and developed to interpret and interact with C++ programs.