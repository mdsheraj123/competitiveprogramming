# competitiveprogramming
C++17 Competitive Programming setup using CMake.

Tested on Windows 10 and Intel Mac. Use VS Code.

Install<br/>
https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack<br/>
Which should also include<br/>
https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools

Ensure you have cmake installed on your system. On mac try<br/>
brew install cmake<br/>

On VSCode open this CMake folder directly or else the folder structure will be incorrect.<br/>

**Windows:**<br/>
CMake: Run Without Debugging (Shift+F5) for build and run.<br/>
CMake: Debug (Ctrl+F5) for debug.<br/>
To format a selection: Ctrl+A, Ctrl+K, Ctrl+F<br/>

**Mac:**<br/>
CMake: Run Without Debugging (Right shift+fn+F5) for build and run.<br/>
CMake: Debug (control+fn+F5) for debug.<br/>
To format a selection: CMD ⌘+A, CMD ⌘+K, CMD ⌘+F<br/>

<hr />

It is possible to run CTest via bottom navigation bar.

<hr />

For interactive tests of Google Code Jam, run on terminal<br/>
C:\Coding\competitiveprogramming\CMake>python interactive/interactive_runner.py python3 interactive/local_testing_tool.py 0 -- build/cp.exe
