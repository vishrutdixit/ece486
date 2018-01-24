close all

A = [ 0 -1 2/3 ; -1 -2 1 ; 0 -3 1 ]
C = [0 1 0]
B = [ 1 ; 2 ; 3 ]
I = eye(3)
s = sym('s');

out = C*inv(I*s-A)*B

a = [ -1 0 0 ; 2 1 3 ; -1 -1 -2 ]
a*a
