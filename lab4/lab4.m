K_tach = .0304

Vi = transpose([5 6 7 8 9 10 11 12 -5 -6 -7 -8 -9 -10 -11 -12]);

ia = transpose([.309 .315 .327 .339 .358 .367 .391 .412 -.311 -.318 -.334 -.348 -.366 -.381 -.399 -.4216]);
V_tach = transpose([2.029 2.517 3.106 3.64 4.176 4.702 5.23 5.766 -1.986 -2.534 -3.067 -3.599 -4.12 -4.668 -5.188 -5.718]);

w = V_tach / K_tach

x_val = ([ia,w]\Vi)

Ra = x_val(1)
Kv = x_val(2)

frictional_force = K_tach*ia

% positive b, c calculations
coeffs = polyfit(w(1:8), frictional_force(1:8), 1)
b_pos = coeffs(1)
c_pos = coeffs(2)

% negative b, c calculations\
coeffs = polyfit(w(9:16), frictional_force(9:16), 1)
b_neg = coeffs(1)
c_neg = coeffs(2)
