
open a terminal with:

```bat
Ctrl+Alt+T
```



open the .bashrc-file 

```bat
gedit .bashrc
```

write at the end of the file:

```bat
########################################################################
### UNTERNEHMEN-STANDARD - in allen TEC-Rechner gleich - bitte benuetzen
########################################################################
### mfront stand alone 
export PATH="/opt/programme/mfront/mfront-4.1.0/build/bin:$PATH" # mfront bin
export LD_LIBRARY_PATH="/opt/programme/mfront/mfront-4.1.0/build/lib:$LD_LIBRARY_PATH" # mfront lib
export PYTHONPATH="/opt/programme/mfront/mfront-4.1.0/tfel/mfront/build/lib/python3.8/site-packages:$PATH" # mfront python bindings
### OpenGeoSys
export LD_LIBRARY_PATH="/opt/programme/opengeosys/ogs-6.4.2.1/build/lib:$LD_LIBRARY_PATH"
export PATH="/opt/programme/opengeosys/ogs-6.4.2.1/build/bin:$PATH"
source /opt/intel/oneapi/setvars.sh intel64
```
