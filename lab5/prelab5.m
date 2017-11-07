%---- P1 -----

s = tf('s');

P1 = 0.888;
P2 = 0.807;

sys1 = (1)/(s*(s^2 + 4*s + 8));
sys2 = (3456)/(s^2 + (64.8*P2 + 5)*s);

figure(1), rlocus(sys1);
title('Root Locus L1');
Zeta = 0.517;
Wn = 55.41;
sgrid(Zeta,Wn);

figure(2), rlocus(sys2);
axis([-60 10 -80 80]);
title('Root Locus L1');
Zeta = 0.517;
Wn = 55.41;
sgrid(Zeta,Wn);




