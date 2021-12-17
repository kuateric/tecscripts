### example 1
```bat
gen zone radcyl &
p0 0 0 25 p1 add 80 0 0 p2 add 0 0 -25 p3 add 0 80 0 &
dim 24.5 24.5 12 12 ratio 1 1 1 1.1
gen zone radcyl &
p0 0 0 0 p1 add 80 0 0 p2 add 0 0 -15 p3 add 0 80 0 &
dim 12 12 12 12 ratio 1 1 1 1.1 fill size 5 7 10 10
gen zone brick &
p0 0 -40 -15 p1 add 12 0 0 p2 add 0 40 0 p3 add 0 0 15 &
size 5 12 7
gen zone brick &
p0 12 -40 -15 p1 add 68 0 0 p2 add 0 40 0 p3 add 0 0 15 &
size 10 12 7 ratio 1.1 1 1
gen zone brick &
p0 12 -40 0 p1 add 68 0 0 p2 add 0 40 0 p3 add 12.5 0 25 &
p4 add 68 40 0 p5 add 12.5 40 25 p6 add 68 0 25 p7 add 68 40 25 &
size 10 12 10 rat 1.1 1 1
```
![grafik](https://user-images.githubusercontent.com/22998049/146570520-fd6416c9-9258-4e1c-a442-cdf22c9f628f.png)

### example 2
```bat
define parm
global rat1 = 1.14
global rat_1 = 1.0/rat1
end
@parm
gen zon cylint p1 7.5 0 0 p2 0 7.5 0 p3 0 0 4.75 dim 2 2 2 2 2 2 &
size 6 6 6 6 6 ratio @rat1 @rat1 1 @rat1
group zone cylint
gen zon radcyl p0 13 0 0 p1 13 4.75 0 p2 7.5 0 0 p3 13 0 4.75 &
p4 7.5 4.75 0 p5 7.5 0 4.75 p6 13 3.75 4.75 p7 7.5 3.75 4.75 &
dim 2 2 2 2 size 1 3 6 6 rat 1 .8 1 @rat1
group zone radcyl range group cylint not
gen zon brick p0 13 4.75 0 p1 13 7.5 0 p2 7.5 4.75 0 p3 13 3.75 4.75 &
p4 7.5 7.5 0 p5 7.5 3.75 4.75 p6 13 7.5 4.75 p7 7.5 7.5 4.75 &
size 6 3 3 rat @rat1 .8 1
group zone brick1 range group cylint not group radcyl not
gen zon radtun p0 7.5 7.5 10 p1 0 7.5 10 p2 7.5 7.5 4.75 p3 7.5 0 10 &
dim 5.5 5.5 3.75 3.75 size 6 5 6 3 rat @rat_1 0.8 @rat_1 1 fill
group zone radtun range group cylint not group radcyl not group brick1 not
gen zon bri p0 7.5 0 4.75 p1 13 0 4.75 p2 7.5 3.75 4.75 p3 7.5 0 10 &
p4 13 3.75 4.75 p5 7.5 2 10 p6 13 0 10 p7 13 2 10 &
size 3 3 5 rat 1.25 1 1.25
gen zon bri p0 7.5 3.75 4.75 p1 13 3.75 4.75 p2 7.5 7.5 4.75 p3 7.5 2 10 &
p4 13 7.5 4.75 p5 7.5 7.5 10 p6 13 2 10 p7 13 7.5 10 &
size 3 6 5 rat 1.25 @rat1 1.25
;lower portion of the grid
gen zon tunint p1 0 7.5 0 p2 7.5 0 0 p3 0 0 -4.75 dim 2 2 2 2 2 2 2 &
size 6 6 4 4 6 rat @rat1 @rat1 1 1 @rat1
gen zon radtun p0 13 0 0 p1 13 0 -4.75 p2 7.5 0 0 p3 13 4.75 0 &
p4 7.5 0 -4.75 p5 7.5 4.75 0 p6 13 3.75 -4.75 p7 7.5 3.75 -4.75 &
dim 2 2 2 2 size 4 3 4 6 rat 1 .8 1 @rat1
gen zon brick p0 7.5 3.75 -4.75 p1 13 3.75 -4.75 p2 7.5 7.5 -4.75 &
p3 7.5 4.75 0 p4 13 7.5 -4.75 p5 7.5 7.5 0 p6 13 4.75 0 &
p7 13 7.5 0 size 3 6 4 rat 1.25 @rat1 1
gen zon radtun p0 7.5 7.5 -4.75 p1 0 7.5 -4.75 p2 7.5 7.5 -10 &
p3 7.5 0 -4.75 dim 3.75 3.75 5 5 &
size 6 5 6 4 rat @rat_1 1.25 @rat_1 1 fill
gen zon brick p0 7.5 0 -10 p1 13 0 -10 p2 7.5 2.5 -10 p3 7.5 0 -4.75 &
p4 13 2.5 -10 p5 7.5 3.75 -4.75 p6 13 0 -4.75 p7 13 3.75 -4.75 &
size 3 4 5 rat 1.25 1 .8
gen zon bri p0 7.5 2.5 -10 p1 13 2.5 -10 p2 7.5 7.5 -10 p3 7.5 3.75 -4.75 &
p4 13 7.5 -10 p5 7.5 7.5 -4.75 p6 13 3.75 -4.75 p7 13 7.5 -4.75 &
size 3 6 5 rat 1.25 @rat1 .8
```
![grafik](https://user-images.githubusercontent.com/22998049/146571236-75ab9f18-7b00-4684-bb4a-004b7b655bad.png)

### example 3
```bat
gen zone brick p1 12 0 0 p2 0 12 0 p3 0 0 12 size 12 12 12 rat 1 1 1
group zone soil
group zone excavate range x 0 4 y 0 4 z 0 5
group zone wal1 range x 4 5 y 0 5 z 0 7
group zone wal2 range x 0 4 y 4 5 z 0 7
group zone wall range union group wal1 group wal2
```
![grafik](https://user-images.githubusercontent.com/22998049/146571615-e66c836b-a275-407d-906c-862dcdc5b2d6.png)


### example 4
```bat
; generate primitive components of grid
; concrete liner - upper tunnel
gen zon cshell p0 0 0 0 p1 7 0 0 p2 0 51 0 p3 0 0 5.5 &
dim 5 5 5 5 size 2 51 10
group zone "concrete liner"
;
; upper tunnel
gen zon cylinder p0 0 0 0 p1 5 0 0 p2 0 51 0 p3 0 0 5 &
size 5 51 10
group zone tunnel range group "concrete liner" not
;
; lower tunnel & liner
gen zone brick p0 0 0 -4.5 p1 add 7 0 0 p2 add 0 51 0 p3 add 0 0 4.5 &
size 7 51 3
;
; surrounding rock (8 primitives)
gen zon radcyl p0 0 0 0 p1 27 0 0 p2 0 51 0 p3 0 0 25 &
dim 7 5.5 7 5.5 size 5 51 10 8 rat 1 1 1 1.3
;
gen zone brick p0 7 0 -4.5 p1 27 0 -15 p2 add 0 51 0 p3 7 0 0 &
p4 27 51 -15 p5 7 51 0 p6 27 0 0 p7 27 51 0 &
size 8 51 3 ratio 1.3 1 1
;
gen zone brick p0 0 0 -15 p1 add 27 0 0 p2 add 0 51 0 p3 0 0 -4.5 &
p4 27 51 -15 p5 0 51 -4.5 p6 7 0 -4.5 p7 7 51 -4.5 &
size 7 51 8 rat 1 1 0.7692307692307692
;
gen zon brick p0 0 0 25 p1 add 27 0 0 p2 add 0 51 0 p3 add 0 0 10 &
size 5 51 2
;
gen zon bric p0 27 0 25 p1 add 17 0 0 p2 add 0 51 0 p3 add 0 0 10 & 
size 2 51 2 rat 2 1 1
;
gen zon bric p0 27 0 -15 p1 add 17 0 0 p2 add 0 51 0 p3 add 0 0 40 &
size 2 51 8 rat 2 1 1
;
gen zon bric p0 27 0 -40 p1 add 17 0 0 p2 add 0 51 0 p3 add 0 0 25 &
size 2 51 2 rat 2 1 0.5
;
gen zon bric p0 0 0 -40 p1 add 27 0 0 p2 add 0 51 0 p3 add 0 0 25 &
size 7 51 2 rat 1 1 0.5
;
; assign names to groups of zones
group zone rock range group "concrete liner" not group tunnel not
```
![grafik](https://user-images.githubusercontent.com/22998049/146572091-13d4c6b2-0ed3-42d0-9422-64ffd91e8928.png)


### example 5
```bat
define parm
  global sq2 = sqrt(2.)
end
@parm

gen zon cylint p0 0 0 0 p1 5 5 0 p2 0 10 0 p3 0 0 5 p4 5 10 0 &
               p5 0 10 5 p6 5 5 5 p7 5 10 5 dim @sq2 @sq2 1 1 1 @sq2 1 &
               fill group Tunnel

gen zon cylint p0 0 0 0 p1 0 -4 0 p2 5 5 0 p3 0 0 5 p4 5 -4 0 &
               p5 5 5 5 p6 0 -4 5 p7 5 -4 5 dim @sq2 @sq2 1 @sq2 1 1 1 &
               fill group Tunnel
gen zon radcyl p0 0 0 0 p1 0 0 5 p2 0 10 0 p3 -5 0 0 dim 1 1 1 1 &
               fill group Tunnel
gen zon radcyl p0 0 -4 0 p1 0 -4 5 p2 0 0 0 p3 -5 -4 0 dim 1 1 1 1 &
               fill group Tunnel
; for cylindrical tunnels
; gen zon ref dip 0 dd 0 ori 0 0 0
;
gen zon tunint p0 0 0 0 p1 0 10 0 p2 5 5 0 p3 0 0 -5 p4 5 10 0 &
               p5 5 5 -5 p6 0 10 -5 p7 5 10 -5 dim @sq2 @sq2 1 @sq2 1 1 1 &
               size 10 10 10 10 10 fill group Tunnel

gen zon tunint p0 0 0 0 p1 5 5 0 p2 0 -4 0 p3 0 0 -5 p4 5 -4 0 &
               p5 0 -4 -5 p6 5 5 -5 p7 5 -4 -5 dim @sq2 @sq2 1 1 1 @sq2 1 &
               size 10 10 10 10 10 fill group Tunnel

gen zon radtun p0 0 0 0 p1 -5 0 0 p2 0 10 0 p3 0 0 -5 dim 1 1 1 1 &
               size 10 10 10 10 fill group Tunnel

gen zon radtun p0 0 -4 0 p1 -5 -4 0 p2 0 0 0 p3 0 -4 -5 dim 1 1 1 1 &
               size 10 10 10 10 fill group Tunnel


title 'Intersection of tunnels based upon brick primitives' 

;
;define input_parameters   ; interactive input
;  global zcentuna   = in('Height of Center of Tunnel A :')
;  global zradtuna   = in('Radius of Tunnel A :')
;  global zcentunb   = in('Height of Center of Tunnel B :')
;  global zradtunb   = in('Radius of Tunnel B :')
;  global ff_height  = in('Far field height above crown :')
;  global ff_depth   = in('Far field depth below base :')
;  global ff_len_a   = in('Length of Tunnel A from intersection :')
;  global ff_len_b   = in('Length of Tunnel B from intersection :')
;  global zone_x_a   = in('Number of Zones for Tunnel A Width :')
;  global zone_x_b   = in('Number of Zones for Tunnel B Width :')
;  global zone_z_a   = in('Number of Zones for Tunnel A Length :')
;  global zone_z_b   = in('Number of Zones for Tunnel B Length :')
;  global zone_y_tun = in('Number of Zones for Height of Tunnels :')
;  global zone_ff_a  = in('Number of Zones above Tunnels :')
;  global zone_ff_b  = in('Number of Zones below Tunnels :')
;  global zone_rat_a = in('Zone Ratio along length of Tunnel A :')
;  global zone_rat_b = in('Zone Ratio along length of Tunnel B :')
;  global zone_rat_z = in('Zone Ratio above and below Tunnels :')
;end

define input_parameters  ; manual input
  global zcentuna   = 1.05
  global zradtuna   = 1.55
  global zcentunb   = 0.80
  global zradtunb   = 1.20
  global ff_height  = 10.0
  global ff_depth   = 5.0
  global ff_len_a   = 10.0
  global ff_len_b   = 5.0
  global zone_x_a   = 5
  global zone_x_b   = 5
  global zone_z_a   = 10
  global zone_z_b   = 5
  global zone_y_tun = 5
  global zone_ff_a  = 10
  global zone_ff_b  = 10
  global zone_rat_a = 1.2
  global zone_rat_b = 1.2
  global zone_rat_z = 1.2
end
;
;  This routine calculates the position and creates 12 bricks
;  that subdivide the tunnel intersection geometry.
;  (Three levels of four bricks)
;
define calculate_bricks
  global x0brick = 0.0
  global x1brick = zradtuna
  global x2brick = x1brick + ff_len_b
  global x3brick
  global y0brick = 0.0
  global y1brick = zradtunb
  global y2brick = y1brick + ff_len_a
  global y3brick
  global z0brick = -ff_depth
  global z1brick = 0.0
  global z2brick = zradtuna + zcentuna
  global z3brick = z2brick + ff_height
  global zone_rat_z_inv = 1.0 / zone_rat_z
  global tunb_len = 2.0 * (ff_len_b + zradtuna)
  global tunc_min = tunb_len - zradtuna
  global tunc_plus = tunb_len + zradtuna
  command                       ;; Brick 1
    gen zone brick size (@zone_x_a,@zone_x_b,@zone_y_tun) &
          p0 (@x0brick,@y0brick,@z1brick) p1(@x1brick,@y0brick,@z1brick) &
          p2 (@x0brick,@y1brick,@z1brick) p3(@x0brick,@y0brick,@z2brick) &
          group Brick_1
  end_command
  command                       ;; Brick 2
    gen zone brick size (@zone_x_a,@zone_z_a,@zone_y_tun) &
          p0 (@x0brick,@y1brick,@z1brick) p1(@x1brick,@y1brick,@z1brick) &
          p2 (@x0brick,@y2brick,@z1brick) p3(@x0brick,@y1brick,@z2brick) &
          ratio (1.0,@zone_rat_a,1.0) &
          group Brick_2
  end_command
  command                       ;; Brick 3
    gen zone brick size (@zone_z_b,@zone_x_b,@zone_y_tun) &
          p0 (@x1brick,@y0brick,@z1brick) p1(@x2brick,@y0brick,@z1brick) &
          p2 (@x1brick,@y1brick,@z1brick) p3(@x1brick,@y0brick,@z2brick) &
          ratio (@zone_rat_b,1.0,1.0) &
          group Brick_3
  end_command
  command                       ;; Brick 4
    gen zone brick size (@zone_z_b,@zone_z_a,@zone_y_tun) &
          p0 (@x1brick,@y1brick,@z1brick) p1(@x2brick,@y1brick,@z1brick) &
          p2 (@x1brick,@y2brick,@z1brick) p3(@x1brick,@y1brick,@z2brick) &
          ratio (@zone_rat_b,@zone_rat_a,1.0) &
          group Brick_4
  end_command
  command                       ;; Brick 5
    gen zone brick size (@zone_x_a,@zone_x_b,@zone_ff_a) &
          p0 (@x0brick,@y0brick,@z2brick) p1(@x1brick,@y0brick,@z2brick) &
          p2 (@x0brick,@y1brick,@z2brick) p3(@x0brick,@y0brick,@z3brick) &
          ratio (1.0,1.0,@zone_rat_z) &
          group Brick_5
  end_command
  command                       ;; Brick 6
    gen zone brick size (@zone_x_a,@zone_z_a,@zone_ff_a) &
          p0 (@x0brick,@y1brick,@z2brick) p1(@x1brick,@y1brick,@z2brick) &
          p2 (@x0brick,@y2brick,@z2brick) p3(@x0brick,@y1brick,@z3brick) &
          ratio (1.0,@zone_rat_a,@zone_rat_z) &
          group Brick_6
  end_command
  command                       ;; Brick 7
    gen zone brick size (@zone_z_b,@zone_x_b,@zone_ff_a) &
          p0 (@x1brick,@y0brick,@z2brick) p1(@x2brick,@y0brick,@z2brick) &
          p2 (@x1brick,@y1brick,@z2brick) p3(@x1brick,@y0brick,@z3brick) &
          ratio (@zone_rat_b,1.0,@zone_rat_z) &
          group Brick_7
  end_command
  command                       ;; Brick 8
    gen zone brick size (@zone_z_b,@zone_z_a,@zone_ff_a) &
          p0 (@x1brick,@y1brick,@z2brick) p1(@x2brick,@y1brick,@z2brick) &
          p2 (@x1brick,@y2brick,@z2brick) p3(@x1brick,@y1brick,@z3brick) &
          ratio (@zone_rat_b,@zone_rat_a,@zone_rat_z) &
          group Brick_8
  end_command
  command                       ;; Brick 9
    gen zone brick size (@zone_x_a,@zone_x_b,@zone_ff_b) &
          p0 (@x0brick,@y0brick,@z0brick) p1(@x1brick,@y0brick,@z0brick) &
          p2 (@x0brick,@y1brick,@z0brick) p3(@x0brick,@y0brick,@z1brick) &
          ratio (1.0,1.0,@zone_rat_z_inv) &
          group Brick_9
  end_command
  command                       ;; Brick 10
    gen zone brick size (@zone_x_a,@zone_z_a,@zone_ff_b) &
          p0 (@x0brick,@y1brick,@z0brick) p1(@x1brick,@y1brick,@z0brick) &
          p2 (@x0brick,@y2brick,@z0brick) p3(@x0brick,@y1brick,@z1brick) &
          ratio (1.0,@zone_rat_a,@zone_rat_z_inv) &
          group Brick_10
  end_command
  command                       ;; Brick 11
    gen zone brick size (@zone_z_b,@zone_x_b,@zone_ff_b) &
          p0 (@x1brick,@y0brick,@z0brick) p1(@x2brick,@y0brick,@z0brick) &
          p2 (@x1brick,@y1brick,@z0brick) p3(@x1brick,@y0brick,@z1brick) &
          ratio (@zone_rat_b,1.0,@zone_rat_z_inv) &
          group Brick_11
  end_command
  command                       ;; Brick 12
    gen zone brick size (@zone_z_b,@zone_z_a,@zone_ff_b) &
          p0 (@x1brick,@y1brick,@z0brick) p1(@x2brick,@y1brick,@z0brick) &
          p2 (@x1brick,@y2brick,@z0brick) p3(@x1brick,@y1brick,@z1brick) &
          ratio (@zone_rat_b,@zone_rat_a,@zone_rat_z_inv) &
          group Brick_12
  end_command
end

set logfile tunint.log
set log on
@input_parameters
set log off

@calculate_bricks

save tunint1

call shape.fis

save tunint2

; Reflects the geometry across symmetry planes

define reflect_tunnels
 command
   gen zone reflect normal (1,0,0) origin (0,0,0)
 end_command
 x3brick = x2brick * 2.0
 command
  gen zone reflect normal (1,0,0) origin (@x2brick,0,0)
 end_command
; NOTE! Final reflection is commented out.  Use if reflecting
;       model about x-z plane
  y3brick = -y2brick
  command
    gen zone reflect normal (0,1,0) origin (0,0,0)
  end_command
end
@reflect_tunnels

; Build some convenient named ranges
group zone TunA range union group Brick_1 group Brick_2
group zone TunB range group Brick_3 x 0 @tunb_len
group zone TunC range group TunA    x @tunc_min @tunc_plus

```
![grafik](https://user-images.githubusercontent.com/22998049/146572966-8f0e6e6a-f367-4bd7-a11f-f82157bbca2d.png)
![grafik](https://user-images.githubusercontent.com/22998049/146573133-9a54d3dc-74ed-4007-887e-18e5700879d1.png)

### example 5
```bat
; create model (quarter-symmetry)
gen zone radcyl size 8 12 6 12 rat 1.0 1.0 1.0 1.2 fill &
p2 0 0 0 p4 250 0 0 p5 0 250 0 p7 250 250 0 &
p0 0 0 45 p1 250 0 45 p3 0 250 45 p6 250 250 45 &
p10 45 0 0 p11 0 45 0 &
p8 45 0 45 p9 0 45 45
;
gen zone radcyl size 8 8 6 12 rat 1.0 1.2 1.0 1.2 fill &
p0 0 0 45 p3 250 0 45 p1 0 250 45 p6 250 250 45 &
p2 0 0 250 p5 250 0 250 p4 0 250 250 p7 250 250 250 &
p10 0 45 250 p11 45 0 250 &
p8 0 45 45 p9 45 0 45
;
; define four groups
group zone salt range z 0 30
group zone cavern range cyl end1 0 0 0 end2 0 0 15 rad 45
group zone mat2 range z 30 45
group zone mat3 range z 45 250
```
![grafik](https://user-images.githubusercontent.com/22998049/146573550-9cb1f6cb-b672-490a-a281-75789369a810.png)


