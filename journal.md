# clox journal
## Chapter 14 - Chucnks of Bytecode
### 14.3 - Chunks of Instructions
#### 14.x.x - *ByteCode*
Hva er bytecode igjen?
#### 14.3.1 - A dynamic array of instructions
Dynamiske lister i C er fine av følgende grunner
 - Det går veldig raskt å legge til et nytt element (constant time)
 - Det går veldig raskt å finne et element (constant time)
 - De spiller fint med buffer
 
 ### 14.4 - Disassembling Chunks
 En *disassembler* tar maskinkode og oversetter det til en tekstlig
 liste med instruksjoner, så den går i motsatt retning av en
 *assembler*.
 
 ### 14.5 - Constants
 #### 14.5.1 - Representing Values
 Det fine med denne koden
 
 ```c
 typedef double Value
 ```
 
 er at det abstraherer bort hvordan vi representerer tall i 
 clox. Vi kan forandre denne til å være `int` uten at det vil
 ødelegge noe.

