# tecscripts
## Installing OpenGeoSys
Summary, 
to install OGS with MKL:
 
step 1:
```bat
git clone https://gitlab.opengeosys.org/ogs/ogs.git
```
step 2: 
```bat
mkdir build
cd build
```
step 3: 
```bat
cmake -DMKL_DIR=/usr/include/mkl -DOGS_USE_MKL=ON -DOGS_USE_MFRONT=ON -DCMAKE_BUILD_TYPE=Release ../ogs

```
step 4:
```bat
make -j 2
```

## Installing Mfront 
step 1:
- Download Latest Version:
https://sourceforge.net/projects/tfel/files/ 

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
step 5:
```bat
make -j 2
```
step 6:
```bat
make install
```

