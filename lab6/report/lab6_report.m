fresp;
omega = dsa(:,1);
data = dsa(:,2) + 1i*dsa(:,3);

s = tf('s');

%%  Bode Plots of DSA Data

dsatf = 64.275*(0.1294*s+1)/((0.0065*s+1)*(0.2027*s+1))
data = data*18.66;


figure(1);
subplot(2,1,1), semilogx(omega,mag2db(abs(data)),'r-'), hold on, bodemag(dsatf);
[m,p,w] = bode(dsatf);
p = squeeze(p);
subplot(2,1,2), xlabel('Frequency (rad/s)'), ylabel('Magnitude (dB)'); 
semilogx(omega,180/pi*(phase(data))), hold on, semilogx(w(:,1),p(:,1));
