https://www3.ntu.edu.sg/home/ehchua/programming/howto/EclipseCpp_HowTo.html

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
2.  Writing your First C/C++ Program in Eclipse
2.1  C++ Program

Step 0: Launch Eclipse
Start Eclipse by running "eclipse.exe" in the Eclipse installed directory.
Choose an appropriate directory for your workspace (i.e., where you would like to save your works).
If the "welcome" screen shows up, close it by clicking the "close" button.

Step 1: Create a new C++ Project
For each C++ application, you need to create a project to keep all the source codes, object files, executable files, and relevant resources.
To create a new C++ project:
Choose "File" menu ⇒ "New" ⇒ Project... ⇒ C/C++ ⇒ C++ project.
The "C++ Project" dialog pops up.
In "Project name" field, enter "FirstProject".
In "Project Types" box, select "Executable" ⇒ "Empty Project".
In "Toolchains" box, choose your compiler, e.g., "Cygwin GCC" or "MinGW GCC" ⇒ Next.
The "Select Configurations" dialog appears. Select both "Debug" and "Release" ⇒ Finish.

Step 2: Write a Hello-world C++ Program
In the "Project Explorer" (leftmost panel) ⇒ Right-click on "FirstProject" (or use the "File" menu) ⇒ New ⇒ Source File.
The "New Source File" dialog pops up.
In "Source file" field, enter "Hello.cpp".
Click "Finish".
The source file "Hello.cpp" opens on the editor panel (double-click on "test.cpp" to open if necessary). Enter the following codes:
#include <iostream>
using namespace std;
 
int main() {
   cout << "Hello, world!" << endl;
   return 0;
}
If "Unresolved Inclusion Error"
If error "unresolved inclusion" appears next to #include statement, the "include paths for headers" are not set properly. Select "Project" menu ⇒ Properties ⇒ C/C++ General ⇒ Paths and Symbols ⇒ In "Includes" tab:
For Cygwin GCC:
"Add" the following directories to "GNU C", where $CYGWIN_HOME is your Cygwin installed directory:
$CYGWIN_HOME\lib\gcc\i686-pc-cygwin\4.5.x\include
$CYGWIN_HOME\lib\gcc\i686-pc-cygwin\4.5.x\include-fixed
$CYGWIN_HOME\usr\include
$CYGWIN_HOME\usr\include\w32api
"Add" the following directories to "GNU C++", where $CYGWIN_HOME is your Cygwin installed directory:
$CYGWIN_HOME\lib\gcc\i686-pc-cygwin\4.5.x\include\c++
$CYGWIN_HOME\lib\gcc\i686-pc-cygwin\4.5.x\include\c++\i686-pc-cygwin
$CYGWIN_HOME\lib\gcc\i686-pc-cygwin\4.5.x\include\c++\backward
$CYGWIN_HOME\lib\gcc\i686-pc-cygwin\4.5.x\include
$CYGWIN_HOME\lib\gcc\i686-pc-cygwin\4.5.x\include-fixed
$CYGWIN_HOME\usr\include
$CYGWIN_HOME\usr\include\w32api

For MinGW GCC:
"Add" the following directories to "GNU C", where $MINGW_HOME is your MinGW installed directory:
$MINGW_HOME\lib\gcc\mingw32\4.6.x\include
$MINGW_HOME\include
$MINGW_HOME\lib\gcc\mingw32\4.6.x\include-fixed
"Add" the following directories to "GNU C++", where $MINGW_HOME is your Cygwin installed directory:
$MINGW_HOME\lib\gcc\mingw32\4.6.x\include\c++
$MINGW_HOME\lib\gcc\mingw32\4.6.x\include\c++\mingw32
$MINGW_HOME\lib\gcc\mingw32\4.6.x\include\c++\backward
$MINGW_HOME\lib\gcc\mingw32\4.6.x\include
$MINGW_HOME\include
$MINGW_HOME\lib\gcc\mingw32\4.6.x\include-fixed
NOTE: To find the header paths, you can do a search on headers such as "stdio.h" (for C) and "iostream" (for C++) under the Cygwin or MinGW installed directory.
Note: If you encounter "error while loading shared libraries" during link. Install "libmpfr4" in cygwin.

Step 3: Compile/Build
Right-click on the "FirstProject" (or use the "Project" menu) ⇒ choose "Build Project" to compile and link the program.

Step 4: Run
To run the program, right-click on the "FirstProject" (or anywhere on the source "test.cpp", or select the "Run" menu) ⇒ Run As ⇒ Local C/C++ Application ⇒ (If ask, choose Cygwin's gdb debugger) ⇒ The output "Hello, world!" appears on the "Console" panel.
NOTE: You need to create a new C++ project for EACH of your programming problems. This is messy for writing toy programs!
