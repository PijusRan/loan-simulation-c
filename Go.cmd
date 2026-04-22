if .%USERDOMAIN% == .Pijus goto :savasPC
Rem MIF kompiuteris
path C:\PROGRA~2\Dev-Cpp\MinGW64\bin\;%path%
mingw32-make.exe
goto :toliau

:savasPC
make

:toliau
main.exe > result0.txt

echo 10000 12 0.05 0.25 >> test1.cfg
echo 1200 2 0.08 0.25 >> test1.cfg
echo 20 1 0.30 0.40 >> test1.cfg

main.exe test1.cfg > result1.txt