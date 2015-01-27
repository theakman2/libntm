rmdir buildfiles /s /q
mkdir buildfiles
cd buildfiles
cmake %* ..
cd ..