If install from existing Eclipse > Help > Install New Software... Work with: [Add...] button
Location: http://download.eclipse.org/tools/cdt/releases/9.2

download and install MSYS2 from https://msys2.github.io/
Go to MinGW shell
(This is a once only operation until new installers are released) update the package database and pacman with:
pacman -Sy pacman
If needed, close MSYS2, run it again from Start menu. Update the rest with: Update the package database and core system packages with:
pacman -Syu
Again, if needed, close MSYS2, run it again from Start menu. Update the rest with:
pacman -Su

Go to MinGW 64 Shell
(this command is to get and install gcc) 
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb mingw-w64-x86_64-pkg-config pkg-config
After verify gcc by: g++ --version

Windows ENV variable:
MINGW_HOME=C:\msys64\mingw64

Project properties
C/C++ Build > Setting > Dialect = -std=c++14

Here the additonal rough steps in case necessary:
I added to my PATH the folders C:\Gnu\mingw64 
and C:\Gnu\usr\bin because if I remember correctly, CDT was complaining that gcc command was not found. 
This is from I read, not recommended by everyone, not sure why thought.

In Eclipse CDT preferences (Windows > Preferences > C/C++ > Build > Environment), 
set a variable MINGW_HOME to /mingw64 mount point location (in my case, path is C:\Gnu\mingw64).
Restart Eclipse. 

Normally, that should be enough. When starting Eclipse, CDT should discover the mingw64 toolchain.
If that does not work out of the box, there is two places to play with some settings:
Windows > Preferences > C/C++ > Build > Settings (Discovery Tab)
You can try to clear entries and reset buttons on the CDT GCC Built-in Compile Settings MinGW.
Project Properties > C/C++ General > Preprocessor Include Paths, Macros, Etc.
In providers tab, you can try to disable all providers except CDT GCC Built-in Compile Settings MinGW, 
CDT User Settings Entries and CDT Manager Build Setting Entries
After each try, rebuild CDT index by right-clicking on project and then select Index > Rebuild.

Project properties:
C/C++ Build > Setting > Dialect = -std=c++14
C/C++ Build > Environment
MSYS_HOME = C:\msys64
PATH = ${MINGW_HOME}\bin;${MSYS_HOME}\bin;${MSYS_HOME}\usr\bin;
C/C++ Tool Chain Editor > Current toolchain: MinGW GCC