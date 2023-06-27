const char T[]="C programming language "
"C (pronounced like the letter c) is a general - purpose computer programming language. It was created in the 1970s by Dennis Ritchie, "
"and remains very widely used and influential. By design, C's features cleanly reflect the capabilities of the targeted CPUs. "
"It has found lasting use in operating systems, device drivers, protocol stacks, though decreasingly for application software. "
"C is commonly used on computer architectures that range from the largest supercomputers to the smallest microcontrollers and embedded systems. "
"C is an imperative procedural language supporting structured programming, lexical variable scope, and recursion, with a static type system. "
"It was designed to be compiled to provide low-level access to memory and language constructs that map efficiently to machine instructions, "
"all with minimal runtime support. Despite its low-level capabilities, the language was designed to encourage cross-platform programming. "
"A standards-compliant C program written with portability in mind can be compiled for a wide variety of computer platforms and "
"operating systems with few changes to its source code.";

const int DELKA=sizeof T/sizeof T[0] -1;

const char S[]="BCDFGHJKLMNPQRSTVWXZ";

#define POCET (sizeof S/sizeof S[0] -1)   // pocet souhlasek

const int M='a'-'A';                      // pro male souhlasky

