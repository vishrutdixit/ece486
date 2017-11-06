s = tf('s');
sys1 = (s^2 + 2*s + 2)/(s^2 -2*s + 2);

sys2c = (s+1.76)/((s+10)*(s^2-1));

sys2h = (33*s+58)/(s^3+10*s^2+32*s+48);

sys2j = (33*(s^2+1.7862*s+.06335))/(s^4+10.01*s^3-33.9*s^2-68.9546*s-2.19)

step(sys2j);

sys2l = (s+1.76)/((s+10)*(s^2-1))*(s+.1)/(s+.01);

sys3 = 1/(s^2+.5*s+1);

sys4a = (s+10)/(s*(s+5));

sys4b = 8*s/(s^2+0.2*s+4);

sys4c = (s^2+.1*s+1)/(s*(s+0.2)*(s+4));

grid on
%rlocus(sys2l);
step(sys2l)