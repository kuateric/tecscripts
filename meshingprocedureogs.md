
## Meshing procedure for OGS simulations
This was tested for 2D-meshes. No warranty for 3D-meshes. 

1. mesh your model with linear element
2. convert if necessary with meshio: 
```bat 
meshio-convert youmesh.msh yourmesh.vtu 
```
3. extract boundaries in paraview:
 
![image](https://user-images.githubusercontent.com/22998049/122689155-f2400380-d220-11eb-91c7-e6c8266274bc.png)

4. convert bulk and boundary mesh into quadratic mesh ( do it for each mesh):
```bat
createQuadraticMesh -i tunnel_inner_linear.vtu -o tunnel_inner.vtu
[2021-06-18 19:24:27.041] [ogs] [info] Create a quadratic order mesh
[2021-06-18 19:24:27.048] [ogs] [info] Save the new mesh into a file

```

5. use identifysubdomain to connect bulk and boundary meshes ( do it for each boundary mesh):
```bat
identifySubdomains -m bulkmesh.vtu  -s 1e-6 -- boundarymesh.vtu
identifySubdomains -m tunnel.vtu  -s 1e-6 -- tunnel_left.vtu

```
if it does not work, increae the s-number for example: `1e-4`

summary: 

```bat
(base) path/to/working/directory$ gmsh tunnel_eric.geo 
(base) path/to/working/directory$ meshio-convert tunnel_eric.msh tunnel_linear.vtu
(base) path/to/working/directory$ paraview tunnel_linear.vtu 
(base) path/to/working/directory$ createQuadraticMesh -i tunnel_linear.vtu -o tunnel.vtu
[2021-06-20 13:41:58.539] [ogs] [info] Create a quadratic order mesh
[2021-06-20 13:42:01.511] [ogs] [info] Save the new mesh into a file
(base) path/to/working/directory$ createQuadraticMesh -i tunnel_top_linear.vtu -o tunnel_top.vtu
[2021-06-20 13:42:14.466] [ogs] [info] Create a quadratic order mesh
[2021-06-20 13:42:14.468] [ogs] [info] Save the new mesh into a file
(base) path/to/working/directory$ createQuadraticMesh -i tunnel_bottom_linear.vtu -o tunnel_bottom.vtu
[2021-06-20 13:42:28.727] [ogs] [info] Create a quadratic order mesh
[2021-06-20 13:42:28.729] [ogs] [info] Save the new mesh into a file
(base) path/to/working/directory$ createQuadraticMesh -i tunnel_left_linear.vtu -o tunnel_left.vtu
[2021-06-20 13:42:40.694] [ogs] [info] Create a quadratic order mesh
[2021-06-20 13:42:40.696] [ogs] [info] Save the new mesh into a file
(base) path/to/working/directory$ createQuadraticMesh -i tunnel_right_linear.vtu -o tunnel_right.vtu
[2021-06-20 13:43:09.612] [ogs] [info] Create a quadratic order mesh
[2021-06-20 13:43:09.614] [ogs] [info] Save the new mesh into a file
(base) path/to/working/directory$ createQuadraticMesh -i tunnel_inner_linear.vtu -o tunnel_inner.vtu
[2021-06-20 13:43:20.486] [ogs] [info] Create a quadratic order mesh
[2021-06-20 13:43:20.493] [ogs] [info] Save the new mesh into a file
(base) path/to/working/directory$ identifySubdomains -m tunnel.vtu -s 1e-6 -- tunnel_inner.vtu 
(base) path/to/working/directory$ identifySubdomains -m tunnel.vtu -s 1e-4 -- tunnel_top.vtu 
(base) path/to/working/directory$ identifySubdomains -m tunnel.vtu -s 1e-4 -- tunnel_bottom.vtu 
(base) path/to/working/directory$ identifySubdomains -m tunnel.vtu -s 1e-4 -- tunnel_left.vtu 
(base) path/to/working/directory$ identifySubdomains -m tunnel.vtu -s 1e-4 -- tunnel_right.vtu 


```
