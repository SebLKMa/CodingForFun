This is just a fun coding as a therapeutic remedy from daily grind.

To run this program from command line:
Go to directory ..\cppWordCount\Debug
Then execute 
   cppWordCount <filename>

Test data files are available in the directory ..\cppWordCount\TestData

E.g. cppWordCount C:\Temp\fun\cppWordCount\TestData\2489.txt


This program is built using Eclipse C/C++ Development Tool.

1.  How to Install Eclipse C/C++ Development Tool (CDT) 8.1.2 for Eclipse 4.2.2 (Juno)
Step 0: Install MinGW GCC or Cygwin GCC
To use Eclipse for C/C++ programming, you need a C/C++ compiler. On Windows, you could install either MinGW GCC or Cygwin GCC. Choose MinGW if you are not sure, because MinGW is lighter and easier to install, but having less features.
MinGW GCC: Read "How to Install MinGW".
Cygwin GCC: Read "How to Install Cygwin". Make sure that you select "gcc", "g++", "gdb", and "make" packages under the "Devel" (Development) category - these packages are not part of the default installation.

Step 1: Install Eclipse C/C++ Development Tool (CDT)
Two ways to install CDT, depending on whether you have previously installed an Eclipse:
If you have already installed "Eclipse for Java Developers" or other Eclipse packages, you could install the CDT plug-in as follows:
Launch Eclipse ⇒ Help ⇒ Install New Software ⇒ In "Work with" field, pull down the drop-down menu and select "Kepler - http://download.eclipse.org/releases/kepler" (or juno for Eclipse 4.2; or helios for Eclipse 3.7).
In "Name" box, expand "Programming Language" node ⇒ Check "C/C++ Development Tools" ⇒ "Next" ⇒ ... ⇒ "Finish".
If you have not install any Eclipse package, you could download "Eclipse IDE for C/C++ Developers" from http://www.eclipse.org/downloads, and unzip the downloaded file into a directory of your choice.

Step 2: Configuration
You do NOT need to do any configuration, as long as the Cygwin or MinGW binaries are included in the PATH environment variable. CDT searches the PATH to discover the C/C++ compilers.

==========================
IMPORTANT NOTES for C++ 11
==========================
1.Make a new C++ project
2.Default options for everything
3.Once created, right-click the project and go to "Properties"
C/C++ Build -> Settings -> Tool Settings -> GCC C++ Compiler -> Miscellaneous -> Other Flags. Put -std=c++0x (or for newer compiler version -std=c++11 at the end . ... instead of GCC C++ Compiler I have also Cygwin compiler
C/C++ General -> Paths and Symbols -> Symbols -> GNU C++. Click "Add..." and paste __GXX_EXPERIMENTAL_CXX0X__ (ensure to append and prepend two underscores) into "Name" and leave "Value" blank.
4.Hit Apply, do whatever it asks you to do, then hit OK.

