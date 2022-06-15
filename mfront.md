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
step 13: 
```bat
cd /home
gedit .bashrc
```

step 14: input for .bashrc
```bat

########################################################################
### UNTERNEHMEN-STANDARD - auf allen TEC-Rechnern gleich - bitte benuetzen
########################################################################
### mfront stand alone 
export PATH="/opt/programme/mfront/mfront-4.1.0/build/bin:$PATH" # mfront bin
export LD_LIBRARY_PATH="/opt/programme/mfront/mfront-4.1.0/build/lib:$LD_LIBRARY_PATH" # mfront lib
export PYTHONPATH="/opt/programme/mfront/mfront-4.1.0/tfel/mfront/build/lib/python3.8/site-packages:$PATH" # mfront python bindings
```

