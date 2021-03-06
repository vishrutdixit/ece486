fresp;
omega = dsa(:,1);
data = dsa(:,2) + 1i*dsa(:,3);

s = tf('s');

%%  Bode Plots of DSA Data

dsatf = 64.275*(0.1294*s+1)/((0.0065*s+1)*(0.2027*s+1));
data = data*18.66;

close all;
figure(1);
subplot(2,1,1), semilogx(omega,mag2db(abs(data)),'r-'), hold on, bodemag(dsatf,'b-');
legend('Fresp data','DSA fit tf');
[m,p,w] = bode(dsatf);
p = squeeze(p);
subplot(2,1,2), xlabel('Frequency (rad/s)'), ylabel('Magnitude (dB)'); 
semilogx(omega,180/pi*(phase(data)),'r-'), hold on, semilogx(w(:,1),p(:,1),'b-');
legend('Fresp data','DSA fit tf');

%% Plotting V_omega/Vi

alpha = (10/(2*pi))/.0304;
dsatf_ol = alpha*64.275*(0.1294*s+1)/((0.0065*s+1)*(0.2027*s+1)*(s));

figure(2);
adj = abs(data);%*(alpha/omega);
subplot(2,1,1), semilogx(omega,adj-10,'r-'), hold on, bodemag(dsatf_ol,'b-');
legend('Fresp data','DSA fit tf');
[m,p,w] = bode(dsatf_ol);
p = squeeze(p);
subplot(2,1,2), xlabel('Frequency (rad/s)'), ylabel('Magnitude (dB)'); 
semilogx(omega,(180/pi*(phase(data)))-90,'r-'), hold on, semilogx(w(:,1),p(:,1),'b-');
legend('Fresp data','DSA fit tf');

figure(3), margin(dsatf_ol);

%% Cl Bode

dsatf_ol = alpha*64.275*(0.1294*s+1)/((0.0065*s+1)*(0.2027*s+1)*(s));
dsatf_cl = dsatf_ol / (1+dsatf_ol);

x = adj-10;
x = x/(1+x);

d = data(:,1) ./ (1+data(:,1));

close all;
figure(5);
adj = abs(data);%*(alpha/omega);
subplot(2,1,1), semilogx(omega,x,'r-'), hold on, bodemag(dsatf_cl,'b-');
legend('Fresp data','DSA fit tf');
[m,p,w] = bode(dsatf_cl);
p = squeeze(p);
subplot(2,1,2), xlabel('Frequency (rad/s)'), ylabel('Magnitude (dB)'); 
semilogx(omega,(180/pi*(phase(d))),'r-'), hold on, semilogx(w(:,1),p(:,1),'b-');
legend('Fresp data','DSA fit tf');

bandwidth(dsatf_cl)

