https://www.youtube.com/watch?v=DIw02CaEusY

1. MINGGW

http://www.mingw.org/

Download mingw-get-setup.exe

After installing minggw, set your env path e.g. C:\bin\MinGW\bin

2. Set include paths
Edit c_cpp_properties.json (using the bulb bubble, or look for it in Ctrl-P and > )
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:\\bin\\MinGW\\lib\\gcc\\mingw32\\6.3.0\\include\\c++"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "windowsSdkVersion": "8.1",
            "compilerPath": "C:\\bin\\MinGW\\bin\\g++.exe",
            "cStandard": "c11",
            "cppStandard": "c++17",
            "intelliSenseMode": "gcc-x64"
        }
    ],
    "version": 4
}

3. Create build task
TASK (Ctrl-P, >, Tasks, Configure tasks, Create Task from template, Others )
Edit tasks.json
{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "label": "echo",
            "type": "shell",
            "command": "g++",
            "args": [
                "-g",  "-o", "hello.exe", "hello.cpp"
            ], 
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}

4. Build
Ctrl-Sift-B to build

5. DEBUG
From left menu, click on DEBUG option.
Click the green run arrow, select C++(GDB/LLDB)

Edit launch.json , 
set "miDebuggerPath": "C:\\bin\\MinGW\\bin\\gdb.exe",
set "preLaunchTask": "mybuildtask", (refer to "label" in task.json)
set "program": "${workspaceFolder}/hello.exe",

