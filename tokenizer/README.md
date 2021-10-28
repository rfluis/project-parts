#C/C++ tokenizer

Handmade C/C++ tokenizer (Not done using lex or similar)
Only works on memory with STL containers.
Doesn't have hex number recognition (0xff) and other patterns.
Keywords are not hardcoded, but can be an advantage, because makes code lighter and can be implemented on other separate stage.
This code doesn't have any fault tolerancy or error recovery mechanism.

It eases the task of writing a C/C++ compiler, because the code is splitted into small recognizeable parts.

