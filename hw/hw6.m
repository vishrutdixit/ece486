s = tf('s');
T = .1;
sys1app = (1-T*s/2)/(1+T*s/2);
sys1 = exp(-T*s);

K = 12;
sys2 = K/(s*(s^2+4*s+8));
sys2closed = sys2 / ( 1 + sys2 );

%sys3cont = 4*(s/.8+1)/(s/5+1)*(s+.05)/(s+.02);
sys3cont = 2*(s/.8+1)/(s/10+1)*(s+.05)/(s+.01);
sys3g = 10/((s/.2+1)*(s/.5+1));

sys3open = (sys3cont*sys3g);
sys3 = sys3cont*sys3g/(1+sys3cont*sys3g);


%hold on
grid on
%bode(sys3cont);
%figure;bode(sys3g);
bode(sys3);
figure;bode(sys3open);