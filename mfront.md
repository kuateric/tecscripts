## Installing MFront NEW
step 1: if not already installed 
```bat
sudo apt install libboost-python-dev gfortran
```
step 1: if already installed 
```bat
sudo apt upgrade libboost-python-dev gfortran
```

step 2: 

```bat
cd /opt/programme
```
step 3: 

```bat
mkdir mfront
```
step 4: 

```bat
cd mfront
```

step 5: 

```bat
mkdir mfront-4.1.0
```
step 6: 

```bat
cd mfront-4.1.0
```

step 7: 

```bat
git clone https://github.com/thelfer/tfel.git
```

step 8: 
```bat
mkdir build
```

step 9: 
```bat
cd build
```

step 10: 

```bat
cmake /opt/programme/mfront/mfront-4.1.0/tfel -DCMAKE_BUILD_TYPE=Release -Denable-fortran=ON -Denable-python-bindings=ON -DCMAKE_INSTALL_PREFIX=/opt/programme/mfront/mfront-4.1.0/build
```
step 11: 

```bat
make -j 2
```

step 12: 

```bat
make install
```

step 13: input for .bashrc
```bat
#export PATH="/opt/programme/mfront/mfront-4.0/build/bin:$PATH" # mfront bin
#export LD_LIBRARY_PATH="/opt/programme/mfront/mfront-4.0/build/lib:$LD_LIBRARY_PATH" # mfront lib
#export PYTHONPATH="/opt/programme/mfront/mfront-4.0/tfel/mfront/build/lib/python3.8/site-packages:$PATH" # mfront python bindings
```


## Installing Mfront 
step 1:
- Download Latest Version:
https://sourceforge.net/projects/tfel/files/ 

setp 1.1: update python
```bat
sudo env "PATH=$PATH" conda update --all
```

step 2:
- Create an mfront folder and open it
```bat
mkdir mfront
cd mfront
```
- Create an sources folder in the mfront folder and open it
```bat
mkdir sources
cd sources
```
- copy and unzip the mfront source file in the mfront folder 

- Create a build repository in the mfront folder 
```bat
cd ..
mkdir build
cd build
```
step 3: 
```bat
sudo apt install libboost-python-dev
```
step 4: 
```bat
cmake /home/tux/programs/mfront/sources/tfel-3.4.0 -DCMAKE_BUILD_TYPE=Release -Denable-fortran=ON -Denable-python-bindings=ON -DCMAKE_INSTALL_PREFIX=/home/tux/programs/mfront/build
```
for me:
```bat
cmake /home/eric/sources/mfront/tfel-3.4.2/source -DCMAKE_BUILD_TYPE=Release -Denable-fortran=ON -Denable-python-bindings=ON -DCMAKE_INSTALL_PREFIX=/home/eric/sources/mfront/tfel-3.4.2/build
```

step 5:
```bat
make -j 2
```
step 6:
```bat
make install
```
step 7: 
```bat
cd /home
gedit .bashrc
```
add in `.bashrc` at the end of the file:

```bat
export PATH="/home/tux/programs/mfront/build/bin:$PATH" # mfront bin
export LD_LIBRARY_PATH="/home/tux/programs/mfront/build/lib:$LD_LIBRARY_PATH" # mfront lib
export PYTHONPATH="/home/tux/programs/mfront/build/lib/python3.8/site-packages:$PATH" # mfront python bindings
```
